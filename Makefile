TARGET = strucit-backend

SRCS = strucit-backend.c lex.yy.c y.tab.c table_symboles.c

CFLAGS = -Wall -Wno-implicit-function-declaration
LDFLAGS = -lfl

CC = gcc
LEX = flex
YACC = yacc

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

lex.yy.c: ANSI-C.l y.tab.h
	$(LEX) $^

y.tab.c y.tab.h: structbe.y
	$(YACC) -d $^

table_symboles.o: table_symboles.c table_symboles.h
	$(CC) $(CFLAGS) -c table_symboles.c

clean:
	rm -f $(TARGET) lex.yy.c y.tab.c y.tab.h table_symboles.o

.PHONY: all clean
