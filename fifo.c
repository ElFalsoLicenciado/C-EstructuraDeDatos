#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 7

/* char *fgets_clean(char *buffer, int len)
{
    fgets(buffer,len,stdin);

    if (strchr(buffer, '\n') == NULL)
        while ((fgetc(stdin)) != '\n');

        buffer[strcspn(buffer, "\n")] = '\0';

        return buffer;
}
*/

int Arre[M] = {0}; 
int ind, end = 0;

void meter(int input);
void sacar();
void recorrer();
void limpiar();
void mostrar();
void menu();
// void special();


int main()
{
    /* Tipos de colas
    FIFO y LIFO 
    FIFO: Recorrer elementos*/
    menu();
}

void menu()
{
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
            limpiar();
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
}

void meter(int input)
{
    if(ind == 0 && end == M)
    {
        printf("\nCola llena.");
    }
    else
    {
        if(end == M)
        {
            recorrer();
            Arre[end] = input;
            // printf("\n ind %d end %d \n",ind,end);
            // special();
        }
        else
            {Arre[end] = input;}
        end++;
    }   
}

void sacar()
{   
    int desertor;
    if(ind!=end)
    {
        desertor = Arre[ind];
        Arre[ind] = 0;
        ind ++;

        if(ind == end)
        {
            ind = 0; end = 0;
        }
        printf("\nSacaste a %d",desertor);
    }else
    {
        printf("\nCola vacia.");
    }
}

void recorrer()
{
    int aux = 0;
    printf("\n***Reordering***\n");
    while (ind < end)
    {
        Arre[aux] = Arre[ind];
        Arre[ind] = 0;
        //printf("\n aux %d ind %d \n",aux,ind);
        aux ++;
        ind ++;
        //special();
    }
    end = aux; //Ojo, en vez de ser ind es aux por que si ya sacaste todos ind estaria casi al tope y pues vale verdura. Pero aux se queda en la ultima posicion.
    ind  = 0;
}

void limpiar()
{
    for (int i = 0; i < M; i++)
        Arre[i] = 0;
    ind = 0; end = 0; 
}

void mostrar()
{
    if(ind==end)
        printf("\nLa cola esta vacia.");
    else
    {
        printf("\nCola: ");
        for (int i = ind; i < end; i++)
            printf("%d ",Arre[i]);
    }
    printf("\nind: %d end: %d",ind,end);
    printf("\n");
}

/*void special()
{
    printf("\nSeguimiento: ");
    for (int i = 0; i < M; i++)
    {
        printf("%d ",Arre[i]);
    }
    printf("\n");
}*/