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
이 어셈블리 코드를 기반으로 하여 amd의 공식 문서와 MIPS명령어 설명을 보며 해당 어셈블리 코드를 x86 MIPS로 바꾸어 만들었습니다.  
이때 몇 가지 대응되는 것들을 추려보겠습니다.  
`%rax`, `%rbp`, `%rsp` -> `\$t`, `\$s`  
`%rsp`, `push`, `pop` -> 스택 프레임 기반 접근으로 변경  
`mov`, `add`, `sub`, `jmp` -> `lw`, `sw`, `add`, `beq`  
<br><br>
다음은 MIPS로 변환한 코드입니다  
```
.data
arr:    .word 1, 3, 5, 7, 9, 11, 13, 15
size:   .word 8
target: .word 0
found:  .byte 0
msg_found:     .asciiz "Target found at index "
msg_not_found: .asciiz "Target not found in the array.\n"
input_msg:     .asciiz "Enter the target value to search: "
newline:       .asciiz "\n"

.text
.globl main
main:
    addi $sp, $sp, -32
    sw $ra, 28($sp)
    sw $s0, 24($sp)

    la $a0, input_msg
    li $v0, 4
    syscall

    li $v0, 5
    syscall
    sw $v0, target

    li $t0, 0
    lw $t1, size
    subi $t1, $t1, 1
    li $t2, 0

binary_search:
    ble $t0, $t1, check_mid
    j end_search

check_mid:
    add $t3, $t0, $t1
    srl $t3, $t3, 1
    sll $t4, $t3, 2

    la $t5, arr
    add $t5, $t5, $t4
    lw $t6, 0($t5)
    lw $t7, target
    beq $t6, $t7, found_target
    blt $t6, $t7, move_right

move_left:
    sub $t1, $t3, 1
    j binary_search

move_right:
    add $t0, $t3, 1
    j binary_search

found_target:
    li $t2, 1
    move $a0, $t3
    la $a0, msg_found
    li $v0, 4
    syscall

    move $a0, $t3
    li $v0, 1
    syscall

    la $a0, newline
    li $v0, 4
    syscall

    j end_search

end_search:
    beqz $t2, not_found
    j cleanup

not_found:
    la $a0, msg_not_found
    li $v0, 4
    syscall

cleanup:
    lw $ra, 28($sp)
    lw $s0, 24($sp)
    addi $sp, $sp, 32
    jr $ra
```
