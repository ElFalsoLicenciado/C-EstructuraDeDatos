#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int buf_len; 
    printf("Buffer length: ");scanf("%d",&buf_len);
    int array[buf_len];     int maj = 0;
    for (int i =0; i<buf_len; i++)
    {
        int input;
        printf("Number #%d  array: ",i+1);
        scanf("%d",&array[i]);
        if (maj<array[i])
            maj = array[i];
        
    }
    for (int i = 0; i < buf_len; i++)
        printf("%d ",array[i]);
        
    printf("\n#1: %d",maj);
    
    

    return 0;
}
