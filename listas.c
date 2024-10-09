#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* char *fgets_clean(char *buffer, int len)
{
    fgets(buffer,len,stdin);

    if (strchr(buffer, '\n') == NULL)
        while ((fgetc(stdin)) != '\n');

        buffer[strcspn(buffer, "\n")] = '\0';

        return buffer;
}
*/

struct nodo
{
    int valor;
    struct nodo *sig;
};

insertar_ord(int x);
insertar(int x);
eliminar(int x);


struct nodo *raiz = NULL;

/* Listas:
    Insertar elementos
    Sacar elementos
    Y insertado ordenado.
*/

int main()
{

    return 1;
}


insertar(int x)
{
    struct nodo *aux;
    aux = (struct nodo*)malloc(sizeof(struct nodo));

    if(raiz == NULL)
    {
        raiz = aux;
    }
    else
    {
        
    }
}

insertar_ord(int x)
{
    struct nodo *aux,*aux2;

    aux = (struct nodo*)malloc(sizeof(struct nodo));
    aux->valor = x; aux->sig=NULL;

    if(raiz == NULL)
    {
        raiz = aux;
    }
    else 
    {
        if(x<raiz->valor)
        {
            aux->sig = raiz->sig;
            raiz = aux;
        }else
        {
            aux2 = raiz;

            while (aux2->valor < x && aux2->sig->valor < x && aux2->sig != NULL)
            {
                aux->sig = aux2->sig;
                aux2->sig = aux;
            }
            
        }

    }
}

eliminar(int x)
{
    struct nodo *aux; aux = raiz;
    
    if (raiz->valor == x)
    {
        raiz = raiz->sig; free(aux);
    }
    else
    {
        while(aux->sig->valor != x && aux->sig != NULL)
            aux = aux->sig;

        if(aux->sig == NULL) printf("No existe el elemento %d",x);
        else
        {
            aux->sig = aux->sig->sig;
            aux = aux->sig;
            free(aux);
        }
    }
}