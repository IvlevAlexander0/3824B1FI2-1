#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

unsigned long long factorial(int n)
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

double maclor_sin(double x, double toch, int N, int* count)
{
	double tec; //tecushiy element
	double sum = 0.0;
	int index = 0;
	*count = 0;
	do {
		tec = (index % 2 == 0 ? 1 : -1) * (pow(x, 2 * index + 1) / factorial(2 * index + 1));
		sum += tec;
		index++;
		(*count)++;
	} while ((fabs(tec) > toch && index < N));
	return sum;
}

double maclor_cos(double x, double toch, int N, int* count)
{
	double tec;
	double sum = 0.0;
	int index = 0;
	*count = 0;
	do {

		tec = (index % 2 == 0 ? 1 : -1) * (pow(x, 2 * index) / factorial(2 * index));
		sum += tec;
		index++;
		(*count)++;
	} while ((fabs(tec) > toch && index < N));
	return sum;
}

double maclor_exp(double x, double toch, int N, int* count)
{
	double tec;
	double sum = 0.0;
	int index = 0;
	*count = 0;
	do {

		tec = (pow(x, index) / factorial(index));
		sum += tec;
		index++;
		(*count)++;
	} while ((fabs(tec) > toch && index < N));
	return sum;
}

double maclor_arct(double x, double toch, int N, int* count) {
	double sum = 0.0, tec;
	int index = 0;
	*count = 0;

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
		(*count)++;
	} while (fabs(tec) > toch && index < N);
	return sum;
}