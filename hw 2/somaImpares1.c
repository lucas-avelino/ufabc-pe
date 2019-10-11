#include<stdio.h>

int main(){
    int i = 0;

        int j, soma = 0;
        int x, y;
        scanf("%d %d", &x, &y);
        j = x;
        while(j != y && j != y-1 && j != y+1){
            if(x < y){j++;}
            if(x > y){j--;}

            if(j % 2 != 0){
                soma += j;
            }
        }
        printf("%d\n", soma);
    

}