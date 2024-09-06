#include <stdio.h>
#include <math.h>
#include <locale.h>

int check(int x1, int y1, int r1, int x2, int y2, int r2) {
	double s = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (r1 + r2 < s || r1 > s + r2 || r2 > s + r1) {
		return 1;
	}
	else if (r1 + r2 == s || r1 + s == r2 || r2 + s == r1) {
		return 2;
	}
	else {
		return 3;
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int x1, y1, r1 = 0, x2, y2, r2 = 0;
	printf("Введите информацию о первой окружности: ");
	while (r1 == 0) {
		scanf_s("%d%d%d", &x1, &y1, &r1);
		if (r1 == 0) {
			printf("Ошибка! Радиус не может быть равен 0. Введите корректную информацию.\n");
		}
	}
	printf("Введите информацию о второй окружности: ");
	while (r2 == 0) {
		scanf_s("%d%d%d", &x2, &y2, &r2);
		if (r2 == 0) {
			printf("Ошибка! Радиус не может быть равен 0. Введите корректную информацию.\n");
		}
	}
	switch (check(x1, y1, r1, x2, y2, r2)) {
	case(1):
		printf("Окружности не пересекаются\n");
		break;
	case(2):
		printf("Окружности касаются\n");
		break;
	case(3):
		printf("Окружности пересекаются\n");
		break;
	default:
		break;
	}
	return 0;
}