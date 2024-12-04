#include "unity.h"
#include "../include/String_Library.h"

void setUp(void) {
    // Set up any necessary test fixtures
}

void tearDown(void) {
    // Clean up after each test
}

void test_getStringLength(void) {
    TEST_ASSERT_EQUAL(5, getStringLength("Hello"));
    TEST_ASSERT_EQUAL(0, getStringLength(""));
    TEST_ASSERT_EQUAL(11, getStringLength("Hello World!"));
}

void test_capitalizeString(void) {
    char* result = capitalizeString("hello");
    TEST_ASSERT_EQUAL_STRING("Hello", result);
    free(result);

    result = capitalizeString("HELLO");
    TEST_ASSERT_EQUAL_STRING("HELLO", result);
    free(result);

    result = capitalizeString("");
    TEST_ASSERT_EQUAL_STRING("", result);
    free(result);
}

void test_caseConversions(void) {
    char* result = toLowerCase("HELLO");
    TEST_ASSERT_EQUAL_STRING("hello", result);
    free(result);

    result = toUpperCase("hello");
    TEST_ASSERT_EQUAL_STRING("HELLO", result);
    free(result);

    result = swapStringCase("Hello World");
    TEST_ASSERT_EQUAL_STRING("hELLO wORLD", result);
    free(result);
}

void test_stringChecks(void) {
    TEST_ASSERT_TRUE(isAlphanumeric("Hello123"));
    TEST_ASSERT_FALSE(isAlphanumeric("Hello!123"));
    
    TEST_ASSERT_TRUE(isAlphabetic("HelloWorld"));
    TEST_ASSERT_FALSE(isAlphabetic("Hello123"));
    
    TEST_ASSERT_TRUE(isDigitString("12345"));
    TEST_ASSERT_FALSE(isDigitString("123a5"));
    
    TEST_ASSERT_TRUE(isIdentifier("validName"));
    TEST_ASSERT_FALSE(isIdentifier("123invalid"));
}

void test_stringSearching(void) {
    TEST_ASSERT_TRUE(startsWith("Hello World", "Hello"));
    TEST_ASSERT_FALSE(startsWith("Hello World", "World"));
    
    TEST_ASSERT_TRUE(endsWith("Hello World", "World"));
    TEST_ASSERT_FALSE(endsWith("Hello World", "Hello"));
    
    TEST_ASSERT_EQUAL(2, countCharacter("Hello", 'l'));
    TEST_ASSERT_EQUAL(0, countCharacter("Hello", 'z'));
}

void test_substringOperations(void) {
    TEST_ASSERT_EQUAL(6, findSubstring("Hello World", "World"));
    TEST_ASSERT_EQUAL(-1, findSubstring("Hello World", "xyz"));
    
    char* result = replaceSubstring("Hello World", "World", "Earth");
    TEST_ASSERT_EQUAL_STRING("Hello Earth", result);
    free(result);
}

void test_stringStripping(void) {
    char* result = stripString("  Hello  ");
    TEST_ASSERT_EQUAL_STRING("Hello", result);
    free(result);

    result = lstripString("  Hello  ");
    TEST_ASSERT_EQUAL_STRING("Hello  ", result);
    free(result);

    result = rstripString("  Hello  ");
    TEST_ASSERT_EQUAL_STRING("  Hello", result);
    free(result);
}

void test_stringSplitting(void) {
    int count;
    char** result = splitString("Hello,World,Test", ",", &count);
    TEST_ASSERT_EQUAL(3, count);
    TEST_ASSERT_EQUAL_STRING("Hello", result[0]);
    TEST_ASSERT_EQUAL_STRING("World", result[1]);
    TEST_ASSERT_EQUAL_STRING("Test", result[2]);
    
    // Clean up
    for (int i = 0; i < count; i++) {
        free(result[i]);
    }
    free(result);
}

void test_stringJoining(void) {
    const char* strings[] = {"Hello", "World", "Test"};
    char* result = joinStrings(", ", (char**)strings, 3);
    TEST_ASSERT_EQUAL_STRING("Hello, World, Test", result);
    free(result);
}

void test_stringJustification(void) {
    char* result = centerString("Hello", 9, '*');
    TEST_ASSERT_EQUAL_STRING("**Hello**", result);
    free(result);

    result = leftJustifyString("Hello", 7, '*');
    TEST_ASSERT_EQUAL_STRING("Hello**", result);
    free(result);

    result = rightJustifyString("Hello", 7, '*');
    TEST_ASSERT_EQUAL_STRING("**Hello", result);
    free(result);
}

void test_stringTranslation(void) {
    char* table = maketrans("aeiou", "12345");
    char* result = translate("hello world", table);
    TEST_ASSERT_EQUAL_STRING("h2ll4 w4rld", result);
    free(result);
    free(table);
}

void test_stringFormatting(void) {
    char* result = title("hello world");
    TEST_ASSERT_EQUAL_STRING("Hello World", result);
    free(result);

    result = removeprefix("HelloWorld", "Hello");
    TEST_ASSERT_EQUAL_STRING("World", result);
    free(result);

    result = removesuffix("HelloWorld", "World");
    TEST_ASSERT_EQUAL_STRING("Hello", result);
    free(result);
}

int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_getStringLength);
    RUN_TEST(test_capitalizeString);
    RUN_TEST(test_caseConversions);
    RUN_TEST(test_stringChecks);
    RUN_TEST(test_stringSearching);
    RUN_TEST(test_substringOperations);
    RUN_TEST(test_stringStripping);
    RUN_TEST(test_stringSplitting);
    RUN_TEST(test_stringJoining);
    RUN_TEST(test_stringJustification);
    RUN_TEST(test_stringTranslation);
    RUN_TEST(test_stringFormatting);
    
    return UNITY_END();
}