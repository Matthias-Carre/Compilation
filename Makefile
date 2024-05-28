TARGET = sortie

SRCS = lex.yy.c y.tab.c table_symboles.c filegestion.c

CFLAGS = -Wall -Wno-implicit-function-declaration
LDFLAGS = -lfl

CC = gcc
LEX = flex
YACC = yacc

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

lex.yy.c: ANSI-proj.l y.tab.h
	$(LEX) ANSI-proj.l

y.tab.c y.tab.h: structfe.y
	$(YACC) -d structfe.y

table_symboles.o: table_symboles.c table_symboles.h
	$(CC) $(CFLAGS) -c table_symboles.c

filegestion.o: filegestion.c filegestion.h
	$(CC) $(CFLAGS) -c filegestion.c

clean:
	rm -f $(TARGET) lex.yy.c y.tab.c y.tab.h table_symboles.o filegestion.o

.PHONY: all clean
