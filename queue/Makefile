CC      := gcc
CFLAGS  := -std=c99

DEPS    := $(wildcard build/*.d)

all: queue

queue: queue.c
	$(CC) $(CFLAGS) -o queue $^

clean:
	@rm queue
	@echo "Done."

-include $(DEPS)