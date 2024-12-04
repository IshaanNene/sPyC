#ifndef LIST_LIBRARY_H
#define LIST_LIBRARY_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    INT,
    FLOAT,
    CHAR,
    STRING
} DataType;

typedef struct {
    void* data;    
    DataType type; 
} Element;

typedef struct {
    Element* items; 
    int size; 
} List;

void init_list(List* list);
void append(List* list, Element element);
void clear(List* list);
List copy(List* list);
int count(List* list, Element element);
void extend(List* list, List* other);
int find_index(List* list, Element element);
void insert(List* list, int position, Element element);
Element pop(List* list, int position);
void remove_element(List* list, Element element);
void reverse(List* list);
int compare_elements(const void* a, const void* b);
void sort(List* list);
void display_list(List* list);
void slice(List* list, int start, int end, List* result);
void remove_duplicates(List* list);
int find(List* list, Element element);

#endif