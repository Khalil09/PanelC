ROOT=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

IDIR=src/include
CC=gcc
CFLAGS= -std=gnu11 -Wall -Wextra -pedantic -g

ODIR=obj
LDIR=src/

LIBS=-lm -I $(IDIR)

_DEPS = nodes.h showTree.h uthash.h ustack.h headerSyntactic.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# _OBJS = showTree.o nodes.o
# OBJS = $(patsubst %,$(ODIR)/%,$(_OBJ))

# $(ODIR)/%.o: $(LDIR)/%.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)

bin/panelc: $(OBJ) src/syntactic_analyzer.y src/lexical_analyzer.l
	bison -vd src/syntactic_analyzer.y --output=src/panelc_parser.c
	flex -o src/panelc_lex.c src/lexical_analyzer.l
	$(CC) -o $@ src/nodes.c src/showTree.c src/panelc_parser.c src/panelc_lex.c $(CFLAGS) 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	rm -f bin/panelc
