/*
 * io.c
 * This file contains basic input/output functions for the operating system.
 * It includes functions to print characters to the screen and read keyboard input.
 */

#include <stdint.h>  // For standard integer types

// Function to print a single character to the screen
void print_char(char c) {
    // The video memory for text mode is mapped at 0xB8000
    volatile char *video_memory = (volatile char *)0xB8000;
    *video_memory++ = c;  // Write the character to video memory
    *video_memory++ = 0x07;  // Attribute byte: light grey on black background 
}

// Function to read a character from the keyboard
char read_char() {
    char c;
    // Wait for a key press on the keyboard
    while (!(inb(0x60) & 0x01));  // Polling the keyboard controller
    c = inb(0x60);  // Read the character from the keyboard data port
    return c;  // Return the character read
}

// Inline assembly function to read from I/O ports
static inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    __asm__ volatile ("inb %1, %0" : "=a" (ret) : "Nd" (port));
    return ret;
}