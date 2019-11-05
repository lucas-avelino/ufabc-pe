#include <stdio.h>
#include "geometria.h"

//  Calcula o produto interno <u,v>
//  double produto_interno(vetor u, vetor v);
int main() {
  vetor u, v;

  while(scanf("%lf %lf %lf %lf", &u.x, &u.y, &v.x, &v.y) == 4) 
    printf("%.4lf\n", ((int) produto_interno(u, v) * 1000000) / 1000000.0);

  return 0;
}
