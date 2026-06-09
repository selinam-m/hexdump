# Makefile for this project

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c11
TARGET = hexdump
SOURCES = hexdump.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

.PHONY: clean
clean:
	rm -f $(TARGET)
