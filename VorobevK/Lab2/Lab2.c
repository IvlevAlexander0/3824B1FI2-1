#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//minimal user interface
int main(){
    //printf("%d",RAND_MAX); 32767
    int mode, counter=0;
    char c;//easier to create c and counter here instead of inside each mode
    srand(time(NULL));//obviously "inspired" by internet, but actually works
    scanf("%d", &mode); //assuming all inputs are valid
    if(mode==1){
        int inp, r = rand()%1000;
        do{
            scanf("%d",&inp);//they are all valid, right? Right...?
            counter+=1;
            while((c=getchar())!='\n' && c!=EOF){}//works even w/o it, but better be safe than sorry
            if(inp>r){
                printf("take lower\n");
            }else if(inp<r){
                printf("take higher\n");
            }else{
                printf("Correct! %d tries",counter);
                return 0;//exit(0) but not in pyhton
            }
        }while(1);
    }else{
        int topborder=1000, bottomborder=0, currentguess;
        char inp;
        do{//simlpiest binary search
            currentguess = (topborder+bottomborder)/2;
            printf("%d\n",currentguess);
            while((c=getchar())!='\n' && c!=EOF){}//clearing the buffer just in case, absolutely not because everything breakes without it
            inp=getchar();
            if (inp=='>'){
                bottomborder=currentguess;
            }else{//probably would be better if i'd put a checker that it actually IS a '<' but works anyway if user isn't a moron
                topborder=currentguess;
            }
            counter+=1;
        }while(inp!='=');
        printf("%d tries",counter);
        return 0;//exit(0) but i have no idea where it sends this zero
    }
}