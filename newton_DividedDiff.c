#include <stdio.h>

int main() {
    printf("\nNewton's Divided And Difference formula");
    printf("\nBy~\nName: Manan Kasturia\tGroup: C13\tRoll No.: 050\n");
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    double x[n], y[n];
    printf("Enter the data points in the format (x,y): \n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }
    double x1;
    printf("\nEnter the value of x for which you want to interpolate: ");
    scanf("%lf", &x1);
    double result = 0;
    double f[n][n];
    for (int i = 0; i < n; i++) {
        f[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            f[i][j] = (f[i + 1][j - 1] - f[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
    double term = 1;
    result = f[0][0];
    for (int j = 1; j < n; j++) {
        term *= (x1 - x[j - 1]);
        result += f[0][j] * term;
    }
    printf("Interpolated value at x = %lf is %lf\n", x1, result);
    return 0;
}