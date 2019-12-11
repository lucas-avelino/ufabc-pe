#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
/*
    Struct definição
*/
typedef struct sNode Node;
typedef struct sOperation *Operation;
typedef struct sOperation SOperation;

struct sNode
{
    int dado;
    Node *prox;
};

struct sOperation
{
    Node *num1;
    Node *num2;
    char operation;
};

/*
    Cabeçario das funções
*/
Node *cria(int numero);
Node * final(Node **head);
void pushBack(Node **head, Node *item);
void pushFront(Node **head, Node *item);
void imprimeLista(Node *cabeca);
void inverte(Node **cabeca);
int length(Node *cabeca);
Node *getElement(Node *list, int index);
void trimLeftNumber(Node **list);
void exclui(Node* no);

//Logica
Node *soma(Node *num1, Node *num2);
Node *multiplica(Node *num1, Node *num2);
Node *multiplicaEscalar(Node *num1, int escalar);
int length(Node *num1);
Operation getOperacao();

Node * nosLivres = NULL;

Operation getOperacao()
{
    char *buffer = NULL;
    size_t size = 0;
    Operation op = malloc(sizeof(SOperation));
    op->operation = 0;
    op->num1 = NULL;
    op->num2 = NULL;
    int line = getline(&buffer, &size, stdin);
    if (line == -1)
    {
        return op;
    }
    for (long i = 0; i < size; i++)
    {

        if (buffer[i] == '*' || buffer[i] == '+') //se for operator
        {
            op->operation = buffer[i];
        }
        else if (buffer[i] >= 48 && buffer[i] <= 57) //Se for numero
        {
            if (op->operation != 0)
            {
                Node *no = cria((int)buffer[i] - 48);
                pushFront(&op->num2, no);
            }
            else
            {
                Node *no = cria((int)buffer[i] - 48);
                pushFront(&op->num1, no);
            }
        }
        else
        {
            return op;
        }
    }
    return op;
}

int main()
{
    do
    {
        Operation op = getOperacao();
        if (op->operation == 0)
        {
            break;
        }
        else if (op->operation == '*')
        {
            Node* result = multiplica(op->num1, op->num2);
            imprimeLista(result);
            if(result!=NULL) exclui(result);
        }
        else if (op->operation == '+')
        {
            Node* result = soma(op->num1, op->num2);
            imprimeLista(result);
            if(result!=NULL) exclui(result);
        }
    } while (1);
    
    return 0;
}

Node *soma(Node *num1, Node *num2)
{
    Node *resultado = NULL;
    int toAdd = 0;
    while (num1 != NULL && num2 != NULL)
    {
        int soma = (num1->dado + num2->dado + toAdd);
        int resto = soma % 10;
        toAdd = (soma - resto) / 10;
        pushFront(&resultado, cria(resto));
        num1 = num1->prox;
        num2 = num2->prox;
    }
    if (num1 == NULL)
    {
        for (; num2 != NULL; num2 = num2->prox)
        {
            int soma = (num2->dado + toAdd);
            int resto = soma % 10;
            toAdd = (soma - resto) / 10;
            pushFront(&resultado, cria(resto));
        }
    }
    else if (num2 == NULL)
    {
        for (; num1 != NULL; num1 = num1->prox)
        {
            int soma = (num1->dado + toAdd);
            int resto = soma % 10;
            toAdd = (soma - resto) / 10;
            pushFront(&resultado, cria(resto));
        }
    }
    if (num1 == NULL && num2 == NULL && toAdd > 0)
    {
        pushFront(&resultado, cria(toAdd));
    }
    trimLeftNumber(&resultado);
    return resultado;
}

Node *multiplica(Node *num1, Node *num2)
{
    int tamanho = length(num2);
    Node **paraSomar = malloc(tamanho * sizeof(Node));

    for (int i = 0; i < tamanho && num2 != NULL; i++)
    {
        paraSomar[i] = multiplicaEscalar(num1, getElement(num2, i)->dado);
        for (int j = 0; j < i; j++)
            pushBack(&paraSomar[i], cria(0));
        num2 = num2->prox;
    }
    Node *total = NULL;
    for (int i = 0; i < tamanho; i++)
    {
        inverte(&paraSomar[i]);
        inverte(&total);

        total = soma(total, paraSomar[i]);
        if(paraSomar[i] != NULL) exclui(paraSomar[i]);
    }
    trimLeftNumber(&total);
    return total;
}

Node *multiplicaEscalar(Node *num1, int escalar)
{
    int tamanho = length(num1);
    Node *no = NULL;
    int toAdd = 0;
    for (int i = 0; i < tamanho && num1 != NULL; i++)
    {
        int mult = (escalar * (getElement(num1, i)->dado)) + toAdd;
        int resto = mult % 10;
        toAdd = (mult - resto) / 10;
        pushFront(&no, cria(resto));
        num1 = num1->prox;
    }
    if (toAdd > 0)
    {
        pushFront(&no, cria(toAdd));
    }

    return no;
}

//Biblioteca
Node *cria(int numero)
{
    if(nosLivres == NULL){
        nosLivres = (Node *) malloc(sizeof(Node)*10000);
        for (int i = 0; i < 10000; i++) (nosLivres + i)->prox = nosLivres + 1 + i ;
    }
    Node *no = nosLivres;
    nosLivres = nosLivres->prox;
    no->dado = numero;
    no->prox = NULL;
    return no;
}

void exclui(Node* no){
    final(&no)->prox = nosLivres;
    nosLivres = no;
}

void pushBack(Node **head, Node *item)
{
    Node *lista = *head;
    Node *ultimoDado = final(head);
    if (lista == NULL)
    {
        lista = item;
    }
    else
    {
        ultimoDado->prox = item;
    }
}

void pushFront(Node **head, Node *item)
{
    item->prox = *head;
    *head = item;
}

Node * final(Node **head)
{
    Node *lista = *head;
    if (lista == NULL)
    {
        return NULL;
    }
    while (lista->prox != NULL)
    {
        lista = lista->prox;
    }
    return lista;
}

void imprimeLista(Node *cabeca)
{
    Node *tmp = cabeca;
    if (cabeca == NULL)
    {
        printf("0\n");
        return;
    }
    while (tmp != NULL)
    {
        // printf("[%lx]:", tmp);
        printf("%d", tmp->dado);
        tmp = tmp->prox;
    }

    printf("\n");
}

void inverte(Node **cabeca)
{
    Node *antigoUltimo = final(cabeca);
    Node *antigoIncio = *cabeca;
    if (*cabeca == NULL || (*cabeca)->prox == NULL)
    {
        return;
    }
    *cabeca = antigoUltimo;
    Node *p = antigoIncio;
    Node *m = p->prox;
    Node *t;
    do
    {
        t = m->prox;
        m->prox = p;
        p = m;
        m = t;
    } while (t != NULL);
    antigoIncio->prox = NULL;
}

int length(Node *cabeca)
{
    int i;
    if (cabeca == NULL)
        return 0;
    for (i = 0; cabeca != NULL; cabeca = cabeca->prox)
        i++;
    return i;
}

Node *getElement(Node *list, int index) //try delete
{
    int i;
    Node *e = list;
    for (i = 0; i < index && e != NULL; i++)
    {
        e = e->prox;
    }
    return list;
}

void trimLeftNumber(Node **list)
{
    while ((*list) != NULL && (*list)->dado == 0)
    {
        (*list) = (*list)->prox;
    }
}