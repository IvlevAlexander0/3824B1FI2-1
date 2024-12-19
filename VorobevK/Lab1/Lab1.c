#include <stdio.h>
#include <math.h>
//no user interface included
void main(){
    double h,w,d;
    double dvpdens = 0.79, dspdens = 0.7, wooddens = 0.63; //values vary alot, taken random in the range, [grams per cm cubed]
    char c;
    do{
        int a=scanf("%lf %lf %lf",&h,&w,&d);
        if((a!=3)||(h>220)||(h<180)||(w>120)||(w<80)||(d>90)||(d<50)){
            while((c=getchar())!='\n' && c!=EOF){}
            continue;
        }
        break;
    }while(1);
    double backside=h*w*0.5*dvpdens;
	double sides=2*h*d*1.5*dspdens;
	double topandbottom=2*w*d*1.5*dspdens;
	double doors=2*h*w*wooddens;
	int shelvescount=h/41; //shelves need to be fucntional, there's no need in one if it's touching the bottom.
    double shelvesweigt=shelvescount*d*w*dspdens;
    double overall=backside+sides+topandbottom+doors+shelvesweigt;
    printf("%lf gramms",overall);
}