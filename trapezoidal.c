#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1 / (1 + x * x);
}

int main() {
    printf("Trapezoidal Formula\n");
    printf("By:~\nName: Manan Kasturia\tGroup: C13\tRoll No.: 050\n");
    double b, a, h, sum, integ;
    unsigned int n;
    printf("\nNumber of sub intervals = ");
    scanf("%d", &n);
    b = 6;
    a = 0;
    h = (b - a) / n;
    sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        sum += 2 * f(a + i * h);
    }
    integ = (h * sum) / 2.0;
    printf("\nRequired Integration = %.2lf\n", integ);
    return 0;
}