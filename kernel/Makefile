# Makefile for building and running MyOS

# Clear function
define clear
    @clear
endef

# Targets
all: swan.iso

run: swan.iso
	@$(call clear)
	@qemu-system-x86_64 -cdrom swan.iso

# Compile boot.s
boot.o: boot.s
	@as --32 boot.s -o boot.o



# Compile kernel.c file
kernel.o: kernel.c
	@gcc -m32 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

# Link kernel with kernel.o and boot.o files
swan.bin: kernel.o boot.o
	@ld -m elf_i386 -T linker.ld kernel.o boot.o -o swan.bin -nostdlib

# Check MyOS.bin file is x86 multiboot file or not
check: swan.bin
	@grub-file --is-x86-multiboot swan.bin

# Build the iso file
swan.iso: swan.bin grub.cfg
	@mkdir -p iso/boot/grub
	@cp swan.bin iso/boot/swan.bin
	@cp grub.cfg iso/boot/grub/grub.cfg
	@grub-mkrescue -o swan.iso iso

# Clean up
clean:
	@rm -rf boot.o kernel.o MyOS.bin iso swan.iso swan.bin keyboard.o

.PHONY: all run check clean

