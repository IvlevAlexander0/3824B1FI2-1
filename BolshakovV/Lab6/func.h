#pragma once
double maclor_sin(double x, double toch, int N, int* count);
double maclor_cos(double x, double toch, int N, int* count);
double maclor_exp(double x, double toch, int N, int* count);
double maclor_arct(double x, double toch, int N, int* count);
typedef double(*maclor_func)(double, double, int, int*);
void vivod(maclor_func func, double x, double toch, int NMax, int* count);