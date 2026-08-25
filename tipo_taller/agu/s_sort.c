# include <stdio.h>
# include <stdbool.h>

void agregar(array, j) {
    return;
}

int main()
{


    int array[] = {1,6,6,2,0,1,4};
    int n = sizeof(array)/sizeof(array[0]);
    int array_2[] = {};

    while (n > 0) {
        int min = array[0];
        for (int j = 0; j < n-1; j++)   
            {
            if  (array[j] <= min) 
                {
                agregar(array_2, array[j]);
                n--;
                break;
                    }

            }
        }
    return 0;

}
