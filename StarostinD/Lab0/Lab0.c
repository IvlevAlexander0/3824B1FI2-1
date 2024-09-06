#include <stdio.h>
#include <math.h>

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
	int x1, y1, r1 = 0, x2, y2, r2 = 0;
	printf("Enter information about the first circle: ");
	while (r1 == 0) {
		scanf_s("%d%d%d", &x1, &y1, &r1);
		if (r1 == 0) {
			printf("Error! Radius can't be equal to 0. Please enter correct information.\n");
		}
	}
	printf("Enter information about the second circle: ");
	while (r2 == 0) {
		scanf_s("%d%d%d", &x2, &y2, &r2);
		if (r2 == 0) {
			printf("Error! Radius can't be equal to 0. Please enter correct information.\n");
		}
	}
	switch (check(x1, y1, r1, x2, y2, r2)) {
	case(1):
		printf("Circles don't intersect\n");
		break;
	case(2):
		printf("Circles touch\n");
		break;
	case(3):
		printf("Circles intersect\n");
		break;
	default:
		break;
	}
	return 0;
}