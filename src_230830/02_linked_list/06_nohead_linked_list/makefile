# * Author  : KeeneChen
# * Date    : 2023.08.28-09:43:36
# * Details : makefile for head linked list

CC = gcc
CFLAGS = -Wall -std=gnu11
TARGET := main
OBJ += main.o nohead_linked_list.o

$(TARGET):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY:
clean:
	rm -rf *.o main