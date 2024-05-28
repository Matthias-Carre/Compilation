#include "filegestion.h"

void printtablignes(Filechar* t){
    for(int i=0;i<(t->nbrlignes);i++){
        printf("Tab[%d]:%s\n",i,t->tab[i]);
    }
}
void addline(Filechar* f,char* chaine){
    
    f->tab[(f->nbrlignes)]=chaine;
    f->nbrlignes++;
    }
void setinfile(Filechar* fc,char* namefileout){
    FILE *fichier;
    const char *fichierout = "out.txt";
    fichier=fopen(fichierout,"w");

    for(int i=0;i<fc->nbrlignes;i++){
        fprintf(fichier,fc->tab[i]);
        fprintf(fichier,"\n");
    }

    fclose(fichier);
}
void setlignenplushaut(Filechar* fc,char* ligne,int n){
    char* tmp;
    int taille=fc->nbrlignes;
    for(int i=0;i<n;i++){
        fc->tab[taille-i]=fc->tab[taille-i-1];

    }
    fc->tab[taille-n]=ligne;
    fc->nbrlignes++;
    
}

/*
int main(){
    Filechar* fc;
    fc= malloc(sizeof(Filechar));
    fc->nbrlignes=0;

    addline(fc,"Test");
    addline(fc,"Change");
    addline(fc,"tft");
    addline(fc,"lol");
    printtablignes(fc);
    printf("Suivant\n\n");
    setlignenplushaut(fc,"LA VIE",2);
    printtablignes(fc);
    setinfile(fc,"oui");

}*/
