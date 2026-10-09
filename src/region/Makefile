# main include path
CVPATH = ../../include

BUILD_DIR ?= .

# return error if FOLDER not exist
ifeq ($(wildcard $(BUILD_DIR)/.),)
  $(error Error: Directory '$(BUILD_DIR)' not found)
endif

# Compiler options
CC ?= gcc
CFLAGS ?= -Wall -Wextra -I$(CVPATH)

AR = ar
ARFLAGS = -rcs

# output library
LIB = $(BUILD_DIR)/libregion.a


# source code filelist
SRC_FILES = \
	region.c 


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


$(BUILD_DIR):
	@echo "Folder '$(BUILD_DIR)' not found\n"

clean:
	rm -f $(OBJ) $(LIB)

help:
	@echo "Source files: $(SRC)"
	@echo "Object files: $(OBJ)"
	@echo "Target output: $(LIB)"