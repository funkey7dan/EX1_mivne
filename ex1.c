// ***REMOVED*** Daniel Bronfman
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

/**
 * We receive two unsigned longs and return a new word, where the first half is comprised of the first half of Y,
 * and the second half is comprised of the second half of X.
 *
 * @param x - the first word
 * @param y - second word
 * @return a word consisting of the merged bytes of the words.
 */
unsigned long merge_bytes(unsigned long x, unsigned long int y) {
    unsigned long first_half, second_half;

    // turn the second half of the bits off using a bit mask.
    first_half = (0xFFFFFFFF00000000) & x;
    // turn the first half of the bits off using a bit mask.
    second_half = (0x00000000FFFFFFFF) & y;
    // we use the bitwise OR to preform addition of the words.
    return first_half | second_half;
}

/**
 *  Put the byte we receive from the function caller to the "word length minus i" position in the word we received.
 * We preform this by creating an empty word and iterating over x byte by byte,
 * in order to populate the empty word with the bytes of x.When we arrive at the location we will be inserting the byte,
 * We skip the bytes of x and instead we insert the bytes given to us via b.
 * @param x - the word we change the byte in
 * @param b - the byte we put in the word
 * @param i - the position we insert the byte in
 * @return
 */
unsigned long put_byte(unsigned long x, unsigned char b, int i) {

    int word_length = sizeof(x), j;
    unsigned long bit_mask = 0x00000000000000FF, new_x = 0x0000000000000000, moved_b = b;
    // iterate through the bytes
    for (j = 0; j < word_length; j++) {
        // check if it's the position we want to put the byte
        if ((word_length - i - 1) == j) {
            // use bitwise OR to add the bytes from b.
            new_x |= moved_b;
        } else {
            // use bitwise OR to add the bytes from x.
            new_x |= x & bit_mask;
        }
        bit_mask <<= 8;
        // we are given b as char, so we need to move the bytes that are on for them to be in the location of the mask.
        moved_b <<= 8;
    }
    return new_x;
}

