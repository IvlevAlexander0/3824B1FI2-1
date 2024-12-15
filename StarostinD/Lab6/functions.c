#define _USE_MATH_DEFINES
#include "functions.h"
#include <stdio.h>
#include <math.h>

long double fact(int x) {
	static int cur = 1;
	static long double fct[1001] = { 1 };
	if (fct[x] != 0) {
		return fct[x];
	}
	while (cur <= x) {
		fct[cur] = fct[cur - 1] * cur;
		++cur;
	}
	return fct[x];
}

long double fact_odd(int x) {
	static int cur = 3;
	static int id = 2;
	static long double fct[1001] = { 1 , 1 };
	if (fct[x] != 0) {
		return fct[x];
	}
	while (id <= x) {
		fct[id] = fct[id - 1] * cur;
		cur += 2;
		++id;
	}
	return fct[x];
}

long double fact_even(int x) {
	static int cur = 4;
	static int id = 2;
	static long double fct[1001] = { 1, 2 };
	if (fct[x] != 0) {
		return fct[x];
	}
	while (id <= x) {
		fct[id] = fct[id - 1] * cur;
		cur += 2;
		++id;
	}
	return fct[x];
}


long double sin_x(long double x, long double prc, int N, int mode) { 
	x = x - M_PI * (long long)(x / M_PI);
	long double res = 0;
	long double cur = prc + 1;
	long double x_i = x;
	int sgn = 1;
	int i = 1;
	int num = i;
	for (; i + 2 <= N && fabs(cur) > prc; i += 2) {
		cur = x_i / fact(i) * sgn;
		res += cur;
		sgn *= -1;
		x_i = x_i * x * x;
		num = i;
	}
	if (mode == 1) {
		printf("Result of standard function: %.19Lf\n", sin(x));
		printf("Calculated function value estimate: %.19Lf\n", res);
		printf("Number of summands: %d\n", num);
		printf("Difference between estimate and reference value: %.19Lf\n", fabs(sin(x) - res));
	}
	else {
		printf("|%-5d|", N + 1);
		printf("%-30.19Lf|", res);
		printf("%-30.19Lf|\n", fabs(sin(x) - res));
	}
	return res;
}

long double cos_x(long double x, long double prc, int N, int mode) {
	x = x - M_PI * (long long)(x / M_PI);
	long double res = 1;
	long double cur = prc + 1;
	long double x_i = x * x;
	int sgn = -1;
	int i = 2;
	int num = i;
	for (; i <= N && fabs(cur) > prc; i += 2) {
		cur = x_i / fact(i) * sgn;
		res += cur;
		sgn *= -1;
		x_i = x_i * x * x;
		num = i;
	}
	if (mode == 1) {
		printf("Result of standard function: %.19Lf\n", cos(x));
		printf("Calculated function value estimate: %.19Lf\n", res);
		printf("Number of summands: %d\n", num);
		printf("Difference between estimate and reference value: %.19Lf\n", fabs(cos(x) - res));
	}
	else {
		printf("|%-5d|", N + 1);
		printf("%-30.19Lf|", res);
		printf("%-30.19Lf|\n", fabs(cos(x) - res));
	}
	return res;
}

long double exp_x(long double x, long double prc, int N, int mode) {
	long double res = 1;
	long double cur = prc + 1;
	long double x_i = x;
	int i = 1;
	int num = i;
	for (; i <= N && fabs(cur) > prc; ++i) {
		cur = x_i / fact(i);
		res += cur;
		x_i *= x;
		num = i;
	}
	if (mode == 1) {
		printf("Result of standard function: %.19Lf\n", exp(x));
		printf("Calculated function value estimate: %.19Lf\n", res);
		printf("Number of summands: %d\n", num);
		printf("Difference between estimate and reference value: %.19Lf\n", fabs(exp(x) - res));
	}
	else {
		printf("|%-5d|", N + 1);
		printf("%-30.19Lf|", res);
		printf("%-30.19Lf|\n", fabs(exp(x) - res));
	}
	return res;
}

long double arcsin_x(long double x, long double prc, int N, int mode) {
	if (x > 1 || x < -1) {
		printf("Incorrect x. The value must belong to the interval [-1; 1].\n");
		return -1;
	}
	long double res = x;
	long double cur = prc + 1;
	long double x_i = x * x * x;
	int i = 1;
	int num = i;
	for (; i <= N && fabs(cur) > prc; ++i) {
		cur = (x_i * fact_odd(i)) / (fact_even(i) * (2 * i + 1));
		res += cur;
		x_i = x_i * x * x;
		num = i;
	}
	if (mode == 1) {
		printf("Result of standard function: %.19Lf\n", asin(x));
		printf("Calculated function value estimate: %.19Lf\n", res);
		printf("Number of summands: %d\n", num);
		printf("Difference between estimate and reference value: %.19Lf\n", fabs(asin(x) - res));
	}
	else {
		printf("|%-5d|", N + 1);
		printf("%-30.19Lf|", res);
		printf("%-30.19Lf|\n", fabs(asin(x) - res));
	}
	return res;
}
