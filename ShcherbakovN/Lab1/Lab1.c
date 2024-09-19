#include <stdio.h>
#include <stdlib.h>

int main() {
	float h, w, d, depth1 = 1.5, depth2 = 0.5, depth3 = 1.0, V_back, V_side, V_up_down, V_doors, V_shelfs, m_all;
	float p_dsp = 0.00065, p_dvp = 0.0008, p_wood = 0.00055;
	printf("Enter the height, width and depth for the wardrobe (in centimeters): ");
	if (scanf_s("%f %f %f", &h, &w, &d) != 3) {
		return -1;
		exit(-1);
	}
	else if (h < 180.0 || h>220.0 || w < 80.0 || w>120.0 || d < 50.0 || d>90.0) {
		return -2;
		exit(-2);
	}
	V_back = h * w * depth2;
	V_side = h * d * depth1 * 2;
	V_up_down = w * d * depth1 * 2;
	V_doors = h * w * depth3;
	if (h < 210.5) {
		V_shelfs = d * (w - 2 * depth1) * depth1 * 4;
	}
	else {
		V_shelfs = d * (w - 2 * depth1) * depth1 * 5;
	}
	m_all = (V_back * p_dvp) + (V_side * p_dsp) + (V_up_down * p_dsp) + (V_doors * p_wood) + (V_shelfs * p_dsp);
	printf("Wardrobe weight: %.2f kilograms", m_all);
	return 0;
}