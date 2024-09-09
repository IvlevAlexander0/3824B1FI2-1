#include<stdio.h>
#include<math.h>
#include<locale.h>
int main() {
	setlocale(LC_ALL, "Rus");
	int r1, r2, d; /*r1 - радиус первой окружности, r2 - радиус второй, d - расстояние между центрами данных окружностей*/
	r1 = 6;
	r2 = 10;
	d = 20;
	if (d == r1 + r2 || d == abs(r1 - r2)) {
		printf("Окружности касаются в одной точке");
	}
	if (d > abs(r1 - r2) && d < (r1 + r2)) {
		printf("Окружности пересекаются в двух точках");

	}
	if (d > (r1 + r2) || d < abs(r1 - r2)) {
		printf("Окружности не имеют общих точек");
	}
	return 0;
}