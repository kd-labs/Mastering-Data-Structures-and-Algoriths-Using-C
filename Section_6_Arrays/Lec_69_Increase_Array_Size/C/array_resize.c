# include <stdio.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *p, *q;

    p = (int *)(malloc(5 * sizeof(int)));
    p[0] = 5;p[1] = 2;p[3] = 7;p[4] = 9; p[2] = 12;

    for(int i = 0; i < 5; i++) {
        printf("%d ", p[i]);
    }

    q = (int *) malloc(10 * sizeof(int));

    // copy elements of p in q
    for(int i = 0; i < 5; i++) {
        q[i] = p[i];
    }

    free(p);
    p = q;
    q = NULL;

    printf("\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", p[i]);
    }

    return 0;
}
