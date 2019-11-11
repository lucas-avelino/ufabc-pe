#include <stdio.h>
#include "item.h"

int compara(item a, item b) {
  return (a < b) ? -1 : ((a == b) ? 0 : 1);
}

void imprime(item dado) {
  printf("%d ", dado);
}
