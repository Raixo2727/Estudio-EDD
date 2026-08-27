# include <stdio.h>
#include <stdbool.h>
int main()
{
    int cats_in_the_room = 5;
    cats_in_the_room++;
    cats_in_the_room++;
    printf("%d\n", cats_in_the_room);

    printf("%d\n", 10 == 10); // Prints 1 (true), because 10 is equal to 10
    printf("%d\n", 10 == 15); // Prints 0 (false), because 10 is not equal to 15
    printf("%d\n", 5 == 55);

    int edadRamirez;

    // Ask the user to type a number
    printf("Type Ramirez's age: \n");

    // Get and save the number the user types
    scanf("%d", &edadRamirez);

    printf("Ramirez tiene: %d\n", edadRamirez);
    return 0;
}
