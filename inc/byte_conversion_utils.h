#ifndef BYTE_CONVERSION_UTILS_H
#define BYTE_CONVERSION_UTILS_H
#include <stdint.h>

typedef struct 
{
    uint8_t bytes[3];
}database_data;

typedef struct {
    database_data lower;
    database_data upper;
} extended_database_data;

void convert_from_char(char raw_value, database_data *result);

void convert_from_short(short raw_value, database_data *result);

void convert_from_long(long raw_value, extended_database_data *parts);

void convert_from_long_long(long long raw_value, extended_database_data *parts);

void print_bytes(const database_data *raw_value);
#endif