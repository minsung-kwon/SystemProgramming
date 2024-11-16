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

### amd64로 컴파일한 코드의 어셈블리 변환
```
0000000000000000 <main>:
#include <stdio.h>
#include <stdbool.h>

int main()
{
   0:   f3 0f 1e fa             endbr64
   4:   55                      push   %rbp
   5:   48 89 e5                mov    %rsp,%rbp
   8:   48 83 ec 50             sub    $0x50,%rsp
   c:   64 48 8b 04 25 28 00    mov    %fs:0x28,%rax
  13:   00 00
  15:   48 89 45 f8             mov    %rax,-0x8(%rbp)
  19:   31 c0                   xor    %eax,%eax
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
  1b:   c7 45 d0 01 00 00 00    movl   $0x1,-0x30(%rbp)
  22:   c7 45 d4 03 00 00 00    movl   $0x3,-0x2c(%rbp)
  29:   c7 45 d8 05 00 00 00    movl   $0x5,-0x28(%rbp)
  30:   c7 45 dc 07 00 00 00    movl   $0x7,-0x24(%rbp)
  37:   c7 45 e0 09 00 00 00    movl   $0x9,-0x20(%rbp)
  3e:   c7 45 e4 0b 00 00 00    movl   $0xb,-0x1c(%rbp)
  45:   c7 45 e8 0d 00 00 00    movl   $0xd,-0x18(%rbp)
  4c:   c7 45 ec 0f 00 00 00    movl   $0xf,-0x14(%rbp)
    int size = sizeof(arr) / sizeof(arr[0]);
  53:   c7 45 c8 08 00 00 00    movl   $0x8,-0x38(%rbp)
    int target;

    printf("Enter the target value to search: ");
  5a:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # 61 <main+0x61>
  61:   48 89 c7                mov    %rax,%rdi
  64:   b8 00 00 00 00          mov    $0x0,%eax
  69:   e8 00 00 00 00          call   6e <main+0x6e>
    scanf("%d", &target);
  6e:   48 8d 45 bc             lea    -0x44(%rbp),%rax
  72:   48 89 c6                mov    %rax,%rsi
  75:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # 7c <main+0x7c>
  7c:   48 89 c7                mov    %rax,%rdi
  7f:   b8 00 00 00 00          mov    $0x0,%eax
  84:   e8 00 00 00 00          call   89 <main+0x89>

    // 이진 탐색
    int left = 0;
  89:   c7 45 c0 00 00 00 00    movl   $0x0,-0x40(%rbp)
    int right = size - 1;
  90:   8b 45 c8                mov    -0x38(%rbp),%eax
  93:   83 e8 01                sub    $0x1,%eax
  96:   89 45 c4                mov    %eax,-0x3c(%rbp)
    bool found = false;
  99:   c6 45 bb 00             movb   $0x0,-0x45(%rbp)

    while (left <= right)
  9d:   eb 6c                   jmp    10b <main+0x10b>
    {
        int mid = left + (right - left) / 2;
  9f:   8b 45 c4                mov    -0x3c(%rbp),%eax
  a2:   2b 45 c0                sub    -0x40(%rbp),%eax
  a5:   89 c2                   mov    %eax,%edx
  a7:   c1 ea 1f                shr    $0x1f,%edx
  aa:   01 d0                   add    %edx,%eax
  ac:   d1 f8                   sar    $1,%eax
  ae:   89 c2                   mov    %eax,%edx
  b0:   8b 45 c0                mov    -0x40(%rbp),%eax
  b3:   01 d0                   add    %edx,%eax
  b5:   89 45 cc                mov    %eax,-0x34(%rbp)

        if (arr[mid] == target)
  b8:   8b 45 cc                mov    -0x34(%rbp),%eax
  bb:   48 98                   cltq
  bd:   8b 54 85 d0             mov    -0x30(%rbp,%rax,4),%edx
  c1:   8b 45 bc                mov    -0x44(%rbp),%eax
  c4:   39 c2                   cmp    %eax,%edx
  c6:   75 1f                   jne    e7 <main+0xe7>
        {
            printf("Target found at index %d\n", mid);
  c8:   8b 45 cc                mov    -0x34(%rbp),%eax
  cb:   89 c6                   mov    %eax,%esi
  cd:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # d4 <main+0xd4>
  d4:   48 89 c7                mov    %rax,%rdi
  d7:   b8 00 00 00 00          mov    $0x0,%eax
  dc:   e8 00 00 00 00          call   e1 <main+0xe1>
            found = true;
  e1:   c6 45 bb 01             movb   $0x1,-0x45(%rbp)
            break;
  e5:   eb 2c                   jmp    113 <main+0x113>
        }
        else if (arr[mid] < target)
  e7:   8b 45 cc                mov    -0x34(%rbp),%eax
  ea:   48 98                   cltq
  ec:   8b 54 85 d0             mov    -0x30(%rbp,%rax,4),%edx
  f0:   8b 45 bc                mov    -0x44(%rbp),%eax
  f3:   39 c2                   cmp    %eax,%edx
  f5:   7d 0b                   jge    102 <main+0x102>
        {
            left = mid + 1;
  f7:   8b 45 cc                mov    -0x34(%rbp),%eax
  fa:   83 c0 01                add    $0x1,%eax
  fd:   89 45 c0                mov    %eax,-0x40(%rbp)
 100:   eb 09                   jmp    10b <main+0x10b>
        }
        else
        {
            right = mid - 1;
 102:   8b 45 cc                mov    -0x34(%rbp),%eax
 105:   83 e8 01                sub    $0x1,%eax
 108:   89 45 c4                mov    %eax,-0x3c(%rbp)
    while (left <= right)
 10b:   8b 45 c0                mov    -0x40(%rbp),%eax
 10e:   3b 45 c4                cmp    -0x3c(%rbp),%eax
 111:   7e 8c                   jle    9f <main+0x9f>
        }
    }

    if (!found)
 113:   0f b6 45 bb             movzbl -0x45(%rbp),%eax
 117:   83 f0 01                xor    $0x1,%eax
 11a:   84 c0                   test   %al,%al
 11c:   74 0f                   je     12d <main+0x12d>
    {
        printf("Target not found in the array.\n");
 11e:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # 125 <main+0x125>
 125:   48 89 c7                mov    %rax,%rdi
 128:   e8 00 00 00 00          call   12d <main+0x12d>
    }

    return 0;
 12d:   b8 00 00 00 00          mov    $0x0,%eax
 132:   48 8b 55 f8             mov    -0x8(%rbp),%rdx
 136:   64 48 2b 14 25 28 00    sub    %fs:0x28,%rdx
 13d:   00 00
 13f:   74 05                   je     146 <main+0x146>
 141:   e8 00 00 00 00          call   146 <main+0x146>
 146:   c9                      leave
 147:   c3                      ret
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
