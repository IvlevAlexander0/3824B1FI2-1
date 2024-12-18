#include <math.h>
#define ull unsigned long long


long double lab_exp(long double x, int *n, long double pres){
    long double res = 0;
    long double pow = 1;
    long double cur = 1;
    ull factorial = 1;
    int i = 0;
    for (; i <= *n && fabs(cur) > pres; i++) {
        if (i > 1) {
            factorial *= i;
        }
        cur = (pow) / (factorial);
        res += cur;
        pow *= x;
    }
    *n = i;
    return res;
}
