#include <stdio.h>

long pot2(int k) {
  if(k == 0){
      return 1;
  }else{
      return 2*pot2(k-1);
  }
}

int main() {
  int k;
  scanf("%d", &k);
 
  printf("%ld\n", pot2(k));
  return 0;
}