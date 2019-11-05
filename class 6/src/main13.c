#include <stdio.h>
#include "geometria.h"

/* Devolve 1 se o triângulo é degenerado, isto é
   se seus três vértices são colineares e 0 caso contrário. */
int main() {
  triangulo t;

  while(scanf("%lf %lf %lf %lf %lf %lf", &t.p.x, &t.p.y,
	      &t.q.x, &t.q.y, &t.r.x, &t.r.y) == 6) {
    if (degenerado(t))
      printf("DEGENERADO\n");
    else
      printf("NAO\n");
  }

  return 0;
}




