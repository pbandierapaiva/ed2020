///
/// cara2.c                               
/// Conta palavras terminando com end. resolução do Exercício

#include <stdio.h>
#include <string.h>

#define MAXSTR 500

int main() {
	int c, i, conta;
	char texto[MAXSTR];
	
	i=0;
	conta=0;

	printf("Entre com cadeia de caracteres: ");
	
	while( 1 ) {
		i++;
		c  = getchar();
		texto[i] = c;
		
		if ( c == ' ' || c=='\n' ) conta++;

		if( i>2 && texto[i-2]=='e' && texto[i-1]=='n' && texto[i]=='d' ) break;
		}
			
	printf("\nTem %d palavras\n", conta);	

	return 0;
}


