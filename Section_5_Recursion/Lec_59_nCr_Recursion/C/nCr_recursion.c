# include <stdio.h>

int nCr_recursion(int n, int r) {
    if(r == 0 || r == n) {
        return 1;
    }
    return nCr_recursion(n-1, r-1) + nCr_recursion(n-1, r);
}

int main(int argc, char const *argv[])
{
    int n = 4, r = 2;
    printf("%d", nCr_recursion(n, r));
    return 0;
}
