#include <stdio.h>

int sum(int n) {
    if(n == 0)
        return 0;
    return sum(n-1) + n;
}

int sum_iteratively(int n) {
    int sum = 0;
    for(int i = 1; i<=n; i++) {
        sum += i;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n = 7;
    printf("%d\n", sum(n));
    printf("%d", sum_iteratively(n));
    return 0;
}
