SHELL := /bin/sh

CC=gcc
SRC=src/main.c
BIN=bin/dectobin
FLAGS=
STD=

all:
	mkdir bin
	$(CC) -Wall $(SRC) $(FLAGS) -o $(BIN) $(STD)
