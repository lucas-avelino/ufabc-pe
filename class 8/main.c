/*
###                                                                      ###
###    Antes de mais nada, complete as funções do arquivo lista.c no     ###
###    espaço reservado para cada uma delas. Depois venha completar      ###
###    o que for pedido neste arquivo.                                   ###
###                                                                      ###
###    ATENÇÃO:                                                          ###
###                                                                      ###
###    Não mudar nada neste arquivo, exceto onde estiver indicado com    ###
###                                                                      ### 
###    // ... seu código aqui.                                           ###
###                                                                      ###
###    use a função le_lista() para ler listas ligadas da entrada pa-    ###
###    drão.                                                             ###
###                                                                      ###
############################################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "lista.h"
#include <math.h>

// Lê uma lista ligada da entrada padrão e devolve um ponteiro para
// seu primeiro nó.
// Use esta função (talvez mais de uma vez) em cada exercício abaixo
// que pedir para ler lista ligada.
no *le_lista()
{
    int n;

    // Lê da entrada padrão um número n.
    scanf("%d", &n);

    if (!n)
        return NULL;

    // Aloca espaço para um vetor com n registros do tipo "no".
    no *lista = (no *)malloc(n * sizeof(no));

    // Lê da entrada padrão n números inteiros, armazenando-os
    // nos nós alocados no vetor "lista", ao mesmo tempo que ajusta
    // os ponteiros "prox" de cada nó para apontar para o nó seguinte.
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &lista[i].dado);
        lista[i].prox = lista + (i + 1);
    }

    // Último nó deve ter o campo "prox" apontando para NULL para marcar
    // o fim da lista ligada.
    lista[n - 1].prox = NULL;

    // Afinal "lista" é um vetor ou é uma lista-ligada?
    return lista;
}

int main()
{
    char operacao[20];

    while (scanf("%s", operacao) == 1)
    {
        if (strcmp(operacao, "zip") == 0)
        {
            /*

      EXERCÌCIO 1

      1. leia duas listas ligadas a e b, através da função le_lista()
      2. combine os nós de a e b numa única lista c, intercalando-os
         como o "cabeçote de um zipper que fecha uma jaqueta": um nó de 
     a, um nó de b, um nó de a, um nó de b, etc; quando o último nó x
     de uma lista for colocado na lista c, concatene o que restou da 
     outra lista após o nó x na lista c;
      3. não é permitido alocar mais espaço de memória (nem através da
         função cria() de lista.h), ou seja, mude apenas o campo "prox" dos
     nós alocados pela função le_lista() para fazer o que foi pedido;
      4. no fim imprima a lista c (só o campo "dado" de cada nó,
         separando-os por espaço em brano);
      5. libere a memória ocupada por esses nós ao fim desta operação
         para evitar vazamento de memória. Mas cuidado! Veja como a memória foi 
     alocada em le_lista() e note que você não vai poder usar a função 
     exclui() de lista.c para liberar a memória (pelo menos não de 
     qualquer jeito).
      6. use apenas a função imprime_lista() do arquivo lista.c

      */

            no *lista1 = le_lista();
            no *lista2 = le_lista();
            no *temp = NULL;
            no *cabecario = lista1;

            if (lista1 == NULL)
            {
                imprime_lista(lista2);
            }
            else if (lista2 == NULL)
            {
                imprime_lista(lista1);
            }
            else
            {
                while (lista1 != NULL && lista2 != NULL)
                {
                    temp = lista1->prox;
                    lista1->prox = lista2;
                    lista1 = lista2;
                    lista2 = temp;
                }
                imprime_lista(cabecario);
                exclui(cabecario->prox);
                exclui(cabecario);
            }
        }
        else if (strcmp(operacao, "unzip") == 0)
        {
            /* 

      EXERCÍCIO 2

      1. leia uma lista ligada c através da função le_lista();
      2. divida seus nós em duas listas a e b, fazendo a operação 
         inversa de "zip". Ou seja, o primeiro nó de c deve ir para a,
     o segundo para b, o terceiro para a, e assim por diante;
      3. não é permitido alocar mais espaço de memória (nem através da
         função cria() de lista.h), ou seja, mude apenas o campo "prox" dos
     nós alocados pela função le_lista() para fazer o que foi pedido;
      4. imprima a lista a
      5. imprima a lista b
      6. libere memória ocupada pelos todos os nós ao fim desta operação
         para evitar vazamento de memória. Mas cuidado! Veja como a memória foi 
     alocada em le_lista() e note que você não vai poder usar a função 
     exclui() de lista.c (pelo menos não de qualquer jeito);
      7. use apenas a função imprime_lista() do arquivo lista.c

      */

            no *c = le_lista();
            if (c == NULL || c->prox == NULL)
            {
                imprime_lista(c);
            }
            else
            {
                no *a = c;
                no *b = c->prox;
                no *temp = NULL;
                while (c != NULL && c->prox != NULL && c->prox != NULL)
                {
                    temp = c->prox;
                    c->prox = temp->prox;
                    c = temp;
                }
                imprime_lista(a);
                imprime_lista(b);
                exclui(a);
                // limpa_lista(a);
                // limpa_lista(b);
            }
        }
        else if (strcmp(operacao, "reverse") == 0)
        {
            /* 

      EXERCÍCIO 3

      1. leia uma lista ligada a através da função le_lista();
      2. crie uma lista ligada b, usando os nós da lista ligada a, de modo que
         os nós em b estejam na ordem reversa à ordem de a.
      3. não é permitido alocar mais espaço de memória (nem através da
         função cria() de lista.h), ou seja, mude apenas o campo "prox" dos
     nós alocados pela função le_lista() para fazer o que foi pedido;
      4. imprima a lista b
      5. libere memória ocupada pelos todos os nós ao fim desta operação
         para evitar vazamento de memória. Mas cuidado! Veja como a memória foi 
     alocada em le_lista() e note que você não vai poder usar a função 
     exclui() de lista.c (pelo menos não de qualquer jeito);
      6. use apenas as funções imprime_lista() e inverte() do arquivo lista.c

      */
			no *lista = le_lista();
			inverte(&lista);
			imprime_lista(lista);
			exclui(final(lista));
		}
		else if (strcmp(operacao, "reverse_rec") == 0)
		{
			/* 

      EXERCÍCIO 4

      1. Faça o mesmo que foi pedido no EXERCÍCIO 3, mas use a função recursiva
         inverte_rec que você implementou no arquivo lista.c para fazer a inversão 
     da lista. Você deve ter implementado essa função de forma recursiva.
      2. use apenas as funções imprime_lista() e inverte_rec() do arquivo lista.c

      */
			no *lista = le_lista();
			inverte_rec(&lista);
			imprime_lista(lista);
			exclui(final(lista));
		}
		else if (strcmp(operacao, "sorted_merge") == 0)
		{
			/* 

      EXERCÍCIO 5

      1. leia duas lista ligadas a e b através da função le_lista(); os 
         inteiros armazenados nessas listas virão ordenados em ordem 
     não-decrescente (você não precisa validar nem ordenar nada);
      2. crie uma lista ligada c que contenha todos nós originalmente 
         em a e b e de forma que seus valores estejam, também, ordenados
     de forma não-decrescente;
      3. não é permitido alocar mais espaço de memória (nem através da
         função cria() de lista.h), ou seja, mude apenas o campo "prox" dos
     nós alocados pela função le_lista() para fazer o que foi pedido;
      4. imprima a lista c
      5. libere memória ocupada pelos todos os nós ao fim desta operação
         para evitar vazamento de memória. Mas cuidado! Veja como a memória foi 
     alocada em le_lista() e note que você não vai poder usar a função 
     exclui() de lista.c (pelo menos não de qualquer jeito);
      6. use apenas a função imprime_lista() do arquivo lista.c e a função
         compara() declarada em item.h

      */
			no *a = le_lista();
			no *b = le_lista();
			if (a == NULL)
			{
				imprime_lista(b);
			}
			else if (b == NULL)
			{
				imprime_lista(a);
			}
			else
			{
				no *atual = a;
				no *prev = NULL;
				while (b != NULL)
				{
					while (atual != NULL)
					{
						// printf("(%d, %d) = %d\n", atual->dado, b->dado, compara(b->dado, atual->dado));
						if (compara(b->dado, atual->dado) <= 0)
						{
							if (prev == NULL)
							{
								no *bProx = b->prox;
								b->prox = a;
								a = b;
								prev = b;
								b = bProx;
							}
							else
							{
								no *bProx = b->prox;
								prev->prox = b;
								b->prox = atual;
								prev = b;
								b = bProx;
							}
							break;
						}
						prev = atual;
						atual = atual->prox;
					}
					if (atual == NULL)
					{
						prev->prox = b;
						break;
					}
				}
				imprime_lista(a);
			}
		}
		else if (strcmp(operacao, "sorted_intersect") == 0)
		{
			/* 

                    temp = temp->prox;
                }
                
                b = b->prox;
            }
            imprime_lista(a);
        }
        else if (strcmp(operacao, "sorted_intersect") == 0)
        {
            /* 

      EXERCÍCIO 6

      1. leia duas lista ligadas a e b através da função le_lista(); os inteiros 
         armazenados nessas listas virão ordenados em ordem não-decrescente;
      2. crie uma lista ligada c que contenha apenas os nós que estejam  
         simultaneamente em a e b, de forma que seus valores estejam, 
     também, ordenados de forma não-decrescente; se a contêm três ocorrências
     do número 5 e b contém duas ocorrências do número 5, então c deve ter 
     duas ocorrências do 5.
      3. não é permitido alocar mais espaço de memória (nem através da
         função cria() de lista.h), ou seja, mude apenas o campo "prox" dos
     nós alocados pela função le_lista() para fazer o que foi pedido;
      4. imprima a lista c
      5. libere memória ocupada pelos todos os nós ao fim desta operação
         para evitar vazamento de memória. Mas cuidado! Veja como a memória foi 
     alocada em le_lista() e note que você não vai poder usar a função 
     exclui() de lista.c (pelo menos não de qualquer jeito);
      6. use apenas a função imprime_lista() do arquivo lista.c e a função
         compara() declarada em item.h

      */
			no *a = le_lista();
			no *b = le_lista();
			no *c = NULL;
			// printf("oi");
			if (a == NULL || b == NULL)
			{
				imprime_lista(c);
			}
			else
			{
				while (b != NULL)
				{
					while (compara(a->dado, b->dado) < 0 && a != NULL)
					{
						a = a->prox;
					}
					if (compara(a->dado, b->dado) == 0)
					{
						no *temp = c;
						c = b;
						b = b->prox;
						c->prox = temp;
						if (a == NULL)
							break;
						a = a->prox;
					}
					else
					{
						b = NULL;
					}
				}
				inverte(&c);
				imprime_lista(c);
			}
			// printf("asd");
		}
		else if (strcmp(operacao, "split_in_half") == 0)
		{
			/* 

      EXERCÍCIO 7

      1. leia uma lista ligada c através da função le_lista();
      2. divida seus nós em duas listas a e b, de modo que a lista a tenha 
         a primeira metade da lista c, e a lista b tenha a segunda metade;
      3. se o número de elementos em c for ímpar, a lista a deve ter um elemento
         a mais que a lista b;
      4. não é permitido alocar mais espaço de memória (nem através da
         função cria() de lista.h), ou seja, mude apenas o campo "prox" dos
     nós alocados pela função le_lista() para fazer o que foi pedido;
      5. imprima a lista a
      6. imprima a lista b
      7. libere memória ocupada pelos todos os nós ao fim desta operação
         para evitar vazamento de memória. Mas cuidado! Veja como a memória foi 
     alocada em le_lista() e note que você não vai poder usar a função 
     exclui() de lista.c (pelo menos não de qualquer jeito);
      8. use apenas a função imprime_lista() do arquivo lista.c

      */

			no *c = le_lista();
			int size = 0;
			no *temp = c;
			no *b;

			if (temp != NULL)
			{
				for (size = 0; temp != NULL; (size++, temp = temp->prox))
					; //calcula tamanho
				temp = c;
				for (int i = 0; i < (size / 2) - 1; (i++, temp = temp->prox))
					; //pega nó do meio
				b = temp->prox;
				temp->prox = NULL;

				imprime_lista(c);
				imprime_lista(b);
			}
		}
		else
		{
			// Nesse caso a operação lida não é válida
			printf("INVALID OPERATION\n");
		}
	}

            if (temp != NULL)
            {
                for (size = 0; temp != NULL; (size++, temp = temp->prox))
                    ; //calcula tamanho
                temp = c;
                for (int i = 0; i < (size / 2) - 1; (i++, temp = temp->prox))
                    ; //pega nó do meio
                b = temp->prox;
                temp->prox = NULL;

                imprime_lista(c);
                imprime_lista(b);
            }
        }
        else
        {
            // Nesse caso a operação lida não é válida
            printf("INVALID OPERATION\n");
        }
    }

    return 0;
}