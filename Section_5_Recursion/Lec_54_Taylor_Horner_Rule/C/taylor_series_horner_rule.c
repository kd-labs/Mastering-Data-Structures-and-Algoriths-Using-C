# include <stdio.h>

double taylor_horner(int x, int term) {
    static double s = 1;
    if(term == 0) {
        return s;
    }
    s = 1 + ((x*s/term));
    return taylor_horner(x, term - 1);
}

int main(int argc, char const *argv[])
{
    int x = 1, term = 10;
    printf("%lf ", taylor_horner(x, term));
    return 0;
}
