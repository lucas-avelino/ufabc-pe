#include <stdio.h>

int soma(int n, int *v) {
    int soma = 0;
    for (int i = 0; i < n; i ++)
        soma += v[i];
    return soma;
}


int main() {
  int n;
  scanf("%d", &n);
  
  int v[n];
  for (int i = 0; i < n; i ++)
  scanf("%d", &v[i]);
  
  printf("%d\n", soma(n, v));
  return 0;
}