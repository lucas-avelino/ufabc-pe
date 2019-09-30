#include <stdio.h>
#include <math.h>
// URI: 1019
int main()
{
    int tempo;

    scanf("%d", &tempo);

    printf("%d:%d:%d\n", (tempo/3600),(tempo%3600)/60, (tempo%60));
    return 0;
}