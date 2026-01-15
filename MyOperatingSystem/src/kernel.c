/*
 * kernel.c
 * This file contains the basic kernel implementation for the operating system.
 * It serves as the core component that interacts with the bootloader and manages system resources.
 */

#include <stdint.h>  
#include "memory_management.c" 
#include "io.h" 

// Function prototypes
void print(const char* str);
void sys_call_handler();

// Kernel entry point that is called by the bootloader
void kernel_main() {
    print("Hello, World!\n");  // Print a welcome message to the screen
    char input = read_char();  // Read a character from the keyboard
    print_char(input);  // Echo the character back to the screen
    // Additional kernel setup can be done here
}

// Simple print function to output to the screen
void print(const char* str) {
    // Iterate through each character in the string and output it to the screen
    while (*str) {
        print_char(*str);  // Use the print_char function to print each character
        str++;  // Move to the next character
    }
}

// Simple system call handler
void sys_call_handler() {
    // Handle system calls here (currently does nothing)
}
