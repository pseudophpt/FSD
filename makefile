# Cross Compiler

VER := 0.0.01
PLATFORM := x86

PROJDIRS := src

SRCFILES := $(shell find $(PROJDIRS) -type f -name "*.c")
ASMFILES := $(shell find $(PROJDIRS) -type f -name "*.s")
HDRFILES := $(shell find $(PROJDIRS) -type f -name "*.h")

OBJ_LINK_LIST := $(patsubst %.c,%.o,$(SRCFILES)) $(patsubst %.s,%.o,$(ASMFILES))

ASSEMBLER := nasm
CC := ~/opt/cross/bin/i686-elf-gcc

DIR := ~/FSD

.PHONY: all clean dist check testdrivers todolist

WARNINGS := -Wall -Wextra -Wno-format -Wno-unused-parameter -Wno-unused-function -Werror

CFLAGS := -g -O2 -ffreestanding -fbuiltin $(WARNINGS) 

all: $(OBJ_LINK_LIST)
	ld -m elf_i386 -T $(DIR)/link.ld -o $(DIR)/iso/kernel $(OBJ_LINK_LIST)
	genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o bin/fsd-$(VER)-$(PLATFORM).iso iso

%.o: %.c
	$(CC) -c $< -o $@ -std=c99 $(CFLAGS) 

%.o: %.s
	$(ASSEMBLER) -f elf32 $< -o $@

clean:
	rm $(OBJ_LINK_LIST)
