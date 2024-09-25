#include <stdio.h>
#include <math.h>

int main() {

	float h, w, d, m, dvp = 820, dsp = 800, wood = 650, m_back, m_sides, m_ud, m_doors, m_sh;
	int flag = 1;
	/* h - height; w - width; d - depth; m_* - mass of cupboard part; dvp, dsp, wood - material density(kg/m^3)*/
	while (flag == 1) {
		printf("Input height (180-220), width(80-120), depth (50-90) of the cupboard(cm):");
		scanf_s("%f %f %f", &h, &w, &d);
		if ((h >= 180) && (h <= 220) && (w >= 80) && (w <= 120) && (d >= 50) && (d <= 90)) {
			flag = 0;
		}
		else {
			printf("Uncorrect data\n");
		}
		char c;
		while ((c = getchar()) != '\n' && c != EOF) {}
	}
	
	m_back = h * w * 0.5 * dvp;
	m_sides = h * d * 1.5 * dsp * 2;
	m_ud = w * d * 1.5 * dsp * 2;
	m_doors = h * w * wood;

	if (h > 210) {
		m_sh = w * d * 1.5 * dsp * 5;
	} // +1 shelf (enough place to add one more shelf)(10-20cm free place if  210-220cm)	|	1(40)	2(80)	3(120)	4(160)	5(200)  |
	else {
		m_sh = w * d * 1.5 * dsp * 4;
	} // +0 shelf (not enough place for one shelf)	|	1(40)	2(80)	3(120)	4(160)	|

	m = (m_back + m_sides + m_ud + m_doors + m_sh) / 1000000;

	printf("m = %f kg", m);

	return 0;
}