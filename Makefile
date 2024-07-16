CC      := gcc
CFLAGS  := -std=c99 -O3

EXAMPLES    := array linked_list queue stack

all: $(EXAMPLES)
	@echo "Done."

define EXAMPLE_BUILD
$1: build/$1

build/$1: $1/$1.c
	@mkdir -p build
	gcc $1/$1.c -o build/$1
endef

$(foreach EXAMPLE,$(EXAMPLES),$(eval $(call EXAMPLE_BUILD,$(EXAMPLE))))

clean:
	@rm -rf build
	@echo "Done."