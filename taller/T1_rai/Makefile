# Program name
BIN=main

# Compiler config
CC=gcc
CFLAGS=-std=gnu11 -Wunused -Wall -g -O0
LIB=-lc -lm

# Directories
SRC=src
LIBEDD=$(SRC)/libedd
SCRIPTS=.scripts
OBJ=.obj
TESTS=tests
OUTPUTS=outputs

# Sources
LIBEDD_OBJS=$(wildcard $(LIBEDD)/*.so)
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

# Rules
all: $(BIN)
	@echo "finished compilation"

clean:
	@if [ -d ./$(OBJ) ]; then rm -rf ./$(OBJ); fi
	@if [ -d ./$(OUTPUTS) ]; then rm -rf ./$(OUTPUTS); fi
	@if [ -f ./$(BIN) ]; then rm -f ./$(BIN); fi
	@echo "finished cleaning"

test: $(BIN)
	$(SCRIPTS)/run-tests.sh $(BIN) $(TESTS) $(OUTPUTS)

init_objs:
	@if [ ! -d ./$(OBJ) ]; then mkdir ./$(OBJ); fi

$(BIN): init_objs $(OBJS)
	$(CC) $(CFLAGS) $(LIB) $(LIBEDD_OBJS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(LIB) -c $< -o $@
