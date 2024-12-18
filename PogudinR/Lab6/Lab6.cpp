#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_TERMS 1000
#define MAX_EXPERIMENTS 25

// Тип указателя на функцию, которая принимает double и int, и возвращает double
typedef double (*FunctionPointer)(double, int);

double taylor_sin(double x, int max_terms);  // Для синуса
double taylor_cos(double x, int max_terms);  // Для косинуса
double taylor_exp(double x, int max_terms);  // Для экспоненты
double taylor_arccos(double x, int max_terms);  // Для арккосинуса

// Функция для вычисления разложения Тейлора для заданной функции с точностью
double calculate_taylor_series(FunctionPointer func, double x, int max_terms, double precision, int* terms_used);

// Функция для режима 1 (одиночного вычисления)
void mode_one(FunctionPointer functions[], const char* function_names[]);

// Функция для режима 2 (эксперимента с рядом)
void mode_two(FunctionPointer functions[], const char* function_names[]);

int main() {
    // Массив указателей на функции, вычисляющие разложения Тейлора для различных функций
    FunctionPointer functions[] = { taylor_sin, taylor_cos, taylor_exp, taylor_arccos };

    // Массив строк с названиями соответствующих функций
    const char* function_names[] = { "sin(x)", "cos(x)", "exp(x)", "arccos(x)" };

    int mode;

    printf("Select mode:\n1. Single calculation\n2. Series experiment\n");
    scanf("%d", &mode);

    if (mode == 1) {
        mode_one(functions, function_names);  // Режим одиночного вычисления
    }
    else if (mode == 2) {
        mode_two(functions, function_names);  // Режим серийного эксперимента с рядом Тейлора
    }
    else {
        printf("Invalid mode. Terminating program.\n");
    }

    return 0;
}


// Расчет ряда Тейлора для синуса
// x - точка вычисления
// max_terms - максимальное число членов ряда
// Возвращает значение синуса, приближенное рядом Тейлора
double taylor_sin(double x, int max_terms) {
    double sum = 0.0, term = x;
    for (int n = 1; n <= max_terms; n++) {
        sum += term;
        term *= (-1) * x * x / (2 * n * (2 * n + 1));
    }
    return sum;
}

// Расчет ряда Тейлора для косинуса
// x - точка вычисления
// max_terms - максимальное число членов ряда
// Возвращает значение косинуса, приближенное рядом Тейлора
double taylor_cos(double x, int max_terms) {
    double sum = 1.0, term = 1.0;
    for (int n = 1; n <= max_terms; n++) {
        term *= (-1) * x * x / (2 * n * (2 * n - 1));
        sum += term;
    }
    return sum;
}

// Расчет ряда Тейлора для экспоненты
// x - точка вычисления
// max_terms - максимальное число членов ряда
// Возвращает значение exp(x), приближенное рядом Тейлора
double taylor_exp(double x, int max_terms) {
    double sum = 1.0, term = 1.0;
    for (int n = 1; n <= max_terms; n++) {
        term *= x / n;
        sum += term;
    }
    return sum;
}

// Расчет ряда Тейлора для арккосинуса
// x - точка вычисления (-1 <= x <= 1)
// max_terms - максимальное число членов ряда
// Возвращает значение arccos(x), приближенное рядом Тейлора
double taylor_arccos(double x, int max_terms) {
    if (x < -1.0 || x > 1.0) {
        printf("Arccos is defined only for x in [-1, 1].\n");
        return NAN;
    }
    double sum = 3.141592653589793 / 2; // π/2
    double term = x;
    for (int n = 1; n <= max_terms; n++) {
        term *= (2.0 * n - 1) * x * x / (2.0 * n);
        sum -= term / (2 * n + 1);
    }
    return sum;
}

// Универсальная функция для вычисления значения ряда Тейлора с заданной точностью
// func - указатель на функцию для вычисления ряда
// x - точка вычисления
// max_terms - максимальное число членов ряда
// precision - заданная точность
// terms_used - указатель для хранения числа использованных членов ряда
// Возвращает приближенное значение функции
double calculate_taylor_series(FunctionPointer func, double x, int max_terms, double precision, int* terms_used) {
    double result, prev_result = 0.0;
    *terms_used = 0;
    for (int n = 1; n <= max_terms; n++) {
        result = func(x, n);
        (*terms_used)++;
        if (fabs(result - prev_result) < precision) {
            break;
        }
        prev_result = result;
    }
    return result;
}

// Режим 1: Однократный расчет функции
// Позволяет выбрать функцию, точку, точность и максимальное число членов ряда
// Выводит эталонное значение, расчетное значение, разницу и число членов ряда
void mode_one(FunctionPointer functions[], const char* function_names[]) {
    int choice, max_terms;
    double x, precision;
    printf("Select function:\n1. sin(x)\n2. cos(x)\n3. exp(x)\n4. arccos(x)\n");
    scanf("%d", &choice);
    if (choice < 1 || choice > 4) {
        printf("Invalid function choice.\n");
        return;
    }

    printf("Enter value of x: ");
    scanf("%lf", &x);
    printf("Enter precision (minimum 0.000001): ");
    scanf("%lf", &precision);
    if (precision < 0.000001) precision = 0.000001;
    printf("Enter maximum number of terms(1 to 1000) : ");
    scanf("%d", &max_terms);
    if (max_terms < 1 || max_terms > 1000) max_terms = 1000;

    int terms_used;
    double estimate = calculate_taylor_series(functions[choice - 1], x, max_terms, precision, &terms_used);
    double exact_value;
    switch (choice) {
    case 1: exact_value = sin(x); break;
    case 2: exact_value = cos(x); break;
    case 3: exact_value = exp(x); break;
    case 4: exact_value = acos(x); break;
    }

    printf("Exact value: %lf\n", exact_value);
    printf("Calculated value: %lf\n", estimate);
    printf("Difference: %lf\n", fabs(estimate - exact_value));
    printf("Number of terms: %d\n", terms_used);
}

// Режим 2: Серийный эксперимент
// Позволяет выбрать функцию, точку и число экспериментов
// Выводит эталонное значение и таблицу результатов с числом членов ряда, расчетным значением и разницей
void mode_two(FunctionPointer functions[], const char* function_names[]) {
    int choice, n_experiments;
    double x;
    printf("Select function:\n1. sin(x)\n2. cos(x)\n3. exp(x)\n4. arccos(x)\n");
    scanf("%d", &choice);
    if (choice < 1 || choice > 4) {
        printf("Invalid function choice.\n");
        return;
    }

    printf("Enter value of x: ");
    scanf("%lf", &x);
    printf("Enter number of experiments (1 to 25): ");
    scanf("%d", &n_experiments);
    if (n_experiments < 1 || n_experiments > MAX_EXPERIMENTS) n_experiments = MAX_EXPERIMENTS;

    double exact_value;
    switch (choice) {
    case 1: exact_value = sin(x); break;
    case 2: exact_value = cos(x); break;
    case 3: exact_value = exp(x); break;
    case 4: exact_value = acos(x); break;
    }

    printf("Exact value: %lf\n", exact_value);
    printf("Results table:\n");
    printf("| Number of terms | Calculated value | Difference |\n");
    for (int n = 1; n <= n_experiments; n++) {
        double estimate = functions[choice - 1](x, n);
        printf("| %15d | %16lf | %10lf |\n", n, estimate, fabs(estimate - exact_value));
    }
}
