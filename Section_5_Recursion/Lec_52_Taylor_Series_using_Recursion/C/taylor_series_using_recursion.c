# include <stdio.h>

double taylor_series_e(int x, int term) {
    static int power_num = 1, factorial_denom = 1;
    double result;

    //base case
    if(term == 0) {
        return 1;
    }
    result = taylor_series_e(x, term - 1);
    power_num *= x;
    factorial_denom *= term;
    return result + (power_num/factorial_denom);
}

int main(int argc, char const *argv[])
{
    int x = 3, term = 4;
    printf("%d ", taylor_series_e(x, term));
    return 0;
}
