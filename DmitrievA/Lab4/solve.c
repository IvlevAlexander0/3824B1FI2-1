#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000
#define MAX_STRING_SIZE 20

void flush(){
    int tc;
    while ((tc = getchar()) != '\n' && tc != EOF){}
}
void flushc(char c){
    if (c == '\n'){
        return;
    }
    flush();
}

int main() {

    char products[MAX_SIZE][MAX_STRING_SIZE];
    for(int i = 0; i <MAX_SIZE; i++){
        products[i][0] = '\0';
    }
    int costs[MAX_SIZE];
    int counts[MAX_SIZE];
    for(int i = 0; i<MAX_SIZE; i++){
        counts[i] = 0;
    }
    int discounts[MAX_SIZE];
    int incorrect;
    char c;
    int total_count = 0;
    sprintf(products[1], "bread"); costs[1] = 3; discounts[1] = 45;
    sprintf(products[2], "milk"); costs[2] = 50; discounts[2] = 0;
    sprintf(products[3], "cookies"); costs[3] = 0; discounts[3] = 34;
    sprintf(products[4], "lays"); costs[4] = 123454; discounts[4] = 29;
    sprintf(products[5], "water"); costs[5] = 1345; discounts[5] = 10;
    while(1){
        printf("Choose operation: \n1. Adding a product description to the program for the duration of its operation\n2. “Scanning” the product and displaying its description\n3. “Scanning” the product and adding it to the receipt\n4. Displaying the receipt for the purchase\n5. Generate a final check\n");
        int option;
        int t;
        do{
            printf("Enter number [1-5]: ");
            t = scanf("%d", &option);
        } while (t != 1 || option>5 || option < 1);
        flush();
        switch (option)
        {
        int i;
        int num;
        char code[4];
        double total_total_cost;
        int total_count;
        double total_cost_without_discount;
        double total_discount;
        case 1:
    
            //считывание штрихкода на 50 строк
            do
            {
                printf("Enter barcode (4 digits from 0 to 9):");
                i = 0;
                while ((c = getchar()) != '\n' && c != EOF && i < 4 && c >= '0' && c <= '9')
                {
                    code[i] = c;
                    i++;
                }
                flushc(c);
                if ( !(c >= '0' && c <= '9') && i < 4){
                    printf("You enter not a digit\n");
                    continue;
                } 
                if(i == 4 && c != '\n'){
                    printf("You write more then 4 sybols. It is to much for barcode of product. It will'n saves at all. Would you like to rewrite it? y/n:");
                    incorrect = 0;
                    do
                    {
                        if(incorrect) printf("Write y or n:");
                        c = getchar();
                        incorrect = 1;
                        flushc(c);
                    } while (c !='y' && c != 'n');
                    if(c =='y'){
                        continue;
                    }
                    else{
                        break;
                    }
                }
                num = 0;
                for(int j = 0; j < 4; j++){
                    num *= 10;
                    num += code[j] - '0';
                }
                if(products[num][0] != '\0'){
                    printf("Product with this code alredy exists. Product:\n");
                    printf("Name: %s\nCost: %d\nDiscount: %d\nBarcode: %.4d\n", products[num], costs[num], discounts[num], num);
                    printf("Do you want to rewrite it? y/n");
                    incorrect = 0;
                    do
                    {
                        if(incorrect) printf("Write y or n:");
                        c = getchar();
                        incorrect = 1;
                        flushc(c);
                    } while (c !='y' && c != 'n');
                    if(c == 'y'){
                        break;
                    }
                    else{
                        continue;
                    }
                }
                break;
            } while (1);

            //ввод имени продукта на 30 строк
            do{
                printf("Enter name of product(less than %d symbols): ", MAX_STRING_SIZE);
                i = 0;
                while ((c = getchar()) != '\n' && c != EOF && i < MAX_STRING_SIZE)
                {
                    products[num][i++] = c;
                }
                flushc(c);
                if(i == MAX_STRING_SIZE && c != '\n'){
                    printf("You write more then %d sybols. It is to much for name of product. It will'n saves at all. Would you like to rewrite it? y/n:", MAX_STRING_SIZE-1);
                    incorrect = 0;
                    do
                    {
                        if(incorrect) printf("Write y or n:");
                        c = getchar();
                        incorrect = 1;
                        flushc(c);
                    } while (c !='y' && c != 'n');
                    if(c =='y'){
                        continue;
                    }
                    else{
                        break;
                    }
                }
                if(i == 0){
                    printf("You enter a empty string. Name of product can't be empty.\n");
                    continue;
                }
                break;
            } while(1);
            products[num][i] = '\0';

            printf("Enter price of product in %%(not too much %d): ", INT_MAX);
            int price;
            incorrect = 0;
            do{
                if(incorrect) printf("incorrect number, try again: ");
                t = scanf("%d", &price);
                incorrect = 1;
                flush();
            } while (t != 1 || price < 0);
            costs[num]=price;

            printf("Enter discount of product[0 - 50]: ");
            int discount;
            incorrect = 0;
            do{
                if(incorrect) printf("incorrect number, try again. Write number from 0 to 50: ");
                t = scanf("%d", &discount);
                incorrect = 1;
                flush();
            } while (t != 1 || discount < 0 || discount > 50);
            discounts[num] = discount;
            break;
            //считывание товара на 120 строк кода. мдааа.

        case 2:
            printf("Scanning product:\n ");
            do
            {
                printf("Enter barcode (4 digits from 0 to 9):");
                i = 0;
                while ((c = getchar()) != '\n' && c != EOF && i < 4 && c >= '0' && c <= '9')
                {
                    code[i++] = c;
                }
                flushc(c);
                if ( !(c >= '0' && c <= '9') && i < 4){
                    printf("You enter not a digit\n");
                    continue;
                }
                if(i == 4 && c != '\n'){
                    printf("You write more then 4 sybols. It is to much for barcode.\n");
                    continue;
                }
                break;
            } while (1);
            num = 0;
            for(i = 0; i < 4; i++){
                num *= 10;
                num += code[i] - '0';
            }
            if(products[num][0] == '\0'){
                printf("Product not found.\n");
                break;
            }
            printf("Name: %s\nCost: %d\nDiscount: %d\nBarcode: %.4d\n", products[num], costs[num], discounts[num], num);
            break;
        case 3:
        printf("Scanning product:\n ");
            do
            {
                printf("Enter barcode (4 digits from 0 to 9):");
                i = 0;
                while ((c = getchar()) != '\n' && c != EOF && i < 4 && c >= '0' && c <= '9')
                {
                    code[i++] = c;
                }
                flushc(c);
                if ( !(c >= '0' && c <= '9') && i < 4){
                    printf("You enter not a digit\n");
                    continue;
                } 
                if(i == 4 && c != '\n'){
                    printf("You write more then 4 sybols. It is to much for barcode.\n");
                    continue;
                }
                break;
            } while (1);
            num = 0;
            for(i = 0; i < 4; i++){
                num *= 10;
                num += code[i] - '0';
            }
            if(products[num][0] == '\0'){
                printf("Product not found.\n");
                break;
            }
            counts[num]++;
            total_count++;
            printf("Product add.\n");
            break;
        
        case 4:
            if(total_count == 0){
                printf("You have not scanned any products.\n");
                break;
            }
            total_total_cost = 0;
            total_count = 0;
            total_cost_without_discount = 0;
            printf("%-*s  %9s  %9s  %8s  %10s\n", MAX_STRING_SIZE, "name", "price", "count", "discount", "totat cost");
            for(int j = 0; j < MAX_SIZE; j++){
                if(counts[j] != 0){
                    double total_cost = (100 - discounts[j])*(counts[j]*costs[j])/(double)100;
                    total_total_cost += total_cost;
                    total_cost_without_discount += (counts[j]*costs[j]);
                    total_count += counts[j];
                    printf("%-*s  %9d  %9d  %7.2d%%  %10.2lf\n", MAX_STRING_SIZE, products[j], costs[j], counts[j], discounts[j], total_cost);
                }
            }
            for(int j = 0; j < MAX_STRING_SIZE+44; j++) printf("-");
            printf("\n");
            printf("%-*sTotal count  Total discount  Total cost\n", MAX_STRING_SIZE+5, "");
            total_discount = 100*(total_cost_without_discount - total_total_cost)/total_cost_without_discount;
            printf("%-*s%11d  %13.2lf%%  %10.2lf\n", MAX_STRING_SIZE+5, "", total_count, total_discount, total_total_cost);
            break;
        case 5:
            if(total_count == 0){
                printf("You have not scanned any products.\n");
                break;
            }
            total_total_cost = 0;
            total_count = 0;
            total_cost_without_discount = 0;
            printf("%-*s  %9s  %9s  %8s  %10s\n", MAX_STRING_SIZE, "name", "price", "count", "discount", "totat cost");
            for(int j = 0; j < MAX_SIZE; j++){
                if(counts[j] != 0){
                    double total_cost = (100 - discounts[j])*(counts[j]*costs[j])/(double)100;
                    total_total_cost += total_cost;
                    total_cost_without_discount += (counts[j]*costs[j]);
                    total_count += counts[j];
                    printf("%-*s  %9d  %9d  %7.2d%%  %10.2lf\n", MAX_STRING_SIZE, products[j], costs[j], counts[j], discounts[j], total_cost);
                    counts[j] = 0;
                }
            }
            for(int j = 0; j < MAX_STRING_SIZE+44; j++) printf("-");
            printf("\n");
            printf("%-*sTotal count  Total discount  Total cost\n", MAX_STRING_SIZE+5, "");
            total_discount = 100*(total_cost_without_discount - total_total_cost)/total_cost_without_discount;
            printf("%-*s%11d  %13.2lf%%  %10.2lf\n", MAX_STRING_SIZE+5, "", total_count, total_discount, total_total_cost);
            printf("Do you want to continue y/n: ");
            incorrect = 0;
            do
            {
                if(incorrect) printf("Write y or n:");
                c = getchar();
                incorrect = 1;
                flushc(c);
            } while (c !='y' && c != 'n');
            if(c == 'y'){
                break;
            }
            else{
                return 0;
            }
        default:
            break;
        }

    }
  
}