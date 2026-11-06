#include <locale.h>
#include <stdio.h>
#include <math.h>

int measurement(const char* name);

int main()
{
    setlocale(LC_CTYPE, "RUS");
    int a = measurement("APP");
    int b = measurement("SSD");
    int c = measurement("LOG");

    printf("\n Проверка инцидента (Два из трёх) \n");
    if ((a && b) || (a && c) || (b && c))
    {
        printf("Инцидент зафиксирован!\n");
    }
    else
    {
        printf("Инцидентов не обнаружено. Все системы в норме.\n");
    }

    return 0;
}
int measurement(const char* name)
{
    int run = 0;
    int warn = 0;
    double x1, x2, x3, Q;
    printf("\n%s:\n", name);
    printf("X[1] = ");
    scanf("%lf", &x1);
    printf("X[2] = ");
    scanf("%lf", &x2);
    for (int i = 2; i < 5; i++)
    {
        printf("X[%d] = ", i + 1);
        scanf("%lf", &x3);

        if (x1 != 0) {
            Q = (x3 - x1) / x1;
            Q = Q * Q;
        }
        else {
            Q = 0;
        }
        x1 = x2;
        x2 = x3;
        if (Q > 1.0)
        {
            run = run + 1;
            if (run >= 2)
            {
                warn = 1;
                printf("Q[%d]=%.6f ПРЕДУПРЕЖДЕНИЕ\n", i + 1, Q);
            }
            else
                printf("Q[%d]=%.6f норма для двух измерений\n", i + 1, Q);
        }
        else
        {
            run = 0;
            printf("Q[%d]=%.6f НОРМА\n", i + 1, Q);
        }
    }
    return warn;
}