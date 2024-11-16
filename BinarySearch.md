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
### arm어셈블리 코드로 변환한 코드
```
000103d4 <_init>:
   103d4:       e92d4008        push    {r3, lr}
   103d8:       eb00002b        bl      1048c <call_weak_fn>
   103dc:       e8bd8008        pop     {r3, pc}

Disassembly of section .plt:

000103e0 <.plt>:
   103e0:       e52de004        push    {lr}            @ (str lr, [sp, #-4]!)
   103e4:       e59fe004        ldr     lr, [pc, #4]    @ 103f0 <.plt+0x10>
   103e8:       e08fe00e        add     lr, pc, lr
   103ec:       e5bef008        ldr     pc, [lr, #8]!
   103f0:       00001c10        .word   0x00001c10

000103f4 <__libc_start_main@plt>:
   103f4:       e28fc600        add     ip, pc, #0, 12
   103f8:       e28cca01        add     ip, ip, #4096   @ 0x1000
   103fc:       e5bcfc10        ldr     pc, [ip, #3088]!        @ 0xc10

00010400 <printf@plt>:
   10400:       e28fc600        add     ip, pc, #0, 12
   10404:       e28cca01        add     ip, ip, #4096   @ 0x1000
   10408:       e5bcfc08        ldr     pc, [ip, #3080]!        @ 0xc08

0001040c <__stack_chk_fail@plt>:
   1040c:       e28fc600        add     ip, pc, #0, 12
   10410:       e28cca01        add     ip, ip, #4096   @ 0x1000
   10414:       e5bcfc00        ldr     pc, [ip, #3072]!        @ 0xc00

00010418 <puts@plt>:
   10418:       e28fc600        add     ip, pc, #0, 12
   1041c:       e28cca01        add     ip, ip, #4096   @ 0x1000
   10420:       e5bcfbf8        ldr     pc, [ip, #3064]!        @ 0xbf8

00010424 <__gmon_start__@plt>:
   10424:       e28fc600        add     ip, pc, #0, 12
   10428:       e28cca01        add     ip, ip, #4096   @ 0x1000
   1042c:       e5bcfbf0        ldr     pc, [ip, #3056]!        @ 0xbf0

00010430 <__isoc99_scanf@plt>:
   10430:       e28fc600        add     ip, pc, #0, 12
   10434:       e28cca01        add     ip, ip, #4096   @ 0x1000
   10438:       e5bcfbe8        ldr     pc, [ip, #3048]!        @ 0xbe8

0001043c <abort@plt>:
   1043c:       e28fc600        add     ip, pc, #0, 12
   10440:       e28cca01        add     ip, ip, #4096   @ 0x1000
   10444:       e5bcfbe0        ldr     pc, [ip, #3040]!        @ 0xbe0

Disassembly of section .text:

00010448 <_start>:
   10448:       e3a0b000        mov     fp, #0
   1044c:       e3a0e000        mov     lr, #0
   10450:       e49d1004        pop     {r1}            @ (ldr r1, [sp], #4)
   10454:       e1a0200d        mov     r2, sp
   10458:       e52d2004        push    {r2}            @ (str r2, [sp, #-4]!)
   1045c:       e52d0004        push    {r0}            @ (str r0, [sp, #-4]!)
   10460:       e59fa01c        ldr     sl, [pc, #28]   @ 10484 <_start+0x3c>
   10464:       e28f3018        add     r3, pc, #24
   10468:       e08aa003        add     sl, sl, r3
   1046c:       e3a03000        mov     r3, #0
   10470:       e52d3004        push    {r3}            @ (str r3, [sp, #-4]!)
   10474:       e59f000c        ldr     r0, [pc, #12]   @ 10488 <_start+0x40>
   10478:       e79a0000        ldr     r0, [sl, r0]
   1047c:       ebffffdc        bl      103f4 <__libc_start_main@plt>
   10480:       ebffffed        bl      1043c <abort@plt>
   10484:       00001b7c        .word   0x00001b7c
   10488:       0000002c        .word   0x0000002c

0001048c <call_weak_fn>:
   1048c:       e59f3014        ldr     r3, [pc, #20]   @ 104a8 <call_weak_fn+0x1c>
   10490:       e59f2014        ldr     r2, [pc, #20]   @ 104ac <call_weak_fn+0x20>
   10494:       e08f3003        add     r3, pc, r3
   10498:       e7932002        ldr     r2, [r3, r2]
   1049c:       e3520000        cmp     r2, #0
   104a0:       012fff1e        bxeq    lr
   104a4:       eaffffde        b       10424 <__gmon_start__@plt>
   104a8:       00001b64        .word   0x00001b64
   104ac:       00000028        .word   0x00000028

000104b0 <deregister_tm_clones>:
   104b0:       e59f0018        ldr     r0, [pc, #24]   @ 104d0 <deregister_tm_clones+0x20>
   104b4:       e59f3018        ldr     r3, [pc, #24]   @ 104d4 <deregister_tm_clones+0x24>
   104b8:       e1530000        cmp     r3, r0
   104bc:       012fff1e        bxeq    lr
   104c0:       e59f3010        ldr     r3, [pc, #16]   @ 104d8 <deregister_tm_clones+0x28>
   104c4:       e3530000        cmp     r3, #0
   104c8:       012fff1e        bxeq    lr
   104cc:       e12fff13        bx      r3
   104d0:       00012038        .word   0x00012038
   104d4:       00012038        .word   0x00012038
   104d8:       00000000        .word   0x00000000

000104dc <register_tm_clones>:
   104dc:       e59f0024        ldr     r0, [pc, #36]   @ 10508 <register_tm_clones+0x2c>
   104e0:       e59f3024        ldr     r3, [pc, #36]   @ 1050c <register_tm_clones+0x30>
   104e4:       e0433000        sub     r3, r3, r0
   104e8:       e1a01fa3        lsr     r1, r3, #31
   104ec:       e0811143        add     r1, r1, r3, asr #2
   104f0:       e1b010c1        asrs    r1, r1, #1
   104f4:       012fff1e        bxeq    lr
   104f8:       e59f3010        ldr     r3, [pc, #16]   @ 10510 <register_tm_clones+0x34>
   104fc:       e3530000        cmp     r3, #0
   10500:       012fff1e        bxeq    lr
   10504:       e12fff13        bx      r3
   10508:       00012038        .word   0x00012038
   1050c:       00012038        .word   0x00012038
   10510:       00000000        .word   0x00000000

00010514 <__do_global_dtors_aux>:
   10514:       e92d4010        push    {r4, lr}
   10518:       e59f4018        ldr     r4, [pc, #24]   @ 10538 <__do_global_dtors_aux+0x24>
   1051c:       e5d43000        ldrb    r3, [r4]
   10520:       e3530000        cmp     r3, #0
   10524:       18bd8010        popne   {r4, pc}
   10528:       ebffffe0        bl      104b0 <deregister_tm_clones>
   1052c:       e3a03001        mov     r3, #1
   10530:       e5c43000        strb    r3, [r4]
   10534:       e8bd8010        pop     {r4, pc}
   10538:       00012038        .word   0x00012038

0001053c <frame_dummy>:
   1053c:       eaffffe6        b       104dc <register_tm_clones>

00010540 <main>:
   10540:       e92d4800        push    {fp, lr}
   10544:       e28db004        add     fp, sp, #4
   10548:       e24dd040        sub     sp, sp, #64     @ 0x40
   1054c:       e59f3158        ldr     r3, [pc, #344]  @ 106ac <main+0x16c>
   10550:       e5933000        ldr     r3, [r3]
   10554:       e50b3008        str     r3, [fp, #-8]
   10558:       e3a03000        mov     r3, #0
   1055c:       e59f314c        ldr     r3, [pc, #332]  @ 106b0 <main+0x170>
   10560:       e24bc028        sub     ip, fp, #40     @ 0x28
   10564:       e1a0e003        mov     lr, r3
   10568:       e8be000f        ldm     lr!, {r0, r1, r2, r3}
   1056c:       e8ac000f        stmia   ip!, {r0, r1, r2, r3}
   10570:       e89e000f        ldm     lr, {r0, r1, r2, r3}
   10574:       e88c000f        stm     ip, {r0, r1, r2, r3}
   10578:       e3a03008        mov     r3, #8
   1057c:       e50b3030        str     r3, [fp, #-48]  @ 0xffffffd0
   10580:       e59f012c        ldr     r0, [pc, #300]  @ 106b4 <main+0x174>
   10584:       ebffff9d        bl      10400 <printf@plt>
   10588:       e24b303c        sub     r3, fp, #60     @ 0x3c
   1058c:       e1a01003        mov     r1, r3
   10590:       e59f0120        ldr     r0, [pc, #288]  @ 106b8 <main+0x178>
   10594:       ebffffa5        bl      10430 <__isoc99_scanf@plt>
   10598:       e3a03000        mov     r3, #0
   1059c:       e50b3038        str     r3, [fp, #-56]  @ 0xffffffc8
   105a0:       e51b3030        ldr     r3, [fp, #-48]  @ 0xffffffd0
   105a4:       e2433001        sub     r3, r3, #1
   105a8:       e50b3034        str     r3, [fp, #-52]  @ 0xffffffcc
   105ac:       e3a03000        mov     r3, #0
   105b0:       e54b303d        strb    r3, [fp, #-61]  @ 0xffffffc3
   105b4:       ea000026        b       10654 <main+0x114>
   105b8:       e51b2034        ldr     r2, [fp, #-52]  @ 0xffffffcc
   105bc:       e51b3038        ldr     r3, [fp, #-56]  @ 0xffffffc8
   105c0:       e0423003        sub     r3, r2, r3
   105c4:       e1a02fa3        lsr     r2, r3, #31
   105c8:       e0823003        add     r3, r2, r3
   105cc:       e1a030c3        asr     r3, r3, #1
   105d0:       e1a02003        mov     r2, r3
   105d4:       e51b3038        ldr     r3, [fp, #-56]  @ 0xffffffc8
   105d8:       e0833002        add     r3, r3, r2
   105dc:       e50b302c        str     r3, [fp, #-44]  @ 0xffffffd4
   105e0:       e51b302c        ldr     r3, [fp, #-44]  @ 0xffffffd4
   105e4:       e1a03103        lsl     r3, r3, #2
   105e8:       e2433004        sub     r3, r3, #4
   105ec:       e083300b        add     r3, r3, fp
   105f0:       e5132024        ldr     r2, [r3, #-36]  @ 0xffffffdc
   105f4:       e51b303c        ldr     r3, [fp, #-60]  @ 0xffffffc4
   105f8:       e1520003        cmp     r2, r3
   105fc:       1a000005        bne     10618 <main+0xd8>
   10600:       e51b102c        ldr     r1, [fp, #-44]  @ 0xffffffd4
   10604:       e59f00b0        ldr     r0, [pc, #176]  @ 106bc <main+0x17c>
   10608:       ebffff7c        bl      10400 <printf@plt>
   1060c:       e3a03001        mov     r3, #1
   10610:       e54b303d        strb    r3, [fp, #-61]  @ 0xffffffc3
   10614:       ea000012        b       10664 <main+0x124>
   10618:       e51b302c        ldr     r3, [fp, #-44]  @ 0xffffffd4
   1061c:       e1a03103        lsl     r3, r3, #2
   10620:       e2433004        sub     r3, r3, #4
   10624:       e083300b        add     r3, r3, fp
   10628:       e5132024        ldr     r2, [r3, #-36]  @ 0xffffffdc
   1062c:       e51b303c        ldr     r3, [fp, #-60]  @ 0xffffffc4
   10630:       e1520003        cmp     r2, r3
   10634:       aa000003        bge     10648 <main+0x108>
   10638:       e51b302c        ldr     r3, [fp, #-44]  @ 0xffffffd4
   1063c:       e2833001        add     r3, r3, #1
   10640:       e50b3038        str     r3, [fp, #-56]  @ 0xffffffc8
   10644:       ea000002        b       10654 <main+0x114>
   10648:       e51b302c        ldr     r3, [fp, #-44]  @ 0xffffffd4
   1064c:       e2433001        sub     r3, r3, #1
   10650:       e50b3034        str     r3, [fp, #-52]  @ 0xffffffcc
   10654:       e51b2038        ldr     r2, [fp, #-56]  @ 0xffffffc8
   10658:       e51b3034        ldr     r3, [fp, #-52]  @ 0xffffffcc
   1065c:       e1520003        cmp     r2, r3
   10660:       daffffd4        ble     105b8 <main+0x78>
   10664:       e55b303d        ldrb    r3, [fp, #-61]  @ 0xffffffc3
   10668:       e2233001        eor     r3, r3, #1
   1066c:       e20330ff        and     r3, r3, #255    @ 0xff
   10670:       e3530000        cmp     r3, #0
   10674:       0a000001        beq     10680 <main+0x140>
   10678:       e59f0040        ldr     r0, [pc, #64]   @ 106c0 <main+0x180>
   1067c:       ebffff65        bl      10418 <puts@plt>
   10680:       e3a03000        mov     r3, #0
   10684:       e59f2020        ldr     r2, [pc, #32]   @ 106ac <main+0x16c>
   10688:       e5921000        ldr     r1, [r2]
   1068c:       e51b2008        ldr     r2, [fp, #-8]
   10690:       e0321001        eors    r1, r2, r1
   10694:       e3a02000        mov     r2, #0
   10698:       0a000000        beq     106a0 <main+0x160>
   1069c:       ebffff5a        bl      1040c <__stack_chk_fail@plt>
   106a0:       e1a00003        mov     r0, r3
   106a4:       e24bd004        sub     sp, fp, #4
   106a8:       e8bd8800        pop     {fp, pc}
   106ac:       00011f0c        .word   0x00011f0c
   106b0:       000107c4        .word   0x000107c4
   106b4:       00010760        .word   0x00010760
   106b8:       00010784        .word   0x00010784
   106bc:       00010788        .word   0x00010788
   106c0:       000107a4        .word   0x000107a4

Disassembly of section .fini:

000106c4 <_fini>:
   106c4:       e92d4008        push    {r3, lr}
   106c8:       e8bd8008        pop     {r3, pc}
```
