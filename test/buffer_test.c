#include "unity.h"
#include "buffer.h"

#define BUFFER_SIZE 3U
void setUp(void) {}

void tearDown(void) {}

void test_buffer(void)
{
    uint8_t buf[BUFFER_SIZE] = {0}; // intialize 8 bit-array buffer to 0

    // Insert data into the buffer and extract
    buffer_insert(buf, 12, 6, 24);
    TEST_ASSERT_EQUAL_INT64(24, buffer_extract(buf, 12, 6));

    buffer_insert(buf, 7, 16, 4);
    TEST_ASSERT_EQUAL_INT64(4, buffer_extract(buf, 7, 16));

    buffer_insert(buf, 7, 16, 17);
    TEST_ASSERT_EQUAL_INT64(17, buffer_extract(buf, 7, 16));

    buffer_insert(buf, 0, 23, 0);
    TEST_ASSERT_EQUAL_INT64(0, buffer_extract(buf, 0, 23));

    // Set buffer bits to 1
    for (uint8_t i = 0; i < BUFFER_SIZE; i++)
        buf[i] = 0xff;

    TEST_ASSERT_EQUAL_INT64(7, buffer_extract(buf, 12, 3)); // expect 111 = 7

    TEST_ASSERT_EQUAL_INT64(255, buffer_extract(buf, 0, 8)); // expect 1111 1111 = 255
}
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_buffer);
    return UNITY_END();
}
