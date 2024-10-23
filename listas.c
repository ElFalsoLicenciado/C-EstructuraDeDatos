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

int main();
void insertar_ord(int x);
void insertar(int x);
void eliminar(int x);
void vaciar();
void mostrar();

struct nodo *raiz = NULL;

/* Listas:
    Insertar elementos
    Sacar elementos
    Y insertado ordenado.
*/

int main()
{
    int c,i; 
    while(c != 0)
    {
        printf("\nListas dobles\n1. Meter con orden\n2. Meter sin orden\n3. Sacar\n4. Vaciar\n5. Mostrar\n0. Salir\n>>> ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("\nDame un numero: ");
            scanf("%d",&i);
            insertar_ord(i);
            mostrar();
            break;
        case 2:
            printf("\nDame un numero: ");
            scanf("%d",&i);
            insertar(i);
            break;
        case 3:
            printf("\nDame un numero: ");
            scanf("%d",&i);
            eliminar(i);
            break;
        case 4:
            vaciar();
            break;
        case 5:
            mostrar();
        case 0:
            break;
        default:
            printf("\nQue pedo.\n");
            break;
        }
    }
    return 1;
}


void insertar(int x)
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

void insertar_ord(int x)
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

void eliminar(int x)
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
    while(aux != NULL){
        printf("%d ", aux->valor); 
        aux = aux->sig;
    }
    printf("\n");
}