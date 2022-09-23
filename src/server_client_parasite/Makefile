CUR_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

CRIU=/home/zildj1an/Documents/VT/popcorn-chameleon/criu
CRIU_PARASITE_HEAD=$(CRIU)/compel/arch/x86/plugins/std/parasite-head.o

CC = gcc
CFLAGS += -g -ggdb -O2 -Wall -pthread -DLOG_USE_COLOR -Wno-discarded-qualifiers \
		-Wno-unused-but-set-variable -Wno-unused-variable \
		-Wno-deprecated-declarations -Wno-maybe-uninitialized \
		-fno-stack-protector -Wno-attributes \
		-Wstrict-prototypes -fno-stack-protector  \
		-fomit-frame-pointer -fpie -I /usr/local/libcompel/include \
		-I$(CRIU)/arch/x86/include -I$(CRIU)/include/ \
		-L/usr/local/libcompel/lib64/release
#		-Wl,--unresolved-symbols=ignore-all

LDFLAGS = -lssl -lcrypto -lncurses -lcompel
 
# $(compel ldflags)
LDFLAGS +=-r -z noexecstack -T $(CRIU)/compel/arch/x86/scripts/compel-pack.lds.S 

DEPS_DIR  := $(CUR_DIR)/.deps$(LIB_SUFFIX)
DEPCFLAGS = -MD -MF $(DEPS_DIR)/$*.d -MP

SRC_FILES = $(wildcard *.c)
OBJ_FILES := parasite.o ptrace.o tls.o bus_functions.o parenthood.o \
	     ../log/log.o dsm_userspace.o untrusted.o trusted.o dsm_statemachine.o

EXE_FILES = $(SRC_FILES:.c=)

%.o:%.c $(DEPS_DIR)
	$(CC) $(CFLAGS) $(DEPCFLAGS) -c $(input) -o $(output) 

popsgx: $(OBJ_FILES)
	$(CC) -c -o parasite-head.o parasite-head.S $(CFLAGS)
	$(CC) -o $@ $(CFLAGS) parasite-head.o $(OBJ_FILES) $(LDFLAGS) 
	#$(CC) -o $@ $(CFLAGS) $(CRIU_PARASITE_HEAD) $(OBJ_FILES) $(LDFLAGS) 

all: $(EXE_FILES)
	echo $(EXE_FILES)
clean:
	rm -f popsgx $(OBJ_FILES)

.PHONY: all clean
