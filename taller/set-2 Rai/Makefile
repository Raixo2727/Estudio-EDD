# Program Name
BIN=set-2

# Compiler config
CC=gcc
CFLAGS=-std=gnu11 -Wunused -Wall -g -O0
LIB=-lc -lm

# Directories
SRC=src
OBJ=.obj
DEP=.hdeps
LIBEDD=$(SRC)/libedd
SCRIPTS=.scripts
TESTS=tests

# Dependency flags
DEPFLAGS=-MMD -MF $(DEP)/$*.d

# Sources
LIBEDD_OBJS=$(wildcard $(LIBEDD)/*.so)
SRCS=$(wildcard $(SRC)/*.c)
DEPS=$(patsubst $(SRC)/%.c, $(DEP)/%.d, $(SRCS))
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

# Rules
all: $(BIN)
	@echo "finished compilation"

clean:
	@if [ -d ./$(OBJ) ]; then rm -rf ./$(OBJ); fi
	@if [ -d ./$(DEP) ]; then rm -rf ./$(DEP); fi
	@if [ -f ./$(BIN) ]; then rm -f ./$(BIN); fi
	@echo "finished cleaning"

test: $(BIN)
	$(SCRIPTS)/run-tests.sh $(BIN) $(TESTS)

init_deps:
	@if [ ! -d ./$(DEP) ]; then mkdir ./$(DEP); fi

init_objs: init_deps
	@if [ ! -d ./$(OBJ) ]; then mkdir ./$(OBJ); fi

$(BIN): init_objs $(OBJS)
	$(CC) $(CFLAGS) $(LIB) $(LIBEDD_OBJS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(DEPFLAGS) $(LIB) -c $< -o $@
-include $(DEPS)
