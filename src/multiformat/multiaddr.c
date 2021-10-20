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
	return -1;
}

int multiaddr_copy(
	struct multiaddr *destination,
	struct multiaddr *source
) {
	return -1;
}

int
multiaddr_encapsulate(
	struct multiaddr *address,
	const struct multiaddr *payload
) {
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
	return -1;
}
