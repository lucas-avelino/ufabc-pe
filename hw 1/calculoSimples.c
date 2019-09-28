#include <stdio.h>
// URI: 1010
int main()
{
	int codPeca1, numDePecas1, codPeca2, numDePecas2;
	float valorPeca1, valorPeca2;
	
	scanf("%d %d %f",&codPeca1,&numDePecas1,&valorPeca1);
	scanf("%d %d %f",&codPeca2,&numDePecas2,&valorPeca2);

	printf("VALOR A PAGAR: R$ %.2f\n", ((numDePecas1*valorPeca1)+(numDePecas2*valorPeca2)));
	return 0;
}
