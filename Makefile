CC = gcc
DEFS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_POSIX_C_SOURCE=200809L
CFLAGS = -Wall -g -std=c99 -pedantic $(DEFS) -I include

SRC := $(shell (find src -iname *.c )) $(shell (find thirdparty -iname *.c ))
INC := $(shell (find include -iname *.h))

OBJ := $(SRC:src/%.c=obj/%.o)
OBJ := $(OBJ:thirdparty/%.c=obj/%.o)

TEST_SRC := $(shell (find test -iname *.c ))
TEST_OBJ := $(TEST_SRC:test/%.c=obj/%.o)
TEST_BIN := $(TEST_SRC:test/%.c=build/%)

all: lib/p2p.a

test: $(TEST_BIN)

obj/%.o: src/%.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)

obj/%.o: thirdparty/%.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)

obj/%.o: test/%.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)

lib/p2p.a: $(OBJ)
	@echo $(OBJ)
	ar rcs $@ $^

build/%: obj/%.o lib/p2p.a
	$(CC) $(LDFALGS) -o $@ $< lib/p2p.a

clean:
	rm -f $(OBJ)
	rm -f $(TEST_BIN)
	rm -f lib/p2p.a

.PHONY: all clean test
