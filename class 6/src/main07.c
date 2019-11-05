#include <stdio.h>
#include "geometria.h"

/*  Retorna 1 se os interiores dos segmentos se cruzam
    e retorna 0 caso contrário. */
//  int cruza(segmento s, segmento t);
int main() {
  segmento s, t;

  while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &s.p.x, &s.p.y,
	      &s.q.x, &s.q.y, &t.p.x, &t.p.y, &t.q.x, &t.q.y) == 8) {
    printf("%d\n", cruza(s, t));
  }

  return 0;
}



