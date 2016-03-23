OBJS=main.c slist.c
CC=gcc
COMPILER_FLAGS=-Wall -Werror
LINKER_FLAGS=-lm
DEPS=dataio.h
OBJ_NAME=dataio

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(COMPILER_FLAGS)
dataio: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
clean:
	rm $(OBJ_NAME)
