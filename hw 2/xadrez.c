#include<stdio.h>
// NÃO EFICIENTE
int main(){
    int xDama, yDama, xDestino, yDestino;
    scanf("%d %d %d %d" , &xDama, &yDama, &xDestino, &yDestino);

    int i;
    while(xDama != 0 && yDama != 0 &&xDestino != 0 &&yDestino != 0){
        for(i = 1; i <= 8; i++){ 
            if(xDama == xDestino && yDama == yDestino){
                printf("0\n");
                break;
            }
            if(xDama + i == xDestino && yDama + i == yDestino){// diagonal ++
                printf("1\n");
                break;
            }
            if(xDama - i == xDestino && yDama + i == yDestino){// diagonal -+
                printf("1\n");
                break;
            }
            if(xDama + i == xDestino && yDama - i == yDestino){// diagonal +-
                printf("1\n");
                break;
            }
            if(xDama - i == xDestino && yDama - i == yDestino){// diagonal --
                printf("1\n");
                break;
            }
            if(xDama + i == xDestino && yDama == yDestino){// vertical +
                printf("1\n");
                break;
            }
            if(xDama - i == xDestino && yDama == yDestino){// vertical -
                printf("1\n");
                break;
            }
            if(xDama == xDestino && yDama + i == yDestino){// horizontal +
                printf("1\n");
                break;
            }   
            if(xDama == xDestino && yDama - i == yDestino){// horizontal -
                printf("1\n");
                break;
            }
        }
        if(i == 9){
            printf("2\n");
        }
        scanf("%d %d %d %d" , &xDama, &yDama, &xDestino, &yDestino);
    }
}