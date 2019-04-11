COMPILER = gcc
FLAGS = -std=gnu11 -Wall -Werror

.PHONY: clean start all

all: bin/main


-include build/*.d

bin/main: build/main.o build/board_print_html.o build/check.o build/move.o 
	$(COMPILER) $(FLAGS) -o $@ $^ #Список всех зависимостей обрабатываемого правила

build/main.o: sources/main.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

build/board_print_html.o: sources/board_print_html.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

build/check.o: sources/check.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

build/move.o: sources/move.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила


start: bin/main
	bin/main

clean:
	rm build/*