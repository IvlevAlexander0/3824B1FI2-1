#include <stdio.h>


int main()
{
    int h, w, d, k, flag=0;
    float t1 = 0.5, t2 = 1.5, t3 = 1.5, t4 = 1., t5 = 1., m, r_wood = 0.52, r_dsp = 0.7, r_dvp = 0.8;

    printf("Enter cabinet height (180 - 220 sm):\n");
    printf("Enter the cabinet width (80 - 120 sm):\n");
    printf("Enter cabinet depth (50 - 90 sm):\n");

    do {
        k = scanf_s("%d %d %d", &h, &w, &d);
        char c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        flag = 0;
        if (k != 3 || (h < 180 || h > 220) || (w < 80 || w > 120) || (d < 50 || d > 90)) {
            flag = 1;
            printf("Uncorrect data! Try again.\n");
        }
    } while (flag == 1);

    m = (h * w * t1) * r_dvp;
    m += 2 * (h * d * t2) * r_dsp;
    m += 2 * (w * d * t3) * r_dsp;
    m += (h * w * t4) * r_wood;
    m += ((int)(h / (40 + (int)t5))) * ((w - 2) * d * t5) * r_dsp;
    //в первой скобке через высоту шкафа, толщину полок и расстония между полками я нахожу их количество. Делю высоту на промежуток между полками + толщину полки
    //во второй скобке я из ширины шкафа вычитаю толщину боковых стенок, чтобы найти ширину полки и считаю её вес
    m = m / 1000;

    printf("The mass of the cabinet: %.2f kg\n", m);

    return 0;
}