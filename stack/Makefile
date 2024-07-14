CC      := gcc
CFLAGS  := -std=c99

DEPS    := $(wildcard build/*.d)

all: stack

stack: stack.c
	$(CC) $(CFLAGS) -o stack $^

clean:
	@rm -rf build
	@rm stack
	@echo "Done."

-include $(DEPS)