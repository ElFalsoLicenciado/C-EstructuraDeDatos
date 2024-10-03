#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct n
{
    int num;
    struct n *nex;
};


struct n *root = NULL;

void push()
{
    int input;  
    struct n *new = (struct n*)malloc(sizeof(struct n)), *aux, *prev = NULL;

    printf("\nInt to input: ");
    scanf("%d", &input);  
    new->num = input; 
    new->nex = NULL;

    if (root == NULL) {
        root = new;
    } else {
        aux = root;

      
        while (aux != NULL && (aux->num) < (input)) {
            prev = aux;  
            aux = aux->nex;  
        }

        if (prev == NULL) {
           
            new->nex = root;
            root = new;
        } else {
           
            prev->nex = new;
            new->nex = aux;
        }
    }
}

void pop()
{
    struct n *aux, *prev; aux = root;

    if(root == NULL)
    {
        printf("\nNothing to pop.");
    } else if (root->nex == NULL)
    {
        free(root); root = NULL;
    } else
    {
        while (aux->nex != NULL)
        {
            prev = aux; aux = aux->nex;
        }
        
        root->num;
        free(aux); prev-> nex = NULL;
    }
}

void show()
{
    struct n *aux = root;
    printf("\nList: ");
    while(aux != NULL){
        printf("%d ", aux->num); 
        aux = aux->nex;
    }
}

void main()
{
    int opt;
    do{
        printf("\nDynamic stacks\n1. Push\n2. Pop\n3. Show\n0. Quit\n--> ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 0: 
            printf("Quitting");
            break;
        case 1:
            push();
            show();
            printf("\n");
            break;
        case 2: 
            pop();
            show();
            printf("\n");
            break;1
            
        case 3:
            show();
            printf("\n");
            break;
        default:
            printf("Huh");
        }

    }while(opt!=0);
}