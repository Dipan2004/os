; bootloader.asm

section .text
    global _start

_start:
    ; Initialize the system
    ; Switch to protected mode here (code not shown)
    call init_memory_management  ; Call the memory management initialization function
    ; Continue with booting the OS
