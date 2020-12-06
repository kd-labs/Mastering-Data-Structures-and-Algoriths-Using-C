# include <stdio.h>

int factorial(int n) {
    if ( n == 0) {
        return 1;
    }
    return factorial(n-1) * n;
}

int main(int argc, char const *argv[])
{
    int n = 8;
    printf("%d ", factorial(n));
    return 0;
}
