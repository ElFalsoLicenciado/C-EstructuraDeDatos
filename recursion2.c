#include <stdio.h>

int main();
int ejer_1(int x);
int ejer_2(int x);
int ejer_3(int num, int pow, int res);
int ejer_3o(int num, int pow);
int ejer_4(int num, int ite);
int ejer_4aux(int a, int b);

int main()
{
    ejer_1(6); printf("\n");
    ejer_2(5342); printf("\n");
    ejer_3(4,3,1); printf("\n");
    printf("%d\n",ejer_3o(4,3)); 
    printf("%d\n",ejer_4(5,3)); 
    
}

int ejer_1(int x)
{
    if(x==0)
        return 0;
    else
    {   
        printf( "%d ", x);
        return ejer_1(x-1);
    }
}

int ejer_2(int x)
{
    if(x<10)
        return x;
    else
    {   
        printf("%d ", x);
        return ejer_2(x/10);
    }
}

int ejer_3(int num, int pow, int res)
{
    if(pow == 0)
        return 0;
    else
    {
        res =  res * num ;
        printf("%d ", res);
        return ejer_3(num,pow-1,res);
    }
}

int ejer_3o(int num, int pow)
{
    if(pow > 1)
        return num * ejer_3o(num,pow-1);
}

int ejer_4(int num, int ite)
{
    if(ite == 1) return num;

    if(ite>1)
    return ejer_4aux(num,ejer_4(num,ite-1));
}

int ejer_4aux(int a, int b)
{
    if(b == 0) return 0;

    return a + ejer_4aux(a, b-1);
}