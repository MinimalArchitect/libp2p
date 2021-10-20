#include <multiformat/unsigned-varint.h>

int
unsigned_varint_from_uint(
	uint8_t **bytes,
	size_t *amount_of_bytes,
	uint64_t value
) {
	// NOTE(lukas): size limit of 2^63 - 1 for max 9 bytes
	if (!(value < ((uint64_t)1<< 63)))
		return -1;

	const int size = 9;
	uint8_t buffer[9] = { 0 };

	int i;
	for (i = 0; i < size - 1; i++) {
		buffer[i] = 0x7f & value;
		value >>= 7;
		buffer[i] |= (value != 0) ? 0x80 : 0x00;
	}
	buffer[size - 1] = 0x7f & value;

	int real_size = 1;

	for (i = 1; i < size; i++) {
		if (buffer[i] != 0)
			real_size++;
	}

	*amount_of_bytes = real_size;
	*bytes = realloc(*bytes, *amount_of_bytes * sizeof(uint8_t));
	if (*bytes == NULL)
		return -1;

	memcpy(*bytes, buffer, *amount_of_bytes);

	return 0;
}

int
unsigned_varint_to_uint(
	uint64_t *value,
	const uint8_t *bytes,
	size_t amount_of_bytes
) {
	int size;

	for (size = 0; (bytes[size] & 0x80) != 0 && size < amount_of_bytes; size++);
	size++;

	// NOTE(lukas): more than ten bytes do not fit in the largest integer
	if (!(size < 10))
		return -1;

	*value = 0;
	for (int i = 0; i < size; i++)
		*value |= (uint64_t)(0x7f & bytes[i]) << 7 * i;

	return size;
}
