#ifndef LISTA
#define LISTA

#include "item.h"

typedef struct s_no no;

struct s_no {
  item dado;
  no * prox;
};

no * cria             (item dado);
void exclui           (no *x);
void imprime_lista    (no *cabeca);
no * busca            (no *cabeca, item dado);
no * busca_rec        (no *cabeca, item dado);
no * final            (no *cabeca);

#endif
