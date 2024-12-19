#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_TERMS 1000
#define MAX_EXPERIMENTS 25

typedef double (*FunctionPointer)(double);

double taylor_sin(double x, double epsilon, int nmax) {
    double term = x; 
    double sum = term; 
    int n = 1;
    while (fabs(term) >= epsilon && n < nmax) {
        term *= -x * x / (2 * n * (2 * n + 1)); 
        sum += term;
        n++;
    }
    return sum;
}

double taylor_cos(double x, double epsilon, int nmax) {
    double term = 1; 
    double sum = term; 
    int n = 1;

    while (fabs(term) >= epsilon && n < MAX_TERMS) {
        term *= -x * x / (2 * n * (2 * n - 1)); 
        sum += term;
        n++;
    }
    return sum;
}

double taylor_exp(double x, double epsilon, int nmax) {
    double term = 1; 
    double sum = term; 
    int n = 1;

    while (fabs(term) >= epsilon && n < nmax) {
        term *= x / n; 
        sum += term;
        n++;
    }
    return sum;
}
double taylor_arctg(double x, double epsilon, int nmax) {

    double term = x;
    double sum = term;
    if (x > -1 && x < 0) sum += M_PI;
    int n = 1;

    while (fabs(term) >= epsilon && n < nmax) {
        term *= -(x * x);
        sum += term / (2 * n + 1);
        n++;
    }

    return sum;
}
double taylor_arcctg(double x, double epsilon, int nmax) {
 
    if (fabs(x) > 1) {
        return taylor_arctg(1.0 / x, epsilon, nmax);
    }

    double term = x;
    double sum = term; 
    int n = 1;

    while (fabs(term) >= epsilon && n < nmax) {
        term *= -(x * x); 
        sum += term /(2 * n + 1);
        n++;
    }

    return M_PI_2 - sum;
}

void single_calculation(double func(double, double, int), double x, double epsilon, int nmax) {
    double result = func(x, epsilon, nmax);
    double true_value = 0.0;

    if (func == taylor_sin) true_value = sin(x);
    else if (func == taylor_cos) true_value = cos(x);
    else if (func == taylor_exp) true_value = exp(x);
    else if (func == taylor_arcctg) true_value = M_PI_2 - atan(x);

    printf("Standard value: %.10f\n", true_value);
    printf("Calculated value: %.10f\n", result);
    printf("Difference: %.10f\n", fabs(result - true_value));
}

void series_experiment(double func(double, double, int), double x, int max_experiments) {
    double true_value = 0.0;

    if (func == taylor_sin) {
        true_value = sin(x);
    }
    else if (func == taylor_cos) {
        true_value = cos(x);
    }
    else if (func == taylor_exp) {
        true_value = exp(x);
    }
    else if (func == taylor_arcctg) {

        if (x > 0) true_value = atan(1.0 / x);
        else if (x < 0) true_value = M_PI - atan(-1.0 / x);
        else {
            printf("arcctg(x) is undefined for x = 0.\n");
            return;
        }
    }

    printf("Standard value: %.10f\n", true_value);
    printf("  Temp's count   |    Calculated value   |   difference\n");

    for (int n = 1; n <= max_experiments; n++) {
        double result = func(x, 0.000001, n);
        double difference = fabs(result - true_value);

        printf(" %d\t\t | %.10f\t\t | %.10f\n", n, result, difference);
    }
}

void main() {

    int mode;
    double x;
    int NMax;
    while (1) {
        printf("\nChoose mode:\n1. One-time calculation\n2. Series experiment\n3. Exit\n");
        while (scanf_s("%d", &mode) != 1 || mode < 1 || mode > 3) {
            printf_s("Mode must be from 1 to 3.\n");
            char c;
            while ((c = getchar()) != '\n' && (c != EOF)) {}
        }
        if (mode == 3) break;
        double (*selected_function)(double, double, int);

        printf("Choose function:\n1. sin(x)\n2. cos(x)\n3. exp(x)\n4. arcctg(x)\n");
        int func_choice;
        scanf("%d", &func_choice);

        switch (func_choice) {
        case 1: selected_function = taylor_sin; break;
        case 2: selected_function = taylor_cos; break;
        case 3: selected_function = taylor_exp; break;
        case 4: selected_function = taylor_arcctg; break;
        default: printf("Uncorrect function.\n"); continue;
        }

        printf("Enter the x: ");
        while (scanf("%lf", &x) != 1) {
            printf_s("Uncorrect x, try again.\n");
            char c;
            while ((c = getchar()) != '\n' && (c != EOF)) {}
        }
        if (mode == 1) {
            double epsilon;
            printf("Enter precision (from 0.000001): ");
            while (scanf("%lf", &epsilon) != 1 || epsilon < 0.000001) {
                printf_s("Uncorrect precision, try again.\n");
                char c;
                while ((c = getchar()) != '\n' && (c != EOF)) {}
            }
            printf("Enter the maximum number of terms (from 1 to 1000): ");
            while (scanf("%d", &NMax) != 1 || NMax < 1 || NMax > 1000) {
                printf_s("Uncorrect maximum, try again.\n");
                char c;
                while ((c = getchar()) != '\n' && (c != EOF)) {}
            }
            single_calculation(selected_function, x, epsilon, NMax);
        }
        else if (mode == 2) {
            printf("Enter the experiment's count (from 1 to 25): ");
            while (scanf("%d", &NMax) != 1 || NMax < 1 || NMax > 1000) {
                printf_s("Uncorrect count, try again.\n");
                char c;
                while ((c = getchar()) != '\n' && (c != EOF)) {}
            }

            if (NMax < 1 || NMax > MAX_EXPERIMENTS) {
                printf("Uncorrect experiment's count.\n");
                continue;
            }

            series_experiment(selected_function, x, NMax);
        }
        else {
            printf("Uncorrect data.\n\n");
        }
    }
}