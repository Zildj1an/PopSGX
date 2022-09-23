# PopSGX

Read our paper [here](https://www.ssrg.ece.vt.edu/papers/systex22.pdf)!

A remote Open Enclave for Raspberry Pi or other embedded devices. As such, it can be used to provide ARM devices with Intel SGX features. We provide instructions to test locally with Qemu.

## Table of contents

1. [Installation](#installation)
2. [Instructions](#instructions)
3. [How does it work?](#magic)
4. [Testing with Qemu](#qemu)
5. [Testing with Raspberry Pi](#rasp)
6. [Compilation issues](#comp)
7. [Authors and License](#authors)

## Installation <a name="installation"></a>

Install [SGX](https://github.com/intel/linux-sgx), [Open Enclave](https://github.com/openenclave/openenclave) (you can check doc/install\_sgx for guidance) and our dependencies:

```
sudo apt-get install libssl-dev gcc-multilib qemu-system-arm bridge-utils cmake ncurses-* 
sudo pip3 instal cmake
```

If you don't install gcc-multilib, you might have issues compiling the oeedger8r tool regarding the headers with asm-generic/.
We need as well the dependencies of CRIU/libcompel:

```
sudo apt install libprotobuf-dev libprotobuf-c0-dev protobuf-c-compiler protobuf-compiler python-protobuf pkg-config libbsd-dev libcap-dev
```
after that, you can install libcompel following [these instructions](https://github.com/ssrg-vt/popcorn-chameleon). Install on /usr/local/libcompel (add `-w` on CFLAGS of criu/Makefile to ignore all warnings). 

To compile src/server\_client, the Makefile needs the location of your criu image, so you will need to update the $(CRIU) variable.

To test Heartbleed we need to install libssl1.0-dev, which can be done with:

```
$ sudo vim /etc/apt/sources.list
$ add deb http://security.ubuntu.com/ubuntu bionic-security main
$ sudo apt update && apt-cache policy libssl1.0-dev
$ sudo apt-get install libssl1.0-dev
```

## Instructions  <a name="instructions"></a>

Add the --pop-sgx flag in oeedger8r for your Makefile and generate the binaries for your OpenEnclave directory contained inside test/. For example, for the sample helloworld we include:

```
$ ./create_popsgx.sh generate helloworld
```

You can clean with:

```
$ ./create_popsgx.sh clean helloworld
```

You can then check how to run popsgx (server and client) with:

```
$ ./popsgx -h
```

### Running helloworld

Running `helloworld` on one desktop (use localhost as the network connection). You need to open two terminals one for client and one for server.

On 'server' side terminal:

```
$ cd build/server
$ sudo ./popsgx -b helloworld
```
On the 'client' side terminal:
```
$ cd build/client
$ sudo ./popsgx
```
You will see the following prompt on the client-side. Confirm the binary info and start offloading the SGX enclave to the 'remote' server:
```
...
What would you like to do? Manage (s)gx/E(x)it?:
Execute binary helloworldhostbin? [y/n]: y
Use enclave image (helloworldenc.signed) as only argument? [y/n]: y
...
```
Clean up the helloworld and the PopSGX:
```
$ cd <PopSGX Home>
$ ./create_popsgx.sh clean helloworld
```

## How does it work? <a name="magic"></a>

On this SSL/TLS infrastructure, both client (untrusted.c) and server (trusted.c) have a child that execve to the same binary:

- In the server, the child is a dummy host (wrapper) and the real enclave.

- In the client, the child is the real host, and the enclave is just a wrapper.

In both cases childs request stuff to their parents via signals (parenthood.c):

1. They ask them for functions when they cannot execute them. In the case of the server, these will be calls to the host, and 
in the client these will be calls to the enclave (wrapped by eedgr8r).

2. They send them their heap information to allow DSM; since function calls have pointers.

3. They ask them for pages when they page fault. The children have userfaultfd (popsgx.h), and the parents synchronize and share with socket.

## Testing with Qemu  <a name="qemu"></a>

To test the framework on your local machine you can use qemu and the contents of directory qemu/. The image for x86 is heavyweight, you need to download it separately. You can use [x86 img](https://drive.google.com/u/0/uc?id=0B7RfKPGm2YZsaURxTVh5ZTMyTk0&export=download) and for arm you will find the files [here](https://people.debian.org/~aurel32/qemu/armel/).

To pass the client files you can do:

```
$ sudo scp popsgx popcorn@10.4.4.101:/home/popcorn
```

You will also need:

```
$ sudo apt install gcc-arm*
```

If you want to use your custom kernel, clone and make it twice (x86 and arm64). For cross compilation:

```
$ git clone  linux-arm
$ cd linux-arm
$ ARCH="arm64" CROSS\_COMPILE="aarch64-linux-gnu-" make defconfig
$ ARCH="arm64" CROSS\_COMPILE="aarch64-linux-gnu-" make -j <threads>
``` 
See errors compiling the kernel below.

## Testing with Raspberry Pi <a name="rasp"></a>

Compile the project with the branch rasp. For openenclave, clone the project and:

0. Check commit 2a55806de20778e8aa68eb53e228434d260cebfb.

1. Edit cmake/add\_enclave.cmake +363 and comment the last two custom targets that use BYPRODUCTS. You should have:

```
  # Strip unneeded bits.
  string(REPLACE "gcc" "objcopy" OBJCOPY ${CMAKE_C_COMPILER})
  #add_custom_target(
  #  ${ENCLAVE_TARGET}.stripped.elf
  # COMMAND ${OBJCOPY} --strip-unneeded $<TARGET_FILE:${ENCLAVE_TARGET}>
  #         $<TARGET_FILE_DIR:${ENCLAVE_TARGET}>/${ENCLAVE_UUID}.stripped.elf
  # BYPRODUCTS $<TARGET_FILE_DIR:${ENCLAVE_TARGET}>/${ENCLAVE_UUID}.stripped.elf
  #)
  #add_dependencies(${ENCLAVE_TARGET}.stripped.elf ${ENCLAVE_TARGET})

  # Sign the TA with the given key, or with the default key if none was given.
  if (NOT ENCLAVE_KEY)
    set(ENCLAVE_KEY ${OE_TZ_TA_DEV_KIT_DEFAULT_SIGNING_KEY})
  endif ()
  #add_custom_target(
  #  ${ENCLAVE_TARGET}.ta ALL
  # COMMAND
  #   ${OE_TZ_TA_DEV_KIT_SIGN_TOOL} --key ${ENCLAVE_KEY} --uuid ${ENCLAVE_UUID}
  #   --version 0 --in
  # $<TARGET_FILE_DIR:${ENCLAVE_TARGET}>/${ENCLAVE_UUID}.stripped.elf --out
  #   $<TARGET_FILE_DIR:${ENCLAVE_TARGET}>/${ENCLAVE_UUID}.ta
  # BYPRODUCTS $<TARGET_FILE_DIR:${ENCLAVE_TARGET}>/${ENCLAVE_UUID}.ta)
  #add_dependencies(${ENCLAVE_TARGET}.ta ${ENCLAVE_TARGET}.stripped.elf)
```

2. If using 32 bits architecture, comment the FATAL\_ERROR message on cmake/compiler\_settings.cmake +53.

3. Start the git submodules recursively. 

4. Cmake and copy the contents of output/ to /opt/openenclave/ and pkgconfig to /opt/openenclave/share.

5. Update /opt/openenclave/share/openenclave/openenclaverc to point to /opt/openenclave.

6. Update include/openenclave/edl/syscall.edl +24 with the right paths. Same idea with platform.edl. Update the edls of your files (inside PopSGX/test/) accordingly.

7. On compilation, you might need to do:

```
$ sudo ln -s /usr/include/arm-linux-gnueabihf/bits /usr/include/bits
```

and the same with sys, gnu. 

8. Adapt the includes of Open Enclave, removing the error on include/openenclave/bits/defs.h +12. Also, fix the conflicting type errors by commenting the typedefs and including the stddef.h and stdint.h headers on bits/types.h. You might also need to update /usr/include/types.h with <asm-generic/types.h>. A fastest way to deal with this is to `mkdir /usr/include/asm/` and `cp \*.h /usr/include/asm-generic /usr/include/asm`. 

9. If the linker cannot find shared libraries (i.e. cannot find -lexample, for example) you might have to do `sudo cp /usr/lib/<path>/libexample.so.version /usr/lib/<path>libexample.so`.

10. For some samples you might need extra packages. For example for the Virtual Assistant you shouldo also have libjson-c-dev and libcurl4-gnutls-dev.

### Server-client communication

To provide network interfaces to the host and VMs at the same time, we make the host's NIC as a bridged interface and tap VMs' NICs to the bridged interface. We assume the host uses 10.4.4.10, x86 VM 10.4.4.100, and ARM VM 10.4.4.101 in 10.4.4.0/24 subnet. Change address, netmask, gateway and dns-nameservers fields accordingly if you want to use other IP addresses/subnet.

- Edit `/etc/network/interfaces` to setup the host's eth0 as a bridged interface:

```
$ sudo vim /etc/network/interfaces
(...)
auto eth0
iface eth0 inet manual

auto br0
iface br0 inet static
    address 10.4.4.10
    netmask 255.255.255.0
    gateway 10.4.4.1
    dns-nameservers 8.8.8.8
    bridge_ports eth0
    bridge_stp off
    bridge_fd 0
    bridge_maxwait 0
```

- Allow IP forwarding at the host

```
$ sudo vi /etc/sysctl.conf
(...)
net.ipv4.ip\_forward = 1
...

$ sysctl -p /etc/sysctl.conf 

```
- Reload the NIC configuration.
```
$ sudo /etc/init.d/networking restart

```

- NIC configuration should be like:

```
$ brctl show
 bridge name        bridge id                STP enabled       interfaces
 br0                8000.0cc47adec9ca        no                eth0
$ sudo ifconfig
br0       Link encap:Ethernet  HWaddr 0c:c4:7a:de:c9:ca
          inet addr:10.4.4.10  Bcast:10.4.4.255  Mask:255.255.255.0
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
        (...)

eth0      Link encap:Ethernet  HWaddr 0c:c4:7a:de:c9:ca
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
        (...)
```

Also, the host should be able to connect to the Internet as it was.

#### Netplan alternative

If instead you are using the new netplan daemon, you can update your file on /etc/netplan/*.yaml, add the ethernet and the bridge. You will need to do sudo netplan generate and sudo netplan apply after that. So, if we replace the ethernet by our ethernet interface (see ```$ip a```):

```
10:11 [qemu] (master)$ cat /etc/netplan/01-network-manager-all.yaml 
# Let NetworkManager manage all devices on this system
network:
  version: 2
  renderer: NetworkManager
  ethernets:
          enx0050b62950bb:
            dhcp4: false
  bridges:
        br0:
            interfaces:
                - enx0050b62950bb
            addresses: [ 10.4.4.10/24 ]
            nameservers:
                addresses: [ "8.8.8.8" ]
            routes:
                - to: 0.0.0.0/0
                  via: 10.4.4.1    
            gateway4: 10.4.4.1
            parameters:
                stp: false
                forward-delay: 0
10:11 [qemu] (master)$ sudo netplan generate
10:11 [qemu] (master)$ sudo netplan apply
```
which will show here:

```
10:34 [~]$ ip route
default via 10.4.4.1 dev br0 proto static metric 20425 
(...)
```
and the bridge as UP on ```$ip a```.

## Compilation issues  <a name="comp"></a>

### PopSGX

Your enclave Makefile needs to include libraries to compile popsgx.h, so don't forget to add '-I/usr/include'. If you followed the installation instructions, on x86 the gcc-multilib package will have linked /usr/include/asm and you will not have compilation issues there. 

The src/oeedgr8r compilation might not succeed due to path conflicts; when you download the repo, CMake has my generated path. The script create\_popsgx.sh tries to automatically fix this, but if that doesn't work you can manually update CMake paths:

```
$ cd src/oeedger8r
$ vim CMakeCache.txt # Update the path were necessary
$ cmake .
```

If you get an error like:

```
Processing /opt/openenclave/share/pkgconfig/../../include/openenclave/edl/sgx/attestation.edl.
error: /opt/openenclave/share/pkgconfig/../../include/openenclave/edl/sgx/attestation.edl:56:14 `out' is invalid for user defined type `format\_ids\_t*'
make[2]: *** [Makefile:31: build] Error 1
```
you are using an older version of eedger8r!

### Kernel

When cross-compiling for arm64 you might get:

```
09:13 [linux-arm] (master)$ ARCH="arm64" CROSS_COMPILE="aarch64-linux-gnu-" make defconfig
*** Default configuration is based on 'defconfig'
scripts/Kconfig.include:39: compiler 'aarch64-linux-gnu-gcc' not found
make[1]: *** [scripts/kconfig/Makefile:87: defconfig] Error 1
make: *** [Makefile:616: defconfig] Error 2
09:13 [linux-arm] (master)$ 
```

Fear not! You can do:

```
$ sudo dpkg --add-architecture arm64
$ sudo apt install gcc-10-aarch64-linux-gnu
$ sudo cp /bin/aarch64-linux-gnu-gcc-10 /bin/aarch64-linux-gnu-gcc
```

## Authors and License <a name="authors"></a>

The main author of this software is [Carlos Bilbao](https://github.com/Zildj1an) under
Dr. [Xiaoguang Wang](https://github.com/xjtuwxg) supervision.

PopSGX is distributed under the MIT license. For more information, read
file LICENSE.
