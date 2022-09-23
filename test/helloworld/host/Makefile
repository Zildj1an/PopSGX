# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.

include ../../config.mk

CFLAGS=$(shell pkg-config oehost-$(COMPILER) --cflags)
LDFLAGS=$(shell pkg-config oehost-$(COMPILER) --libs)

# Disable positional independent code
# LDFLAGS+=" -no-pie emerge -v1 foo-package"

INCDIR=$(shell pkg-config oehost-$(COMPILER) --variable=includedir)

build:
	@ echo "Compilers used: $(CC), $(CXX)"
	oeedger8r -Wno-non-portable-type ../helloworld.edl --popsgx --untrusted \
		--search-path $(INCDIR) \
		--search-path $(INCDIR)/openenclave/edl/sgx
	$(CC) -g -c $(CFLAGS) -fno-stack-protector -ggdb host.c
	$(CC) -g -c $(CFLAGS) -fno-stack-protector -ggdb helloworld_u.c
	$(CC) -o helloworldhost helloworld_u.o host.o $(LDFLAGS)

clean:
	rm -f helloworldhost host.o helloworld_u.o helloworld_u.c helloworld_u.h helloworld_args.h
