CC=gcc
CFLAGS=-std=c11 -O2 -Os -W -Wall -Werror -Wextra \
	   -pedantic -Wshadow -Wstrict-overflow -fno-strict-aliasing \
	   -fsanitize=address -fsanitize=float-divide-by-zero \
	   -fsanitize=float-cast-overflow -fno-sanitize-recover=all \
	   -fstack-protector-all -Wfloat-equal -Wconversion -Wlogical-op \
	   -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align \
	   -Wno-unused-result -Wno-sign-conversion
LIBS=

.PHONY: test run clean

main: main.c
	$(CC) $(LIBS) $(CFLAGS) -o main main.c

test: clean main input_test
	./main < input_test

run: clean main input
	./main < input

clean:
	rm -f main
