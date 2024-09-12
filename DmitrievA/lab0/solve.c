#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>

int main()
{
    const double delta = 0.000000000000001;
	double x1, x2, y1, y2, r1, r2;
    printf("Enter the x coordinate of the center of the first circle: ");
	scanf("%lf", &x1);
    printf("\nEnter the y coordinate of the center of the first circle: ");
	scanf("%lf", &y1);
    printf("\nEnter the radius of the first circle: ");
	scanf("%lf", &r1);
    printf("\nEnter the x coordinate of the center of the second circle: ");
	scanf("%lf", &x2);
    printf("\nEnter the y coordinate of the center of the second circle: ");
	scanf("%lf", &y2);
    printf("\nEnter the radius of the second circle: ");
	scanf("%lf", &r2);
    printf("\n");
	double d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    double sd = sqrt(d);
    //printf("%lf %lf %lf", d + delta, (r1+r2)*(r1+r2), d - delta);
    if ((r1 == r2) && (x1 == x2) && (y1 == y2)){
        printf("The circles are the same.");
    }
    else if (d > (r1+r2)*(r1+r2)){
        printf("The circles do not intersect.");
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
        printf("the circles touch each other externally at a point (%lf, %lf).", x3, y3);
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
        printf("The circles intersect at two points: (%lf, %lf), (%lf, %lf).", x3, y3, x4, y4);
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
        printf("the circles touch each other internally at a point (%lf, %lf).", x3, y3);
    }
    else {
        printf("One circle is inside another and they do not intersect.");
    }
	return 0;
}                                                                           