#include <stdio.h>
int main() {
	float w, d, h, m1, m2, m3, m4, m5, r1, r2, r3, res;
	int c;
	r1 = 0.7;//плотность ДСП(г/см^2)
	r2 = 0.82;//плотность ДВП(г/см^2)
	r3 = 0.5;//плотность дерева(г/см^2)
	do {
		printf("Enter the data: width(80<=w<=120), depth(50<=d<=90) and height(180<=h<=220) of the cabinet\n");
		c = scanf_s("%f%f%f", &w, &d, &h);
		char flag;
		while ((flag = getchar()) != '\n' && flag != EOF) {}
	} while (c != 3 || w < 80 || w>120 || 50 > d || 90 < d || 180 > h || 220 < h);
	m1 = h * w * 0.5 * r2;//масса задней стенки
	m2 = 2 * h * d * 1.5 * r1;//масса масса боковых стенок
	m3 = 2 * w * d * 1.5 * r1;//масса крышек
	m4 = 2 * w * h * r3;//масса масса дверей 
	m5 = int(h) / 40 * (w - 3) * d * r1;//масса масса полок
	res = (m1 + m2 + m3 + m4 + m5) / 1000;
	printf("cabinet's mass = %.3f kg", res);
	return 0;
}