#include <stdio.h>
enum BOOLEAN {
	False,
	True
};

void main() {
	enum BOOLEAN flag = True;
	long long int h, w, d, pol, num = 0;
	double dsp = 0.5, dvp = 0.82, derevo = 0.55; //В граммах на см^3
	char c;
	float res;
	do { 
		if (num == 0) {
			printf("Enter height of the closet (minimum is 180 cm, maximum is 220 cm): ");
			pol = scanf_s("%lld", &h);
			if (pol != 1 || h < 180 || h > 220) {
				printf("Error. Please, input valid numbers.\n");
				while ((c = getchar()) != '\n' && c != EOF) {}
			}
			else {
				num++;
			}
		}
		else if (num == 1) {
			printf("Enter depth of the closet (from 50 to 90 cm): ");
			pol = scanf_s("%lld", &d);
			if (pol != 1 || d < 50 || d > 90) {
				printf("Error. Please, input valid numbers.\n");
				while ((c = getchar()) != '\n' && c != EOF) {}
			}
			else {
				num++;
			}
		}
		else {
			flag = False;
			printf("Enter width of the closet (from 80 to 120 cm): ");
			pol = scanf_s("%lld", &w);
			if (pol != 1 || w < 80 || w > 120) {
				printf("Error. Please, input valid numbers.\n");
				while ((c = getchar()) != '\n' && c != EOF) {}
				flag = True;
			}
			else {
				num++;
			}
		}
	
	} while (flag);
	int hei = h;
	int numpol = -1;
	while (hei > 0) {
		hei = hei - 40 - 1;
		numpol++;
	}
	printf("%d", numpol);
	res = (h * w * 0.5 * dvp) + (2 * d * h * 1.5 * dsp) + (2 * w * d * 1.5 * dsp) + (h * w * 1 * derevo) + (numpol * d * (w - 3) * dsp);
	printf("Mass of the closet is %.1f gramm or %.4f kilogramms\n", res, (res/1000));
}