#include "../../Unity-master/src/unity.h"
#include "../../Unity-master/src/unity_internals.h"
#include "../src/code1.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_mult_shouldReturnZero(void)
{
    TEST_ASSERT_EQUAL_UINT64(0, mult(5, 0));
    TEST_ASSERT_EQUAL_UINT64(0, mult(0, 1540));
    TEST_ASSERT_NOT_EQUAL_UINT64(0, mult(-5, 1540));
}