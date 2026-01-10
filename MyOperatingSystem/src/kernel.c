/*
 * kernel.c
 * This file contains the basic kernel implementation for the operating system.
 * It serves as the core component that interacts with the bootloader and manages system resources.
 */

#include <stdint.h>  // Standard integer types 
#include "memory_management.c"  // Include memory management header for memory functions

// Function prototypes
void print(const char* str);
void sys_call_handler();

// Kernel entry point that is called by the bootloader
void kernel_main() {
    print("Hello, World!\n");  // Print a welcome message to the screen
    // Additional kernel setup can be done here
}

// Simple print function to output to the screen
void print(const char* str) {
    // Iterate through each character in the string and output it to the screen
    while (*str) {
        // Use a simple outb function to write each character to the video memory
        // Assuming video memory is mapped at 0xB8000 for text mode
        volatile char *video_memory = (volatile char *)0xB8000;
        *video_memory++ = *str;  // Write character
        *video_memory++ = 0x07;  // Attribute byte: light grey on black background
        str++;  // Move to the next character
    }
}

// Simple system call handler
void sys_call_handler() {
    // Handle system calls here (currently does nothing)
}
