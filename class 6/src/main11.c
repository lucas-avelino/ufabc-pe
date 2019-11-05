#include <stdio.h>
#include "geometria.h"

/*  Devolve a cordenada do ponto em que s e t se intersecta
    caso eles se intersectem ou qualquer ponto caso contrário. */
//  ponto cruzamento(segmento s, segmento t);
int main() {
  segmento s, t;

  while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &s.p.x, &s.p.y,
	      &s.q.x, &s.q.y, &t.p.x, &t.p.y, &t.q.x, &t.q.y) == 8) {
    ponto p = cruzamento(s, t);
    
    printf("%.4lf %.4lf\n", ((int) (p.x * 1000000)) / 1000000.0,
	   ((int) (p.y * 1000000)) / 1000000.0);
  }

  return 0;
}


