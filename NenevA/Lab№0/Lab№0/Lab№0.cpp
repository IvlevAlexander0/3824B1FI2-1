#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	float x1, y1, x2, y2, r1, r2, l, R;
	setlocale(LC_ALL, "Rus");
	printf("Введите координату центра и радиус первой окружности\n");
	scanf_s("%f%f%f", &x1, &y1, &r1);
	printf("Введите координату центра и радиус второй окружности\n");
	scanf_s("%f%f%f", &x2, &y2, &r2);
	l = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	R = r1 + r2;
	if (x1 > 0 && x2 > 0 && y1 > 0 && y2 > 0 && r1 > 0 && r2 > 0) {
		if (x1 == x2 && y1 == y1 && r1 == r2) {
			printf("Окружности совпадают");
		}
		else if (l == R) {
			printf("Окружности касаются");
		}
		else if (l > R) {
			printf("Окружности не пересекаются");
		}
		else if (l < R) {
			if (l > fabsf(r1 - r2)) {
				printf("Окружности пересекаются");
			}
			else if (l == fabsf(r1 - r2)) {
				printf("Окружности касаются");
			}
			else {
				printf("Окружности не пересекаются");
			}
		}

	}
	else {
		printf("Введены некорректные данные");
	}

}