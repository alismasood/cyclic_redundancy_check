#define POLYNOMIAL 0xD8 /* 11011 followed by 0's */

uint8_t crc(uint8_t const message)
{
    uint8_t remainder;
    
    // Initially, the dividend is the remainder
    remainder = message;

    // For each bit position in the message...
    for(uint8_t bit = 8; bit > 0; bit--){
        // If the upper most bit is 1
        if (remainder & 0x80){
            // COR the previous remainder with the divisor
            remainder ^= POLYNOMIAL;    
        }
    }
    
    // Return only the relevant bits of the remainder as CRC
    return (remainder >> 4);
}
