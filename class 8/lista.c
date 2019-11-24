#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "lista.h"

// Aloca memória para um registro do tipo "no".
// Inicializa seu membro "dado" com o dado passado por parâmetro e
// o campo "prox" com um ponteiro nulo.
// Devolve o ponteiro para o registro alocado.
no *cria(item dado)
{
    no *ref = (no *)malloc(sizeof(no));
    ref->dado = dado;

    return (no *)ref;
}

// Libera memória para o registro apontado pelo parâmetro "x".
void exclui(no *x)
{
    free(x->prox);
}

// imprime lista ligada encabeçada pelo nó apontado pelo parâmetro "cabeca".
void imprime_lista(no *cabeca)
{
    no *tmp = cabeca;

    while (tmp != NULL)
    {
        imprime(tmp->dado);
        tmp = tmp->prox;
    }

    printf("\n");
}

// Busca pelo nó da lista ligada encabeçada pelo nó apontado por "cabeca"
// que possui valor armazenado igual ao valor do parâmetro  "dado".
// Devolve um ponteiro para o nó da lista que contém esse valor ou
// um ponteiro nulo caso o valor não se encontre em nenhum nó da lista.
no *busca(no *cabeca, item dado)
{
}

// Faz o mesmo que a função descrita anteriormente, mas de uma forma
// recursiva.
no *busca_rec(no *cabeca, item dado)
{

    // ... seu código aqui.
}

// Devolve um ponteiro para o último nó da lista ou um ponteiro
// nulo caso a lista esteja vazia.
no * final(no *cabeca)
{

    // ... seu código aqui.
}

// Faz uma cópia (deep copy) da lista encabeçada pelo nó apontado
// pelo parâmetro "cabeca".
// Devolve o ponteiro para o primeiro nó da "nova" lista.
no *copia_lista(no *cabeca)
{

    // ... seu código aqui.
}

// Remove o nó seguinte ao nó x, isto é, remove x->prox.
// Supõe que x não é NULL.
// Devolve um ponteiro para o nó removido ou NULL se x->prox == NULL.
no *remove_apos(no *x)
{

    // ... seu código aqui.
}

// Insere o nó apontado por "x" no início da lista que começa com o nó
// apontado por "*p_cabeca".
// Como consequencia, a "cabeça" da lista deverá mudar.
void insere_inicio(no **p_cabeca, no *x)
{

    // ... seu código aqui.
}

// Insere o nó apontado por "x" no fiunal da lista que começa com o nó
// apontado por "*p_cabeca".
// Como é possível que a "cabeça" da lista mude (caso a lista esteja
// vazia), devemos passar um ponteiro para o ponteiro para a "cabeça"
// da lista.
void insere_final(no **p_cabeca, no *x)
{

    // ... seu código aqui.
}

// Retira o primeiro nó da lista encabeçada pelo nó apontado por
// "*p_cabeca". Devolve o ponteiro para o nó removido, ou NULL se a
// lista estiver vazia.
// O campo "prox" do nó removido deve ser ajustado para NULL.
no *remove_inicio(no **p_cabeca)
{

    // ... seu código aqui.
}

// Retira o último nó da lista encabeçada pelo nó apontado por
// "*p_cabeca". Devolve o ponteiro para o nó removido, ou NULL se a
// lista estiver vazia.
no *remove_final(no **p_cabeca)
{

    // ... seu código aqui.
}

// Remove da lista e exclui todos os nós cujo campo
// "dado" seja igual ao item passado como argumento.
// Como o primeiro nó da lista pode ser removido, talvez seja necessário
// alterar a "cabeça" da lista. É por isso que a "cabeça" (que seria
// um ponteiro para o primeiro nó) não é passada por valor para a função,
// mas passamos um ponteiro para a "cabeça", ou seja, um ponteiro para
// um ponteiro para para o primeiro nó, chamado "p_cabeca".
void remove_todos(no **p_cabeca, item dado)
{
    
}

// Faz o mesmo que a função descrita anteriormente, mas de uma forma
// recursiva.
void remove_todos_rec(no **p_cabeca, item dado)
{
    
}

// Troca os elementos da lista de lugar, sem alocar espaço adicional
// na memória principal, somente mudando os ponteiros "prox", de forma
// que a nova lista apontada por "*p_cabeca" tenha exatamente os mesmos
// nós que a lista dada, exceto que estes, agora, estão na ordem reversa.
void inverte(no **p_cabeca)
{

    // ... seu código aqui.
}

// Faz o mesmo que a função descrita anteriormente, mas de uma forma
// recursiva.
void inverte_rec(no **p_cabeca)
{

    // ... seu código aqui.
}
