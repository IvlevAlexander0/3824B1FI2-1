#include <stdio.h>
#include <math.h>
enum BOOLEAN {
	False,
	True
};

int main() {
	float v, u;
	float t1, t2;
	enum BOOLEAN flag;
	float s, s1, s2;
	char c;
	int pol;
	int num = 0;
	
	do {
		if (num == 0) {
			flag = False;
			printf("Enter speed of the boat and river (in km/h): ");
			pol = scanf_s("%f%f", &v, &u);
			if (pol != 2 || v < 0 || u < 0) {
				printf("Error. Input valid numbers.\n");
				while ((c = getchar()) != '\n' && c != EOF) {}
				flag = True;
			}
			else {
				num += 1;
				flag = True;
			}
		}
		else {
			flag = False;
			printf("Enter time of travel on lake and on river against the flow (in hours): ");
			pol = scanf_s("%f%f", &t1, &t2);
			if (pol != 2 || t1 < 0 || t2 < 0) {
				printf("Error. Input valid numbers.\n");
				while ((c = getchar()) != '\n' && c != EOF) {}
				flag = True;
			}
		}
	} while (flag);
	s1 = v * t1;
	s2 = fabsf(v-u) * t2;
	s = s1 + s2;
	printf("The boat has traveled %.3f kilometres.", s);
	return 0;
}