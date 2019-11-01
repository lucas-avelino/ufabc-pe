#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int aloc = 2;
    int* p = (int*) malloc(aloc * sizeof(int));
    p[0] = p[1] = 1;
    do{
        int ret = scanf("%d", &n);
        if(ret > 0){
            if(n > (aloc - 1)){
                p = (int*) realloc(p, (n+1)*sizeof(int));
                for(int i = aloc; i<=n; i++){
                    int a = p[i-1] % i;
                    int b = p[i-2] % i;
                    p[i] = p[a] + p[b];
                }
                aloc = n;
            }
            printf("%d\n", p[n]);
        }else{
            break;
        }
    } while(1);
    free(p);
}