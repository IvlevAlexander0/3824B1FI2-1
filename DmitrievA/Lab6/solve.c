
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arcsin.h"
#include "sin_cos.h"
#include "exp.h"

#define _CRT_SECURE_NO_WARNINGS
long double (*func[4])(long double, int*, long double) = { lab_sin, lab_cos, lab_exp, lab_arcsin};
long double (*std_func[4])(long double) = { sinl, cosl, expl, asinl };

void flush(){
    int tc;
    while ((tc = getchar()) != '\n' && tc != EOF){}
}
void flushc(char c){
    if (c == '\n'){
        return;
    }
    flush();
}

int main() {
    int ans, ans2;
    int incorrect = 0;
    int t;
    printf("Choice mode:\n1. Single calculation\n2. Serial experement\n");
    do{
        if (incorrect) { printf("Input 1 or 2: "); }
        t = scanf("%d", &ans);
        flush();
        incorrect = 1;
    } while (ans < 1 || ans > 2 || t<1);
    printf("Choose function:\n1.sin\n2.cos\n3.exp\n4.arcsin\n");
    incorrect = 0;
    do {
        if (incorrect) { printf("Input number from 1 to 4: "); }
        t = scanf("%d", &ans2);
        flush();
        incorrect = 1;
    } while (ans2 < 1 || ans2 > 4 || t < 1);
    ans2--;
    printf("Input point: ");
    long double point;
    incorrect = 0;
    do {
        if (incorrect) { printf("Input float number up to 19 digits: "); }
        t = scanf("%Lf", &point);
        flush();
        incorrect = 1;
    } while (t != 1 && (ans2 == 4 && (point < -1 || point > 1)));
    switch (ans)
    {
        long double res;
        long double std_res;
        int n;
    case 1:
        printf("Input precision: ");;
        incorrect = 0;
        long double precision;
        do {
            if (incorrect) { printf("Input float number: "); }
            t = scanf("%Lf", &precision);
            flush();
            incorrect = 1;
        } while (t != 1);
        printf("Input maximum numbers of elements: ");
        incorrect = 0;
        do {
            if (incorrect) { printf("Input number from 1 to 30"); }
            t = scanf("%d", &n);
            flush();
            incorrect = 1;
        } while (t != 1);
        res = func[ans2](point, &n, precision);
        std_res = std_func[ans2](point);
        printf("standard:   %.19Lf\nCalculated: %.19Lf\ndiffernce:  %.19Lf\nCount of elments: %d", std_res, res, fabs(res - std_res), n);
        break;
    case 2:
        printf("Input numbers of experements: ");
        incorrect = 0;
        do {
            if (incorrect) { printf("Input number from 1 to 30"); }
            t = scanf("%d", &n);
            flush();
            incorrect = 1;
        } while (t != 1);
        printf("number %20s %20s %20s\n", "calculated", "standard", "difference");
        for (int i = 0; i < n; i++) {
            int nn = i;
            long double res = func[ans2](point, &nn, -1);
            long double std_res = std_func[ans2](point);
            printf("%6.2d|%22.19Lf|%22.19Lf|%.19Lf\n", i, res, std_res, fabs(res - std_res));
        }
        break;
    }
    return 0;
}