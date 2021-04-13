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

.PHONY: clean valgrind
clean:
	rm -rf $(OBJS) $(TARGET) *~
	rm valgrind-out.txt

valgrind:
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./$(TARGET)
