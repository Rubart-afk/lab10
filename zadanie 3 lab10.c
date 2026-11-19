#include <stdio.h>
#include <math.h>

double get_side(void)
{
    double a;

    printf("Введите сторону квадрата: ");
    scanf("%lf", &a);

    return a;
}

double area_square(double a)
{
    return a * a;
}

void definition_square(void)
{
    printf("Квадрат — четырехугольник, у которого все стороны\n");
    printf("равны, а все углы прямые. Наклон не меняет его площадь.\n");
}

double compare_square(double a, double b)
{
    return area_square(a) - area_square(b);
}

void draw_square(double a, double angle)
{
    double rad = angle * acos(-1.0) / 180.0;
    double c = cos(rad);
    double s = sin(rad);
    double half = a / 2.0;
    int size = (int)ceil(half * (fabs(c) + fabs(s))) + 1;
    int i, j;

    for (i = size; i >= -size; i--) {
        for (j = -2 * size; j <= 2 * size; j++) {
            double x = j / 2.0;
            double y = i;

            double u = x * c + y * s;
            double v = -x * s + y * c;

            if ((fabs(fabs(u) - half) <= 0.5 &&
                 fabs(v) <= half + 0.5) ||
                (fabs(fabs(v) - half) <= 0.5 &&
                 fabs(u) <= half + 0.5))
                printf("*");
            else
                printf(" ");
        }

        printf("\n");
    }
}

int main(void)
{
    double a, b, angle, difference;
    int choice;

    a = get_side();

    printf("1. Рассчитать площадь\n");
    printf("2. Вывести определение фигуры\n");
    printf("3. Нарисовать контур фигуры\n");
    printf("4. Сравнить площади двух квадратов\n");
    printf("Выберите операцию: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Площадь квадрата: %.2f\n", area_square(a));
            break;

        case 2:
            definition_square();
            break;

        case 3:
            printf("Введите угол наклона в градусах: ");
            scanf("%lf", &angle);
            draw_square(a, angle);
            break;

        case 4:
            printf("Для второго квадрата:\n");
            b = get_side();

            difference = compare_square(a, b);

            printf("Разность площадей: %.2f\n", difference);

            if (difference > 0)
                printf("Площадь первого квадрата больше.\n");
            else if (difference < 0)
                printf("Площадь второго квадрата больше.\n");
            else
                printf("Площади равны.\n");

            break;
    }

    return 0;
}