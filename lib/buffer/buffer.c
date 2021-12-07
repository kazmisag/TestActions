#include "buffer.h"

void buffer_insert(uint8_t *buffer, uint8_t start, uint8_t length, uint64_t value)
{
    uint8_t flag = 1;     // variable flag for shifting bits
    uint64_t position = 0; // variable to set the position of shifting bit

    for (uint8_t i = start; i < (start + length); i++)
    {
        if (value & (flag << position)) //Test if the input bit is 1 then set
        {
            buffer[i / 8] |= (flag << (i % 8)); // shift flag bit and OR with buffer to set buffer bit
        }
        else
        {
            buffer[i / 8] &= ~(flag << (i %8)); // set buffer bit to 0
        }
        position++; //increment the position
    }
}

uint64_t buffer_extract(uint8_t *buffer, uint8_t start, uint8_t length)
{
    uint64_t flag = 1;
    uint64_t position = 0;
    uint64_t extracted_value = 0;

    for(uint8_t i = start; i < (start+length); i++)
    {
        // Test if the buffer bit is 1
        if((buffer[i / 8]) & (1 << (i%8)))
        {
            extracted_value |= (flag << position); 
        }
        position++;
    }
    return extracted_value;
}
