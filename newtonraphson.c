#include <stdio.h>
#include <math.h>
#define e 0.0001

double f(double x){
    return pow(x, 3) - 3 * x - 9;
}

double df(double x){
    return 3 * x * x - 3;
}

int main(){
    double x0, x1;
    printf("NEWTON RAPHSON METHOD\n");
    printf("By~\nName: Manan Kasturia\tClass: C13\tRoll No.: 050\n");
    printf("Enter initial guess: ");
    scanf("%lf", &x0);
    int i = 1, maxitr;
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxitr);

    while (i <= maxitr){
        x1 = x0 - (f(x0) / df(x0));

        if (fabs(x1 - x0) < e){
            printf("Root found at x = %lf\n", x1);
            break;
        }
        x0 = x1;
        printf("Iteration %d: x = %lf, f(x) = %lf\n", i, x0, f(x0));
        i++;
    }
    if (i > maxitr){
        printf("Root not found within %d iterations\n", maxitr);
    }
    return 0;
}