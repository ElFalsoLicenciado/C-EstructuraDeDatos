#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int valor;
    struct nodo *sig;
    struct nodo *pre;
};

struct nodo *raiz = NULL;

meter(int x);
eliminar(int x);
mostrar();

meter(int x)
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
        {
            aux2 = aux2->sig;
        }
        
        aux->pre = raiz->valor;
        raiz->sig = aux->valor;
    }
}

mostrar()
{

}