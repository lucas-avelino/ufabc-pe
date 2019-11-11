/* 
############################################################################
###                                                                      ###
###                                                                      ###
###    ATENÇÃO:                                                          ###
###                                                                      ###
###    Não mudar nada desse arquivo, exceto onde estiver indicado com    ###
###                                                                      ### 
###    // ... seu código aqui.                                           ###
###                                                                      ###
###                                                                      ###
############################################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "lista.h"

no *cria(item dado)
{
    no* p = malloc(sizeof(no));
    *p = (no) {dado, NULL};

    return p;
}

void exclui(no *x)
{
    free(x);
}

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

no *busca(no *cabeca, item dado)
{
    if(cabeca->dado == dado){
        return cabeca;
    }
    while(cabeca != NULL && cabeca->prox != NULL){
        cabeca = cabeca->prox;
        if(cabeca->dado == dado){
            return cabeca;
        }
    }
    return NULL;
}

no *busca_rec(no *cabeca, item dado)
{
    if(cabeca == NULL)
        return NULL;
    if(cabeca->dado == dado)
        return cabeca;
    return busca_rec(cabeca->prox, dado);
}

no * final(no *cabeca)
{
    if(cabeca == NULL){
        return cabeca;
    }
    while(cabeca->prox != NULL){
        cabeca = cabeca->prox;
    }
    return cabeca;
}
