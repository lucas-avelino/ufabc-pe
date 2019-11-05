#include <stdio.h>
#include "geometria.h"

//  Calcula o vetor u - v
//  vetor subtrai(vetor u, vetor v);
int main() {
  vetor u, v;

  while(scanf("%lf %lf %lf %lf", &u.x, &u.y, &v.x, &v.y) == 4) {
    vetor d = subtrai(u, v);
    printf("%.6lf %.6lf\n", d.x, d.y);
  }

  return 0;
}

