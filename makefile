CC=gcc
SRC=src/main.c
BIN=bin/dectobin
FLAGS=
STD=

all:
	$(CC) -Wall $(SRC) $(FLAGS) -o $(BIN) $(STD)
