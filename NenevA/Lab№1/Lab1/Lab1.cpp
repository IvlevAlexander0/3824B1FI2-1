#include <stdio.h>
int main() {
	float w, d, h, m1, m2, m3, m4, m5, chipboard, fiberboard, wood, res;
	int c;
	chipboard = 0.7;//плотность ДСП(г/см^2)
	fiberboard = 0.82;//плотность ДВП(г/см^2)
	wood = 0.5;//плотность дерева(г/см^2)
	do {
		printf("Enter the data: width(80<=w<=120), depth(50<=d<=90) and height(180<=h<=220) of the cabinet\n");
		c = scanf_s("%f%f%f", &w, &d, &h);
		char flag;
		while ((flag = getchar()) != '\n' && flag != EOF) {}
	} while (c != 3 || w < 80 || w>120 || 50 > d || 90 < d || 180 > h || 220 < h);
	m1 = h * w * 0.5 * fiberboard;//масса задней стенки
	m2 = 2 * h * d * 1.5 * chipboard;//масса боковых стенок
	m3 = 2 * w * d * 1.5 * chipboard;//масса крышек
	m4 = 2 * w * h * wood;//масса дверей 
	if (h / 41 == int(h) / 41)
	{
		m5 = int(h) / 41 * (w - 3) * d * chipboard;//масса полок
	}
	else
	{
		m5 = ((int(h) / 41) - 1) * (w - 3) * d * chipboard;//таким образом, например, при h =180 будет 
		//лишь 3 полки, а не 4; поскольку в оставшиеся ~56 см нельзя поместить ещё одну полку
	}
	res = (m1 + m2 + m3 + m4 + m5) / 1000.0;
	printf("cabinet's mass = %.3f kg", res);
	return 0;
}