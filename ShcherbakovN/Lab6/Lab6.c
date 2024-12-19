#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "taylor_function.h"

void main()
{
	printf("Hello, select the operating mode:\n1.A single calculation of the function at a given point.\n2.Serial experiment.\n");
	int choice_mode = 0;
	while (scanf("%d", &choice_mode) != 1 || (choice_mode != 1 && choice_mode != 2))
	{
		int c = 0;
		while ((c = getchar()) != '\n' && c != EOF)
		{
			;
		}
		printf("Incorrect value\n");
	}

	printf("Select function:\n1.sin(x)\n2.cos(x)\n3.exp(x)\n4.arctg(x)\n");
	int choice_f = 0;
	while (scanf("%d", &choice_f) != 1 || (choice_f != 1 && choice_f != 2 && choice_f != 3 && choice_f != 4))
	{
		int c = 0;
		while ((c = getchar()) != '\n' && c != EOF)
		{
			;
		}
		printf("Incorrect value\n");
	}

	double (*taylor_function) (double, double, int, int*) = 0;
	double (*standart_function) (double) = 0;
	switch (choice_f)
	{
	case 1:
		taylor_function = taylor_sin;
		standart_function = sin;
		printf("===Sin===\n");
		break;
	case 2:
		taylor_function = taylor_cos;
		standart_function = cos;
		printf("===Cos===\n");
		break;
	case 3:
		taylor_function = taylor_exp;
		standart_function = exp;
		printf("===Exp===\n");
		break;
	case 4:
		taylor_function = taylor_arctg;
		standart_function = atan;
		printf("===Arctg===\n");
		break;
	}

	printf("Enter a point:\n");
	double p_x = 0;
	while (scanf("%lf", &p_x) != 1)
	{
		int c = 0;
		while ((c = getchar()) != '\n' && c != EOF)
		{
			;
		}
		printf("Incorrect value\n");
	}

	int count = 0;
	int* count_terms = &count;

	switch (choice_mode)
	{
	case 1:
		printf("Enter a accuracy:\n");
		double accuracy = 0;
		while (scanf("%lf", &accuracy) != 1 || accuracy <= 0.0 || accuracy < 0.000001)
		{
			int c = 0;
			while ((c = getchar()) != '\n' && c != EOF)
			{
				;
			}
			printf("Incorrect value\n");
		}
		printf("\n%.15lf\n", accuracy);


		printf("Enter the number of elements in the row:\n");
		int num_elements = 0;
		while (scanf("%d", &num_elements) != 1 || num_elements < 1 || num_elements > 1000)
		{
			int c = 0;
			while ((c = getchar()) != '\n' && c != EOF)
			{
				;
			}
			printf("Incorrect value\n");
		}

		count = 0;
		double res = taylor_function(p_x, accuracy, num_elements, count_terms);
		printf("\nReference value:%.15lf\n", standart_function(p_x));
		printf("\nThe result of the calculation:%.15lf\n", res);
		printf("\nDifference:%.15lf\n", fabs(standart_function(p_x) - res));
		printf("\nThe number of terms:%d\n", count);

		exit(EXIT_SUCCESS);

	case 2:
		printf("Enter the number of experiments:\n");
		int n_max = 0;
		while (scanf("%d", &n_max) != 1 || n_max < 1 || n_max > 25)
		{
			int c = 0;
			while ((c = getchar()) != '\n' && c != EOF)
			{
				;
			}
			printf("Incorrect value\n");
		}

		printf("\nReference value:%.15lf\n", standart_function(p_x));
		printf("Table with experimental results:\n");
		printf("|Nmax|The number of terms| The result of the calculation |       Difference       |\n");
		printf("|----|-------------------|-------------------------------|------------------------|\n");
		count = 0;
		for (int i = 1; i <= n_max; i++) //Вывод таблицы
		{
			count = 0;
			double res = taylor_function(p_x, -1, i, count_terms);
			printf("|(%2d)|%19d|%31.15lf|%24.15lf|\n", i, count, res, fabs(standart_function(p_x) - res));
		}
		printf("|------------------------|-------------------------------|------------------------|\n");
		exit(EXIT_SUCCESS);
	}
}