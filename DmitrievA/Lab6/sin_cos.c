#include <math.h>

int sin_get_derivative_from_0(int n){
    switch (n % 4){
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return -1;
    }
}

int cos_get_derivative_from_0(int n){
    switch (n % 4){
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return -1;
        case 3:
            return 0;
    }
}

double lab_cos(double x, int n){
    double res = 0;
    double pow = 1;
    unsigned int factorial = 1;
    x = x - (int)(x / (2 * M_PI)) * (2* M_PI);
    if (x > M_PI){
        factorial *= -1;
        x = x - M_PI;
    }
    if (x > M_PI_2){
        x = x - M_PI_2;
        return lab_sin(x, n);
    }
    if(x > M_PI_4){
        x = M_PI_4 - x;
        return lab_sin(x, n);
    }
    for(int i = 0; i < n; i++){
        res += (cos_get_derivative_from_0(i)*pow)/(factorial);
        if(i > 1){
            factorial *= i;
        }
        pow *= x;
    }
    return res;
}

double lab_sin(double x, int n){
    double res = 0;
    double pow = 1;
    unsigned int factorial = 1;
    x = x - (int)(x / (2 * M_PI)) * (2* M_PI);//делаем так, что x < 2*M_PI
    if (x > M_PI){
        factorial *= -1;
        x = x - M_PI;
    }
    if(x > M_PI_2){
        x = x - M_PI_2;
        return lab_cos(x, n);
    }
    if(x > M_PI_4){
        x = M_PI_4-x;
        return lab_cos(x, n);
    }
    for(int i = 0; i < n; i++){
        res += (sin_get_derivative_from_0(i)*pow)/factorial;
        if(i > 1){
            factorial *= i;
        }
        pow *= x;
    }
    return res;
}

