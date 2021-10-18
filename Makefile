CC = cc
CFLAGS = -I include -std=c99

SRC := $(shell (find src -iname *.c )) $(shell (find thirdparty -iname *.c ))
INC := $(shell (find include -iname *.h))

OBJ := $(SRC:src/%.c=obj/%.o)
OBJ := $(OBJ:thirdparty/%.c=obj/%.o)

TEST_SRC := $(shell (find test -iname *.c ))
TEST_OBJ := $(TEST_SRC:test/%.c=obj/%.o)
TEST_BIN := $(TEST_SRC:test/%.c=build/%)

all: lib/libp2p.a

test: $(TEST_BIN)

obj/%.o: src/%.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)

obj/%.o: thirdparty/%.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)

obj/%.o: test/%.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)

lib/libp2p.a: $(OBJ)
	ar rcs $@ $^

build/%: obj/%.o lib/libp2p.a
	$(CC) $(LDFALGS) -Llib -o $@ $<

clean:
	rm -f $(OBJ)
	rm -f $(TEST_BIN)
	rm -f lib/libp2p.a

.PHONY: all clean test
