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

no *cria(item dado) {



      // ... seu código aqui.


  
}
  
void exclui(no *x) {



      // ... seu código aqui.


  
}

void imprime_lista(no *cabeca) {
  no *tmp = cabeca;
  
  while (tmp != NULL) {
    imprime(tmp->dado);
    tmp = tmp->prox;
  }

  printf("\n");
}

no *busca(no *cabeca, item dado) {



      // ... seu código aqui.



}

no *busca_rec(no *cabeca, item dado) {



      // ... seu código aqui.



}

no *final(no *cabeca) {



      // ... seu código aqui.



}
