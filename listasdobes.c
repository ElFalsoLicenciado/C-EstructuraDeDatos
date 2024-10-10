#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int valor;
    struct nodo *sig;
    struct nodo *pre;
};

struct nodo *raiz = NULL;

int main();
void meter(int x);
void eliminar(int x);
void vaciar();
void mostrar();


int main() {
    int c,i; 
    while(c != 0)
    {
        printf("\nListas dobles\n1. Meter\n2. Sacar\n3. Vaciar\n0. Salir\n>>> ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("\nDame un numero: ");
            scanf("%d",&i);
            meter(i);
            mostrar();
            break;
        case 2:
            printf("\nDame un numero: ");
            scanf("%d",&i);
            eliminar(i);
            break;
        case 3:
            vaciar();
            break;
        case 0:
            break;
        default:
            printf("\nQue pedo.\n");
            break;
        }
    }
    return 1;
}

void meter(int x)
{
    struct nodo *aux,*aux2;
    aux = (struct nodo*)malloc(sizeof(struct nodo));
    aux->valor = x; aux->sig = NULL; aux->pre = NULL;
    aux2 = raiz;


    if(raiz==NULL)
    {
        raiz == aux;
    }
    else //Enlazar el nodo nuevo y luego enlazar los demas.
    {
        while (aux2->sig->valor < x && aux2->sig!= NULL)
            aux2 = aux2->sig;

            aux->pre = aux2;
            aux->sig = aux2->sig;
            
            if(aux->sig != NULL)
                aux->sig->pre = aux;

            aux2->sig = aux;
        // aux->pre = raiz->valor;
        // raiz->sig = aux->valor;
    }
}

void eliminar(int x)
{
    struct nodo *aux;
    aux = raiz;

    while (aux->valor != x && aux->sig != NULL)
        aux = aux->sig;
    
    if(aux == raiz)
    {
        aux->pre = NULL;
        raiz = aux->sig;
        free(aux);
    }

    if(aux->sig == NULL) printf("\nNo encontrado.\n");
    else
    {
        if(aux->sig != NULL)
            aux->sig->pre = aux->pre;

        aux->pre->sig = aux->sig;
        free(aux);
    }
}

void vaciar()
{
    raiz = NULL;
}

void mostrar()
{
    struct nodo *aux = raiz;
    printf("\nList: ");
    while(aux != NULL){
        printf("%d ", aux->valor); 
        aux = aux->sig;
    }
    printf("\n");
}
