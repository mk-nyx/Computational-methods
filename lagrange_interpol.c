#include <stdio.h>

int main(){
    int n;
    printf("Lagrange Interpolation Method\n");
    printf("By~\nName: Manan Kasturia\tGroup: C-13\tRoll No.:050");
    printf("\nEnter the maximum number of points = ");
    scanf("%d",&n);
    double x[100], y[100], x1, term, result = 0.0;
    for(int i = 0; i < n; i++){
        printf("Value of x[%d]: ", i);
        scanf("%lf", &x[i]);
        printf("Value of y[%d]: ", i);
        scanf("%lf", &y[i]);
    }
    printf("Enter the value where interpolated value is to be found: ");
    scanf("%lf", &x1);
    for(int i = 0; i < n; i++){
        term = y[i];
        for(int j = 0; j < n; j ++){
            if(i != j){
                term *= (x1 - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    printf("Interpolated value at x = %lf is y: %lf", x1, result);
    printf("\nInterpolated Polynomial :");
    printf("\nP(x) = ");
    for(int i = 0; i < n; i++){
        printf("(%lf)", y[i]);
        for(int j = 0; j < n; j++){
            if( i != j){
                printf("*(x-%lf) / (%lf-%lf)", x[j], x[i], x[j]);
            }
        }
        if(i < n-1){
            printf(" + ");
        }
    }
    return 0;
}