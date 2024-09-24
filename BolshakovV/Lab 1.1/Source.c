#include <stdio.h>

int main() {
	double h, w, d; /*h-height, w-width, d-depth*/
	double sten, bok, kr, ndr, polka;
	double p1, p2, p3 /*p1 - dwp, p2 - dsp, p3- wood*/;
	int flag;
	int c;
	p1 = 0.82;
	p2 = 0.8;
	p3 = 0.6;
	double M;
	int n;
	printf("Get ready to enter the values\n");
	printf("h - height (180.0 <= h <= 220.0 cm), w - width (80.0 <= w <= 120.0 cm), d -  depth (50.0 <= d <= 90.0 cm)\n");
	do {
		flag = 0;
		int r = scanf("%lf %lf %lf", &h, &w, &d);
		if (r != 3) {
			flag = 1;
			printf("Error. Please enter the correct values\n");
		}
		while ((c = getchar()) != '\n' && c != EOF) 
		{}
	} while (flag != 0);

	sten = h * w * 0.5 * p1;
	bok = 2 * h * d * 1.5 * p2;
	kr = 2 * w * d * 1.5 * p2;
	ndr = 2 * h * w * 1 * p3;
	n = h / 40;
	polka = n * w * d * 1 * p2;
	M = sten + bok + kr + ndr + polka;
	printf("Weight in grams = %f", M);
	return 0;
}