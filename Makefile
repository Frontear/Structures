CC := gcc
CFLAGS := -Wall -Wextra

BIN_PATH := bin
OBJ_PATH := obj
SRC_PATH := src

TARGET := ${BIN_PATH}/structs

SRC_FILES := $(wildcard ${SRC_PATH}/*)
OBJ_FILES := $(addprefix ${OBJ_PATH}/, $(notdir ${SRC_FILES:.c=.o}))

.PHONY: all clean debug

all: ${OBJ_FILES}
	@mkdir -p ${BIN_PATH}
	@${CC} ${CFLAGS} -O3 -s -o ${TARGET} ${SRC_FILES}

clean:
	@rm -rf ${BIN_PATH} ${OBJ_PATH}

debug:
	@mkdir -p ${BIN_PATH}
	@${CC} ${CFLAGS} -g -o ${TARGET} ${SRC_FILES}

${OBJ_PATH}/%.o: ${SRC_PATH}/%.c
	@mkdir -p ${OBJ_PATH}
	@${CC} ${CFLAGS} -c -o $@ $<
