#include <stdio.h>
#include <math.h>
#include "func.h"
#include "func2.h"

int main() {

	int mode;

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
		int count; //for mode==1 
		double res1, res2, res3, res4;
		double rs1, rs2, rs3, rs4;

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


		double (*funkcii[])(double, double, int, int*) = { maclor_sin, maclor_cos, maclor_exp, maclor_arct };

		switch (fun) {
		case 1:
			printf("Reference value: ");
			rs1 = sin(x);
			printf("%lf\n", rs1);

			res1 = funkcii[0](x, toch, N, &count);
			printf("Calculated value: ");
			printf("%lf\n", res1);


			printf("The difference between the reference and calculated values: ");
			double tr1 = fabs(rs1 - res1);
			printf("%lf\n", tr1);

			printf("The number of calculated terms: ");
			printf("%d\n", count);
			break;

		case 2:
			printf("Reference value: ");
			rs2 = cos(x);
			printf("%lf\n", rs2);

			printf("Calculated value: ");
			res2 = funkcii[1](x, toch, N, &count);
			printf("%lf\n", res2);

			printf("The difference between the reference and calculated values: ");
			double tr2 = fabs(rs2 - res2);
			printf("%lf\n", tr2);

			printf("The number of calculated terms: ");
			printf("%d\n", N);
			break;

		case 3:
			printf("Reference value: ");
			rs3 = exp(x);
			printf("%lf\n", rs3);

			printf("Calculated value: ");
			res3 = funkcii[2](x, toch, N, &count);
			printf("%lf\n", res3);

			printf("The difference between the reference and calculated values: ");
			double tr3 = fabs(rs3 - res3);
			printf("%lf\n", tr3);

			printf("The number of calculated terms: ");
			printf("%d\n", N);
			break;

		case 4:
			printf("Reference value: ");
			rs4 = atan(x);
			printf("%lf\n", rs4);

			printf("Calculated value: ");
			res4 = funkcii[3](x, toch, N, &count);
			printf("%lf\n", res4);

			printf("The difference between the reference and calculated values: ");
			double tr4 = fabs(rs4 - res4);
			printf("%lf\n", tr4);

			printf("The number of calculated terms: ");
			printf("%d\n", N);
			break;
		}
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


		double (*funkcii[])(double, double, int) = { maclor_sin1, maclor_cos1, maclor_exp1, maclor_arct1 };
		switch (fun) {
		case 1:
			printf("Reference value: ");
			rs1 = sin(x);
			printf("%lf\n", rs1);

			vivod(funkcii[0], x, -1.0, NMax);
			break;

		case 2:
			printf("Reference value: ");
			rs2 = cos(x);
			printf("%lf\n", rs2);

			vivod(funkcii[1], x, -1.0, NMax);
			break;

		case 3:
			printf("Reference value: ");
			rs3 = exp(x);
			printf("%lf\n", rs3);

			vivod(funkcii[2], x, -1.0, NMax);
			break;

		case 4:
			printf("Reference value: ");
			rs4 = atan(x);
			printf("%lf\n", rs4);

			vivod(funkcii[3], x, -1.0, NMax);
			break;
		}

	}

	return 0;
}