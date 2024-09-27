#include <stdio.h>
#include "Dictionary.h"

int main() {
    Dictionary* dict = CreateDictionary();
    
    dict->Insert(dict, "Alice", 30);
    dict->Insert(dict, "Bob", 25);
    dict->Insert(dict, "Charlie", 35);
    
    printf("List of dictionary items:\n");
    dict->List(dict);
    
    printf("Searching for Bob: %d\n", dict->Search(dict, "Bob"));
    
    dict->Remove(dict, "Alice");
    
    printf("List after removing Alice:\n");
    dict->List(dict);
    
    DestroyDictionary(dict);
    return 0;
}
