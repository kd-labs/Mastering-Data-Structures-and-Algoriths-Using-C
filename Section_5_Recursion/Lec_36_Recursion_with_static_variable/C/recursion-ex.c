# include <stdio.h>

int fun(int n) {
/*
    funtion to calculate the sum of first n numbers
*/

    if (n > 0) {
        return fun(n-1) + n;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int x = 5;
    printf("%d ", fun(x));
    return 0;
}
