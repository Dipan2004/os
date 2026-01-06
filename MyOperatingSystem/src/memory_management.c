/*
 * memory_management.c
 * This file contains functions for managing memory in the operating system.
 * It includes initialization of the memory management system, allocation, and deallocation of memory.
 */

#include <stddef.h>  // For size_t
#include <stdint.h>  // For uintptr_t

#define PAGE_SIZE 4096  // Define the size of a page (4KB)
#define TOTAL_PAGES 1024  // Define the total number of pages available

// Structure to represent a page frame
typedef struct {
    uint8_t allocated;  // 1 if allocated, 0 if free
} page_frame_t;

// Array to hold page frames
static page_frame_t page_table[TOTAL_PAGES];

/**
 * Initializes the memory management system by setting up the page table.
 */
void init_memory_management() {
    for (int i = 0; i < TOTAL_PAGES; i++) {
        page_table[i].allocated = 0;  // Mark all pages as free
    }
    // Additional setup for paging can be added here
}

/**
 * Allocates a block of memory of the specified size.
 * @param size The size of memory to allocate.
 * @return Pointer to the allocated memory, or NULL if allocation fails.
 */
void* allocate_memory(size_t size) {
    // Ensure the requested size does not exceed page size
    if (size > PAGE_SIZE) {
        return NULL;  // Allocation request too large
    }
    // Find a free page
    for (int i = 0; i < TOTAL_PAGES; i++) {
        if (page_table[i].allocated == 0) {  // Check if the page is free
            page_table[i].allocated = 1;  // Mark page as allocated
            return (void*)(i * PAGE_SIZE);  // Return the address of the allocated page
        }
    }
    return NULL;  // No free pages available
}

/**
 * Frees a previously allocated block of memory.
 * @param ptr Pointer to the memory to free.
 */
void free_memory(void* ptr) {
    // Calculate the page index from the pointer
    uintptr_t page_index = (uintptr_t)ptr / PAGE_SIZE;
    if (page_index < TOTAL_PAGES) {
        page_table[page_index].allocated = 0;  // Mark the page as free
    }
}