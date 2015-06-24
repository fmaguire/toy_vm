SRCDIR := src
SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
TARGET := bin/vm

CC := gcc
CC_FLAGS := -Wall -Wextra -g -std=c11

all:
	${CC} ${SOURCES} ${CC_FLAGS} -o ${TARGET}
