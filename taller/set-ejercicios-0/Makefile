CC=gcc
CFLAGS=-std=gnu11 -Wunused -Wall -g -O0
LIB=-lc

SRC=src
OBJ=obj
LIBEDD=libedd
BIN=set-0

LIBEDD_OBJS=$(wildcard $(LIBEDD)/*.so)
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

all: $(BIN)
	@echo "finished compilation"

clean:
	@if [ -d ./$(OBJ) ]; then rm -rf ./$(OBJ); fi
	@if [ -f ./$(BIN) ]; then rm -f ./$(BIN); fi
	@echo "finished cleaning"

init_objs:
	@if [ ! -d ./$(OBJ) ]; then mkdir ./$(OBJ); fi

$(BIN): init_objs $(OBJS)
	$(CC) $(CFLAGS) $(LIB) $(LIBEDD_OBJS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(LIB) -c $< -o $@ $(LIB)
