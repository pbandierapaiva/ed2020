///
/// caras.c                               
/// Conta palavras. resolução do Exercício

#include <stdio.h>
#include <string.h>

#define MAXSTR 500

void  main() {
	int c, i, conta;
	char texto[MAXSTR];
	
	conta=0;

	printf("Entre com cadeia de caracteres: ");
	fgets(texto, MAXSTR, stdin);
	
	

	printf("O string tem %d caracteres.\n", strlen(texto) );

	for( i=0; texto[i]; i++) {
		if(  texto[i] == ' ' ) conta++;
		if( i>2 && texto[i-2]=='e' && texto[i-1]=='n' && texto[i]=='d') {
			conta++;
			break;
			}
		}
	
	printf("\nTem %d palavras\n", conta);	

}


