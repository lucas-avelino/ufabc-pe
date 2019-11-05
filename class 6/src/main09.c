#include <stdio.h>
#include "geometria.h"

// Lê um retângulo definido pelos pontos inferior
// esquerdo e superior direito.

// Imprime VAZIO se for vazio, NAO caso contrário.
int main() {
  retangulo r;

  // ie = inferior esquerdo
  // sd = superior direito
  while(scanf("%lf %lf %lf %lf", &r.ie.x, &r.ie.y,
	      &r.sd.x, &r.sd.y) == 4) {
    if (retangulo_vazio(r))
      printf("VAZIO\n");
    else
      printf("NAO\n");

  }

  return 0;
}


