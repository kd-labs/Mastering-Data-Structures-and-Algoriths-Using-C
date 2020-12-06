# include <stdio.h>

int x = 0;

int fun(int n) {
/*
    funtion to calculate the sum of first n numbers
*/

    if (n > 0) {
        x++; // executed while calling
        return fun(n-1) + x; // addition of x is executed while returning
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int x = 5;
    printf("%d ", fun(x));
    return 0;
}
