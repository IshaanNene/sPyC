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

void init_list(List* list) {
    list->size = 0;
    list->items = NULL;
}

void append(List* list, Element element) {
    list->items = (Element*)realloc(list->items, (list->size + 1) * sizeof(Element));
    list->items[list->size++] = element;
}

void clear(List* list) {
    free(list->items);
    init_list(list);
}

List copy(List* list) {
    List new_list;
    init_list(&new_list);
    for (int i = 0; i < list->size; i++) {
        append(&new_list, list->items[i]);
    }
    return new_list;
}

int count(List* list, Element element) {
    int count = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->items[i].data == element.data && list->items[i].type == element.type) {
            count++;
        }
    }
    return count;
}

void extend(List* list, List* other) {
    for (int i = 0; i < other->size; i++) {
        append(list, other->items[i]);
    }
}

int find_index(List* list, Element element) {
    for (int i = 0; i < list->size; i++) {
        if (list->items[i].data == element.data && list->items[i].type == element.type) {
            return i;
        }
    }
    return -1;
}

void insert(List* list, int position, Element element) {
    if (position < 0 || position > list->size) {
        return;
    }
    list->items = (Element*)realloc(list->items, (list->size + 1) * sizeof(Element));
    for (int i = list->size; i > position; i--) {
        list->items[i] = list->items[i - 1];
    }
    list->items[position] = element;
    list->size++;
}

Element pop(List* list, int position) {
    if (position < 0 || position >= list->size) {
        Element empty = {NULL, INT};
        return empty;
    }
    Element element = list->items[position];
    for (int i = position; i < list->size - 1; i++) {
        list->items[i] = list->items[i + 1];
    }
    list->size--;
    list->items = (Element*)realloc(list->items, list->size * sizeof(Element));
    return element;
}

void remove_element(List* list, Element element) {
    int pos = find_index(list, element);
    if (pos != -1) {
        pop(list, pos);
    }
}

void reverse(List* list) {
    for (int i = 0; i < list->size / 2; i++) {
        Element temp = list->items[i];
        list->items[i] = list->items[list->size - i - 1];
        list->items[list->size - i - 1] = temp;
    }
}

int compare_elements(const void* a, const void* b) {
    Element* elemA = (Element*)a;
    Element* elemB = (Element*)b;
    if (elemA->type != elemB->type) {
        return elemA->type - elemB->type;
    }
    switch (elemA->type) {
        case INT:
            return (*(int*)elemA->data) - (*(int*)elemB->data);
        case FLOAT:
            return (*(float*)elemA->data) > (*(float*)elemB->data) ? 1 : -1;
        case CHAR:
            return (*(char*)elemA->data) - (*(char*)elemB->data);
        case STRING:
            return strcmp((char*)elemA->data, (char*)elemB->data);
    }
    return 0;
}

void sort(List* list) {
    qsort(list->items, list->size, sizeof(Element), compare_elements);
}

void display_list(List* list) {
    printf("[");
    for (int i = 0; i < list->size; i++) {
        switch (list->items[i].type) {
            case INT:
                printf("%d", *(int*)list->items[i].data);
                break;
            case FLOAT:
                printf("%f", *(float*)list->items[i].data);
                break;
            case CHAR:
                printf("'%c'", *(char*)list->items[i].data);
                break;
            case STRING:
                printf("\"%s\"", (char*)list->items[i].data);
                break;
        }
        if (i < list->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void slice(List* list, int start, int end, List* result) {
    init_list(result);
    if (start < 0) start = 0;
    if (end > list->size) end = list->size;
    for (int i = start; i < end; i++) {
        append(result, list->items[i]);
    }
}

void remove_duplicates(List* list) {
    List temp;
    init_list(&temp);
    for (int i = 0; i < list->size; i++) {
        if (find_index(&temp, list->items[i]) == -1) {
            append(&temp, list->items[i]);
        }
    }
    clear(list);
    extend(list, &temp);
    clear(&temp);
}

int find(List* list, Element element) {
    return find_index(list, element);
}

int main() {
    List list;
    init_list(&list);

    char input[100];
    printf("Enter a value: ");
    scanf("%s", input);

    Element element;
    if (strspn(input, "0123456789") == strlen(input)) {
        int* data = (int*)malloc(sizeof(int));
        *data = atoi(input);
        element.data = data;
        element.type = INT;
    } else if (strspn(input, "0123456789.") == strlen(input)) {
        float* data = (float*)malloc(sizeof(float));
        *data = atof(input);
        element.data = data;
        element.type = FLOAT;
    } else if (strlen(input) == 1) {
        char* data = (char*)malloc(sizeof(char));
        *data = input[0];
        element.data = data;
        element.type = CHAR;
    } else {
        char* data = strdup(input);
        element.data = data;
        element.type = STRING;
    }

    append(&list, element);
    display_list(&list);

    // Clean up
    for (int i = 0; i < list.size; i++) {
        free(list.items[i].data);
    }
    clear(&list);

    return 0;
}