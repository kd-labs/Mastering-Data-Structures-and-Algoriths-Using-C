# include <stdio.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a[5] = {1,2,3,4,6};
    int * p;
    p = (int *) malloc(sizeof(int) * 5);

    p[0] = 4;
    p[1] = 2;
    p[2] = 6;
    p[3] = 4;
    p[4] = 9;

    for(int i = 0; i < 5; i++) {
        printf("%d ", p[i]);
    }
    return 0;
}
