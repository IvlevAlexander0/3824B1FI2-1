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

    char products[MAX_SIZE][MAX_STRING_SIZE]; //обьявление массива с названиями продутктов
    for(int i = 0; i <MAX_SIZE; i++){
        products[i][0] = '\0'; // установка первого символа на \0 для каждого имени
    }
    int costs[MAX_SIZE];// цены
    int counts[MAX_SIZE];// количество
    for(int i = 0; i<MAX_SIZE; i++){
        counts[i] = 0;// установление количества на 0 для всех товаров. Я не сделал это с ценами, т.к. цены не будут считываться в дальнейшем, если имя или количество не нулевое
    }
    int discounts[MAX_SIZE];// скидки. Храню в интах. От 0 до 50. Не заполняются нулями по аналогичной причине
    int incorrect; // переменная для проверки корректности ввода. я устал её обьявлять каждый раз при вводе, поэтому просто вынес её в начало программы
    char c; // символ - переменная для посимвольного ввода
    int total_count = 0; // тотальное количество. ещё одна лоботомия с этой переменной. я её обьявил дважды. в этой и в 53 строчке. лучше убери обьявление в 53 строчке и обнуляй её в каждой итерации глаыного цикла
    sprintf(products[1], "bread"); costs[1] = 3; discounts[1] = 45; // добавление товара. функция sprintf записывает строку в массив чаров
    sprintf(products[2], "milk"); costs[2] = 50; discounts[2] = 0;
    sprintf(products[3], "cookies"); costs[3] = 0; discounts[3] = 34;
    sprintf(products[4], "lays"); costs[4] = 123454; discounts[4] = 29;
    sprintf(products[5], "water"); costs[5] = 1345; discounts[5] = 10;
    while(1){ // главный цикл
        printf("Choose operation: \n1. Adding a product description to the program for the duration of its operation\n2. “Scanning” the product and displaying its description\n3. “Scanning” the product and adding it to the receipt\n4. Displaying the receipt for the purchase\n5. Generate a final check\n");
        int option;
        int t;
        do{// ввод опции и проверка ввода
            printf("Enter number [1-5]: ");
            t = scanf("%d", &option);
        } while (t != 1 || option>5 || option < 1);// проверка ввода
        flush();// очиска буфера после ввода
        switch (option)// switch вместо if. в каждом case реализация одной из опций.
        {
        int i;
        int num;
        char code[4];
        double total_total_cost;
        int total_count;
        double total_cost_without_discount;
        double total_discount;// инициализация переменных, которые я устал инициализировать по несколько раз.
        case 1:
    
            //считывание штрихкода на 50 строк
            do// цикл для считывания штрихкода. елси что-то пошло не так, то заставляем пользователя вводить штрихкод снова
            {
                printf("Enter barcode (4 digits from 0 to 9):");
                i = 0;
                while ((c = getchar()) != '\n' && c != EOF && i < 4 && c >= '0' && c <= '9')// посимвольное считывание штрихкода. (c = getchar()) возвращает символ, который считался(присваивание (i = 4) вернёт 4. присваивание возвращает присвоенный символ). проверка на количество введённых символов и то, что это цифры
                {
                    code[i] = c; // занесения символа в массив для штрихкода
                    i++;//увеличение счётчика
                }
                flushc(c);//очистка буфера после ввода. Нужна для ситуаций, когда жопорукий пользователь ввёл больше символов, чем надо.
                if ( !(c >= '0' && c <= '9') && i < 4){ // проверка на то, что мы вышли из цикла не изза того, что пользователь ввёл не символ.
                    printf("You enter not a digit\n"); // если пользователь ввёл не цифру, мы сообщаем ему об этом, и заставляем снова вводить штрихкод
                    continue;
                } 
                if(i == 4 && c != '\n'){//написано в принте ниже
                    printf("You write more then 4 sybols. It is to much for barcode of product. It will'n saves at all. Would you like to rewrite it? y/n:");
                    incorrect = 0; // обнуляем флаг жопорукости
                    do// считываем букву 
                    {
                        if(incorrect) printf("Write y or n:"); // если это не первая попытка , то пользователю сообщится, что от него требуется
                        c = getchar();
                        incorrect = 1;// устанавливаем флаг жопорукости на 1. Елси пользователь ввёл не правильно, то на следующей итерации цикла ему сообщится об этом
                        flushc(c);// смотри cтроку 68
                    } while (c !='y' && c != 'n');// проверка на правильность ввода
                    if(c =='y'){// пользователь хочет перезаписать штрихкод
                        continue;
                    }
                    else{//пользователь не ъочет перезавписать штрихкод
                        break;
                    }
                }
                num = 0;// перевод штрихкода в цисло
                for(int j = 0; j < 4; j++){
                    num *= 10;
                    num += code[j] - '0';//перевод символа в цифру. все цифры в ascii расположены вместе и по порядку
                }
                if(products[num][0] != '\0'){// проверка на то, что продукта с таким штрихкодом ещё нет
                    printf("Product with this code alredy exists. Product:\n");
                    printf("Name: %s\nCost: %d\nDiscount: %d\nBarcode: %.4d\n", products[num], costs[num], discounts[num], num);
                    printf("Do you want to rewrite it? y/n");//надеюсь в пояснениях не нуждается
                    incorrect = 0;//смотри строки 75 - 82. Вообще я бы мог вынести это в отдельную функцию
                    do
                    {
                        if(incorrect) printf("Write y or n:");
                        c = getchar();
                        incorrect = 1;
                        flushc(c);
                    } while (c !='y' && c != 'n');
                    if(c == 'y'){//надеюсь в пояснениях не нуждается
                        break;
                    }
                    else{
                        continue;
                    }
                }
                break;
            } while (1);//конец цикла ввода штрихкода

            //ввод имени продукта на 30 строк
            do{
                printf("Enter name of product(less than %d symbols): ", MAX_STRING_SIZE);
                i = 0;
                while ((c = getchar()) != '\n' && c != EOF && i < MAX_STRING_SIZE)//посимвольный ввод строки
                {
                    products[num][i++] = c;//запись сиволов в название продукта.
                }
                flushc(c);//смотри строчку 68
                if(i == MAX_STRING_SIZE && c != '\n'){//проверка на то, что пользователь ввёл символов больше, чем можно было. максимум вводимых символов - MAX_STRING_SIZE-1, т.к. последний символ должен быть \0
                    printf("You write more then %d sybols. It is to much for name of product. It will'n saves at all. Would you like to rewrite it? y/n:", MAX_STRING_SIZE-1);
                    incorrect = 0;
                    do//смотри строчки 75 - 82. Это точно нужно было вынести в отдельную функцию
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
                if(i == 0){//проверка на то, что пользователь ввёл пустую строку. Имя продукта не может быть пустым. Путь переписывает заново
                    printf("You enter a empty string. Name of product can't be empty.\n");
                    continue;
                }
                break;
            } while(1);// конец цикла ввода назвния
            products[num][i] = '\0';// установка последнего символа на \0. Обрати внимание, что он не всегда в конце массива будет(не на 20 месте)

            printf("Enter price of product in %%(not too much %d): ", INT_MAX);
            int price;//ввод цены. 
            incorrect = 0;//аналогично с вводом y or n (строки 75 - 82)
            do{
                if(incorrect) printf("incorrect number, try again: ");
                t = scanf("%d", &price);
                incorrect = 1;
                flush();
            } while (t != 1 || price < 0);// проврека на то, что цена не отрицательна
            costs[num]=price;

            printf("Enter discount of product[0 - 50]: ");//ввод скидки
            int discount;
            incorrect = 0;//аналогично с вводом y or n (строки 75 - 82)
            do{
                if(incorrect) printf("incorrect number, try again. Write number from 0 to 50: ");
                t = scanf("%d", &discount);
                incorrect = 1;
                flush();
            } while (t != 1 || discount < 0 || discount > 50);// проверка на то, что скидка находится от 0 до 50 
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