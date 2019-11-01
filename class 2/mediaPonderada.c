#include<stdio.h>

int main(){
    int i;
    int interations;
    scanf("%d", &interations);
    for(i = 0; i<interations; i++){
        double val1, val2, val3;
        scanf("%lf %lf %lf", &val1, &val2, &val3);
        printf("%.1f\n",(2*val1 + 3*val2 + 5*val3)/10);
    }
}