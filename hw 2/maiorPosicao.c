#include<stdio.h>

int main(){
    int i;
    int maiorIndex, maiorNumero = 0;
    for(i = 1; i<=100; i++){
        int val;
        scanf("%d", &val);
        if(val > maiorNumero){
            maiorNumero = val;
            maiorIndex = i;
        }
    }
    printf("%d\n", maiorNumero);
    printf("%d\n", maiorIndex);
}