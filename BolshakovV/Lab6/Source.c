#include <stdio.h>
#include <math.h>
#include "func.h"

int main() {

	int mode;
	int count; //for mode==1  

	printf("Please select the mode\n");
	printf("1 - one-time calculation of the function at a given point\n");
	printf("2 - serial experiment\n");
	int flag1;
	char m;
	do {
		flag1 = 0;
		int r = scanf_s("%d", &mode);
		if (r != 1 || (mode < 1 || mode >2)) {
			printf("Error. Please enter the correct values\n");
			flag1 = 1;
		}
		while ((m = getchar()) != '\n' && m != EOF) {};
	} while (flag1 != 0);

	if (mode == 1) {
		double res, rs;

		printf("Before selecting the function, select:\n");
		printf("The point at which you want to find the value\n");
		printf("The accuracy of the calculation\n");
		printf("The maximum number of elements in the series to perform the calculation [1-1000]\n");

		double x;
		printf("\nPlease select the point where you want to find the value for the selected function\n");
		int flag;
		char c;

		do {
			flag = 0;
			int r = scanf_s("%lf", &x);
			if (r != 1) {
				printf("Error. Please enter the correct values\n");
				flag = 1;
			}
			while ((c = getchar()) != '\n' && c != EOF) {};
		} while (flag != 0);


		double toch;
		printf("Please select the calculation accuracy (from 0.000001 or more)\n"); //tochnost

		do {
			flag = 0;
			int r = scanf_s("%lf", &toch);
			if (r != 1 || (toch < (0.000001))) {
				printf("Error. Please enter the correct values\n");
				flag = 1;
			}
			while ((c = getchar()) != '\n' && c != EOF) {};
		} while (flag != 0);

		int N;
		printf("Please select the maximum number of items in the row [1-1000]\n");

		do {
			flag = 0;
			int r = scanf_s("%d", &N);
			if (r != 1 || (N < 1 || N>1000)) {
				printf("Error. Please enter the correct values\n");
				flag = 1;
			}
			while ((c = getchar()) != '\n' && c != EOF) {};
		} while (flag != 0);

		int fun;
		printf("Please select the function\n");
		printf("1 - sin(x)\n");
		printf("2 - cos(x)\n");
		printf("3 - exp(x)\n");
		printf("4 - arctan(x)\n");


		do {
			flag = 0;
			int r = scanf_s("%d", &fun);
			if (r != 1 || (fun > 4 || fun < 1)) {
				printf("Error. Please enter the correct values\n");
				flag = 1;
			}
			while ((c = getchar()) != '\n' && c != EOF) {};
		} while (flag != 0);

		double (*etalon1)(double);
		double(*funcia)(double, double, int, int*);

		switch (fun) {
		case 1:
			etalon1 = sin;
			rs = etalon1(x);
			funcia = maclor_sin;
			res = funcia(x, toch, N, &count);
			break;

		case 2:
			etalon1 = cos;
			rs = etalon1(x);
			funcia = maclor_cos;
			res = funcia(x, toch, N, &count);
			break;

		case 3:
			etalon1 = exp;
			rs = etalon1(x);
			funcia = maclor_exp;
			res = funcia(x, toch, N, &count);
			break;

		case 4:
			etalon1 = atan;
			rs = etalon1(x);
			funcia = maclor_arct;
			res = funcia(x, toch, N, &count);
			break;
		}
		printf("Reference value: ");
		printf("%lf\n", rs);
		printf("Calulated value: ");
		printf("%lf\n", res);
		printf("The difference between the reference and calculated values: ");
		printf("%lf\n", fabs(rs - res));
		printf("The number of calculated terms: ");
		printf("%d\n", count);

	}
	else {
		double rs1, rs2, rs3, rs4;
		printf("Before selecting the function, select:\n");
		printf("The point at which you want to find the value\n");
		printf("The number of experiment\n");

		double x;
		printf("\nPlease select the point where you want to find the value for the selected function\n");

		int flag;
		char c;

		do {
			flag = 0;
			int r = scanf_s("%lf", &x);
			if (r != 1) {
				printf("Error. Please enter the correct values\n");
				flag = 1;
			}
			while ((c = getchar()) != '\n' && c != EOF) {};
		} while (flag != 0);


		int NMax;
		printf("Please select the number of experiments\n");

		do {
			flag = 0;
			int r = scanf_s("%d", &NMax);
			if (r != 1 || (NMax > 25 || NMax < 1)) {
				printf("Error. Please enter the correct values\n");
				flag = 1;
			}
			while ((c = getchar()) != '\n' && c != EOF) {};
		} while (flag != 0);


		int fun;
		printf("Please select the function\n");
		printf("1 - sin(x)\n");
		printf("2 - cos(x)\n");
		printf("3 - exp(x)\n");
		printf("4 - arctan(x)\n");


		do {
			flag = 0;
			int r = scanf_s("%d", &fun);
			if (r != 1 || (fun > 4 || fun < 1)) {
				printf("Error. Please enter the correct values\n");
				flag = 1;
			}
			while ((c = getchar()) != '\n' && c != EOF) {};
		} while (flag != 0);


		double (*funkcii[])(double, double, int, int*) = { maclor_sin, maclor_cos, maclor_exp, maclor_arct };

		switch (fun) {
		case 1:
			printf("Reference value: ");
			rs1 = sin(x);
			printf("%lf\n", rs1);

			vivod(funkcii[0], x, -1.0, NMax, &count);
			break;

		case 2:
			printf("Reference value: ");
			rs2 = cos(x);
			printf("%lf\n", rs2);

			vivod(funkcii[1], x, -1.0, NMax, &count);
			break;

		case 3:
			printf("Reference value: ");
			rs3 = exp(x);
			printf("%lf\n", rs3);

			vivod(funkcii[2], x, -1.0, NMax, &count);
			break;

		case 4:
			printf("Reference value: ");
			rs4 = atan(x);
			printf("%lf\n", rs4);

			vivod(funkcii[3], x, -1.0, NMax, &count);
			break;
		}
	}
	return 0;
}