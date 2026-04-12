.syntax unified
.cpu cortex-m4
.thumb

.global _start
.global Reset_Handler

.section .isr_vector
.type _start, %object

_start:
  .word _estack
  .word Reset_Handler

  .rept 14
  .word Default_Handler
  .endr

Reset_Handler:
  ldr r0, =_sidata
  ldr r1, =_sdata
  ldr r2, =_edata
1:
  cmp r1, r2
  ittt lt
  ldrlt r3, [r0], #4
  strlt r3, [r1], #4
  blt 1b

  ldr r0, =_sbss
  ldr r1, =_ebss
2:
  cmp r0, r1
  it lt
  strlt r2, [r0], #4
  blt 2b

  bl main

Default_Handler:
  b Default_Handler