#include <stdio.h>
#include <stdlib.h>

void print(int k, double *v) {
  for (int i = 0; i < k; i ++)
    printf("%lf ", v[i]);
  printf("\n");
}

int main(int ac, char **av) {
  if (ac != 2) {
    fprintf(stderr, "group <n>\n");
    return 1;
  }

  int k = atoi(av[1]);
  double v[k];
  while (1) {
    int read, i;
    
    for (i = 0; i < k; i ++)
      read = scanf("%lf", v + i);
    
    if (read != 1) {
      if (i) {
	fprintf(stderr, "Input not multiple of %d.\n", k);
	fprintf(stderr, "Printing last line anyway.\n");
	print(i, v);
      }
      
      break;
    }
    
    print(k, v);
  }

  return 0;
}
