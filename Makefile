COMPILER = gcc
FLAGS = -std=gnu11 -Wall -Werror

.PHONY: clean start all

all: bin/main

test: bin/main-test

-include build/*.d

bin/main: build/main.o build/board_print_html.o build/check.o build/move.o 
	$(COMPILER) $(FLAGS) -o $@ $^ 

build/main.o: sources/main.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<а

build/board_print_html.o: sources/board_print_html.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $<

build/check.o: sources/check.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< 

build/move.o: sources/move.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< 

-include build-test/*.d

bin/main-test: build-test/main.o build-test/move.o build-test/tests.o
	$(COMPILER) $(FLAGS) -o $@ $^

build-test/main.o: test/main.c
	$(COMPILER) -I thirdparty -I sources $(FLAGS) -MMD -c -o $@ $<

build-test/tests.o: test/tests.c
	$(COMPILER) -I thirdparty -I sources $(FLAGS) -MMD -c -o $@ $<

build-test/move.o: sources/move.c
	$(COMPILER) -I thirdparty -I sources $(FLAGS) -MMD -c -o $@ $<


start: bin/main
	bin/main

clean:
	rm build/*
