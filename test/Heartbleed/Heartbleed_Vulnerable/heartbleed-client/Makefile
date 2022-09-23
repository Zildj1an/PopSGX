LDFLAGS += -lssl -lcrypto -lncurses -L./openssl_src

all:
	$(CC) -g -c -I./openssl_src -fno-stack-protector -ggdb heartbleed.c
	$(CC) -g -c -I./openssl_src -fno-stack-protector -ggdb tls.c
	$(CC) -I./openssl_src -o heart heartbleed.o tls.o /lib/x86_64-linux-gnu/libcrypto.so /lib/x86_64-linux-gnu/libssl.so $(LDFLAGS)
clean:
	rm *.o 
