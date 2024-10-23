#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void flush(){
    int tc;
    while ((tc = getchar()) != '\n' && tc != EOF){}
}

int main() {
    int l;
    printf("input number length: ");
    int incorrect = 0;
    int t = 0;
    // генерация числа
    do{
        if(incorrect){ printf("Incorrect data. Try again: ");}
        t = scanf(" %d", &l);
        flush();
        incorrect = 1;
    }
    while(t != 1 || l < 2 || l > 5);
    int m = 0;
    srand(time(NULL));
    int digits[5] = {0};
    int is_repeat = 0;
    for(int i = 0; i < l; i++){
        int temp_n;
        do{
            is_repeat = 0;
            temp_n =  (rand()%10); 
            for(int j = 0; j < m; j++){
                if(digits[j] == temp_n){
                    is_repeat = 1;
                    //printf("%d %d %d\n", temp_n, j, digits[j]);
                }
            }
            //printf("%d %d %d [%d %d %d %d %d] \n", temp_n, i, is_repeat, digits[0], digits[1], digits[2], digits[3], digits[4]);
        }
        while (is_repeat || ((m == l-1) && (temp_n == 0)));
        digits[m] = temp_n;
        m += 1;
    }
    char temp[5];
    int bulls = 0;
    for(int i = 0; i < l; i++){
        printf("%d", digits[i]);
    }

    while(bulls != l){

        //ввод числа пользователя
        printf("\nInput number: ");
        char tc;
        for(int i = l-1; i >=0; i--){
            char c = getchar();
            printf("%c %d \n", c, i);
            if( c < '0' || c > '9'){
                flush();
                printf("\nInput only number: ");
                i = l;
            }
            else{
                //проверка на неповторяемость цифр
                int flag = 1;
                for(int j = l-1; j > i; j--){
                    if(temp[j] == c){
                        i = l;
                        flush();
                        flag = 0;
                        printf("Input number with unrepeating digits:");
                    }
                }
                if (flag)
                temp[i] = c;
            }
        }
        flush();

        //подсчёт быков и коров
        bulls = 0;
        int cows = 0;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < l; j++){
                if(digits[j] == (temp[i]- '0')){
                    if(i==j){
                        bulls++;
                    }
                    else{
                        cows++;
                    }
                }
            }
        }
        printf("bulls: %d\n", bulls);
        printf("cows: %d\n", cows);
    }
    printf("you guessed number");
    return 0;
    
}