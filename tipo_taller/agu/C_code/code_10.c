# include <stdio.h>
# include <stdlib.h>

void change_value (char *letter) 
{
    *letter = 't'; 
}

int main(int argc, char const *argv[])
{
    char *l = malloc(sizeof(char)); 
    if (l == NULL) 
    {
        fprintf(stderr, "Error de memoria \n");
        return 1;
    }
    *l = 'a';
    change_value(l);
    printf("%c\n", *l);
    free(l);
    return 0;
}
