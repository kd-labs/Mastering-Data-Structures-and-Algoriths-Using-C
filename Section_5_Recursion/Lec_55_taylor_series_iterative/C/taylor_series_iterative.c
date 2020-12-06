# include <stdio.h>

double taylor_iterative(int x, int term) {
    double s = 1;
    double power_num = 1;
    double factorial_denom = 1;

    for(int i = 1; i<=term; i++) {
        power_num *= x;
        factorial_denom *= i;
        s += power_num/factorial_denom;
    }
    return s;
}

int main(int argc, char const *argv[])
{
    int x = 3, term = 20;
    printf("%lf", taylor_iterative(x, term));
    return 0;
}
