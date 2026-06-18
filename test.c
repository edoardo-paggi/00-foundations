#include <limits.h>
#include <stdio.h>

int main(void) {

    printf("short min:          %d\n", SHRT_MIN);
    printf("short max:          %d\n", SHRT_MAX);
    printf("unsigned short max: %d\n", USHRT_MAX);
    printf("int min:            %d\n", INT_MIN);
    printf("int min:            %d\n", INT_MAX);
    printf("unsigned int max:   %u\n", UINT_MAX);
    printf("long min:           %ld\n", LONG_MIN);
    printf("long max:           %ld\n", LONG_MAX);
    printf("unsigned long max:  %lu\n", ULONG_MAX);
    printf("long long min:      %lld\n", LLONG_MIN);
    printf("long long max:      %lld\n", LLONG_MAX);
    printf("u long long min:    %llu\n", ULLONG_MAX);

    printf("\nDimensions in bits\n");
    printf("short int: %zu\n", sizeof(short int) * 8);
    printf("int: %zu\n", sizeof(int) * 8);
    printf("long int: %zu\n", sizeof(long int) * 8);
    printf("long long int: %zu\n", sizeof(long long int) * 8);
    printf("float: %zu\n", sizeof(float) * 8);
    printf("double: %zu\n", sizeof(double) * 8);
    printf("long double: %zu\n", sizeof(long double) * 8);
    printf("char: %zu\n", sizeof(char) * 8);

    printf("\n Escpae char 'A': \x41 \n");

    return 0;
}