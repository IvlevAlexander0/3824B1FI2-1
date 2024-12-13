#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

unsigned long long factorial1(int n)
{
	unsigned long long result = 1;
	if (n == 1) {
		result = 1;
	}
	if (n == 0) {
		result = 1;
	}
	for (size_t i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

double maclor_sin1(double x, double toch, int N)
{
	double tec; //tecushiy element
	double sum = 0.0;
	int index = 0;

	do {
		tec = (index % 2 == 0 ? 1 : -1) * (pow(x, 2 * index + 1) / factorial1(2 * index + 1));
		sum += tec;
		index++;

	} while ((fabs(tec) > toch && index < N));
	return sum;
}

double maclor_cos1(double x, double toch, int N)
{
	double tec;
	double sum = 0.0;
	int index = 0;

	do {

		tec = (index % 2 == 0 ? 1 : -1) * (pow(x, 2 * index) / factorial1(2 * index));
		sum += tec;
		index++;

	} while ((fabs(tec) > toch && index < N));
	return sum;
}

double maclor_exp1(double x, double toch, int N)
{
	double tec;
	double sum = 0.0;
	int index = 0;

	do {

		tec = (pow(x, index) / factorial1(index));
		sum += tec;
		index++;

	} while ((fabs(tec) > toch && index < N));
	return sum;
}

double maclor_arct1(double x, double toch, int N) {
	double sum = 0.0, tec;
	int index = 0;


	if (fabs(x) > 1) {
		if (x > 1) {
			x = 1 / x;
			sum = M_PI / 2;
		}
		if (x < -1) {
			x = 1 / x;
			sum = -M_PI / 2;
		}
	}

	do {
		tec = (pow(-1, index) * pow(x, 2 * index + 1)) / (2 * index + 1);
		sum += tec;
		index++;

	} while (fabs(tec) > toch && index < N);
	return sum;
}

typedef double(*maclor_func)(double, double, int); //noviy tip - ycazatel na funkciu

void vivod(maclor_func func, double x, double toch, int NMax) // func - ycazatel na funkciu
{
	double(*etalon)(double);
	etalon = func;
	if (func == maclor_sin1) {
		etalon = sin;
	}
	else if (func == maclor_cos1) {
		etalon = cos;
	}
	else if (func == maclor_exp1) {
		etalon = exp;
	}
	else if (func == maclor_arct1) {
		etalon = atan;
	}

	printf("|The number of terms |   Calculated value   | The difference between the calculated and reference values |\n");
	for (int i = 1; i <= NMax; i++) {
		double result = func(x, toch, i);
		double result1 = fabs(result - etalon(x));
		printf("|%20.d|%22.10lf|%60.10lf|\n", i, result, result1);
	}
}