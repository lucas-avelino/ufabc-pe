## Soma v[0] + v[1] + ... + v[n-1]

Computar a soma dos elementos de um vetor v com índices de 0 até n − 1.

Sua função deve ser recursiva e ter cabeçalho:

`int soma(int n, int *v);`

Use o esqueleto:

    #include <stdio.h>
    int soma(int n, int *v) {
        // seu código aqui ...
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