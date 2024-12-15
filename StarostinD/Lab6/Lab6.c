#define _USE_MATH_DEFINES
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	long double (*func[4])(long double, long double, int, int) = { sin_x, cos_x, exp_x, arcsin_x };
	long double (*std_func[4])(long double) = { sin, cos, exp, asin};
	int mode;
	printf("Select mode:\n1. one time\t2. N times\n");
	scanf_s("%d", &mode);
	int f;
	long double x;
	switch (mode) {
	case 1:
		printf("Select function:\n1. sin(x) \t 2. cos(x) \t 3. exp(x) \t 4. arcsin(x)\n");
		scanf_s("%d", &f);
		--f;
		printf("Enter point X: ");
		scanf_s("%Lf", &x);
		printf("Set the calculation precision: ");
		long double prc;
		scanf_s("%Lf", &prc);
		printf("Set the maximum number of elements in a series: ");
		int N;
		scanf_s("%d", &N);
		func[f](x, prc, N, mode);
		break;
	case 2:
		printf("Select function:\n1. sin(x) \t 2. cos(x) \t 3. exp(x) \t 4. arcsin(x)\n");
		scanf_s("%d", &f);
		--f;
		printf("Enter point X: ");
		scanf_s("%Lf", &x);
		printf("Set the number of experiments: ");
		long double NMax;
		scanf_s("%Lf", &NMax);
		printf("\nResult of standard function: %.19Lf\n", std_func[f](x));
		printf("|N    |Calculated function           |Difference between values     |\n");
		for (int i = 0; i < NMax; ++i) {
			func[f](x, -1, i, mode);
		}
		break;
	default:
		printf("Error! Incorrect number\n");
		return -1;
	}
	return 0;
}