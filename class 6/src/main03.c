#include <stdio.h>
#include "geometria.h"

/*  Calcula o vetor resultante da rotação do vetor v
    de um ângulo de 90 graus (no sentido anti-horário). */
//  vetor roda90(vetor v);
int main() {
  vetor v;

  while(scanf("%lf %lf", &v.x, &v.y) == 2) {
    vetor w = roda90(v);
    printf("%.6lf %.6lf\n", w.x, w.y);
  }

  return 0;
}

