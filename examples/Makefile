
CV_PATH = $(CURDIR)/../include

BUILD_PATH = $(CURDIR)/build/
CV_FILE = $(BUILD_PATH)/libcutievanilla.a

SRC_FILE ?= $(CURDIR)/cascade.c

all: build

build: $(CV_FILE) $(SRC_FILE)

# 	echo $(SRC_FILE)
	gcc $(SRC_FILE) $(CV_FILE) -I$(CV_PATH) -o run

	@echo TUDO CERTO!!

cv: $(CV_FILE)

$(CV_FILE): $(BUILD_PATH)
	cd .. && make OUTPUT_PATH=$(BUILD_PATH)

$(BUILD_PATH):
	mkdir -p $(BUILD_PATH)


clean:
	rm -f $(CV_FILE)