#include <stdio.h>

double f(double x){
    return 1 / (1 + x * x);
}

int main(){
    printf("Simpson's 3/8 Rule\n");
    printf("By:\nName:Manan Kasturia\tGroup: 3C13\tEnrollment No.: 05096402723\n");
    int n;
    double a, b;
    printf("Enter the lower limit a: ");
    scanf("%lf", &a);
    printf("Enter the upper limit b: ");
    scanf("%lf", &b);
    printf("Enter the sub-intervals (n should be multiple of 3): ");
    scanf("%d", &n);
    if (n % 3 != 0){
        printf("n must be multiple of 3.");
        return 1;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++){
        double x = a + i * h;
        if (i % 3 == 0){
            sum += 2 * f(x);
        }
        else{
            sum += 3 * f(x);
        }
    }
    double integral = (3 * h / 8) * sum;
    printf("The result is: %.2lf\n", integral);
    return 0;
}