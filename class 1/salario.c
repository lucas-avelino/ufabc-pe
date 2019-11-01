#include <stdio.h>
// URI: 1008
int main()
{
	int cod, horas;
	float salarioPorHora;
	scanf("%d", &cod);
    scanf("%d", &horas);
	scanf("%f", &salarioPorHora);

	printf("NUMBER = %d\n", cod);
	printf("SALARY = U$ %.2f\n", (horas*salarioPorHora));

	return 0;
}
