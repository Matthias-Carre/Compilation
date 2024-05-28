pour executer le frontend:

make

./intermediaire.c "fichierdetest.c" -o fichierdesortie

pour executer le backend

lex ANSI-C.l && yacc -d structbe.y && gcc lex.yy.c y.tab.c -o sortiebe

cat fichierdesortie.txt | ./sortiebe