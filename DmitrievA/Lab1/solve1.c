#include <stdio.h>

void main(){
    double h, d, w, p_dsp, p_dvp;
    printf("Введите высоту (в см): ");
    scanf("%lf", &h);
    if (h > 220 || h < 180){
        printf("Неверное значение высоты");
        return;
    }
    h /= 100;
    printf("Введите глубину (в см):");
    scanf("%lf", &d);
    if (d < 50 || d > 90){
        printf("Неверное значение глубины");
        return;
    }
    d /= 100;
    printf("Введите ширину (в см)");
    scanf("%lf", &w);
    if ( w < 80 || w > 120){
        printf("");
        return;
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