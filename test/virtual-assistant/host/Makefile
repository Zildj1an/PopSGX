include ../../config.mk

CC = gcc
CFLAGS = -std=gnu11 -Isrc -Iutils `pkg-config --cflags libcurl`
LIBS = -lssl -lcrypto -ljson-c `pkg-config --libs libcurl`

CFLAGS+=$(shell pkg-config oehost-$(COMPILER) --cflags)
LDFLAGS+=$(shell pkg-config oehost-$(COMPILER) --libs)

ROOT_DIR = $(shell pwd)
BUILD_DIR = ./build
SRC_DIR = ./src
USR_BIN = /usr/bin
INCDIR=$(shell pkg-config oehost-$(COMPILER) --variable=includedir)

# Header file dependencies
DEPS = src/init_config.h utils/b64.h utils/defines.h

# Source file dependencies
SRCS_DEPS = $(shell find $(SRC_DIR) -name "*.c")

# Main Target: ./build/virtual_assistant
$(BUILD_DIR)/virtual_assistant: $(BUILD_DIR)/main.o $(BUILD_DIR)/init_config.o
	oeedger8r -Wno-non-portable-type ../virtualassistant.edl --popsgx --untrusted \
		--search-path $(INCDIR) \
		--search-path $(INCDIR)/openenclave/edl/sgx
	$(CC) -g -fno-stack-protector -c $(CFLAGS) -DOE_API_VERSION=2 virtualassistant_u.c -o $(BUILD_DIR)/virtualassistant_u.o $(LDFLAGS) -I/usr/include/
	$(CC) -o $@ $(BUILD_DIR)/virtualassistant_u.o $^ $(CFLAGS) $(LDFLAGS) $(LIBS)

# Rule: building main.o
$(BUILD_DIR)/main.o: main.c $(DEPS) $(SRCS_DEPS)
	mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

# Rule: building any build/*.o file from src/*.c file
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c $(DEPS) $(SRCS_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

.PHONY: clean
# Install the binary
install:
	ln -sf $(ROOT_DIR)/$(BUILD_DIR)/virtual_assistant $(USR_BIN)/virtual_assistant
	ln -sf $(ROOT_DIR)/events.dat $(USR_BIN)/events.dat
	ln -sf $(ROOT_DIR)/config		$(USR_BIN)/config
	@echo "Installation Complete: run using virtual_assistant"

# Target: remove build dir
clean:
	rm -rf $(BUILD_DIR)
uninstall:	
	rm -rf $(USR_BIN)/virtual_assistant $(USR_BIN)/virtual_assistant $(USR_BIN)/config
