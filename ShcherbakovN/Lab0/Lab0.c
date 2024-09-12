#include <stdio.h>
#include <math.h>
main() {
	float r1, r2, x1, x2, y1, y2, sum, dist;
	printf("Data of the first circle(R, x, y):");
	scanf_s("%f%f%f", &r1, &x1, &y1);
	printf("The data of the second circle(R, x, y):");
	scanf_s("%f%f%f", &r2, &x2, &y2);
	dist = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2))); //Теорема Пифагора
	sum = r1 + r2;
	if (r1 > r2) {
		if ( (r2 + dist) < r1 ||  dist > (r1+r2) ){
			printf("The circles don't intersect!");
		}
		if ( (dist+r2) > r1 && dist < (r1+r2) ) {
			printf("The circles intersect at two points!");
		}
		if ( (r2 + dist) == r1 || dist == (r1+r2) ){
			printf("The circles touch each other!");
		}
	}
	if (r2 > r1) {
		if ( (r1 + dist) < r2 || dist > (r2 + r1) ) {
			printf("The circles don't intersect!");
		}
		if ( (dist + r1) > r2 && dist < (r2 + r1) ) {
			printf("The circles intersect at two points!");
		}
		if ( (r1 + dist) == r2 || dist == (r2 + r1) ) {
			printf("The circles touch each other!");
		}
	}
	if (r1 == r2) {
		if ( dist == 0 ) {
			printf("The circles are on top of each other!");
		}
		if ( dist > 0 && dist < (r1+r2) ) {
			printf("The circles intersect at two points!");
		}
		if (dist > (r1 + r2)) {
			printf("The circles don't intersect!");
		}
	}
}