#pragma once

double factorial_N(int N);

double taylor_exp(double point_x, double accuracy, int num_elements, int* count_terms);

double taylor_sin(double point_x, double accuracy, int num_elements, int* count_terms);

double taylor_cos(double point_x, double accuracy, int num_elements, int* count_terms);

double taylor_arctg(double point_x, double accuracy, int num_elements, int* count_terms);