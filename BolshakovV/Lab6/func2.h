#pragma once
unsigned long long factorial1(int n);
double maclor_sin1(double x, double toch, int N);
double maclor_cos1(double x, double toch, int N);
double maclor_exp1(double x, double toch, int N);
double maclor_arct1(double x, double toch, int N);
typedef double(*maclor_func)(double, double, int);;
void vivod(maclor_func func, double x, double toch, int NMax);