#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int valor;
    struct nodo *sig;
    struct nodo *ant;
};

struct nodo *raiz = NULL;
int items;

int main();
void meter(int x);
void eliminar();
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
            eliminar();
            mostrar();
            break;
        case 3:
            vaciar();
            break;
        case 4:
            mostrar();
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
    struct nodo *Nodo, *aux;
    Nodo = (struct nodo*)malloc(sizeof(struct nodo));
    Nodo->valor = x;

    if(raiz==NULL)
    {
        raiz = Nodo;
        Nodo->sig = raiz;
        Nodo->ant = raiz;
    }
    else
    {
        aux = raiz->ant;
        Nodo->sig = raiz;
        Nodo->ant = aux;
        aux->sig = Nodo;
        raiz->ant = Nodo;
    }
    items++;
}

void eliminar()
{
    if(raiz == NULL)
    {
        printf("\nVacio.");
    }
    else
    {
        if(raiz->ant == raiz)
        {
            free(raiz);
            raiz = NULL;
        }
        else
        {
            struct nodo *end = raiz->ant;
            struct nodo *aux = end->ant;
            aux->sig = raiz;
            raiz->ant = aux;
            free(end);
        }
    }
    items--;
}

void vaciar()
{
    struct nodo *aux;
    while (raiz != NULL) {
        aux = raiz;
        raiz = raiz->sig;
        free(aux);
    }
}

void mostrar()
{
    struct nodo *aux = raiz;
    printf("\nList: ");
    for(int i = 0; i<items ; i++){
        printf("%d ", aux->valor); 
        aux = aux->sig;
    }
    printf("\n");
}
