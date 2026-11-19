#include <stdio.h>
#include <math.h>

double fa(double x)
{
    double y;

    if (x <= 3)
        y = x * x - 3 * x + 9;
    else
        y = 1.0 / (x * x * x + 3);

    return y;
}

double fb(double x)
{
    double y;

    y = x * exp(sin(x * x));

    return y;
}

int main(void)
{
    double x;
    int choice;

    printf("Введите x: ");
    scanf("%lf", &x);

    printf("fa(x)=%f, fb(x)=%f\n", fa(x), fb(x));

    printf("Произведение: %f\n", fa(x) * fb(x));
    printf("Разность квадратов: %f\n",
           fa(x) * fa(x) - fb(x) * fb(x));
    printf("Удвоенная сумма: %f\n", 2 * (fa(x) + fb(x)));

    printf("\n1. Значение первой функции\n");
    printf("2. Значение второй функции\n");
    printf("3. Произведение\n");
    printf("4. Разность квадратов\n");
    printf("5. Удвоенная сумма\n");
    printf("Выберите пункт меню: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("fa(x)=%f\n", fa(x));
            break;
        case 2:
            printf("fb(x)=%f\n", fb(x));
            break;
        case 3:
            printf("Произведение: %f\n", fa(x) * fb(x));
            break;
        case 4:
            printf("Разность квадратов: %f\n",
                   fa(x) * fa(x) - fb(x) * fb(x));
            break;
        case 5:
            printf("Удвоенная сумма: %f\n", 2 * (fa(x) + fb(x)));
            break;
    }

    return 0;
}