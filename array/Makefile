CC      := gcc
CFLAGS  := -std=c99

DEPS    := $(wildcard build/*.d)

all: dynamic static

dynamic: dynamic.c build/array.o
	$(CC) $(CFLAGS) -o dynamic $^

static: static.c
	$(CC) $(CFLAGS) -o static $^

build/%.o: %.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c -o $@ $< -MMD

clean:
	@rm -rf build
	@rm dynamic static
	@echo "Done."

-include $(DEPS)