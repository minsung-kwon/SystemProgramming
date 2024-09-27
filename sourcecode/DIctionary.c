#include "Dictionary.h"
#include <stdio.h>
#include <string.h>

#define INITIAL_CAPACITY 4

static void Insert(Dictionary* dict, const char* key, int value) {
    if (dict->Size >= dict->Capacity) {
        dict->Capacity *= 2;
        dict->Items = realloc(dict->Items, dict->Capacity * sizeof(KeyValue));
    }

    dict->Items[dict->Size].Key = strdup(key);
    dict->Items[dict->Size].Value = value;
    dict->Size++;
}

static void RemoveItem(Dictionary* dict, const char* key) {
    for (size_t i = 0; i < dict->Size; i++) {
        if (strcmp(dict->Items[i].Key, key) == 0) {
            free(dict->Items[i].Key);
            dict->Items[i] = dict->Items[dict->Size - 1];
            dict->Size--;
            return;
        }
    }
}

static int SearchByValue(Dictionary* dict, const char* key) {
    for (size_t i = 0; i < dict->Size; i++) {
        if (strcmp(dict->Items[i].Key, key) == 0) {
            return dict->Items[i].Value;
        }
    }
    return -1; // Not found
}

static void List(Dictionary* dict) {
    for (size_t i = 0; i < dict->Size; i++) {
        printf("이름: %s, 전화번호: %d\n", dict->Items[i].Key, dict->Items[i].Value);
    }
}

Dictionary* CreateDictionary() {
    Dictionary* dict = (Dictionary*)malloc(sizeof(Dictionary));
    dict->Items = (KeyValue*)malloc(INITIAL_CAPACITY * sizeof(KeyValue));
    dict->Size = 0;
    dict->Capacity = INITIAL_CAPACITY;

    // Assign function pointers
    dict->Insert = Insert;
    dict->Remove = RemoveItem;
    dict->Search = SearchByValue;
    dict->List = List;

    return dict;
}

void DestroyDictionary(Dictionary* dict) {
    for (size_t i = 0; i < dict->Size; i++) {
        free(dict->Items[i].Key);
    }
    free(dict->Items);
    free(dict);
}
