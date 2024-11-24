#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) pow(x, 3) - 4 * x - 9
const float e = 0.0001;

int main(){
    float x0, x1, x2, f0, f1, f2;
    int i = 0, maxitr;
    up:
    printf("Enter the 1st assumed root = ");
    scanf("%f", &x0);
    printf("Enter the 2nd assumed root = ");
    scanf("%f", &x1);
    printf("Enter the maximum number of iterations = ");
    scanf("%d", &maxitr);
    f0 = f(x0);
    f1 = f(x1);
    if (f0 * f1 > 0){
        printf("Error\n");
        goto up;
    }

    do{
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        if(f0 * f2 < 0){
            x1 = x2;
        }
        else{
            x0 = x2;
        }
        i++;
        if (i > maxitr){
            printf("Stopped\n");
            exit(0);
        }
        printf("Iteration number = %d\n", i);
        printf("Root = %f\n", x2);
        printf("Value of function at %f = %f\n", x2, f(x2));
    }
    while(fabs(x0 - x1) >= e);

    return 0;
}