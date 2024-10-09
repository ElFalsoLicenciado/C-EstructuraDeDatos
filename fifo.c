#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5

/* char *fgets_clean(char *buffer, int len)
{
    fgets(buffer,len,stdin);

    if (strchr(buffer, '\n') == NULL)
        while ((fgetc(stdin)) != '\n');

        buffer[strcspn(buffer, "\n")] = '\0';

        return buffer;
}
*/

int Arre[M]; 
int ind = 0;
int end = 0;

int main()
{
    /* Tipos de colas
    FIFO y LIFO 
    FIFO: Recorrer elementos*/
    int flag = 1;
    while(flag)
    {
        printf("\nColas\n1. Meter\n2. Sacar\n3. Vaciar\n4. Mostrar\n0. Salir\nInput: ");
        int i; scanf("%d",&i);
        printf("\n");
        switch (i)
        {
        case 1:
            printf("Introduce un numero: "); scanf("%d",&i);
            meter(i);
            mostrar();
            break;

        case 2:
            sacar();
            mostrar();
            break;
        case 3:
            vaciar();
            mostrar();
            break;
        case 4:
            mostrar();
            break;
        case 0:
            flag = 0;
            break;
        default:
            break;
        }

    }
    return 1;
}

void meter(int input)
{
    if(ind<M)
    {
        Arre[ind]=input;
        ind++;
    }
    else
    {
        printf("Cola llena.");
    }
}

void sacar()
{
    int aux;
    if(ind > 0)
    {
        aux = Arre[ind];
        recorrer();
    }
}

void recorrer()
{
    int aux = 0;

    while (aux<ind)
    {
        Arre[aux] = Arre[aux+1];
        aux++; 
    }
    ind--;
}

void vaciar()
{
    for (int i = 0; i < M; i++)
        Arre[i] = NULL;
    ind = 0;
}

void mostrar()
{   
    if(ind>0)
    {
        printf("\nCola: ");
        for (int i = 0; i < ind; i++)
            printf("%d ",Arre[i]);
        printf("\n");
    }else
        printf("Cola vacia.\n");
}