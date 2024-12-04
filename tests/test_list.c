#include <unity.h>
#include "../src/List_Library.c"

List list;

void setUp(void) {
    init_list(&list);
}

void tearDown(void) {
    for (int i = 0; i < list.size; i++) {
        free(list.items[i].data);
    }
    clear(&list);
}

void test_init_list(void) {
    TEST_ASSERT_EQUAL(0, list.size);
    TEST_ASSERT_NULL(list.items);
}

void test_append(void) {
    // Test integer
    int* num = malloc(sizeof(int));
    *num = 42;
    Element e1 = {num, INT};
    append(&list, e1);
    
    TEST_ASSERT_EQUAL(1, list.size);
    TEST_ASSERT_EQUAL(42, *(int*)list.items[0].data);
    TEST_ASSERT_EQUAL(INT, list.items[0].type);
}

void test_clear(void) {
    int* num = malloc(sizeof(int));
    *num = 42;
    Element e1 = {num, INT};
    append(&list, e1);
    
    clear(&list);
    TEST_ASSERT_EQUAL(0, list.size);
    TEST_ASSERT_NULL(list.items);
}

void test_copy(void) {
    int* num = malloc(sizeof(int));
    *num = 42;
    Element e1 = {num, INT};
    append(&list, e1);
    
    List new_list = copy(&list);
    TEST_ASSERT_EQUAL(list.size, new_list.size);
    TEST_ASSERT_EQUAL(*(int*)list.items[0].data, *(int*)new_list.items[0].data);
    
    // Clean up new list
    free(new_list.items);
}

void test_count(void) {
    int* num1 = malloc(sizeof(int));
    int* num2 = malloc(sizeof(int));
    *num1 = 42;
    *num2 = 42;
    Element e1 = {num1, INT};
    Element e2 = {num2, INT};
    
    append(&list, e1);
    append(&list, e2);
    
    TEST_ASSERT_EQUAL(2, count(&list, e1));
}

void test_find_index(void) {
    int* num = malloc(sizeof(int));
    *num = 42;
    Element e1 = {num, INT};
    append(&list, e1);
    
    TEST_ASSERT_EQUAL(0, find_index(&list, e1));
    
    int* num2 = malloc(sizeof(int));
    *num2 = 99;
    Element e2 = {num2, INT};
    TEST_ASSERT_EQUAL(-1, find_index(&list, e2));
    
    free(num2);
}

void test_insert(void) {
    int* num1 = malloc(sizeof(int));
    int* num2 = malloc(sizeof(int));
    *num1 = 42;
    *num2 = 99;
    
    Element e1 = {num1, INT};
    Element e2 = {num2, INT};
    
    append(&list, e1);
    insert(&list, 0, e2);
    
    TEST_ASSERT_EQUAL(2, list.size);
    TEST_ASSERT_EQUAL(99, *(int*)list.items[0].data);
    TEST_ASSERT_EQUAL(42, *(int*)list.items[1].data);
}

void test_pop(void) {
    int* num = malloc(sizeof(int));
    *num = 42;
    Element e1 = {num, INT};
    append(&list, e1);
    
    Element popped = pop(&list, 0);
    TEST_ASSERT_EQUAL(0, list.size);
    TEST_ASSERT_EQUAL(42, *(int*)popped.data);
    
    free(popped.data);
}

void test_reverse(void) {
    int* num1 = malloc(sizeof(int));
    int* num2 = malloc(sizeof(int));
    *num1 = 42;
    *num2 = 99;
    
    Element e1 = {num1, INT};
    Element e2 = {num2, INT};
    
    append(&list, e1);
    append(&list, e2);
    
    reverse(&list);
    TEST_ASSERT_EQUAL(99, *(int*)list.items[0].data);
    TEST_ASSERT_EQUAL(42, *(int*)list.items[1].data);
}

int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_init_list);
    RUN_TEST(test_append);
    RUN_TEST(test_clear);
    RUN_TEST(test_copy);
    RUN_TEST(test_count);
    RUN_TEST(test_find_index);
    RUN_TEST(test_insert);
    RUN_TEST(test_pop);
    RUN_TEST(test_reverse);
    
    return UNITY_END();
}