#include <stdio.h>
#include "geometria.h"

/*  Retorna 1 se o coseno do ângulo entre os vetores u e v é positivo
    e retorna -1 se for negativo e 0 se for nulo. */
//  int sinal_do_coseno(vetor u, vetor v);
int main() {
  vetor u, v;

  while(scanf("%lf %lf %lf %lf", &u.x, &u.y, &v.x, &v.y) == 4) {
    int sinal = sinal_do_coseno(u, v);
    printf("%d\n", sinal);
  }

  return 0;
}

