#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fgets_clean(char *buffer, int len)
{
    fgets(buffer,len,stdin);

    if (strchr(buffer, '\n') == NULL)
        while ((fgetc(stdin)) != '\n');

        buffer[strcspn(buffer, "\n")] = '\0';

        return buffer;
}

int main()
{
    char buffer[5];
    printf("Enter text 1: "); fgets_clean(buffer,5); printf("Text 1: %s\n",buffer); 

    printf("\nEnter text 2: "); fgets_clean(buffer,5); printf("Text 2: %s\n",buffer);  
    return 1;
}
