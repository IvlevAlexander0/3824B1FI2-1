#include <stdio.h>

void main(){
    double h, d, w, p_dsp, p_dvp;
    printf("Input height (in sm): ");
    scanf("%lf", &h);
    while (h > 220 || h < 180){
        printf("Incorrect value. Input value between 180 and 220: ");
        scanf("%lf", &h);
    }
    h /= 100;
    printf("Input depth (in sm):");
    scanf("%lf", &d);
    while (d < 50 || d > 90){
        printf("Incorrect value. Input value between 50 and 90: ");
        scanf("%lf", &d);
    }
    d /= 100;
    printf("Input width (in sm):");
    scanf("%lf", &w);
    while ( w < 80 || w > 120){
        printf("Incorrect value. Input value between 80 and 120: ");
        scanf("%lf", &w);
    }
    p_dsp = 1;
    p_dvp = 1;
    double tp = 0.015; // толщина полок. Так как в задании не указана толщина полок я взял толщину верхней и нижней крышки.

    double mzs = p_dvp*h*w*0.005;
    double mb = 2*p_dsp*h*d*0.015;
    double mupdown = 2*p_dsp*w*d*0.015;
    double md = h*w*0.01;
    int c;
    if (h > 2){
        c = 5;
    }
    else{
        c = 4;
    }
    double mp = c*w*d*tp;
    double m = mzs+mb+mupdown+md+mp;
    printf("mass of closet: %lf", m);
}