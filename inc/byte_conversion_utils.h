#ifndef BYTE_CONVERSION_UTILS_H
#define BYTE_CONVERSION_UTILS_H
#include <stdint.h>

/**
 * Struct representing a 3-byte integer.
 * 
 * This structure is used to store a 3-byte integer value in an array of three 
 * unsigned 8-bit integers (`uint8_t`). 
 * 
 * Members:
 * - `bytes`: An array of three `uint8_t` values representing the 3-byte integer.
 */
typedef struct 
{
    uint8_t bytes[3];
}database_data;

/**
 * Struct representing a 6-byte extended integer split into two 3-byte parts.
 * 
 * Members:
 * - `lower`: A `database_data` structure that holds the lower 3 bytes of the extended data (Least signifact bytes).
 * - `upper`: A `database_data` structure that holds the upper 3 bytes of the extended data (Most signifact bytes)
 */
typedef struct {
    database_data lower;
    database_data upper;
} extended_database_data;

/**
 * Converts a `char` value to a 3-byte representation.
 * This function extracts the lower byte of the `char` value and stores it in the 
 * first byte of the `result` structure. The remaining two bytes of the `result` 
 * structure are set to zero.
 * 
 * @param raw_value       The `char` value to be converted.
 * @param result          A pointer to a `database_data` structure where the 
 *                        converted 3-byte representation will be stored. * 
 */
void convert_from_char(char raw_value, database_data *result);

/**
 * Converts a `short` value to a 3-byte representation.
 * This function extracts the lower byte and the upper byte of the `short` value and 
 * stores them in the first and second bytes of the `result` structure, respectively. 
 * The third byte of the `result` structure is set to zero.
 * 
 * @param raw_value       The `short` value to be converted.
 * @param result          A pointer to a `database_data` structure where the 
 *                        converted 3-byte representation will be stored.
 * 
 */
void convert_from_short(short raw_value, database_data *result);

/**
 * Converts a `long` value to a 6-byte representation split into two 3-byte parts.
 * This function stores the lower 3 bytes of the `long` value in the `lower` member of 
 * the `parts` structure, and the upper byte (24-31 bits) of the `long` value in the 
 * `upper` member of the `parts` structure, with the remaining bytes set to zero.
 * 
 * @param raw_value       The `long` value to be converted.
 * @param parts           A pointer to an `extended_database_data` structure where 
 *                        the converted 6-byte representation will be stored in two 
 *                        3-byte parts (`lower` and `upper`).
 * 
 * @note If `parts` is `NULL`, the function does nothing.
 */
void convert_from_long(long raw_value, extended_database_data *parts);

/**
 * Converts a `long long` value  into two 3-byte parts.
 * This function stores the lower 3 bytes of the `long long` value in the `lower` member 
 * of the `parts` structure, and the upper 3 bytes (24-63 bits) of the `long long` 
 * value in the `upper` member of the `parts` structure.
 * 
 * @param raw_value       The `long long` value to be converted.
 * @param parts           A pointer to an `extended_database_data` structure where 
 *                        the converted 6-byte representation will be stored in two 
 *                        3-byte parts (`lower` and `upper`).
 * 
 * @note If `parts` is `NULL`, the function does nothing.
 */
void convert_from_long_long(long long raw_value, extended_database_data *parts);

/**
 * Prints the 3-byte representation stored in the `result` structure in hexadecimal format.
 * This function prints the bytes in reverse order (from highest to lowest) as a 
 * hexadecimal value.
 * 
 * @param parts           A pointer to a `database_data` structure containing the 
 *                        3-byte representation to be printed. * 
 */
void print_bytes(const database_data *parts);
#endif