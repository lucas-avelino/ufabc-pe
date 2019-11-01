#include <stdio.h>

void imprimir_em_base(int n, int b) {
    //
    // printf("%d", n);
    if(n<0){
        n*=-1;
        printf("-");
    }
    if( (n>0 && b > n) || n<=0 && b > -n){
        printf("%d",n);
    }else{
        imprimir_em_base(n/b,b);
        printf("%d",n%b);
    }
}

int main() {
  int b, n;
  scanf("%d %d", &b, &n);
 
  imprimir_em_base(n, b);
  return 0;
}