#include <stdio.h>
#include <endian.h>
#include "ex1.h"

/**
 *
 * @return Whether the passed int is in the big endian representation
 */
int is_big_endian() {
    short val = 0x0001; // set value to 1
    char singleByte = *(char *) &val; // set to the first byte of val (char is 1 byte in size)
    // if the first byte is 1, the first in the memory is the LSB, and we are in little endian
    if (singleByte == 1) {
        return 0;
        // otherwise the first byte is zero's, and it means we are in big endian
    } else {
        return 1;
    }
}

unsigned long merge_bytes(unsigned long x, unsigned long int y) {
    return 0;
}

unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    return 0;
}

int isLittleEndian()
{
    short int number = 0x1;
    char *numPtr = (char*)&number;
    return (numPtr[0] == 1);
}
