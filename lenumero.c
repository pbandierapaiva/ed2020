///////////////////////////////////////////////////////////////////////////////////
// lenumero.c - exemplo de código para ler número.
// Autor: P.Bandiera Paiva
//
#include <stdio.h>

void main() {
	int i;
	float f;
	printf("\nEntre com um número inteiro: ");
	scanf("%d", &i);
	printf("\nEntre com um número racional (float): ");
	scanf("%f", &f);

	printf("Li os  números: %d (int) e %f (float)\n",i,f);
	return;
}
