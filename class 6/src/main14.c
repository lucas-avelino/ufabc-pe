#include <stdio.h>
#include "geometria.h"

/*  Devolve 1 se o interior dos triângulos a e b se 
    intersectam e devolve 0 caso contrário. */
//  int intersecta(triangulo a, triangulo b);
int main() {
  triangulo a, b;

  while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
	      &a.p.x, &a.p.y, &a.q.x, &a.q.y, &a.r.x, &a.r.y, &b.p.x,
	      &b.p.y, &b.q.x, &b.q.y, &b.r.x, &b.r.y) == 12) {
    printf("%d\n", intersecta_tri(a, b));
  }

  return 0;
}



