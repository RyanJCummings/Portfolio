# Makefile for data structures and algorithms practice

TARGET	= BinaryTree
CC		= gcc
CFLAGS	= -ggdb -Wall
SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
DEPS	= $(wildcard *.h)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

.PHONY: clean
clean:
	rm -rf $(OBJS) $(TARGET) *~
