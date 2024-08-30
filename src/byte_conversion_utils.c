/**
 * \file
 *
 * \brief 24bits Integers implemenation
 * This library provides support for 3-byte integer conversions
 *  from various data types, such as:
 * -char (1 byte)
 * -short (2 bytes)
 * -long (4 bytes)
 * -long long (8 bytes)
 */

#include "../inc/byte_conversion_utils.h"
#include <stdio.h>
#include <stdint.h>

void convert_from_char(char raw_value, database_data *result) {
    if (result != NULL) {
        result->bytes[0] = (uint8_t)(raw_value & 0xFF); 
        result->bytes[1] = 0; 
        result->bytes[2] = 0;
    }
}

void convert_from_short(short raw_value, database_data *result) {
    if (result != NULL) {
        result->bytes[0] = (uint8_t)(raw_value & 0xFF);          
        result->bytes[1] = (uint8_t)((raw_value >> 8) & 0xFF);   
        result->bytes[2] = 0;
    }
}

void convert_from_long(long raw_value, extended_database_data *parts) {
    if (parts != NULL) {
        parts->lower.bytes[0] = (uint8_t)(raw_value & 0xFF);            
        parts->lower.bytes[1] = (uint8_t)((raw_value >> 8) & 0xFF);     
        parts->lower.bytes[2] = (uint8_t)((raw_value >> 16) & 0xFF);    

        parts->upper.bytes[0] = (uint8_t)((raw_value >> 24) & 0xFF);   
        parts->upper.bytes[1] = 0; 
        parts->upper.bytes[2] = 0;
    }
}

void convert_from_long_long(long long raw_value, extended_database_data *parts) {
    if (parts != NULL) {
        parts->lower.bytes[0] = (uint8_t)(raw_value & 0xFF);            
        parts->lower.bytes[1] = (uint8_t)((raw_value >> 8) & 0xFF);     
        parts->lower.bytes[2] = (uint8_t)((raw_value >> 16) & 0xFF);    

        parts->upper.bytes[0] = (uint8_t)((raw_value >> 24) & 0xFF);    
        parts->upper.bytes[1] = (uint8_t)((raw_value >> 32) & 0xFF);    
        parts->upper.bytes[2] = (uint8_t)((raw_value >> 40) & 0xFF);    
    }
}

void print_bytes(const database_data *parts) {
    printf("3 bytes conversion Hex format : 0x%02X%02X%02X\n", 
            parts->bytes[2], parts->bytes[1], parts->bytes[0]);
}