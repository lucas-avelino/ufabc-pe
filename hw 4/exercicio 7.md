## Imprimir em base b
Dados inteiros positivos 0 < b <= 10 e n < 2000000000, nesta ordem, na entrada padrão, imprimir n em base b. 

Sua função deve ser recursiva e ter o cabeçalho:

``void imprimir_em_base(int n, int b);``
Use o esqueleto:

    #include <stdio.h>

    void imprimir_em_base(int n, int b) {
        // seu código aqui ...
    }
    
    int main() {
        int b, n;
        scanf("%d %d", &b, &n);
        
        imprimir_em_base(n, b);
        return 0;
    }