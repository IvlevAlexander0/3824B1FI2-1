#define _USE_MATH_DEFINES
#include <math.h>
#include "functions.h"
#define ull long long unsigned int
#define eps 1e-10

long double lab_cos(long double x, int *n, long double pres){
    int sign = 1;
    x = x - (int)(x / (2 * M_PI)) * (2* M_PI);
    x = fabs(x);
    if (x > M_PI){
        sign *= -1;
        x = x - M_PI;
    }
    if (x > M_PI_2){
        x = x - M_PI_2;
        sign *= -1;
        return sign * lab_sin(x, n, pres);
    }
    if(x > M_PI_4){
        x = M_PI_2 - x;
        return sign * lab_sin(x, n, pres);
    }
    long double res = 1;
    long double cur = 1;
    unsigned i = 1;
    for(; i <= *n && fabs(cur) > pres; i++){
        cur *= (-1 * x*x) / (2 * i * (2 * i - 1));
        res += cur;
    }
    *n = i-1;
    return sign * res;
}

long double lab_sin(long double x, int *n, long double pres){
    int sign = 1;
    if (x < 0) {
        x *= -1;
        sign *= -1;
    }
    //printf("%lf\n", M_PI);
    x = x - (int)(x / (2 * M_PI)) * (2* M_PI);//делаем так, что x < 2*M_PI
    if (x > M_PI){
        sign *= -1;
        x = x - M_PI;
    }
    if(x > M_PI_2){
        x = x - M_PI_2;
        return sign * lab_cos(x, n, pres);
    }
    if(x > M_PI_4){
        x = M_PI_2-x;
        return sign * lab_cos(x, n, pres);
    }
    long double res = x;
    long double cur = x;
    unsigned i = 1;
    for(; i <= *n && fabs(cur) > pres; i++){
        cur *= -1 * x * x / (2 * i * (2 * i + 1));
        //printf("%1.19Lf + (%d * %1.19Lf) / %d = %1.19Lf + %1.19Lf = ", res, sign, pow, factorial, cur, res);
        res += cur;
        //printf("%1.19Lf\n", res);
    }
    *n = i-1;
    res = res * sign;
    return res;
}

long double lab_exp(long double x, int* n, long double pres) {
    long double res = 1;
    long double cur = 1;
    int i = 1;
    for (; i <= *n && fabs(cur) > pres; i++) {
        cur *= x / (i);
        res += cur;
    }
    *n = i-1;
    return res;
}

long double lab_arcsin(long double x, int* n, long double pres) {
    long double res = x;
    long double cur = x;
    cur *= (x * x * 1) / 2;
    res += cur/3;
    if (*n == 1) return res;
    unsigned i = 2;
    for (; i <= *n && fabsl(cur) > pres; i++) {
        //printf("(%Lf*%Lf * %u)/(%u * %u ) = %Lf\n", x, x, (2 * (i + 1) - 1), (2 * (i + 1)), (2 * i + 1), (x * x * (2 * (i + 1) - 1)) / ((2 * (i + 1)) * (2 * i + 1));
        cur *= (x * x * (2 * i - 1)) / (2 * i);
        res += cur/ (2 * i + 1);
    }
    *n = i-1;
    return res;
}
