//Version 1
//
//#include <stdio.h>
//#include <math.h>
//#include <locale.h>
//main() {
//	setlocale(LC_ALL, "RUS");
//	//float r1=6, r2=2, O1x=7, O2x=14, O1y=5, O2y=8, sum, dist;
//	float r1, r2, O1x, O2x, O1y, O2y, sum, dist;
//	printf("Данные первой окружности(R, x, y):");
//	scanf_s("%f%f%f", &r1, &O1x, &O1y);
//	printf("Данные второй окружности(R, x, y):");
//	scanf_s("%f%f%f", &r2, &O2x, &O2y);
//	dist = sqrt(((O1x-O2x)*(O1x - O2x))+((O1y - O2y)*(O1y - O2y))); //Теорема Пифагора
//	sum = r1 + r2;
//	if (sum == dist) {
//		printf("Окружности касаются друг друга!");
//	}
//	else {
//		if (sum>dist) {
//			printf("Окружности пересекаются в двух точках!");
//		}
//		else {
//			printf("Окружности не пересекаются!");
//		}
//	}
//}
//
// Version 2
//
//#include <stdio.h>
//#include <math.h>
//#include <locale.h>
//main() {
//	setlocale(LC_ALL, "RUS");
//	//float r1=6, r2=2, O1x=7, O2x=14, O1y=5, O2y=8, sum, dist;
//	float r1, r2, O1x, O2x, O1y, O2y, sum, dist;
//	printf("Data of the first circle(R, x, y):");
//	scanf_s("%f%f%f", &r1, &O1x, &O1y);
//	printf("The data of the second circle(R, x, y):");
//	scanf_s("%f%f%f", &r2, &O2x, &O2y);
//	dist = sqrt(((O1x - O2x) * (O1x - O2x)) + ((O1y - O2y) * (O1y - O2y))); //Теорема Пифагора
//	sum = r1 + r2;
//	if (r1 > r2) {
//		if ( (r2 + dist) < r1 ||  dist > (r1+r2) ){
//			printf("Окружности не пересекаются!");
//		}
//		if ( (dist+r2) > r1 && dist < (r1+r2) ) {
//			printf("Окружности пересекаются в двух точках!");
//		}
//		if ( (r2 + dist) == r1 || dist == (r1+r2) ){
//			printf("Окружности касаются друг друга!");
//		}
//	}
//	if (r2 > r1) {
//		if ( (r1 + dist) < r2 || dist > (r2 + r1) ) {
//			printf("Окружности не пересекаются!");
//		}
//		if ( (dist + r1) > r2 && dist < (r2 + r1) ) {
//			printf("Окружности пересекаются в двух точках!");
//		}
//		if ( (r1 + dist) == r2 || dist == (r2 + r1) ) {
//			printf("Окружности касаются друг друга!");
//		}
//	}
//	if (r1 == r2) {
//		if ( dist == 0 ) {
//			printf("Окружности лежат друг на друге!");
//		}
//		if ( dist > 0 && dist < (r1+r2) ) {
//			printf("Окружности пересекаются в двух точках!");
//		}
//		if (dist > (r1 + r2)) {
//			printf("Окружности не пересекаются!");
//		}
//	}
//}

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