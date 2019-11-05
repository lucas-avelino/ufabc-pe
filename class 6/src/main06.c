#include <stdio.h>
#include "geometria.h"

/*  Retorna 1 se p, q e r estão em sentido horário e -1 se for
    anti-horário. Se os pontos forem colineares devolva 0. */
//  int sentido(ponto p, ponto q, ponto r);
int main() {
  ponto p, q, r;

  while(scanf("%lf %lf %lf %lf %lf %lf", &p.x, &p.y,
	      &q.x, &q.y, &r.x, &r.y) == 6) {
    printf("%d\n", sentido(p, q, r));
  }

  return 0;
}


