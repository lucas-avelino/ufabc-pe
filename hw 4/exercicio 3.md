## Mínimo de um vetor v[0..(n-1)]

Faça uma função recursiva para encontrar o valor do menor elemento de um vetor v com índices
de 0 até n − 1. Sua função deve ter o cabeçalho:

`int min(int n, int *v);`

Use o esqueleto:

    #include <stdio.h>

    int min(int n, int *v) {
        // seu código aqui ...
    }
    int main() {
        int n;
        scanf("%d", &n);
        
        int v[n];
        for (int i = 0; i < n; i ++)
        scanf("%d", &v[i]);
        
        printf("%d\n", min(n, v));
        return 0;
    }