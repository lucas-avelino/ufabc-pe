#include <stdio.h>
#include "geometria.h"

//  Calcula o ponto que é a projeção de p no segmento s. 
//  ponto projeta(ponto r, segmento s);
int main() {
  ponto r;
  segmento s;

  while(scanf("%lf %lf %lf %lf %lf %lf", &r.x, &r.y,
	      &s.p.x, &s.p.y, &s.q.x, &s.q.y) == 6) {
    ponto p = projeta(r, s);
    printf("%.6lf %.6lf\n", p.x, p.y);
  }

  return 0;
}




