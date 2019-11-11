## Listas ligadas

Arquivos requeridos:

## main.c
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
    #include <string.h>
    #include "item.h"
    #include "lista.h"

    // Lê da entrada padrão uma lista de números e
    // popula uma lista ligada com esses números.
    no *le_lista_inicial()
    {
        int n;

        scanf("%d", &n);

        no *lista = NULL;
        no *ultimo = NULL;

        for (int i = 0; i < n; i++)
        {
            item dado;
            scanf("%d", &dado);

            no *x = cria(dado);

            if (lista == NULL)
                lista = x;
            else
                ultimo->prox = x;
            ultimo = x;
        }

        return lista;
    }

    int main()
    {
        char operacao[20];
        no *lista = le_lista_inicial();

        while (scanf("%s", operacao) == 1)
        {
            if (strcmp(operacao, "is_empty") == 0)
            {
                // imprime "TRUE\n" se a lista estiver vazia
                // e "FALSE\n" caso contrário

                // ... seu código aqui.
            }
            else if (strcmp(operacao, "push_front") == 0)
            {
                // lê um item x, cria novo nó com dado = x e
                // insere nó criado no início da lista
                item dado;
                scanf("%d", &dado);

                // ... seu código aqui.
            }
            else if (strcmp(operacao, "push_back") == 0)
            {
                // lê um item x, cria novo nó com dado = x e
                // insere nó criado no final da lista
                item dado;
                scanf("%d", &dado);

                // ... seu código aqui.
            }
            else if (strcmp(operacao, "pop_front") == 0)
            {
                // remove o primeiro nó da lista, imprime o
                // campo dado (seu item) na saída padrão e
                // exclui o nó removido
                // imprime "IMPOSSIBLE\n" se a lista estiver vazia

                // ... seu código aqui.
            }
            else if (strcmp(operacao, "pop_back") == 0)
            {
                // remove o último nó da lista, imprime o
                // campo dado (seu item) na saída padrão e
                // exclui o nó removido
                // imprime "IMPOSSIBLE\n" se a lista estiver vazia

                // ... seu código aqui.
            }
            else if (strcmp(operacao, "print") == 0)
            {
                // imprime os itens na lista na ordem
                // da esquerda para a direita
                // imprime só o '\n' se a lista estiver vazia

                imprime_lista(lista);
            }
            else if (strcmp(operacao, "search") == 0)
            {
                // lê um item x e busca por x na lista
                // imprime -1 se x não for encontrado ou
                // o índice do nó que contem o dado x
                // (0 se for 1º nó, 1 se for o segundo, etc.)
                // sempre imprimir o '\n' no final
                item dado;
                scanf("%d", &dado);

                // ... seu código aqui.
            }
            else if (strcmp(operacao, "clear") == 0)
            {
                // exclui todos os nós da lista, deixando-a vazia

                // ... seu código aqui.
            }
            else
            {
                // Nesse caso a operação lida não é válida

                printf("INVALID OPERATION\n");
            }
        }

        return 0;
    }
## lista.c
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

        // ... seu código aqui.
    }

    void exclui(no *x)
    {

        // ... seu código aqui.
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

        // ... seu código aqui.
    }

    no *busca_rec(no *cabeca, item dado)
    {

        // ... seu código aqui.
    }

    no * final(no *cabeca)
    {

        // ... seu código aqui.
    }

