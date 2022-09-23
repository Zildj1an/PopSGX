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
	oeedger8r -Wno-non-portable-type ../Heartbleed.edl --pop-sgx --trusted \
		--search-path $(INCDIR) \
		--search-path $(INCDIR)/openenclave/edl/sgx
	$(CC) -g -fno-stack-protector -c $(CFLAGS) -DOE_API_VERSION=2 ecalls.c -o ecalls.o -I/usr/include/
	$(CC) -g -fno-stack-protector -c $(CFLAGS) -DOE_API_VERSION=2 Heartbleed_t.c -o Heartbleed_t.o $(LDFLAGS) -I/usr/include/
	$(CC) -o Heartbleedenc Heartbleed_t.o ecalls.o $(LDFLAGS) $(CRYPTO_LDFLAGS)

sign:
	oesign sign -e Heartbleedenc -c Heartbleed.conf -k private.pem

clean:
	rm -f ecalls.o Heartbleedenc Heartbleedenc.signed private.pem public.pem Heartbleed_t.o Heartbleed_t.h Heartbleed_t.c Heartbleed_args.h

keys:
	openssl genrsa -out private.pem -3 3072
	openssl rsa -in private.pem -pubout -out public.pem
