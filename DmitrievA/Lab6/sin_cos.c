#define _USE_MATH_DEFINES
#include <math.h>
#include "sin_cos.h"
#define ull long long unsigned int
#define eps 1e-10

long double lab_cos(long double x, int *n, long double pres){
    long double res = 0;
    long  double pow = 1;
    long double cur = 1;
    int sign = 1;
    ull factorial = 1;
    x = x - (int)(x / (2 * M_PI)) * (2* M_PI);
    if (x > M_PI){
        sign = -1;
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
    int i = 0;
    int sgn = 1;
    for(; i <= *n && fabs(cur) > pres; i++){
        if(i > 0){
            factorial *= 2 * i * (2 * i - 1);
        }
        cur = (sgn * pow) / (factorial);
        res += cur;
        pow *= x*x;
        sgn *= -1;
    }
    *n = i;
    return sign * res;
}

long double lab_sin(long double x, int *n, long double pres){
    long double res = 0;
    long double pow = x;
    long double cur = 1;
    int sign = 1;
    ull factorial = 1;
    //printf("%lf\n", M_PI);
    x = x - (int)(x / (2 * M_PI)) * (2* M_PI);//делаем так, что x < 2*M_PI
    if (x > M_PI){
        sign = -1;
        x = x - M_PI;
    }
    if(x > M_PI_2){
        x = x - M_PI_2;
        sign *= -1;
        return sign * lab_cos(x, n, pres);
    }
    if(x > M_PI_4){
        x = M_PI_2-x;
        return sign * lab_cos(x, n, pres);
    }
    int sgn = 1;
    unsigned int i = 0;
    for(; i <= *n && fabs(cur) > pres; i++){
        if(i > 0){
            factorial *= 2*i * (2 * i + 1);
        }
        cur = sgn * pow / factorial;
        printf("%1.19Lf + (%d * %1.19Lf) / %d = %1.19Lf + %1.19Lf = ", res, sign, pow, factorial, cur, res);
        res += cur;
        printf("%1.19Lf\n", res);
        pow *= x*x;
        sgn *= -1;
    }
    *n = i;
    res = res * sign;
    return res;
}

