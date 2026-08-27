# include <stdio.h>
# include <stdbool.h>

int main(int argc, char const *argv[])
{
    int numero;
    int *point1 = &numero;

    printf("%i", &point1);
    return 0;
}

