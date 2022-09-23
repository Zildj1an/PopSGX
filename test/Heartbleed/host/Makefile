# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.

include ../config.mk

CFLAGS=$(shell pkg-config oehost-$(COMPILER) --cflags) 
LDFLAGS=$(shell pkg-config oehost-$(COMPILER) --libs)

LDFLAGS += -lsslhost -lcryptohost -lncurses
LDFLAGS += -L../openssl_src

# Disable positional independent code
# LDFLAGS+=" -no-pie emerge -v1 foo-package"

INCDIR=$(shell pkg-config oehost-$(COMPILER) --variable=includedir)

build:
	@ echo "Compilers used: $(CC), $(CXX)"
	oeedger8r -Wno-non-portable-type ../Heartbleed.edl --popsgx --untrusted \
		--search-path $(INCDIR) \
		--search-path $(INCDIR)/openenclave/edl/sgx
	$(CC) -g -c $(CFLAGS) -I../openssl_src -fno-stack-protector -ggdb host.c
	$(CC) -g -c $(CFLAGS) -I../openssl_src -fno-stack-protector -ggdb Heartbleed_u.c
	$(CC) -g -c $(CFLAGS) -I../openssl_src -fno-stack-protector -ggdb log.c
	$(CC) -g -c $(CFLAGS) -I../openssl_src -fno-stack-protector -ggdb tls.c
	$(CC) -g -c $(CFLAGS) -I../openssl_src -fno-stack-protector -ggdb bus_functions.c
	$(CC) -I../openssl_src -o Heartbleedhost bus_functions.o log.o tls.o Heartbleed_u.o host.o /lib/x86_64-linux-gnu/libcryptohost.so /lib/x86_64-linux-gnu/libsslhost.so $(LDFLAGS)

clean:
	rm -f Heartbleedhost bus_functions.o host.o log.o Heartbleed_u.o tls.o Heartbleed_u.c Heartbleed_u.h Heartbleed_args.h
