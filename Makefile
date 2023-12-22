all:
	@mkdir -p bin
	gcc -Wall -Wextra -g -o bin/structs src/main.c
