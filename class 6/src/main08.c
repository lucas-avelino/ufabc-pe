#include <stdio.h>
#include "geometria.h"

/*  Retorna 1 se o ponto p está no interior do triângulo t
    e retorna 0 caso contrário. */
//  int dentro(ponto p, triangulo t);
int main() {
  ponto p;
  triangulo t;

  while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p.x, &p.y,
	      &t.p.x, &t.p.y, &t.q.x, &t.q.y, &t.r.x, &t.r.y) == 8) {
    printf("%d\n", dentro(p, t));
  }

  return 0;
}

