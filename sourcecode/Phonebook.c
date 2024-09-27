#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Dictionary.h"

int main()
{
    Dictionary* dict = CreateDictionary();

    while(1)
    {
        int Command=0;
        while(1)
        {
            printf("명령을 입력하세요\n1. 전화번호 추가\n2. 전화번호 삭제\n3. 전화번호 검색\n4. 전화번호 나열\n5.프로그램 종료\n");
            scanf("%d", &Command);
            if(Command==1 || Command==2 || Command==3 || Command==4 || Command==5)
            {
                break;
            }
            else
            {
                system("cls");
                printf("명령을 다시 입력해주세요\n");
            }
        }

        system("cls");

        switch(Command)
        {
            case(1):
            {
                char* Name; int PhoneNumber;
                printf("전화번호를 입력하세요: ");
                scanf("%d", &PhoneNumber);
                printf("\n해당 전화번호를 가진 사람의 이름을 입력하세요: ");
                getch(Name);
                system("cls");
                printf("전화번호부에 이름이 %s이고 전화번호가 %d인 인물이 추가되었습니다.\n", Name, PhoneNumber);
                dict->Insert(dict, Name, PhoneNumber);
            }
            case(2):
            {
                char* Name;
                printf("전화번호부에서 삭제할 사람의 이름을 입력하세요: ");
                getch(Name);
                system("cls");
                printf("전화번호부에서 이름이 %s이고 전화번호가 %d인 인물이 삭제되었습니다.\n", Name, dict->Search(dict, Name));
                dict->Remove(dict, Name);
            }
            case(3):
            {
                char* Name;
                printf("전화번호를 검색할 사람의 이름을 입력하세요: ");
                getch(Name);
                system("cls");
                printf("이름이 %s인 사람의 전화번호는 %d입니다.", Name, dict->Search(dict, Name));
            }
            case(4):
            {
                printf("현재 저장된 전화번호는 다음과 같습니다.\n");
                dict->List(dict);
            }
            case(5):
            {
                break;
            }
        }
    }

    DestroyDictionary(dict);
    return 0;
}
