#include<stdio.h>

int main(){
    int a = 0;
    char string[1001] = {0};
    while(scanf("%s", &string) == 1){
        
        int i = 0;
        int info = 0;

        for(; string[i] != '\0';i++){
            if(string[i] == '('){
                info++;
            }
            if(string[i] == ')'){
                info--;
            }
            if(info < 0){
                break;
            }
        }
        if(info != 0){
            printf("incorrect\n");
        }else{
            printf("correct\n");
        }

    }
}