#include <math.h>
#define ull unsigned long long

long double lab_arcsin(long double x, int *n, long double pres){
    long double res = x;
    long double pow = x*x*x;
    long double cur = x;
    ull factorial = 1;
    ull factorial2 = 2;
    int i = 1;
    for(; i <= *n && fabsl(cur) > pres; i++){
        //printf("(%Lf*%llu)/(%llu*%d) = %Lf\n", pow, factorial, factorial2, (2 * i + 1), (pow * factorial) / (factorial2 * (2 * i + 1)));
        cur = (pow * factorial) / (factorial2 * (2 * i + 1));
        res += cur;
        pow *= x*x;
        factorial *= 2*(i+1)-1;
        factorial2 *= 2*(i+1);
    }
    *n = i;
    return res;
}