#include <stdio.h>
#include <math.h>

double exp_n(double x, int N)
{
    double sum = 0;
    double term = 1;
    int k;

    for (k = 0; k < N; k++) {
        sum += term;
        term *= -x / (k + 1);
    }

    return sum;
}

double exp_eps(double x, double eps)
{
    double sum = 1;
    double term = 1;
    int k = 1;

    do {
        term *= -x / k;
        sum += term;
        k++;
    } while (fabs(term) > eps);

    return sum;
}

int main(void)
{
    double x, eps;
    double result, result_n, result_eps;
    int N;

    printf("Введите x: ");
    scanf("%lf", &x);

    printf("Введите число членов ряда N: ");
    scanf("%d", &N);

    printf("Введите точность eps: ");
    scanf("%lf", &eps);

    result = exp(-x);
    result_n = exp_n(x, N);
    result_eps = exp_eps(x, eps);

    printf("Стандартная функция: %.10f\n", result);
    printf("Сумма N членов ряда: %.10f\n", result_n);
    printf("Ряд с точностью eps: %.10f\n", result_eps);

    printf("Отклонение exp_n: %.10e\n", fabs(result - result_n));
    printf("Отклонение exp_eps: %.10e\n", fabs(result - result_eps));

    return 0;
}