#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>

int main()
{
    const double delta = 0.000000000000001;
	double x1, x2, y1, y2, r1, r2;
    printf("Введите координату x центра первой окружности: ");
	scanf("%lf", &x1);
    printf("\nвведите координату y центра первой окружности: ");
	scanf("%lf", &y1);
    printf("\nВведите длину радиуса первой окружности: ");
	scanf("%lf", &r1);
    printf("\nВведите координату x центра второй окружности: ");
	scanf("%lf", &x2);
    printf("\nВведите координату y центра второй окружности: ");
	scanf("%lf", &y2);
    printf("\nВведите длину радиуса второй окружности: ");
	scanf("%lf", &r2);
    printf("\n");
	double d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    double sd = sqrt(d);
    //printf("%lf %lf %lf", d + delta, (r1+r2)*(r1+r2), d - delta);
    if ((r1 == r2) && (x1 == x2) && (y1 == y2)){
        printf("окружности одинаковы");
    }
    else if (d > (r1+r2)*(r1+r2)){
        printf("окружности не пересекаются");
    }
    else if (fabs(d - (r1+r2)*(r1+r2)) <= delta){
        double x3, y3;
        if (x1 > x2){
            x3 = x1 - r1*(x1-x2)/sd;
        }
        else{
            x3 = x1 + r1*(x2-x1)/sd;
        }
        if (y1 > y2){
            y3 = y1 - r1*(y1-y2)/sd;
        }
        else{
            y3 = y1 + r1*(y2-y1)/sd;
        }
        printf("окружности касаются друг друга внешним образом в точке (%lf, %lf)", x3, y3);
    }
    else if (d - delta > (r1-r2)*(r1-r2)) {
        double b = (r1*r1 + sd*sd - r2*r2)/(2*sd);
        double c = sqrt((r1*r1)-b*b);
        double sind = (y1-y2)/sd;
        double cosd = (x1-x2)/sd;
        double x3 = x1 - cosd*b - sind*c;
        double y3 = y1 - sind*b + cosd*c;
        double x4 = x1 - cosd*b + sind*c;
        double y4 = y1 - sind*b - cosd*c;
        printf("окружности пересекаются в двух точках: (%lf, %lf), (%lf, %lf)", x3, y3, x4, y4);
    }
    else if (fabs(d - (r1-r2)*(r1-r2)) <= delta){
        double x3, y3;
        if (x1 > x2){
            x3 = x1 - r1*(x1-x2)/sd;
        }
        else{
            x3 = x1 + r1*(x2-x1)/sd;
        }
        if (y1 > y2){
            y3 = y1 - r1*(y1-y2)/sd;
        }
        else{
            y3 = y1 + r1*(y2-y1)/sd;
        }
        printf("окружности касаются друг друга внутренним образом в точке (%lf, %lf)", x3, y3);
    }
    else {
        printf("Одна окружность находится в другой и они не пересекаются");
    }
	return 0;
}                                                                           