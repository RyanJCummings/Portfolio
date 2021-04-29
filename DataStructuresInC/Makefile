# Makefile for data structures and algorithms practice #TARGET	= BinaryTree SingleLinkedList CC					= gcc
CFLAGS				= -ggdb -Wall
#SRCS				= $(wildcard *.c)
OBJS				= $(SRCS:.c=.o)
DEPS				= $(wildcard *.h)
VALGRIND_OPTIONS	= 	--leak-check=full \
						--show-leak-kinds=all \
         				--track-origins=yes \
         				--verbose 


all: BinaryTree SingleLinkedList

BinaryTree: $(OBJS)
	$(CC) $(CFLAGS) BinaryTree.c -o BinaryTree

SingleLinkedList: $(OBJS)
	$(CC) $(CFLAGS) SingleLinkedList.c -o SingleLinkedList

.PHONY: clean valgrind_bst valgrind_sll
clean:
	rm -rf $(OBJS) BinaryTree SingleLinkedList

valgrind_bst:
	valgrind $(VALGRIND_OPTIONS) \
         --log-file=valgrind-out-BinaryTree.txt \
         ./BinaryTree

valgrind_sll:
	valgrind $(VALGRIND_OPTIONS) \
		--log-file=valgrind-out-SingleLinkedList.txt \
	./SingleLinkedList

clean_valgrind:
	rm -rf *.txt
