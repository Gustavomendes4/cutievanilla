# Base Directory
BUILD_DIR 	?= $(CURDIR)/build/make

OUTPUT_PATH ?= $(BUILD_DIR)

MODULES_DIR =  src

MODULES 	=  \
	histogram \
	image \
	matrix \
	region \
	type \

# Cria a lista de caminhos dos Makefiles dos submódulos
SUBDIRS = $(addprefix $(MODULES_DIR)/, $(MODULES))

# Cria a lista de bibliotecas dentro de suas respectivas subpastas no BUILD_DIR
SUB_LIBS = $(foreach mod, $(MODULES), $(BUILD_DIR)/$(mod)/lib$(mod).a)

# Biblioteca unificada final
FINAL_LIB = $(OUTPUT_PATH)/libcutievanilla.a


# === Compiler configuration ===
CC ?= gcc
CFLAGS ?= -Wall -Wextra

AR ?= ar -rcs

# === TARGETS ===

.PHONY: all build clean $(SUB_LIBS) $(SUBDIRS)

all: build

build: $(FINAL_LIB)

# Executa o make dentro de cada subdiretorio
$(SUBDIRS):
	@mkdir -p $(BUILD_DIR)/$(notdir $@)
	@$(MAKE) -C $@ BUILD_DIR=$(BUILD_DIR)/$(notdir $@)


$(SUB_LIBS): $(SUBDIRS)

# Mescla todas as libs .a secundárias em uma única lib unificada usando MRI Script
$(FINAL_LIB): $(SUB_LIBS) $(BUILD_DIR)

#	Busca por todos .o
	$(eval ALL_OBJS := $(shell find $(BUILD_DIR) -mindepth 2 -type f -name "*.o"))
	
	$(AR) $(ARFLAGS) $@ $(ALL_OBJS)


$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
