#!/bin/bash
# Script to start PopSGX
# author Carlos Bilbao 😎
# bilbao at vt.edu

function gen_s_c {
	cd src/server_client
	make
	mv popsgx ../..
	cd -
}

function gen_s_c_arm {
	cd src/server_client
	make arm
	mv popsgx ../..
	cd -
}

# Generate the oeedger8r used in OpenEnclave
function gen_oeedger8r {
	pushd .
	cd src/oeedger8r-cpp; mkdir -p build; cd build
	cmake ..; make -C ../
	cd ..
	sudo cp src/oeedger8r /usr/bin
	popd
}

function generate {
	clean

	# Make the shell exit if a command exits with a nonzero value
	set -e

	echo "#############################################################"
	echo "# [1/2] Building the server-client source code...           #"
	echo "#############################################################"
	gen_s_c
	if [ ! -d "build" ]; then
		mkdir build
		mkdir build/server
		mkdir build/client
	fi
	cp popsgx build/server
	cp popsgx build/client
	
	cp cert/mycert.pem build/server

	echo "#############################################################"
	echo "# [2/2] Generating the SGX source code...                   #"	
	echo "#############################################################"
	gen_oeedger8r
	cp src/popsgx.h test/$1/
	cd test/$1
	
	make
	
	if [[ $1 == *"virtual"* ]]; then
		cp host/build/virtual_assistant host/$1host
		cp enclave/virtualenc.signed enclave/$1enc.signed
		cp enclave/virtualenc enclave/$1enc
		cp host/config ../../build/client/
		cp host/config ../../build/server/
	fi
	
	mv host/$1host ../../build/server
	mv enclave/$1enc ../../build/server

	if [[ $1 == *"file"* ]]; then
		# File encryptor
		echo "potato" > ../../build/server/test_file
		echo "potato" > ../../build/client/test_file
		cp enclave/$1enc.signed ../../build/server/fileencryptorenc.signed	
	else
		mv enclave/$1enc.signed ../../build/server	
	
		if [[ $1 == *"virtual"* ]]; then
			mv ../../build/server/$1enc.signed ../../build/server/virtualassistantenc.signed
		fi
	fi

	if [[ $1 == *"openfabmap"* ]]; then
		cp host/settings.yml ../../build/server
	fi
	
	if [[ $1 == *"gcc"* ]]; then
		echo "502_gcc_r" >  ../../build/client/gcc_file
	fi

	rm ../../popsgx
	
	echo "#############################################################"
	echo "#  You can find binaries in the directory ./build           #"
	echo "#############################################################"
}

function clean {
	# Clean the PopSGX build/server build/client
	echo "[-] Clean the PopSGX build/server build/client"
	rm -rf build &> /dev/null

	# Clean the oeedger8r
	echo "[-] Clean the oeedger8r"
	rm -rf src/oeedger8r-cpp/build &> /dev/null
	make clean -C src/oeedger8r-cpp/src &> /dev/null

	# Clean the test case build
	echo "[-] Clean the test case"
	cd test/$1
	rm -f popsgx.h &> /dev/null
	make clean &> /dev/null
	cd - &> /dev/null

	# Get rid of any missing executable... 
	pkill $1 &> /dev/null
	make clean -C test/virtual-assistant/host &> /dev/null
	make clean -C test/virtual-assistant/enclave &> /dev/null

	echo "Finish the cleaning..."
}

# Default open-enclave functions
. /opt/openenclave/share/openenclave/openenclaverc

if [ "$1" = "generate" ]; then
    if [ "$#" -lt 2 ]; then
    	echo "You must provide the directory as an argument"
    	exit
    fi
    if [ "$#" -lt 3 ]; then
    	echo "Starting to generate..."
    	generate $2 $3
	exit
    fi
elif [ "$1" = "clean" ]; then
    echo "Cleaning..."
    clean $2 $3
elif [ "$1" = "test" ]; then
    gen_s_c
    gen_test
elif [ "$1" == "oed" ]; then
    gen_oeedger8r
fi
