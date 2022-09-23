# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.

include ../../config.mk

CFLAGS=$(shell pkg-config oehost-$(C_COMPILER) --cflags)
CXXFLAGS=$(shell pkg-config oehost-$(CXX_COMPILER) --cflags)
LDFLAGS=$(shell pkg-config oehost-$(CXX_COMPILER) --libs)
INCDIR=$(shell pkg-config oehost-$(C_COMPILER) --variable=includedir)

all: build

build:
	@ echo "Compilers used: $(CC), $(CXX)"
	oeedger8r ../fileencryptor.edl --pop-sgx --untrusted \
		--search-path $(INCDIR) \
		--search-path $(INCDIR)/openenclave/edl/sgx
	$(CXX) -g -c $(CXXFLAGS) -I/home/zildj1an/Documents/VT/openenclave/include/ -I/home/zildj1an/Documents/VT/openenclave/host/ -I/usr/include/ host.cpp
	$(CC) -g -c $(CFLAGS) -I/home/zildj1an/Documents/VT/openenclave/include/ -I/home/zildj1an/Documents/VT/openenclave/host/ -I/usr/include/ fileencryptor_u.c
	$(CXX) -o file-encryptorhost host.o fileencryptor_u.o $(LDFLAGS)

clean:
	rm -f file-encryptorhost fileencryptor_u.* fileencryptor_args.h *.o ../out.decrypted ../out.encrypted

