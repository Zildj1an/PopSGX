# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.

include ../../config.mk

CRYPTO_LDFLAGS := $(shell pkg-config oeenclave-$(COMPILER) --variable=${OE_CRYPTO_LIB}libs)

ifeq ($(LVI_MITIGATION), ControlFlow)
	ifeq ($(LVI_MITIGATION_BINDIR),)
		$(error LVI_MITIGATION_BINDIR is not set)
	endif
	# Only run once.
	ifeq (,$(findstring $(LVI_MITIGATION_BINDIR),$(CC)))
		CC := $(LVI_MITIGATION_BINDIR)/$(CC)
	endif
	COMPILER := $(COMPILER)-lvi-cfg
	CRYPTO_LDFLAGS := $(shell pkg-config oeenclave-$(COMPILER) --variable=${OE_CRYPTO_LIB}libslvicfg)
endif

CFLAGS=$(shell pkg-config oeenclave-$(COMPILER) --cflags)

LDFLAGS=$(shell pkg-config oeenclave-$(COMPILER) --libs)
INCDIR=$(shell pkg-config oeenclave-$(COMPILER) --variable=includedir)

all:
	$(MAKE) build
	$(MAKE) keys
	$(MAKE) sign

build:
	@ echo "Compilers used: $(CC), $(CXX)"
	oeedger8r -Wno-non-portable-type ../openfabmap.edl --pop-sgx --trusted \
		--search-path $(INCDIR) \
		--search-path $(INCDIR)/openenclave/edl/sgx
	$(CC) -g -fno-stack-protector -c $(CFLAGS) -DOE_API_VERSION=2 enc.c -o enc.o -I/usr/include/
	$(CC) -g -fno-stack-protector -c $(CFLAGS) -DOE_API_VERSION=2 openfabmap_t.c -o openfabmap_t.o $(LDFLAGS) -I/usr/include/
	$(CC) -o openfabmapenc openfabmap_t.o enc.o $(LDFLAGS) $(CRYPTO_LDFLAGS) -L/opt/openenclave/share/pkgconfig/../../lib/openenclave/enclave -nostdlib -nodefaultlibs -nostartfiles -Wl,--no-undefined -Wl,-Bstatic -Wl,-Bsymbolic -Wl,--export-dynamic -Wl,-pie -Wl,--build-id -Wl,-z,noexecstack -Wl,-z,now -Wl,-gc-sections -loeenclave -loelibc -loesyscall -loecore -loecryptombedtls -lmbedx509 -lmbedtls -lmbedcrypto -loelibc -loesyscall -loecore


sign:
	oesign sign -e openfabmapenc -c openfabmap.conf -k private.pem

clean:
	rm -f enc.o openfabmapenc openfabmapenc.signed private.pem public.pem openfabmap_t.o openfabmap_t.h openfabmap_t.c openfabmap_args.h

keys:
	openssl genrsa -out private.pem -3 3072
	openssl rsa -in private.pem -pubout -out public.pem
