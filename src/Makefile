PROJECT_NAME = conways_game_of_life
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OS = $(shell uname -s)

ifeq ($(OS), Darwin)
	RUN_CMD = sh
	ADD_FLAGS = -lncurses
endif

ifeq ($(OS), Linux)
	RUN_CMD = bash
	ADD_FLAGS = -lncurses
endif

build:
	$(CC) $(CFLAGS) $(PROJECT_NAME).c -o $(PROJECT_NAME) $(ADD_FLAGS)

run: build
	$(RUN_CMD) run.sh

clang:
	clang-format -n *.c *.h

clang-replace:
	clang-format -i *.c *.h

clean:
	rm $(PROJECT_NAME)
	clear
