CC=gcc
SRC=src/main.c
BIN=bin/dectobin

all:
	mkdir bin
	$(CC) -Wall $(SRC) -o $(BIN)
