#!/bin/bash

# This script sets up the development environment for building an operating system.

# Function to install a package if it is not already installed
install_if_not_present() {
    if ! command -v $1 &> /dev/null
    then
        echo "$1 is not installed. Installing..."
        sudo apt-get install -y $1
    else
        echo "$1 is already installed."
    fi
}

# Install NASM (Netwide Assembler) for assembling the bootloader
install_if_not_present nasm

# Install GCC (GNU Compiler Collection) for cross-compilation
install_if_not_present gcc

# Install QEMU for emulation
install_if_not_present qemu

# Install Git for version control
install_if_not_present git

# Install Vim as a text editor
install_if_not_present vim

# Create the project directory structure
PROJECT_DIR="MyOperatingSystem"

# Check if project directory already exists
if [ ! -d "$PROJECT_DIR" ]; then
    echo "Creating project directory: $PROJECT_DIR"
    mkdir -p "$PROJECT_DIR/src" "$PROJECT_DIR/bin" "$PROJECT_DIR/docs"
else
    echo "Project directory $PROJECT_DIR already exists."
fi

# Create a simple Hello World program
cat <<EOL > "$PROJECT_DIR/src/hello.c"
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
EOL

# Create a simple Makefile for building the bootloader and kernel
cat <<EOL > "$PROJECT_DIR/Makefile"
# Makefile for building the bootloader and kernel

# Specify the assembler and compiler
AS=nasm
CC=gcc

# Specify the target files
BOOTLOADER=bootloader.asm
KERNEL=kernel.bin

# Default target
all: bootloader.bin kernel.bin

# Rule to build the bootloader
bootloader.bin: 
		echo "Assembling bootloader..."
		$(AS) -f bin $(BOOTLOADER) -o bootloader.bin

# Rule to build the kernel
kernel.bin:
		echo "Compiling kernel..."
		$(CC) -ffreestanding -c kernel.c -o kernel.o
		$(CC) -T link.ld -o kernel.bin kernel.o

# Clean target
clean:
		rm -f *.bin *.o
EOL

# Notify that the setup is complete
echo "Development environment setup complete!"
