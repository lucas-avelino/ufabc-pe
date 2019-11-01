#include <stdio.h>
#include <string.h>

int eh_palindroma(int n, char *p) {
    if(n == 1 || n == 0){
        return 1;
    }

    return p[0] == p[n-1] && eh_palindroma(n-2, &p[0]+1);
}

int main() {
  int n;
 
  // Vetor com espaço para 1002 carcteres (1001 da palavra mais '\0')
  char palavra[1002];
 
  // Lê uma palavra, não mais que 1001 caractéres
  scanf("%1001s", palavra);
 
  n = strlen(palavra);
 
  if (eh_palindroma(n, palavra)) 
    printf("SIM");
  else 
    printf("NAO");
 
  return 0;
}