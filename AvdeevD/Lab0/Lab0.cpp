#include <iostream>
#include <stdio.h>
#include <math.h>
int main()
{
    double x1, y1, r1;
    double x2, y2, r2;
    printf("Enter the x, y and radius of first circle: ");
    scanf_s("%lf %lf %lf", &x1, &y1, &r1);
    printf("Enter the x, y and radius of second circle: ");
    scanf_s("%lf %lf %lf", &x2, &y2, &r2);

    double distance = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
    if (r1 > 0 && r2 > 0) {
        if (distance < fabs(r1 - r2)) {
            printf("They don't touch each other.");
        }
        else if (distance == fabs(r1 - r2)) {
            printf("They touch each other.");
        }
        else if (distance < r1 + r2) {
            printf("They cross each other.");
        }
        else if (distance == r1 + r2) {
            printf("They touch each other.");
        }
        else {
            printf("They don't each other.");
        }
    }
    else {
        printf("Error. Input valid numbers.");
    }
}
