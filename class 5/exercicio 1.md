## Fibonacci iterado
Você conhece a definição da sequência de Fibonacci. Hoje vamos modificar um pouco essa definição. Vamos definir uma função semelhante a de Fibonacci da seguinte maneira.

    Fi[0] = 1;
    Fi[1] = 1;
    Fi[n] = Fi[Fi[n - 1] % n] + Fi[Fi[n-2] % n];

É claro que essa definição não faria muito sentido se tirássemos as ocorrências da expressão ``% n`` , porque os índices ``a = Fi[n-1]`` e ``b = Fi[n-1]`` provavelmente seriam maiores de que n e, portanto, ``Fi[a]`` e ``Fi[b]`` não estariam ainda definidos no momento em que estivéssemos definindo ``Fi[n]``. Por isso, colocando ``% n``, temos a certeza de que ``Fi[n-1] % n`` e também ``Fi[n-2] % n`` são ambos índices no intervalo ``0 ... (n - 1)``.

Neste exercício programa, você deverá implementar um programa para calcular Fi, a sequência "Fibonacci Iterado".

Seu programa deve ler um valor inteiro n da entrada padrão e imprimir ``Fi[n]``, depois ler outro valor inteiro n e e imprimir ``Fi[n]``, e assim por diante até o fim da entrada (EOF). Para fazer isso, seu programa deve ter um laço da forma

``while (scanf("%d", &n) == 1) { ... }``

Note que isso é ligeiramente diferente de 

``while (scanf("%d", &n) != EOF) { ... }``

pois, qualquer erro na leitura faz com que o programa pare, não somente o fim da entrada. A primeira forma é preferível sobre a segunda.

Seu programa não pode usar função recursiva porque, assim como a função de Fibonacci, os cálculos seriam repetitivos e a árvore de chamadas recursivas tende a ficar com um número exponencial de nós (em n). Seu programa precisa usar um vetor Fi, que deve ser alocado dinamicamente, na heap, via malloc, calloc ou realloc. Se não usar alocação dinâmica no código, seu programa irá valer no máximo 2.5 pontos. 

Como a entrada de teste terá muitas linhas, você não pode se dar ao luxo de, para cada valor de n lido, recomeçar todo o processo (i.e. calcular ``Fi[0]``, ``Fi[1]``, ... até ``Fi[n]``), senão você vai estourar no tempo. A idéia é que para cada valor de n lido, você apenas calcule o que faltar para ter o valor ``Fi[n]`` (às vezes esse valor já foi até calculado e nem falta nada!). 

Se fizer direitinho com realloc ganha 12 pontos. (A ser corrigido manualmente, posteriormente.)

Casos de teste. Os primeiros 16 valores da sequência de Fibonacci Iterada são

0
1
2
3
5
4
9
7
8
15
12
6
10
21
19
14

O máximo valor n que seu programa poderá ler da entrada não passará de 50000000.