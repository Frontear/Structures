CC := gcc
CFLAGS := -Wall -Wextra -g

BIN_PATH := bin
OBJ_PATH := obj
SRC_PATH := src

TARGET := ${BIN_PATH}/structs

SRC_FILES := $(wildcard ${SRC_PATH}/*.c)
OBJ_FILES := $(addprefix ${OBJ_PATH}/, $(notdir ${SRC_FILES:.c=.o}))

.PHONY: all clean

all: ${OBJ_FILES}
	@mkdir -p ${BIN_PATH}
	@${CC} ${CFLAGS} -o ${TARGET} ${OBJ_FILES}

clean:
	@rm -rf ${BIN_PATH} ${OBJ_PATH}

${OBJ_PATH}/%.o: ${SRC_PATH}/%.c
	@mkdir -p ${OBJ_PATH}
	@${CC} ${CFLAGS} -c -o $@ $<
