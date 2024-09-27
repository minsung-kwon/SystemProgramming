#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdlib.h>

typedef struct KeyValue {
    char* Key;
    int Value;
} KeyValue;

typedef struct Dictionary {
    KeyValue* Items;
    size_t Size;
    size_t Capacity;
    
    // Function pointers for dictionary operations
    void (*Insert)(struct Dictionary*, const char*, int);
    void (*Remove)(struct Dictionary*, const char*);
    int (*Search)(struct Dictionary*, const char*);
    void (*List)(struct Dictionary*);
} Dictionary;

// Function declarations
Dictionary* CreateDictionary();
void DestroyDictionary(Dictionary* dict);

#endif // DICTIONARY_H
