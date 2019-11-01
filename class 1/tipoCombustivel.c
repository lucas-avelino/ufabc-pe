#include <stdio.h>
// URI: 1134
int main(){
  int command, alcool = 0, gasolina = 0, diesel = 0;
  scanf( "%d", &command);
  while(command !=4 ){
    if(command == 1){
      alcool++;
    }else if(command == 2){
      gasolina++;
    }else if(command == 3){
      diesel++;
    }
    scanf( "%d", &command);
  }
  printf("MUITO OBRIGADO\n");
  printf("Alcool: %d\n", alcool );
  printf("Gasolina: %d\n", gasolina );
  printf("Diesel: %d\n", diesel );
}
