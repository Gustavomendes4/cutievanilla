# main include path
CVPATH = ../../include

BUILD_DIR ?= .

ifeq ($(wildcard $(BUILD_DIR)/.),)
  $(error Error: Directory '$(BUILD_DIR)' not found)
endif


# Compiler options
CC ?= gcc
CFLAGS ?= -Wall -Wextra -I$(CVPATH)

AR = ar
ARFLAGS = -rcs

# output library
LIB = $(BUILD_DIR)/libhistogram.a


# source code filelist
SRC_FILES = \
	histogram_arithmetic.c \
	histogram_compare.c \
	histogram_filter.c \
	histogram_image.c \
	histogram_internal.c \
	histogram_matrix.c \
	histogram_stats.c 

SRC = $(strip $(SRC_FILES))

# source object list
OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))


.PHONY: all build clean help

all: build

build: $(LIB)


$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
# 	rm -f $(OBJ)

# Pattern rule to compile each .c file into a .o file
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(BUILD_DIR):
	@echo "Folder '$(BUILD_DIR)' not found\n"

clean:
	rm -f $(OBJ) $(LIB)

help:
	@echo "Source files: $(SRC)"
	@echo "Object files: $(OBJ)"
	@echo "Target output: $(LIB)"