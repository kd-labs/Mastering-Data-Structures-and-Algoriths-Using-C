# include <stdio.h>

int power(int base, int p) {
    if(p == 0)
        return 1;
    return base * power(base,p - 1);
}

int power_optimized(int base, int p) {

    // base case
    if(p == 0)
        return 1;
    
    // recursive case
    if(p % 2 == 0) {
        // if power is even, then
        // pow(m, n) = pow(m*m, n/2)
        return power_optimized(base*base, p/2);
    } else {
        // if power is odd, then
        // pow(m, n) = m * pow(m*m, n-1/2)
        return base * power_optimized(base*base, (p-1)/2);
    }
}

int main(int argc, char const *argv[])
{
    int base = 3;
    int p = 9;
    printf("%d\n", power(base, p));
    printf("%d ", power_optimized(2, 9));
    return 0;
}
