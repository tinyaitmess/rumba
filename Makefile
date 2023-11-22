CC=gcc
CFLAGS=-std=c99 -Wextra -Wall  -pedantic
LDFLAGS=-lm

ifeq ($(DEBUG),yes)
	CFLAGS += -g
	LDFLAGS +=
else
	CFLAGS += -O3 -DNDEBUG
	LDFLAGS +=
endif

EXEC=main
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all:
ifeq ($(DEBUG),yes)
	@echo "Generating in debug mode"
else
	@echo "Generating in release mode"
endif
	@$(MAKE) $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC) documentation/html

doc: rng.h skiplist.h
	@doxygen documentation/TP4


tests : $(EXEC)
	@$(BASH) ../Test/test_script.sh $(EXEC)

etat.o : etat.h stack.h
stack.o : stack.h
main.o : stack.h etat.h
doc : stack.h etat.h

DELIVER_FMT=$(shell date "+$(shell id -un)_%d-%m-%y_%Hh%Mm%Ss")

deliver:
	zip -r $(DELIVER_FMT).zip .

