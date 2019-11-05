#include <stdio.h>
#include "geometria.h"

//  Calcula distância
//  double distancia(ponto p, ponto q);
int main() {
  ponto p, q;

  while(scanf("%lf %lf %lf %lf", &p.x, &p.y, &q.x, &q.y) == 4) 
    printf("%.6lf\n", distancia(p, q));

  return 0;
}


