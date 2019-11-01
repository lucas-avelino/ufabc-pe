## String reversa

Faça uma função :

``void reverter(int n, char *p);``

Que recebe uma palavra p com n caracteres e que troca os caracteres de lugar de modo que, após a chamada da função, p contenha a string reversa. 

Use o esqueleto:

    #include <stdio.h>
    #include <string.h>

    void reverter(int n, char *p) {
        // seu código aqui ...
    }
    
    int main() {
        int n;
        
        // Vetor com espaço para 1002 carcteres (1001 da palavra mais '\0')
        char palavra[1002];
        
        // Lê uma palavra, não mais que 1001 caractéres
        scanf("%1001s", palavra);
        
        n = strlen(palavra);
        reverter(n, palavra);
        
        printf("%s\n", palavra);
        
        return 0;
    }