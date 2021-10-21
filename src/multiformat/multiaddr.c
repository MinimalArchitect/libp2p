#include <multiformat/multiaddr.h>

int
multiaddr_from_string(
	struct multiaddr *address,
	const char *string
) {
	return -1;
}

int
multiaddr_from_bytes(
	struct multiaddr *address,
	uint8_t *bytes,
	size_t amount_of_bytes
) {
	return -1;
}

int
multiaddr_free(
	struct multiaddr *address
) {

	free(address->string);
	address->string = NULL;

	free(address->bytes);
	address->bytes = NULL;
	address->amount_of_bytes = 0;

	return -1;
}

void *
memdup(
	void *data,
	size_t size
) {
	void *return_data = malloc(size);

	if (return_data != NULL)
		memcpy(return_data, data, size);

	return return_data;
}

int multiaddr_copy(
	struct multiaddr *destination,
	struct multiaddr *source
) {
	destination->string = strdup(source->string);

	destination->bytes = memdup(source->bytes, source->amount_of_bytes * sizeof(uint8_t));
	destination->amount_of_bytes = source->amount_of_bytes;

	return -1;
}

int
multiaddr_encapsulate(
	struct multiaddr *address,
	const struct multiaddr *payload
) {
	size_t string_length = strlen(address->string) + strlen(payload->string);
	address->string = realloc(address->string, (string_length + 1) * sizeof(char));

	strcat(address->string, payload->string);

	size_t tmp = address->amount_of_bytes + payload->amount_of_bytes;
	address->string = realloc(address->string, tmp * sizeof(char));

	memcpy(address->bytes + address->amount_of_bytes, payload->bytes, payload->amount_of_bytes);
	address->amount_of_bytes = tmp;

	return -1;
}

int
multiaddr_decapsulate(
	struct multiaddr *address,
	struct multiaddr *payload
) {
	return -1;
}

int
multiaddr_compare(
	struct multiaddr *left,
	struct multiaddr *right
) {
	if (left == NULL && right == NULL)
		return 0;

	if (left == NULL && right != NULL)
		return -1;

	if (left != NULL && right == NULL)
		return 1;

	// NOTE(lukas): this could over or underflow
	int total = right->amount_of_bytes - left->amount_of_bytes;
	if (total != 0)
		return total;

	return memcmp(left->bytes, right->bytes, right->amount_of_bytes);
}
