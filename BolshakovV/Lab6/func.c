#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double maclor_sin(double x, double toch, int N, int* count)
{
	double sum = x;
	double tec = x;
	*count = 1;
	for (int index = 1; index < N; index++) {

		tec *= -x * x / ((2 * index) * (2 * index + 1));
		sum += tec;
		(*count)++;
		if (fabs(tec) < toch) {
			break;
		}
	}
	return sum;

}

double maclor_cos(double x, double toch, int N, int* count)
{
	double sum = 1.0;
	double tec = 1.0;
	*count = 1;
	for (int index = 1; index < N; index++) {
		tec *= -x * x / ((2 * index - 1) * (2 * index));
		sum += tec;
		(*count)++;
		if (fabs(tec) < toch) {
			break;
		}
	}
	return sum;

}

double maclor_exp(double x, double toch, int N, int* count)
{
	double sum = 1;
	double tec = 1;
	*count = 1;
	for (int index = 1; index < N; index++) {
		tec *= x / index;
		sum += tec;
		(*count)++;
		if (fabs(tec) < toch) {
			break;
		}
	}
	return sum;
}

double maclor_arct(double x, double toch, int N, int* count) {
	double sum = x, tec = x;
	*count = 1;
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
	for (int index = 1; index < N; index++) {
		tec *= -x * x / (index * 2 + 1);
		sum += tec;
		(*count)++;
		if (fabs(tec) < toch) {
			break;
		}
	}
	return sum;
}

typedef double(*maclor_func)(double, double, int, int*); //noviy tip - ycazatel na funkciu

void vivod(maclor_func func, double x, double toch, int NMax, int* count) // func - ycazatel na funkciu
{
	double(*etalon)(double);
	etalon = func;
	if (func == maclor_sin) {
		etalon = sin;
	}
	else if (func == maclor_cos) {
		etalon = cos;
	}
	else if (func == maclor_exp) {
		etalon = exp;
	}
	else if (func == maclor_arct) {
		etalon = atan;
	}

	printf("|The number of terms |   Calculated value   | The difference between the calculated and reference values |\n");
	for (int i = 1; i <= NMax; i++) {
		double result = func(x, toch, i, &count);
		double result1 = fabs(result - etalon(x));
		printf("|%20.d|%22.10lf|%60.10lf|\n", i, result, result1);
	}
}