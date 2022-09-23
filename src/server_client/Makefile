CUR_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

CC = gcc
CFLAGS += -g -ggdb -O2 -Wall -pthread -DLOG_USE_COLOR -Wno-discarded-qualifiers \
		-Wno-unused-but-set-variable -Wno-unused-variable \
		-Wno-deprecated-declarations -Wno-maybe-uninitialized \
		-fno-stack-protector -Wno-attributes

LDFLAGS = -lssl -lcrypto -lncurses 

DEPS_DIR  := $(CUR_DIR)/.deps$(LIB_SUFFIX)
DEPCFLAGS = -MD -MF $(DEPS_DIR)/$*.d -MP

SRC_FILES = $(wildcard *.c)
OBJ_FILES := trace.o tls.o bus_functions.o parenthood.o \
	     ../log/log.o dsm_userspace.o untrusted.o trusted.o dsm_statemachine.o

EXE_FILES = $(SRC_FILES:.c=)

%.o:%.c $(DEPS_DIR)
	$(CC) $(CFLAGS) $(DEPCFLAGS) -c $(input) -o $(output) 

popsgx: $(OBJ_FILES)
	$(CC) -o $@ $(CFLAGS) $(OBJ_FILES) $(LDFLAGS)

all: $(EXE_FILES)
	echo $(EXE_FILES)
clean:
	rm -f popsgx $(OBJ_FILES)

.PHONY: all clean
