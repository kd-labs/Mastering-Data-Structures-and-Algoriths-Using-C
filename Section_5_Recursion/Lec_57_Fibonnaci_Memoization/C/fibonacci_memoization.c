# include <stdio.h>

int F[7];

int fib_memoization(int n) {
    if(n <= 1) {
        return n;
    } else {
        if(F[n-2] == -1)
            F[n-2] = fib_memoization(n-2);
        if(F[n-1] == -1)
            F[n-1] = fib_memoization(n-1);
        return F[n-2] + F[n-1];
    }
}

int fib(int n) {
    int t0 = 0, t1 = 1, s=0;

    for(int i = 2; i <= n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int fib_recursive(int n) {
    if(n <= 1) return n;
    return fib(n-2) + fib(n-1);
}

int main(int argc, char const *argv[])
{

    for(int i = 0; i < 10; i++){
        F[i] = -1;
    }
    int n = 5;
    printf("%d\n", fib_memoization(n));
    printf("%d\n", fib(n));
    printf("%d", fib_recursive(n));
    return 0;
}
