#pragma once

struct multiaddr {
	char *string;

	uint8_t *bytes;
	size_t amount_of_bytes;
};

int multiaddr_from_string(struct multiaddr *address, const char *string);
int multiaddr_from_bytes(struct multiaddr *address, uint8_t *bytes, size_t amount_of_bytes);

int multiaddr_free(struct multiaddr *address);

int multiaddr_copy(struct multiaddr *destination, struct multiaddr *source);

int multiaddr_encapsulate(struct multiaddr *, const struct multiaddr *);
int multiaddr_decapsulate(struct multiaddr *, struct multiaddr *);

int multiaddr_compare(struct multiaddr *left, struct multiaddr *right);
