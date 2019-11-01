## É palíndromo?

Você deve fazer uma função recursiva em C com o seguinte cabeçalho:

`int eh_palindroma(int n, char *p);`

Que deve decidir se a palavra contida em p é um palíndromo. Ou seja, sua função deve retornar 1 se p é palíndromo e 0 caso contrário. A palavra da entrada não terá mais do que 1001 caracteres. 

Use o esqueleto:

    #include <stdio.h>
    #include <string.h>

    int eh_palindroma(int n, char *p) {
        // seu código aqui ...
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