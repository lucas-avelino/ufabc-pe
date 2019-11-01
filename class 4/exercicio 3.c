#include <stdio.h>

int min(int n, int *v) {
    if(n==0)
        return v[0];

    int eleito = min(n-1,v);
    return v[n] > eleito? eleito: v[n];
    
}

int main() {
  int n;
  scanf("%d", &n);
 
  int v[n];
  for (int i = 0; i < n; i ++)
  scanf("%d", &v[i]);
 
  printf("%d\n", min(n-1, v));
  return 0;
}