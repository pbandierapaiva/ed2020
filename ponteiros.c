///
/// ponteiro.c                               
/// 

#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 500


int main() {
	char *c;

	printf("\no endereço de c é: %ld, \n", c);
	
	printf( "Caracter: %d bytes\nInteiro: %d bytes\nFloat: %d bytes\n\n ", sizeof(char), sizeof(int), sizeof(float) ); 
	
	// alocação dinâmica:
	
	c = malloc(1);
	
	*c = 'A';

	printf("\napós alocar espaço o endereço de c é: %ld, e seu valor: %d \n", c, *c);


	return 0;
}


