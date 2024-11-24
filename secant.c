#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define e 0.0001

double func(double x)
{
    return pow(x, 3) - 4 * x - 9;
}

int main()
{
    printf("Secant Method\n");
    printf("By~\nName: Manan Kasturia\tGroup: C13\tRoll No.: 050\n");
    double x0, x1, x2, f0, f1, f2;
    int maxitr, count = 1;
    printf("Enter the first assumed root: ");
    scanf("%lf", &x0);
    printf("Enter the second assumed root: ");
    scanf("%lf", &x1);
    printf("Enter the maximum iterations: ");
    scanf("%d", &maxitr);
    while (count <= maxitr)
    {
        f0 = func(x0);
        f1 = func(x1);
        x2 = (x0 * f1 - x1 * f0) / (f1 - f0);
        if (fabs(x1 - x0) < e)
        {
            printf("Root found at x = %lf\n", x1);
            break;
        }
        x0 = x1;
        x1 = x2;
        printf("Iteration %d: x = %lf, f(x) = %lf\n", count, x1, f1);
        count++;
    }
    (count > maxitr) ? printf("\n Root not found within %d iterations.", maxitr) : exit(0);
    return 0;
}