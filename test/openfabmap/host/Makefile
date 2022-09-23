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
	oeedger8r -Wno-non-portable-type ../openfabmap.edl --popsgx --untrusted \
		--search-path $(INCDIR) \
		--search-path $(INCDIR)/openenclave/edl/sgx
	$(CC) -g -c $(CFLAGS) -fno-stack-protector -ggdb openFABMAPcli.cpp -lstdc++ 
	$(CC) -g -c $(CFLAGS) -fno-stack-protector -ggdb openfabmap_u.c -lstdc++
	$(CC) -o openfabmaphost openfabmap_u.o openFABMAPcli.o $(LDFLAGS) -lstdc++

clean:
	rm -f openfabmaphost openFABMAPcli.o openfabmap_u.o openfabmap_u.c openfabmap_u.h openfabmap_args.h
