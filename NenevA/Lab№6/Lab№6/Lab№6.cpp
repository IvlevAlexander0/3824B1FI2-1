#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
unsigned long long fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
double augmentation(double x) { //Уменьшение аргумента x для работы с большими числами в тригонометрии
    while (fabs(x) > 2 * M_PI) {
        if (x > 0) {
            x -= 2 * M_PI;
        }
        else {
            x += 2 * M_PI;
        }
    }
    return x;
}
double sinTaylor(double x, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(-1, i) * pow(x, 2 * i + 1) / fact(2 * i + 1);
    }
    return sum;
}

double cosTaylor(double x, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(-1, i) * pow(x, 2 * i) / fact(2 * i);
    }
    return sum;
}

double expTaylor(double x, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(x, i) / fact(i);
    }
    return sum;
}

double lnTaylor(double x, int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(-1, i + 1) * pow(x, i) / i;
    }
    return sum;
}

typedef struct {
    double (*taylor)(double, int);
    double (*exact)(double);
} Function;

Function functions[] = {
    {sinTaylor, sin},
    {cosTaylor, cos},
    {expTaylor, exp},
    {lnTaylor, log1p}
};

void singleCalculation() {
    int choice;
    printf("Choose the function (1 - sin(x), 2 - cos(x), 3 - exp(x), 4 - ln(1 + x)): ");
    do {
        scanf_s("%d", &choice);
    } while (1 > choice || choice > 4);

    double x, precision;
    int maxTerms;
    if (choice == 4) {
        printf("Choose the X point(from -1 to 1 not including these points): ");
        do {
            scanf_s("%lf", &x);
        } while (-1 > x || x > 1); //Вычисляется только на этом промежутке
    }
    else {
        printf("Choose the X point: ");
        scanf_s("%lf", &x);
    }
    if ((choice == 1 || choice == 2)) {
        x = augmentation(x); //Упрощение больших исков
    }
    do {
        printf("Enter the precision (>= 0.000001): ");
        scanf_s("%lf", &precision);
    } while (precision < 0.000001);
    printf("Enter the maximum amount of elements (1-1000): ");
    do {
        scanf_s("%d", &maxTerms);
    } while (maxTerms < 1 || maxTerms>1000);
    if (maxTerms < 1 || maxTerms > 1000) {
        printf("Maximum amount of numbers must be from 1 to 1000.\n");
        return;
    }

    double taylorValue = functions[choice - 1].taylor(x, maxTerms);
    double exactValue = functions[choice - 1].exact(x);
    int termsUsed = 0;
    double currentPrecision = 100;
    for (int i = 1; i <= maxTerms && currentPrecision >= precision; i++) {
        termsUsed = i;
        currentPrecision = fabs(functions[choice - 1].taylor(x, i) - exactValue);
    }
    printf("Etalon value: %.6f\n", exactValue);
    printf("Calculated estimation: %.6f\n", functions[choice - 1].taylor(x, termsUsed));
    printf("Difference: %.6f\n", fabs(functions[choice - 1].taylor(x, termsUsed) - exactValue));
    printf("Amount of terms: %d\n", termsUsed);
}

void seriesExperiment() {
    int choice;
    printf("Choose the function (1 - sin(x), 2 - cos(x), 3 - exp(x), 4 - ln(1 + x)): ");
    do {
        scanf_s("%d", &choice);
    } while (1 > choice || choice > 4);
    double x;
    int numExperiments;
    if (choice == 4) {
        printf("Choose the X point(from -1 to 1 not including these points): ");
        do {
            scanf_s("%lf", &x);
        } while (-1 > x || x > 1); //Вычисляется только на этом промежутке
    }
    else {
        printf("Choose the X point: ");
        scanf_s("%lf", &x);
    }
    if ((choice == 1 || choice == 2)) {
        x = augmentation(x);
    }
    printf("Enter the number of experiments (1-25): ");
    do {
        scanf_s("%d", &numExperiments);
    } while (1 > numExperiments || numExperiments > 25);

    double exactValue = functions[choice - 1].exact(x);
    printf("Etalon value: %.6f\n", exactValue);
    printf("Results table:\n");
    printf("Amount of terms \tCalculated estimation \tDifference\n");

    for (int i = 1; i <= numExperiments; i++) {
        double taylorValue = functions[choice - 1].taylor(x, i);
        double difference = fabs(taylorValue - exactValue);
        printf("%d\t\t\t%.6f\t\t%.6f\n", i, taylorValue, difference);
    }
}

int main() {
    int mode;
    do {
        printf("Choose the mode (1 - single calculation, 2 - numerous experiments, 3 - finish calculations): ");
        do {
            scanf_s("%d", &mode);
        } while (1 > mode || mode > 3);
        if (mode == 1) {
            singleCalculation();
        }
        else if (mode == 2) {
            seriesExperiment();
        }
    } while (mode != 3);
    return 0;
}