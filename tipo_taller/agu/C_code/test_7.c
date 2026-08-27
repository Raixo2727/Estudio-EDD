#include <stdio.h>
#include <stdbool.h>

int main()
{
    int array_1[] = {1, 4, 5, 7, 3, 5, 6, 7, 8} ;

    // Source - https://stackoverflow.com/q/72844649
    // Posted by Isto Vilhola, modified by community. See post 'Timeline' for change history
    // Retrieved 2026-08-07, License - CC BY-SA 4.0
    size_t len = sizeof(array_1) / sizeof(array_1[0]);
    // -
    printf("lenght : %d\n", len);

    for (int a = 0; a<len; a++) {
        
        printf("--->%d\n", array_1[a]);
    }
    
    return 0;
}
