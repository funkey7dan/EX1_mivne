#include <stdio.h>
#include <endian.h>
#include "ex1.h"

/**
 * In order to check the Endianness of the system, we will first create a 2 byte word, with the value 1.
 * We then will set a 1 byte char to be the value of the "first" part of val.
 * Because val is a short and 2 bytes long, singleByte will be equal to the first byte.
 * We know that in Big endian the MSB is first, and in our case it's 0. In little endian the LSB is the first,
 * and in our case it will be ...10 so we check the value of singleByte, to check what part of val we got.
 * @return 1 if the file was compiled on a Big endian system, 0 otherwise.
 */
int is_big_endian() {
    short val = 0x0001; // set value to 1
    char singleByte = *((char *) &val); // set to the first byte of val (char is 1 byte in size)
    // if the first byte is 1, the first in the memory is the LSB, and we are in little endian
    if (singleByte == 1) {
        return 0;
        // otherwise the first byte is zero's, and it means we are in big endian
    } else {
        return 1;
    }
}

unsigned long merge_bytes(unsigned long x, unsigned long int y) {
    unsigned long first_half, second_half;

    // turn the first half of the bits off
    first_half = (0xFFFFFFFF00000000) & x;
    // turn the second half of the bits off
    second_half = (0x00000000FFFFFFFF) & y;

    return first_half | second_half;
}

/**
 *
 * @param x
 * @param b
 * @param i
 * @return
 */
unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    int word_length = sizeof(unsigned long);
    unsigned long bit_mask = 0x00000000000000FF, empty_word = 0x0000000000000000, moved_b = b;
    for (int j = 0; j < word_length; j++) {
        if (j == (word_length - i - 1)) {
            empty_word |= moved_b;
        } else {
            empty_word |= x & bit_mask;
        }

        bit_mask <<= 8;
        moved_b <<= 8;
    }
    return empty_word;
}

