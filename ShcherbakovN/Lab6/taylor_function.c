#define _USE_MATH_DEFINES // чтобы использовать число pi: M_PI (pi) и M_PI_2 (pi/2)
#include <stdio.h>
#include <math.h>

double factorial_N(int N)
{
	double F = 1.0;
	for (int i = 2; i <= N; i++)
	{
		F *= i;
	}
	return F;
}

double taylor_exp(double point_x, double accuracy, int num_elements, int* count_terms) //exp(x)=1 + x + x^2/2! +x^3/3! + ... + x^n / n!
{
	double res = 0, difference = 0;
	for (int i = 1; i <= num_elements; i++)
	{
		difference = res;
		res += pow(point_x, i - 1) / factorial_N(i - 1);
		*count_terms += 1;
		if (fabs(res - difference) < accuracy) // fabs() - возвращает абсолютное значение числа (модуль)
			break;
	}
	return res;
}

double taylor_sin(double point_x, double accuracy, int num_elements, int* count_terms) //sin(x)=x - x^3/3! + x^5/5! + ... + (-1)^n-1 * (x^2n-1 / (2n-1)! )
{
	double res = 0, difference = 0, reduced_point_x = point_x;

	if (point_x > 2 * M_PI) //Так как при больших значениях point_x ряд расходится, можно свести к промежутку от 0 до 2*pi, так как период sin равен 2*pi
	{
		while (reduced_point_x > 2 * M_PI)
		{
			reduced_point_x -= 2 * M_PI;
		}
		res = taylor_sin(reduced_point_x, accuracy, num_elements, count_terms);
		return res;
	}

	if (point_x < 0) //Так как при больших значениях point_x ряд расходится, можно свести к промежутку от 0 до 2*pi, так как период sin равен 2*pi
	{
		while (reduced_point_x < 0)
		{
			reduced_point_x += 2 * M_PI;
		}
		res = taylor_sin(reduced_point_x, accuracy, num_elements, count_terms);
		return res;
	}

	for (int i = 1; i <= num_elements; i++)
	{
		difference = res;
		res += (pow(-1.0, i - 1) * pow(point_x, 2 * i - 1)) / factorial_N(2 * i - 1);
		*count_terms += 1;
		if (fabs(res - difference) < accuracy)
			break;
	}
	return res;
}

double taylor_cos(double point_x, double accuracy, int num_elements, int* count_terms) //cos(x)=1 - x^2/2! + x^4/4! + ... + (-1)^n-1 * (x^2n-2 / (2n-2)! )
{
	double res = 0, difference = 0, reduced_point_x = point_x;

	if (point_x > 2 * M_PI) //Так как при больших значениях point_x ряд расходится, можно свести к промежутку от 0 до 2*pi, так как период cos равен 2*pi
	{
		while (reduced_point_x > 2 * M_PI)
		{
			reduced_point_x -= 2 * M_PI;
		}
		res = taylor_cos(reduced_point_x, accuracy, num_elements, count_terms);
		return res;
	}

	if (point_x < 0) //Так как при больших значениях point_x ряд расходится, можно свести к промежутку от 0 до 2*pi, так как период cos равен 2*pi
	{
		while (reduced_point_x < 0)
		{
			reduced_point_x += 2 * M_PI;
		}
		res = taylor_cos(reduced_point_x, accuracy, num_elements, count_terms);
		return res;
	}

	for (int i = 1; i <= num_elements; i++)
	{
		difference = res;
		res += (pow(-1.0, i - 1) * pow(point_x, 2 * i - 2)) / factorial_N(2 * i - 2);
		*count_terms += 1;
		if (fabs(res - difference) < accuracy)
			break;
	}
	return res;
}

double taylor_arctg(double point_x, double accuracy, int num_elements, int* count_terms) //arctg(x)=x - x^3/3 + x^5/5 - x^7/7 + ... + (-1)^n-1 * (x^2n-1 / 2n-1)
{
	double res = 0, difference = 0;
	if (fabs(point_x) > 1.0) // Так как ряд расходится при x > 1, то можно воспользоваться формулой arctg(x) + arctg(1/x) = pi/2, то есть acrtg(x) = pi/2 - arctg(1/x)
	{
		double inversion_poin_x = 1.0 / point_x;
		res = taylor_arctg(inversion_poin_x, accuracy, num_elements, count_terms);
		if (inversion_poin_x > 0) // так как arctg(x) - нечётная функция, то есть arctg(-x) = - arctg(x)
		{
			res = M_PI_2 - res; // acrtg(x) = pi/2 - arctg(1/x)
		}
		else
		{
			res = res - M_PI_2; // acrtg(-x) = -arctg(x) = -(pi/2 - arctg(1/x)) = arctg(1/x) - pi/2
		}
		return res;
	}
	for (int i = 1; i <= num_elements; i++)
	{
		difference = res;
		res += (pow(-1.0, i - 1) * pow(point_x, 2 * i - 1)) / (2 * i - 1);
		*count_terms += 1;
		if (fabs(res - difference) < accuracy)
			break;
	}
	return res;
}