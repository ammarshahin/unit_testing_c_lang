#include "../Unity/src/unity.h"
#include "../Unity/src/unity_internals.h"
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

void test_factorial_shouldReturnOne(void)
{
    TEST_ASSERT_EQUAL_UINT64(1, factorial(0));
    TEST_ASSERT_EQUAL_UINT64(1, factorial(1));
}

void test_factorial_shouldReturnTwo(void)
{
    TEST_ASSERT_EQUAL_UINT64(2, factorial(2));
}

void test_factorial_shouldReturnSix(void)
{
    TEST_ASSERT_EQUAL_UINT64(6, factorial(3));
}

void test_factorial_shouldReturn120(void)
{
    TEST_ASSERT_EQUAL_UINT64(120, factorial(5));
}