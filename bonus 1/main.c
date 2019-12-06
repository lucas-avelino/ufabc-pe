#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
/*
    Struct definição
*/
typedef struct sNode Node;
struct sNode
{
    int dado;
    Node *prox;
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

//Logica
Node *soma(Node *num1, Node *num2);
Node *multiplica(Node *num1, Node *num2);
Node *multiplicaEscalar(Node *num1, int escalar);
int length(Node *num1);

void main()
{
    int result = 0;
    char operation = 0;
    Node *numero1 = NULL;
    Node *numero2 = NULL;

    do
    {
        char numero;
        result = scanf("%c", &numero);
        if (numero == '\n')
            break;
        if (numero == '*' || numero == '+')
        {
            operation = numero;
        }
        else if (operation == '*' || operation == '+')
        {
            Node *no = cria((int)numero - 48);
            pushFront(&numero2, no);
        }
        else
        {
            Node *no = cria((int)numero - 48);
            pushFront(&numero1, no);
        }
        // printf("teste %d", result);
    } while (1);
    // inverte(&numero1);
    // inverte(&numero2);
    imprimeLista(soma(numero1, numero2));
    imprimeLista(multiplica(numero1, numero2));
    // imprimeLista(numero1);
    // imprimeLista(numero2);
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
        // Node * resto = cria(resto);
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
    return resultado;
}

Node *multiplica(Node *num1, Node *num2)
{
    int tamanho = length(num2);
    Node **paraSomar = malloc(tamanho * sizeof(Node));

    printf("117: %d\n", getElement(num2, 3)->dado);
    for (int i = 0; i < tamanho && num2!=NULL; i++)
    {
        paraSomar[i] = multiplicaEscalar(num1, getElement(num2, i)->dado);
        for (int j = 0; j < i; j++)
        {
            pushBack(&paraSomar[i], cria(0));
        }
        num2 = num2->prox;
    }
    Node 
    for (int i = 0; i < tamanho; i++)
    {
       imprimeLista(paraSomar[i]);
    }
    
    return paraSomar[3];
}

Node *multiplicaEscalar(Node *num1, int escalar)
{
    int tamanho = length(num1);
    Node *no = NULL;
    for (int i = 0; i < tamanho && num1!=NULL; i++)
    {
        pushFront(&no, cria(escalar * (getElement(num1, i)->dado)));
        num1 = num1->prox;
    }
    
    return no;
}

//Biblioteca
Node *cria(int numero)
{
    Node *no = (Node *)malloc(sizeof(Node));
    no->dado = numero;
    return no;
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
    while (lista->prox != NULL)
    {
        lista = lista->prox;
    }
    return lista;
}

void imprimeLista(Node *cabeca)
{
    Node *tmp = cabeca;

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
    if(cabeca == NULL) return 0;
    for (i = 1; cabeca != NULL; cabeca = cabeca->prox)
        i++;
    return i;
}

Node *getElement(Node *list, int index)
{
    int i;
    Node * e = list;
    for (i = 0; i < index && e != NULL; i++)
    {
        e = e->prox;
    }
    return list;
}