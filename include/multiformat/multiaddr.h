#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct multiaddr {
	char *string;

	uint8_t *bytes;
	size_t amount_of_bytes;
};

int multiaddr_from_string(struct multiaddr *address, const char *string);
int multiaddr_from_bytes(struct multiaddr *address, uint8_t *bytes, size_t amount_of_bytes);

int multiaddr_free(struct multiaddr *address);

int multiaddr_copy(struct multiaddr *destination, struct multiaddr *source);

int multiaddr_encapsulate(struct multiaddr *address, const struct multiaddr *payload);
int multiaddr_decapsulate(struct multiaddr *address, struct multiaddr *payload);

int multiaddr_compare(struct multiaddr *left, struct multiaddr *right);
