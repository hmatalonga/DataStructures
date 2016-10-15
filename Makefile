SHELL = /bin/sh

CC = gcc
COMPILER_FLAGS = -Wall -Werror
LINKER_FLAGS = -lm
DEPS = src/dataio.h
OBJ_NAME = dataio

SLIST = src/slist/main.c src/slist/slist.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(COMPILER_FLAGS)
slist: $(SLIST)
	$(CC) $(SLIST) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
clean:
	rm -f $(OBJ_NAME)
