#include <stdio.h>
#include <math.h>

int main() {
	float x1, x2, y1, y2, r1, r2, d;

	printf("Input coordinates and radius of the 1st circle (x, y, r):");
	scanf_s("%f %f %f", &x1, &y1, &r1); // Input the 1st circle
	printf("Input coordinates and radius of the 2nd circle (x, y, r):");
	scanf_s("%f %f %f", &x2, &y2, &r2); // Input the 2nd circle

	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	if (d == 0 && r1 == r2) {
		printf("Circles coincide");
	}
	else if (d < fabs(r1 - r2) && (d > 0)) {
		printf("Circles don't intersect (inside)");
	}
	else if (d > (r1 + r2)) {
		printf("Circles don't intersect (outside)");
	}
	else if (d < (r1 + r2) && (d > fabs(r1 - r2))) {
		printf("Circles intersect in two points");
	}
	else if (d == r1 + r2) {
		printf("Circles intersect in one point (outside)");
	}
	else if (d == fabs(r1 - r2)) {
		printf("Circles intersect in one point (inside)");
	}
	return 0;
}