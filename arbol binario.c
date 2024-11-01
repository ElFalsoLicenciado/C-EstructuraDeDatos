#include <stdio.h>
#include <stdlib.h>

struct lemonTree
{
    int val;
    struct lemonTree *menor;
    struct lemonTree *mayor;
};

struct lemonTree *padre = NULL;

void meter(int val)
{
    struct lemonTree *aux;
    aux = malloc(sizeof(struct lemonTree));
    aux->val = val;
    aux->mayor = NULL;
    aux->menor = NULL;

    if(padre==NULL)
    {
        printf("\nNo hay nada. Se mete: %d\n",val);        
        padre = aux;
    }
    else
    {
        struct lemonTree *ant, *extra;
        ant = NULL;
        extra = padre;
        while(extra!=NULL)
        {
            ant = extra;
            if(val < extra->val)
                extra = extra->menor;
            else
                extra = extra->mayor;
        }
        if( val< ant->val)
            ant->menor = aux;
        else
            ant->mayor = aux;
    }
}

void borrar(int val)
{

}

void imPr(struct lemonTree *extra)
{
    if (extra != NULL)
    {
        printf("%d -",extra->val);
        imPr(extra->menor);
        imPr(extra->mayor);
    }
}


void imEn(struct lemonTree *extra)
{
    if (extra != NULL)
    {
        imEn(extra->menor);
        printf("%d ",extra->val);
        imEn(extra->mayor);
    }
    
}

void imPo(struct lemonTree *extra)
{
    if (extra != NULL)
    {
        imPo(extra->menor);
        imPo(extra->mayor);
        printf("%d",extra->val);
    }
    
}

void borrar(struct lemonTree *extra)
{
    if (extra != NULL)
    {
        borrar(extra->menor);
        borrar(extra->mayor);
        free(extra);
    }
}

void main()
{
    int opt = 1, aux;

    while(opt!=0)
    {
        printf("\n1.Meter\n2.Sacar\n0.Salir\n>>> ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                printf("\nDame un valor: ");
                scanf("%d",&aux);
                meter(aux);
                imEn(padre);
            break;

            case 2:
                printf("\nDame un valor: ");
                scanf("%d",&aux);
                borrar(aux);
            break;

            case 0:
                printf("\nSaliendo");
            break;

            default:
                printf("\nNada");
            break;
        }
    }
}
