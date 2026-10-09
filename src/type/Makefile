# main include path
CVPATH = ../../include

BUILD_DIR ?= .

# return error if FOLDER not exist
ifeq ($(wildcard $(DIR)/.),)
  $(error Error: Directory '$(DIR)' not found)
endif

# Compiler options
CC ?= gcc
CFLAGS ?= -Wall -Wextra -I$(CVPATH)

AR = ar
ARFLAGS = -rcs

# output library
LIB = $(BUILD_DIR)/libtype.a


# source code filelist
SRC_FILES = \
	type.c \
	primitive/float32.c \
	primitive/float64.c \
	primitive/int8.c \
	primitive/int16.c \
	primitive/int32.c \
	primitive/uint8.c \
	primitive/uint16.c \
	primitive/uint32.c


SRC = $(strip $(SRC_FILES))

# source object list
OBJ = $(addprefix $(BUILD_DIR)/, $(notdir $(SRC:.c=.o)))


# Ensina o Make a procurar arquivos .c em qualquer subpasta listada em SRC
vpath %.c $(sort $(dir $(SRC)))


.PHONY: all build clean help

all: build

build: $(LIB)

$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
# 	rm -f $(OBJ)

# Pattern rule to compile each .c file into a .o file
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIB)

help:
	@echo "Source files: $(SRC)"
	@echo "Object files: $(OBJ)"
	@echo "Target output: $(LIB)"