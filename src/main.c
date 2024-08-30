#include <stdio.h>
#include "../inc/byte_conversion_utils.h"


int main(int argc, char const *argv[])
{
    database_data database_data_character;
    database_data database_data_short;
    extended_database_data database_data_long;
    extended_database_data database_data_long_long;

    printf("======================================= \n");
    printf("Example Application for byte conversion \n");
    printf("======================================= \n");
    
    char  raw_char = -1;
    short raw_short = 12345;
    long  raw_long = 1234567890L;
    long long raw_long_long = 123456789012345LL;
    
    convert_from_char(raw_char, &database_data_character);
    printf("For char conversion 0x%hhx:\n", raw_char);
    print_bytes(&database_data_character);

    convert_from_short(raw_short, &database_data_short);
    printf("For short conversion 0x%hx:\n", raw_short);
    print_bytes(&database_data_short);

    convert_from_long(raw_long, &database_data_long);
    printf("For long conversion 0x%lx:\n", raw_long);
    print_bytes(&database_data_long.upper);
    print_bytes(&database_data_long.lower);

    convert_from_long_long(raw_long_long, &database_data_long_long);
    printf("For long long conversion 0x%lx:\n", raw_long_long);
    print_bytes(&database_data_long_long.upper);
    print_bytes(&database_data_long_long.lower);

    return 0;
}
