
CV_PATH = $(CURDIR)/build/make
CV_FILE = $(CV_PATH)/libcutievanilla.a

all: build

build: $(CV_FILE)
	@echo TUDO CERTO!!

cv: $(CV_FILE)

$(CV_FILE):
	cd .. && make OUTPUT_PATH=$(CV_PATH)

clean:
	rm -f $(CV_FILE)