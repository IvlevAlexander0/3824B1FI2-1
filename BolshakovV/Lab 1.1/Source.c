#include <stdio.h>
int main() {
	double h, w, d; /*h-height, w-width, d-depth*/
	double sten, bok, kr, ndr, polka;
	double dwp, dsp, wood;
	int flag;
	int c;
	dwp = 0.82;
	dsp = 0.8;
	wood = 0.6;
	double M;
	int n;
	printf("Get ready to enter the values\n");
	printf("h - height (180.0 <= h <= 220.0 cm), w - width (80.0 <= w <= 120.0 cm), d -  depth (50.0 <= d <= 90.0 cm)\n");
	do {
		flag = 0;
		int r = scanf("%lf %lf %lf", &h, &w, &d);
		if ((r != 3) || (h < 180.0 || h > 220.0 || w < 80.0 || w > 120.0 || d < 50.0 || d > 90.0)) {
			flag = 1;
			printf("Error. Please enter the correct values\n");
		}
		while ((c = getchar()) != '\n' && c != EOF)
		{
		}
	} while (flag != 0);

	sten = h * w * 0.5 * dwp;
	bok = 2 * h * d * 1.5 * dsp;
	kr = 2 * w * d * 1.5 * dsp;
	ndr = 2 * h * w * 1 * wood;
	n = (h - 3) / (40 + 1);

	/*	if (h < 208) {
		n = 4;}
		else { n = 5 ; } */

	//printf("%d\n", n);
	polka = n * (w - 3) * d * 1 * dsp;
	M = sten + bok + kr + ndr + polka;
	printf("Weight in grams = %f", M);
	return 0;
}