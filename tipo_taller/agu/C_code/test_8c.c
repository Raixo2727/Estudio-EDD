#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // malloc, calloc and free()

int main()
{
    char oye[] = "hello bro";

    printf("%s\n",oye);
    for (int i = 0; i < 7; i++) 
    {
        printf("%c\0", oye[i]);

    }
    /* code */
    return 0;
}
