#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    void* value;
} DictItem;

typedef struct {
    DictItem* items;
    int size;
    int capacity;
} Dictionary;

void init_dictionary(Dictionary* dict) {
    dict->size = 0;
    dict->capacity = 10;
    dict->items = (DictItem*)malloc(dict->capacity * sizeof(DictItem));
}

void add(Dictionary* dict, const char* key, void* value) {
    if (dict->size == dict->capacity) {
        dict->capacity *= 2;
        dict->items = (DictItem*)realloc(dict->items, dict->capacity * sizeof(DictItem));
    }
    dict->items[dict->size].key = strdup(key);
    dict->items[dict->size].value = value;
    dict->size++;
}

void* get(Dictionary* dict, const char* key) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->items[i].key, key) == 0) {
            return dict->items[i].value;
        }
    }
    return NULL;
}

void remove_key(Dictionary* dict, const char* key) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->items[i].key, key) == 0) {
            free(dict->items[i].key);
            for (int j = i; j < dict->size - 1; j++) {
                dict->items[j] = dict->items[j + 1];
            }
            dict->size--;
            return;
        }
    }
}

void clear(Dictionary* dict) {
    for (int i = 0; i < dict->size; i++) {
        free(dict->items[i].key);
    }
    free(dict->items);
    dict->size = 0;
    dict->capacity = 10;
    dict->items = (DictItem*)malloc(dict->capacity * sizeof(DictItem));
}

Dictionary copy(Dictionary* dict) {
    Dictionary new_dict;
    init_dictionary(&new_dict);
    for (int i = 0; i < dict->size; i++) {
        add(&new_dict, dict->items[i].key, dict->items[i].value);
    }
    return new_dict;
}

Dictionary fromkeys(char** keys, int num_keys, void* value) {
    Dictionary new_dict;
    init_dictionary(&new_dict);
    for (int i = 0; i < num_keys; i++) {
        add(&new_dict, keys[i], value);
    }
    return new_dict;
}

DictItem* items(Dictionary* dict) {
    return dict->items;
}

char** keys(Dictionary* dict) {
    char** keys_list = (char**)malloc(dict->size * sizeof(char*));
    for (int i = 0; i < dict->size; i++) {
        keys_list[i] = dict->items[i].key;
    }
    return keys_list;
}

void* pop(Dictionary* dict, const char* key) {
    void* value = NULL;
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->items[i].key, key) == 0) {
            value = dict->items[i].value;
            free(dict->items[i].key);
            for (int j = i; j < dict->size - 1; j++) {
                dict->items[j] = dict->items[j + 1];
            }
            dict->size--;
            break;
        }
    }
    return value;
}

DictItem popitem(Dictionary* dict) {
    if (dict->size == 0) {
        DictItem empty_item = {NULL, NULL};
        return empty_item;
    }
    DictItem last_item = dict->items[dict->size - 1];
    dict->size--;
    return last_item;
}

void* setdefault(Dictionary* dict, const char* key, void* default_value) {
    void* value = get(dict, key);
    if (value == NULL) {
        add(dict, key, default_value);
        return default_value;
    }
    return value;
}

void update(Dictionary* dict, Dictionary* other) {
    for (int i = 0; i < other->size; i++) {
        add(dict, other->items[i].key, other->items[i].value);
    }
}

void** values(Dictionary* dict) {
    void** values_list = (void**)malloc(dict->size * sizeof(void*));
    for (int i = 0; i < dict->size; i++) {
        values_list[i] = dict->items[i].value;
    }
    return values_list;
}

int main() {
    Dictionary dict;
    init_dictionary(&dict);

    int value1 = 42;
    add(&dict, "key1", &value1);

    int* retrieved_value = (int*)get(&dict, "key1");
    if (retrieved_value) {
        printf("Retrieved value: %d\n", *retrieved_value);
    }

    remove_key(&dict, "key1");
    clear(&dict);

    return 0;
}