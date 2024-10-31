#include <stdio.h>
#include <stdlib.h>
#include "listasimple.h"

struct Simple
{
    int val;
    struct Simple* sig;
};

struct Simple* padre = NULL;
 
void inOrdeSi(int input)
{
    
    
}

void inPrinSi(int input)
{
    struct Simple* nuevaCabeza = crSimple(input);
    if (padre->sig == NULL)
    {
        padre->sig->val = padre->val; 
        padre->val = nuevaCabeza->val;
    }
}

void inUltiSi(int input)
{

}

void elDatoSi (int input)
{

}

void imSi()
{
    struct Simple *aux = padre;
    printf("\nList: ");
    while(aux != NULL){
        printf("%d ", aux->val); 
        aux = aux->sig;
    }
    printf("\n");
}

struct Simple* crSimple(int input)
{
    struct Simple* nuevoSimple = (struct Simple*)malloc(sizeof(struct Simple));
    nuevoSimple->val = input; nuevoSimple->sig =  NULL;
    return nuevoSimple;
}