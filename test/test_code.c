#include "../../Unity-master/src/unity.h"
#include "../../Unity-master/src/unity_internals.h"
#include "../src/code.h"

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
    TEST_ASSERT_EQUAL_UINT64(0, mult(-5, 0));
}

void test_mult_shouldReturnTen(void)
{
    TEST_ASSERT_EQUAL_UINT64(10, mult(5, 2));
    TEST_ASSERT_EQUAL_UINT64(10, mult(1, 10));
    TEST_ASSERT_EQUAL_UINT64(10, mult(2, 5));
}

void test_divide_shouldReturnZero(void)
{
    TEST_ASSERT_EQUAL_UINT64(0, divide(0, 2));
    TEST_ASSERT_EQUAL_UINT64(0, divide(5, 0));
    TEST_ASSERT_EQUAL_UINT64(0, divide(0, 0));
}