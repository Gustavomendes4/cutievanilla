# main include path
FCPATH = ../../libs/filecore/src
CVPATH = ../../include

BUILD_DIR ?= .

# return error if FOLDER not exist
ifeq ($(wildcard $(BUILD_DIR)/.),)
  $(error Error: Directory '$(BUILD_DIR)' not found)
endif

# Compiler options
CC ?= gcc
CFLAGS ?= -Wall -Wextra -I$(CVPATH) -I$(FCPATH)

AR = ar
ARFLAGS = -rcs

# output library
LIB = $(BUILD_DIR)/libimage.a


# source code filelist
SRC_FILES = \
	image.c \
	io/bmp/bmp_io.c \
	io/jpeg/jpeg_io.c \
	io/jpg/jpg_io.c \
	io/png/png_io.c \
	io/tiff/tiff_io.c


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