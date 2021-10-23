#include <stdio.h>
#include "ex1.h"

int main() {

    printf("%d\n", is_big_endian());
    printf("0x%lx\n", merge_bytes(0x89ABCDEF12893456, 0x76543210ABCDEF19));
    printf("0x%lx\n", put_byte(0x12345678CDEF3456, 0xAB, 0));
	printf("0x%lx\n", put_byte(0x12345678CDEF3456, 0x0A, 2));
    printf("0x%lx\n", put_byte(0x12345678CDEF3456, 0xA0, 2));
	printf("0x%lx\n", put_byte(0x12345678CDEF3456, 0xFF, 134));
    printf("0x%lx\n", put_byte(0x0000000000000000, 0xFF, 3));
    printf("0x%lx\n", put_byte(0x12345678CDEF3456, 0x00, 2));
    return 0;
}


