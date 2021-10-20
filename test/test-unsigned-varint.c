#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <assert.h>

#include <multiformat/unsigned-varint.h>

typedef void(*test_function)(void);

void
test_unsigned_varint_from_uint_0(
	void
) {
	uint8_t *bytes = NULL;
	size_t amount_of_bytes = 0;

	uint8_t compare_bytes[] = {'\x00'};
	size_t amount_of_compare_bytes = sizeof(compare_bytes) / sizeof(compare_bytes[0]);

	int result = unsigned_varint_from_uint(&bytes, &amount_of_bytes, 0);

	assert(result == 0);
	assert(amount_of_bytes == amount_of_compare_bytes);
	assert(bytes != NULL);
	assert(memcmp(bytes, compare_bytes, amount_of_compare_bytes * sizeof(uint8_t)) == 0);

	return;
}

void
test_unsigned_varint_from_uint_1(
	void
) {
	uint8_t *bytes = NULL;
	size_t amount_of_bytes = 0;

	uint8_t compare_bytes[] = {'\x01'};
	size_t amount_of_compare_bytes = sizeof(compare_bytes) / sizeof(compare_bytes[0]);

	int result = unsigned_varint_from_uint(&bytes, &amount_of_bytes, 1);

	assert(result == 0);
	assert(amount_of_bytes == amount_of_compare_bytes);
	assert(bytes != NULL);
	assert(memcmp(bytes, compare_bytes, amount_of_compare_bytes * sizeof(uint8_t)) == 0);

	return;
}

void
test_unsigned_varint_from_uint_127(
	void
) {
	uint8_t *bytes = NULL;
	size_t amount_of_bytes = 0;

	uint8_t compare_bytes[] = {'\x7f'};
	size_t amount_of_compare_bytes = sizeof(compare_bytes) / sizeof(compare_bytes[0]);

	int result = unsigned_varint_from_uint(&bytes, &amount_of_bytes, 127);

	assert(result == 0);
	assert(amount_of_bytes == amount_of_compare_bytes);
	assert(bytes != NULL);
	assert(memcmp(bytes, compare_bytes, amount_of_compare_bytes * sizeof(uint8_t)) == 0);

	return;
}

void
test_unsigned_varint_from_uint_128(
	void
) {
	uint8_t *bytes = NULL;
	size_t amount_of_bytes = 0;

	uint8_t compare_bytes[] = { '\x80', '\x01' };
	size_t amount_of_compare_bytes = sizeof(compare_bytes) / sizeof(compare_bytes[0]);

	int result = unsigned_varint_from_uint(&bytes, &amount_of_bytes, 128);

	assert(result == 0);
	assert(amount_of_bytes == amount_of_compare_bytes);
	assert(bytes != NULL);
	assert(memcmp(bytes, compare_bytes, amount_of_compare_bytes * sizeof(uint8_t)) == 0);

	return;
}

void
test_unsigned_varint_from_uint_255(
	void
) {
	uint8_t *bytes = NULL;
	size_t amount_of_bytes = 0;

	uint8_t compare_bytes[] = { '\xff', '\x01' };
	size_t amount_of_compare_bytes = sizeof(compare_bytes) / sizeof(compare_bytes[0]);

	int result = unsigned_varint_from_uint(&bytes, &amount_of_bytes, 255);

	assert(result == 0);
	assert(amount_of_bytes == amount_of_compare_bytes);
	assert(bytes != NULL);
	assert(memcmp(bytes, compare_bytes, amount_of_compare_bytes * sizeof(uint8_t)) == 0);

	return;
}

void
test_unsigned_varint_from_uint_300(
	void
) {
	uint8_t *bytes = NULL;
	size_t amount_of_bytes = 0;

	uint8_t compare_bytes[] = { '\xac', '\x02' };
	size_t amount_of_compare_bytes = sizeof(compare_bytes) / sizeof(compare_bytes[0]);

	int result = unsigned_varint_from_uint(&bytes, &amount_of_bytes, 300);

	assert(result == 0);
	assert(amount_of_bytes == amount_of_compare_bytes);
	assert(bytes != NULL);
	assert(memcmp(bytes, compare_bytes, amount_of_compare_bytes * sizeof(uint8_t)) == 0);

	return;
}

void
test_unsigned_varint_from_uint_16384(
	void
) {
	uint8_t *bytes = NULL;
	size_t amount_of_bytes = 0;

	uint8_t compare_bytes[] = { '\x80', '\x80', '\x01' };
	size_t amount_of_compare_bytes = sizeof(compare_bytes) / sizeof(compare_bytes[0]);

	int result = unsigned_varint_from_uint(&bytes, &amount_of_bytes, 16384);

	assert(result == 0);
	assert(amount_of_bytes == amount_of_compare_bytes);
	assert(bytes != NULL);
	assert(memcmp(bytes, compare_bytes, amount_of_compare_bytes * sizeof(uint8_t)) == 0);

	return;
}

void
test_unsigned_varint_to_uint_0(
	void
) {
	uint8_t bytes[] = {'\x00'};
	size_t amount_of_bytes = sizeof(bytes) / sizeof(bytes[0]);

	uint64_t value;
	int result = unsigned_varint_to_uint(&value, bytes, amount_of_bytes);

	assert(result == 1);
	assert(value == 0);

	return;
}

void
test_unsigned_varint_to_uint_1(
	void
) {
	uint8_t bytes[] = {'\x01'};
	size_t amount_of_bytes = sizeof(bytes) / sizeof(bytes[0]);

	uint64_t value;
	int result = unsigned_varint_to_uint(&value, bytes, amount_of_bytes);

	assert(result == 1);
	assert(value == 1);

	return;
}

void
test_unsigned_varint_to_uint_127(
	void
) {
	uint8_t bytes[] = {'\x7f'};
	size_t amount_of_bytes = sizeof(bytes) / sizeof(bytes[0]);

	uint64_t value;
	int result = unsigned_varint_to_uint(&value, bytes, amount_of_bytes);

	assert(result == 1);
	assert(value == 127);

	return;
}

void
test_unsigned_varint_to_uint_128(
	void
) {
	uint8_t bytes[] = { '\x80', '\x01' };
	size_t amount_of_bytes = sizeof(bytes) / sizeof(bytes[0]);

	uint64_t value;
	int result = unsigned_varint_to_uint(&value, bytes, amount_of_bytes);

	assert(result == 2);
	assert(value == 128);

	return;
}

void
test_unsigned_varint_to_uint_255(
	void
) {
	uint8_t bytes[] = { '\xff', '\x01' };
	size_t amount_of_bytes = sizeof(bytes) / sizeof(bytes[0]);

	uint64_t value;
	int result = unsigned_varint_to_uint(&value, bytes, amount_of_bytes);

	assert(result == 2);
	assert(value == 255);

	return;
}

void
test_unsigned_varint_to_uint_300(
	void
) {
	uint8_t bytes[] = { '\xac', '\x02' };
	size_t amount_of_bytes = sizeof(bytes) / sizeof(bytes[0]);

	uint64_t value;
	int result = unsigned_varint_to_uint(&value, bytes, amount_of_bytes);

	assert(result == 2);
	assert(value == 300);

	return;
}

void
test_unsigned_varint_to_uint_16384(
	void
) {
	uint8_t bytes[] = { '\x80', '\x80', '\x01' };
	size_t amount_of_bytes = sizeof(bytes) / sizeof(bytes[0]);

	uint64_t value;
	int result = unsigned_varint_to_uint(&value, bytes, amount_of_bytes);

	assert(result == 3);
	assert(value == 16384);

	return;
}

int
main(
	int argc,
	char **argv
) {
	const test_function tests[] = {
		test_unsigned_varint_from_uint_0,
		test_unsigned_varint_from_uint_1,
		test_unsigned_varint_from_uint_127,
		test_unsigned_varint_from_uint_128,
		test_unsigned_varint_from_uint_255,
		test_unsigned_varint_from_uint_300,
		test_unsigned_varint_from_uint_16384,

		test_unsigned_varint_to_uint_0,
		test_unsigned_varint_to_uint_1,
		test_unsigned_varint_to_uint_127,
		test_unsigned_varint_to_uint_128,
		test_unsigned_varint_to_uint_255,
		test_unsigned_varint_to_uint_300,
		test_unsigned_varint_to_uint_16384,
	};

	for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
		tests[i]();

	exit(EXIT_SUCCESS);
}
