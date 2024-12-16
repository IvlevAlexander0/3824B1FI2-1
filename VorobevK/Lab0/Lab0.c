#include <math.h>
#include <stdio.h>
void main(){
    double cer = 0.0000001;
    double x1, y1, r1, x2, y2, r2, maxr, minr;
    int flag = 0,a;
    char c;
    do{
        flag=1;
        a=scanf("%lf %lf %lf",&x1,&y1,&r1);
        if((a!=3)||(r1<0)){
            while((c=getchar())!='\n' && c!=EOF){}
            flag = 0;
        }
    }while(flag!=1);
    do{
        flag=1;
        a=scanf("%lf %lf %lf",&x2,&y2,&r2);
        if((a!=3)||(r2<0)){
            while((c=getchar())!='\n' && c!=EOF){}
            flag = 0;
        }
    }while(flag!=1);
    if(r1>=r2){
        maxr=r1;
        minr=r2;
    }else{
        maxr=r2;
        minr=r1;
    }
    double d = sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
    if(d<(maxr-minr)){printf("Circles dont touch");}
    else if(fabs(maxr-(minr+d))<=cer){printf("Circles touch");}
    else if(d<(r1+r2)){printf("Circles cross");}
    else if(fabs(d-(r1+r2))<=cer){printf("Circles touch");}
    else{printf("Circles dont touch");}
}