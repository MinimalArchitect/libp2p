#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int unsigned_varint_from_uint(uint8_t **bytes, size_t *amount_of_bytes, uint64_t value);
int unsigned_varint_to_uint(uint64_t *value, const uint8_t *bytes, size_t amount_of_bytes);
