# include <stdio.h>
# include<stdlib.h>

int main(int argc, char const *argv[])
{
    // Method 1 to create 2D Array
    int a[3][4] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    // Method 2 to create 2D Array
    int *b[3]; // array of 3 int pointers created in stack frame of main
    for(int i = 0; i < 3; i++) {
        b[i] = (int *) malloc(4 * sizeof(int));
    }

    // Method 3 to create 2D Array
    int **c; // pointer to pointer
    c = (int **) malloc(3 * sizeof(int *));
    for(int i = 0; i < 3; i++) {
        c[i] = (int *) malloc(4 * sizeof(int));
    }

    /******************Below code is to access the elements of array ********************/

    for(int i = 0 ; i < 3 ; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
