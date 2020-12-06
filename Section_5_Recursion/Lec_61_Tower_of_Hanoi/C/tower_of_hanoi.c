# include <stdio.h>

int TOH(int n, int a, int b, int c) {
    if(n > 0) {
        TOH(n-1, a, c, b);
        printf("moving disk from %d to %d\n", a, c);
        TOH(n-1, b, a, c);
    }
}

int main(int argc, char const *argv[])
{
    int n = 3, a = 1, b = 2, c = 3;
    TOH(n, a, b, c);
    return 0;
}
