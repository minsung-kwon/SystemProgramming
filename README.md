### 시스템프로그래밍 1주차 과제


**환경 구축**
Microsoft의 공식 문서를 참고하여 wsl환경에서 vscode를 코드 편집기로 사용할 수 있는 환경을 구축했다.  
우분투의 사용을 편리하게 하기 위해 docker 컨테이너를 이용해 wsl을 관리하도록 하였다.  
우분투 버전의 경우 24.04.1 LTS를 사용했다.  
  
[wsl과 vscode연동 가이드](https://learn.microsoft.com/ko-kr/windows/wsl/tutorials/wsl-vscode)  
[wsl에서 docker container사용 가이드](https://learn.microsoft.com/ko-kr/windows/wsl/tutorials/wsl-containers)  

**프로그램 소스코드 작성**
삽입, 삭제, 검색, 리스트 기능의 구현을 위해 python의 dictionary와 유사한 기능을 가진 key-value 컨테이너를 구현하기로 했다.  
C++ STL unordered_map의 구조를 틀로 잡아 기능과 인터페이스를 설정하였고, 힙 메모리의 할당의 경우 C++ STL vector의 구조와 유사하게 진행하였다.  
C언어에는 C++과 달리 클래스 개념이 존재하지 않으므로, 함수 포인터를 이용하여 구조체 안의 포인터 멤버 변수와 함수를 연동하는 방식으로 클래스와 유사한 구조를 구현했다.  
소스 코드 파일을 두 개 이상 사용해야 하므로, .h확장자를 가진 헤더 파일과 .c확장자를 가진 소스 파일로 나누어 작업했다.  
헤더 파일이 구조체의 원형을, 소스 파일은 구체적 구현을 가지도록 작업했으며, 또 다른 .c 소스 파일에 드라이버 코드를 구성하여 테스트를 진행했다.  
  
소스 코드는 다음과 같으며, 이 markdown파일이 있는 branch에서 소스 파일을 확인할 수 있다.
- Phonebook.h
```c
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
    
    void (*Insert)(struct Dictionary*, const char*, int);
    void (*Remove)(struct Dictionary*, const char*);
    int (*Search)(struct Dictionary*, const char*);
    void (*List)(struct Dictionary*);
} Dictionary;

Dictionary* CreateDictionary();
void DestroyDictionary(Dictionary* dict);

#endif // DICTIONARY_H
```
- Phonebook.c
```c
#include "Phonebook.h"
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

static int Search(Dictionary* dict, const char* key) {
    for (size_t i = 0; i < dict->Size; i++) {
        if (strcmp(dict->Items[i].Key, key) == 0) {
            return dict->Items[i].Value;
        }
    }
    return -1;
}

static void List(Dictionary* dict) {
    for (size_t i = 0; i < dict->Size; i++) {
        printf("Name: %s, Phone Number: %d\n", dict->Items[i].Key, dict->Items[i].Value);
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
    dict->Search = Search;
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
```
- Driver.c
```c
#include <stdio.h>
#include "Phonebook.h"

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
```
