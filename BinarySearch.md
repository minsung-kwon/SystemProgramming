### c 코드
```c
#include <stdio.h>
#include <stdbool.h>

int main() 
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the target value to search: ");
    scanf("%d", &target);

    // 이진 탐색
    int left = 0;
    int right = size - 1;
    bool found = false;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) 
        {
            printf("Target found at index %d\n", mid);
            found = true;
            break;
        } 
        else if (arr[mid] < target) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }

    if (!found) 
    {
        printf("Target not found in the array.\n");
    }

    return 0;
}
```

<br>

### arm어셈블리로 변환한 코드
```
<_init>:
push    {r3, lr}
bl      1048c <call_weak_fn>
pop     {r3, pc}

<.plt>:
push    {lr}            
ldr     lr, [pc, #4]    
add     lr, pc, lr
ldr     pc, [lr, #8]!


<__libc_start_main@plt>:
add     ip, pc, #0, 12
add     ip, ip, #4096   
ldr     pc, [ip, #3088]!      

<printf@plt>:
add     ip, pc, #0, 12
add     ip, ip, #4096  
ldr     pc, [ip, #3080]!  

0001040c <__stack_chk_fail@plt>:
add     ip, pc, #0, 12
add     ip, ip, #4096  
ldr     pc, [ip, #3072]!       

<puts@plt>:
add     ip, pc, #0, 12
add     ip, ip, #4096  
ldr     pc, [ip, #3064]!     

<__gmon_start__@plt>:
add     ip, pc, #0, 12
add     ip, ip, #4096  
ldr     pc, [ip, #3056]!      

<__isoc99_scanf@plt>:
add     ip, pc, #0, 12
add     ip, ip, #4096 
ldr     pc, [ip, #3048]!  

<abort@plt>:
add     ip, pc, #0, 12
add     ip, ip, #4096 
ldr     pc, [ip, #3040]! 

<_start>:
mov     fp, #0
mov     lr, #0
pop     {r1}          
mov     r2, sp
push    {r2}            
push    {r0}          
ldr     sl, [pc, #28]   
add     r3, pc, #24
add     sl, sl, r3
mov     r3, #0
push    {r3}           
ldr     r0, [pc, #12]   
ldr     r0, [sl, r0]
bl      103f4 <__libc_start_main@plt>
bl      1043c <abort@plt>

<call_weak_fn>:
ldr     r3, [pc, #20]   
ldr     r2, [pc, #20]   
add     r3, pc, r3
ldr     r2, [r3, r2]
cmp     r2, #0
bxeq    lr
b       10424 <__gmon_start__@plt>

<deregister_tm_clones>:
ldr     r0, [pc, #24] 
ldr     r3, [pc, #24]  
cmp     r3, r0
bxeq    lr
ldr     r3, [pc, #16]   
cmp     r3, #0
bxeq    lr
bx      r3

<register_tm_clones>:
ldr     r0, [pc, #36] 
ldr     r3, [pc, #36]  
sub     r3, r3, r0
lsr     r1, r3, #31
add     r1, r1, r3, asr #2
asrs    r1, r1, #1
bxeq    lr
ldr     r3, [pc, #16]  
cmp     r3, #0
bxeq    lr
bx      r3

<__do_global_dtors_aux>:
push    {r4, lr}
ldr     r4, [pc, #24] 
ldrb    r3, [r4]
cmp     r3, #0
popne   {r4, pc}
bl      104b0 <deregister_tm_clones>
mov     r3, #1
strb    r3, [r4]
pop     {r4, pc}

<frame_dummy>:
b       104dc <register_tm_clones>

<main>:
push    {fp, lr}
add     fp, sp, #4
sub     sp, sp, #64   
ldr     r3, [pc, #344] 
ldr     r3, [r3]
str     r3, [fp, #-8]
mov     r3, #0
ldr     r3, [pc, #332] 
sub     ip, fp, #40   
mov     lr, r3
ldm     lr!, {r0, r1, r2, r3}
stmia   ip!, {r0, r1, r2, r3}
ldm     lr, {r0, r1, r2, r3}
stm     ip, {r0, r1, r2, r3}
mov     r3, #8
str     r3, [fp, #-48]  
ldr     r0, [pc, #300] 
bl      10400 <printf@plt>
sub     r3, fp, #60    
mov     r1, r3
ldr     r0, [pc, #288] 
bl      10430 <__isoc99_scanf@plt>
mov     r3, #0
str     r3, [fp, #-56]  
ldr     r3, [fp, #-48]  
sub     r3, r3, #1
str     r3, [fp, #-52] 
mov     r3, #0
strb    r3, [fp, #-61]  
b       10654 <main+0x114>
ldr     r2, [fp, #-52]  
ldr     r3, [fp, #-56]  
sub     r3, r2, r3
lsr     r2, r3, #31
add     r3, r2, r3
asr     r3, r3, #1
mov     r2, r3
ldr     r3, [fp, #-56]  
add     r3, r3, r2
str     r3, [fp, #-44]  
ldr     r3, [fp, #-44] 
lsl     r3, r3, #2
sub     r3, r3, #4
add     r3, r3, fp
ldr     r2, [r3, #-36] 
ldr     r3, [fp, #-60] 
cmp     r2, r3
bne     10618 <main+0xd8>
ldr     r1, [fp, #-44]
ldr     r0, [pc, #176] 
bl      10400 <printf@plt>
mov     r3, #1
strb    r3, [fp, #-61]  
b       10664 <main+0x124>
ldr     r3, [fp, #-44]  
lsl     r3, r3, #2
sub     r3, r3, #4
add     r3, r3, fp
ldr     r2, [r3, #-36]  
ldr     r3, [fp, #-60]  
cmp     r2, r3
bge     10648 <main+0x108>
ldr     r3, [fp, #-44]  
add     r3, r3, #1
str     r3, [fp, #-56]
b       10654 <main+0x114>
ldr     r3, [fp, #-44]  
sub     r3, r3, #1
str     r3, [fp, #-52] 
ldr     r2, [fp, #-56] 
ldr     r3, [fp, #-52]
cmp     r2, r3
ble     105b8 <main+0x78>
ldrb    r3, [fp, #-61]
eor     r3, r3, #1
and     r3, r3, #255  
cmp     r3, #0
beq     10680 <main+0x140>
ldr     r0, [pc, #64]  
bl      10418 <puts@plt>
mov     r3, #0
ldr     r2, [pc, #32]   
ldr     r1, [r2]
ldr     r2, [fp, #-8]
eors    r1, r2, r1
mov     r2, #0
beq     106a0 <main+0x160>
bl      1040c <__stack_chk_fail@plt>
mov     r0, r3
sub     sp, fp, #4
pop     {fp, pc}

<_fini>:
push    {r3, lr}
pop     {r3, pc}
```

이진 탐색 코드는 기본적으로 계속해서 탐색 범위를 줄여나간다.  
이에 따라 탐색 범위를 줄이기 위한 연산이 계속해서 들어가고, 해당 연산 이후 cmp를 이용하여 찾으려는 수와 비교한다.  
또한 계속해서 bl,b를 이용하여 분기를 나누었다.  
이러한 분기의 나눔은 이진 탐색에서 필수적이다.  
