///
/// leint.c                               
/// Lê número inteiro

#include <stdio.h>
#include <string.h>

#define MAXSTR 500

void LeInt( int *p ) {
	printf("Entre com inteiro: ");
	scanf("%d", p);
	}

int main() {
	int a=0;

	printf("\no endereço de a é: %ld, \ncom valor: %d\n", &a, a);
	LeInt(&a);
	
	printf("\no a virou: %d \n\n", a);
	return 0;
}


