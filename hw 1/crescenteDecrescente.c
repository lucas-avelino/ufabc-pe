#include <stdio.h>
// URI: 1113
int main()
{
    int a, b;
    scanf("%d %d",&a,&b);
    while(a!=b){
        if( a < b ){
            printf("Crescente\n");
        }else{
            if(a > b){
                printf("Decrescente\n");
            }
        }
        scanf("%d %d",&a,&b);
    }
	return 0;
}
