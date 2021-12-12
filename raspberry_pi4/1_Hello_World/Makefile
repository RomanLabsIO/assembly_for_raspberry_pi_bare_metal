GCC_BIN_DIR=~/gcc-arm-10.3-2021.07-x86_64-aarch64-none-elf/bin
AS=$(GCC_BIN_DIR)/aarch64-none-elf-gcc
CC=$(GCC_BIN_DIR)/aarch64-none-elf-gcc
LD=$(GCC_BIN_DIR)/aarch64-none-elf-ld
OBJCOPY=$(GCC_BIN_DIR)/aarch64-none-elf-objcopy
OBJDUMP=$(GCC_BIN_DIR)/aarch64-none-elf-objdump
ELF=kernel8.elf
IMAGE=kernel8.img

TARGET_EXEC ?= kernel8.img
SRC_DIRS ?= ./src
BUILD_DIR ?= ./build
OUTPUT_DIR ?= ./output

SRCS := $(shell find $(SRC_DIRS) -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS = $(INC_FLAGS) -mcpu=cortex-a72 -O0 -ffreestanding -nostdlib

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(LD) $(OBJS) -T linker.ld -o $(OUTPUT_DIR)/$(ELF)
	$(OBJCOPY) -O binary $(OUTPUT_DIR)/$(ELF) $(OUTPUT_DIR)/$(IMAGE)
	$(OBJDUMP) -D $(OUTPUT_DIR)/$(ELF) > $(OUTPUT_DIR)/kernel8.lss
	$(OBJDUMP) -s $(OUTPUT_DIR)/$(ELF) > $(OUTPUT_DIR)/kernel8.dump

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) $(OUTPUT_DIR)/$(ELF)
	$(RM) $(OUTPUT_DIR)/kernel8.lss
	$(RM) $(OUTPUT_DIR)/kernel8.dump

MKDIR_P ?= mkdir -p