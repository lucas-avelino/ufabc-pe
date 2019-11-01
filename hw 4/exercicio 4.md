## Calcular 2^k

Faça uma função recursiva para calcular a k-ésima potência de 2. Sua função deve ter cabeçalho:

`long pot2(int k);`

Use o esqueleto:

    #include <stdio.h>
    
    long pot2(int k) {
        // seu programa aqui ...
    }
    
    int main() {
        int k;
        scanf("%d", &k);
        
        printf("%ld\n", pot2(k));
        return 0;
    }