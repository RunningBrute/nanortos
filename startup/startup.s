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
  bl reset_handler_cpp

Default_Handler:
  b Default_Handler
  