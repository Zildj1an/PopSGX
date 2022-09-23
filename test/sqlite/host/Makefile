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
	oeedger8r -Wno-non-portable-type ../sqlite.edl --popsgx --untrusted \
		--search-path $(INCDIR) \
		--search-path $(INCDIR)/openenclave/edl/sgx
	$(CC) -g -c $(CFLAGS) -fno-stack-protector -ggdb host.cpp
	$(CC) -g -c $(CFLAGS) -fno-stack-protector -ggdb ocalls.c
	$(CC) -g -c $(CFLAGS) -fno-stack-protector -ggdb sqlite_u.c
	$(CC) -o sqlitehost sqlite_u.o ocalls.o host.o $(LDFLAGS)

clean:
	rm -f sqlitehost host.o ocalls.o sqlite_u.o sqlite_u.c sqlite_u.h sqlite_args.h
