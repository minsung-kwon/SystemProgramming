### MySort.h
```c
// MySort.h
#ifndef MYSORT_H
#define MYSORT_H

void Sort(int *arr, int size);

#endif // MYSORT_H
```
### MySort.c
```c
#include "MySort.h"

void Sort(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(arr[i]<=arr[j])
            {
                continue;
            }
            
            int temp;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
}
```
### main.c
```c
// main.c
#include <stdio.h>
#include <stdlib.h>
#include "MySort.h"

int main()
{
    int* arr;
    int size;
    printf("enter size of array : ");
    scanf("%d",&size);
    arr=(int*)malloc(sizeof(int)*size);
    printf("\nenter values of array : ");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    Sort(arr,size);
    printf("sorted array : ");
    for(int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}
```

### 어셈블리 코드
```
minsungkwon1202@DESKTOP-F1ELN05:~/src/sort$ objdump -d -S main.o

main.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <main>:
#include <stdio.h>
#include <stdlib.h>
#include "MySort.h"

int main()
{
   0:   f3 0f 1e fa             endbr64
   4:   55                      push   %rbp
   5:   48 89 e5                mov    %rsp,%rbp
   8:   48 83 ec 20             sub    $0x20,%rsp
   c:   64 48 8b 04 25 28 00    mov    %fs:0x28,%rax
  13:   00 00
  15:   48 89 45 f8             mov    %rax,-0x8(%rbp)
  19:   31 c0                   xor    %eax,%eax
    int* arr;
    int size;
    printf("enter size of array : ");
  1b:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # 22 <main+0x22>
  22:   48 89 c7                mov    %rax,%rdi
  25:   b8 00 00 00 00          mov    $0x0,%eax
  2a:   e8 00 00 00 00          call   2f <main+0x2f>
    scanf("%d",&size);
  2f:   48 8d 45 e4             lea    -0x1c(%rbp),%rax
  33:   48 89 c6                mov    %rax,%rsi
  36:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # 3d <main+0x3d>
  3d:   48 89 c7                mov    %rax,%rdi
  40:   b8 00 00 00 00          mov    $0x0,%eax
  45:   e8 00 00 00 00          call   4a <main+0x4a>
    arr=(int*)malloc(sizeof(int)*size);
  4a:   8b 45 e4                mov    -0x1c(%rbp),%eax
  4d:   48 98                   cltq
  4f:   48 c1 e0 02             shl    $0x2,%rax
  53:   48 89 c7                mov    %rax,%rdi
  56:   e8 00 00 00 00          call   5b <main+0x5b>
  5b:   48 89 45 f0             mov    %rax,-0x10(%rbp)
    printf("\nenter values of array : ");
  5f:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # 66 <main+0x66>
  66:   48 89 c7                mov    %rax,%rdi
  69:   b8 00 00 00 00          mov    $0x0,%eax
  6e:   e8 00 00 00 00          call   73 <main+0x73>
    for(int i=0; i<size; i++)
  73:   c7 45 e8 00 00 00 00    movl   $0x0,-0x18(%rbp)
  7a:   eb 2f                   jmp    ab <main+0xab>
    {
        scanf("%d", &arr[i]);
  7c:   8b 45 e8                mov    -0x18(%rbp),%eax
  7f:   48 98                   cltq
  81:   48 8d 14 85 00 00 00    lea    0x0(,%rax,4),%rdx
  88:   00
  89:   48 8b 45 f0             mov    -0x10(%rbp),%rax
  8d:   48 01 d0                add    %rdx,%rax
  90:   48 89 c6                mov    %rax,%rsi
  93:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # 9a <main+0x9a>
  9a:   48 89 c7                mov    %rax,%rdi
  9d:   b8 00 00 00 00          mov    $0x0,%eax
  a2:   e8 00 00 00 00          call   a7 <main+0xa7>
    for(int i=0; i<size; i++)
  a7:   83 45 e8 01             addl   $0x1,-0x18(%rbp)
  ab:   8b 45 e4                mov    -0x1c(%rbp),%eax
  ae:   39 45 e8                cmp    %eax,-0x18(%rbp)
  b1:   7c c9                   jl     7c <main+0x7c>
    }
    Sort(arr,size);
  b3:   8b 55 e4                mov    -0x1c(%rbp),%edx
  b6:   48 8b 45 f0             mov    -0x10(%rbp),%rax
  ba:   89 d6                   mov    %edx,%esi
  bc:   48 89 c7                mov    %rax,%rdi
  bf:   e8 00 00 00 00          call   c4 <main+0xc4>
    printf("sorted array : ");
  c4:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # cb <main+0xcb>
  cb:   48 89 c7                mov    %rax,%rdi
  ce:   b8 00 00 00 00          mov    $0x0,%eax
  d3:   e8 00 00 00 00          call   d8 <main+0xd8>
    for(int i=0; i<size; i++)
  d8:   c7 45 ec 00 00 00 00    movl   $0x0,-0x14(%rbp)
  df:   eb 30                   jmp    111 <main+0x111>
    {
        printf("%d ",arr[i]);
  e1:   8b 45 ec                mov    -0x14(%rbp),%eax
  e4:   48 98                   cltq
  e6:   48 8d 14 85 00 00 00    lea    0x0(,%rax,4),%rdx
  ed:   00
  ee:   48 8b 45 f0             mov    -0x10(%rbp),%rax
  f2:   48 01 d0                add    %rdx,%rax
  f5:   8b 00                   mov    (%rax),%eax
  f7:   89 c6                   mov    %eax,%esi
  f9:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # 100 <main+0x100>
 100:   48 89 c7                mov    %rax,%rdi
 103:   b8 00 00 00 00          mov    $0x0,%eax
 108:   e8 00 00 00 00          call   10d <main+0x10d>
    for(int i=0; i<size; i++)
 10d:   83 45 ec 01             addl   $0x1,-0x14(%rbp)
 111:   8b 45 e4                mov    -0x1c(%rbp),%eax
 114:   39 45 ec                cmp    %eax,-0x14(%rbp)
 117:   7c c8                   jl     e1 <main+0xe1>
    }
    free(arr);
 119:   48 8b 45 f0             mov    -0x10(%rbp),%rax
 11d:   48 89 c7                mov    %rax,%rdi
 120:   e8 00 00 00 00          call   125 <main+0x125>
    return 0;
 125:   b8 00 00 00 00          mov    $0x0,%eax
}
 12a:   48 8b 55 f8             mov    -0x8(%rbp),%rdx
 12e:   64 48 2b 14 25 28 00    sub    %fs:0x28,%rdx
 135:   00 00
 137:   74 05                   je     13e <main+0x13e>
 139:   e8 00 00 00 00          call   13e <main+0x13e>
 13e:   c9                      leave
 13f:   c3                      ret
```

해당 어셈블리 코드는 디스어셈블 옵션을 조정하여, c언어의 코드가 함께 보이도록 설정한 것입니다.  
<br>
컴파일 환경은 다음과 같습니다.  
os: wsl ubuntu 22.04  
compiler: gcc elf64-x86-64  
cpu: amd ryzen 7900x  
<br>
참고자료 : [AMD 공식 instruction set link](https://www.amd.com/content/dam/amd/en/documents/processor-tech-docs/programmer-references/24592.pdf)  
<br>
각 c언어 코드마다 어심블리 코드가 드러나고 있습니다.  
가장 눈에 띄는 것은, for문 내부의 mov 와 jump 인데, 이는 c의 goto와 유사한 기능을 하여 반복문이 기능하도록 만들어주고 있습니다.   
또한 `scanf`를 통해 데이터를 입력받는 부분과 `malloc`을 이용해 메모리를 할당하는 부분에서는 `mov`를 이용하여 `siz`e의 값을 가져오고,  
그 아래의 두 줄은 각각 메모리 할당 크기를 계상하기 위해 레지스터의 크기를 32->64비트로 늘리는 작업과 `int`의 크기를 계산해주는 작업을 수핸합니다.  
이후 `call`을 통해 `malloc`함수를 호출하여 메모리를 할당합니다.  
`Sort`함수를 call하는 부분 또한 실제 `call`명령어가 나오기 전에 여러가지 전처리를 진행하는데, 이는 지역 변수를 매개변수로 변환하기 위함입니다.  
이렇게 함수가 call될 때 callstack에 주소가 쌓이게 되며, 이는 `return 0`을 이루는 워드를 마주치자 callstack이 비고, 종료를 위한 명령어가 수행됩니다.  
