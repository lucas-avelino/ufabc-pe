#include<stdio.h>

int main(){
    int i;
    int n;
    scanf("%d", &n);
    int maiorIndex, maiorNumero = 0;
    for(i = 2; i<=n; i+=2){
        int val = i*i;
        printf("%d%s = %d\n", i, "^2", val);
    }
}