#include <cstdint>

#define POLYNOMIAL_8BIT 11011000b   //Note: Polynomial should be 9bits long, but this is 8bits

uint8_t simple_checksum(const char* message, uint16_t length){
    uint8_t checksum_value = 0;
    for(uint16_t i = 0; i < length; i++){
        checksum_value += message[i];
    }
    // Invert checksum. (Avoids issue of erroneously assigning
    // a valid checksum to a stream of 0's).
    checksum_value = ~checksum_value;

    return checksum_value;
} 

uint8_t crc_8bit(const char* message, uint16_t length){
    if(length < 1){
        return 0;
    }
    uint16_t remainder = 0;
    remainder += message[byte_index++];

    //For every byte
    for(uint16_t i = 0; i < length; i++){
        // Check if most significant bit is 1
        while(remainder & 0x80){
            remainder << 1;
            remainder += get_bit_at_position(
        }
        if(remainder & 0x80){
            remainder ^= POLYNOMIAL_8BIT;
        }
    }
}


/*
#define POLYNOMIAL 0xD8 // 11011 followed by 0's 

typedef uint8_t crc;

#define WIDTH (8 * sizeof(crc))
#define TOPBIT (1 << (WIDTH - 1))


crc crc_8bit(uint8_t const message, int nBytes)
{
    crc remainder;
    
    // Initially, the dividend is the remainder
    remainder = message;
    for (int byte = 0; byte < Byes; ++byte){
        // Bring the next byte into the remainder
        remainder ^= (message[byte] << (WIDTH - 8));

        // For each bit position in the message ...
        for(uint8_t bit = 8; bit > 0; bit--){

            // If the upper most bit is 1 (Try to divide the current data bit).
            if (remainder & TOPBIT){
            {
                // XOR the previous remainder with the divisor
                remainder ^=  (remainder << 1) ^ POLYNOMIAL;   
            }

            // Shift the next bit of the message into the remainder
            remainder = (remainder << 1);
        }
    }
    // Return only the relevant bits of the remainder as CRC
    return (remainder >> 4);
}
*/
