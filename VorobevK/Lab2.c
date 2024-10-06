#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//minimal user interface
int main(){
    //printf("%d",RAND_MAX); 32767
    int mode;
    char c;
    srand(time(NULL));//obviously "inspired" by internet, but actually works
    scanf("%d", &mode); //assuming all inputs are valid
    if(mode==1){
        int inp;
        int r = rand()%1000;
        do{
            scanf("%d",&inp);//they are all valid, right? Right...?
            if(inp>r){
                printf("take lower\n");
            }else if(inp<r){
                printf("take higher\n");
            }else{
                printf("Correct!\n");
                return 1;
            }
        }while(1);
    }else{
        int topborder=1000, bottomborder=0, currentguess;
        char inp;
        do{//simlpiest binary search, probably exist easier ways to implement it but it works
            currentguess = (topborder+bottomborder)/2;
            printf("%d\n",currentguess);
            while((c=getchar())!='\n' && c!=EOF){}//clearing the buffer just in case, absolutely not because everything breakes without it
            inp=getchar();
            if (inp=='>'){
                bottomborder=currentguess;
            }else{
                topborder=currentguess;
            }
        }while(inp!='=');
        return 0;
    }
}