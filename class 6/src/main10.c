#include <stdio.h>
#include "geometria.h"

/*  Devolve o retângulo resultante da intersecção de 
    dois retângulos fechados passados como argumento. 
    Se a intersecção é vazia, qualquer representação 
    de retângulo vazio serve como resposta da funçao! */
int main() {
  retangulo a, b;

  while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a.ie.x, &a.ie.y,
	      &a.sd.x, &a.sd.y, &b.ie.x, &b.ie.y, &b.sd.x, &b.sd.y) == 8) {
    retangulo r = intersecta_ret(a, b);
    if (r.ie.x > r.sd.x || r.ie.y > r.sd.y)
      printf("vazio\n");
    else
      printf("%.6lf %.6lf %.6lf %.6lf\n", r.ie.x, r.ie.y, r.sd.x, r.sd.y);
  }

  return 0;
}




