# include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[4];
    int b[5] = {0};
    int c[5] = {1, 0};
    int d[4] = {2,3,4,5};
    int e[] = {1,3,4,5,6};

    for(int i = 0; i < 5; i++) {
        printf("%u\n", (e+i));
    }

    return 0;
}
