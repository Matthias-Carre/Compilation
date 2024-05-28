#include <stdio.h>
#include <stdlib.h>

typedef struct Filechar{
    int nbrlignes;
    char* tab[200];
}Filechar;

void printtablignes(Filechar* t);
void addline(Filechar* f,char* chaine);
void setinfile(Filechar* fc,char* namefileout);
void setlignenplushaut(Filechar* fc,char* ligne,int n);

