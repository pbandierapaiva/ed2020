/*
* Programa: cad.c
* 
* Lê arquivo CSV baixado do transparencia.gov com dados de servidores públicos
* 
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cadastro.h"


int main() {

	FILE *fp;
	
	char linha[MAXLIN];
	char dado[MAXLIN], d2[MAXLIN], d3[MAXLIN];
	char nome[MAXLIN];
	char *ptr;
	
	fp = fopen("/data/datasets/ed2020/cad2020.csv", "r");
	
	if( ! fp ) {
		printf("\nErro de abertura de arquivo\n\n");
		return -1;
		}
		
	printf("\nNome para busca: ");
	fgets( nome, MAXLIN, stdin);
	ptr = nome;
	while( *ptr!='\0' &&  *ptr!='\n') {
		ptr++;
		}
	*ptr = '\0';
	printf("Nome: %s\n", nome);
		
	while( fgets( linha, MAXLIN, fp ) ) {
		extrai( linha, 1, dado );
		if( ! strcmp( dado, nome) ) {
			extrai( linha, 4, d2 );	
			extrai( linha, 16, d3 );
			printf("\n%s \n%s\n%s\n", dado, d2,d3);
			}
	}
	
}

void extrai( char *lin,  int elem, char *d ) {

	char linha[MAXLIN], *p, *q;
	int i=0;
	
	strcpy( linha, lin );
	p = linha;
	
	while( *p!='\0' ) {		
		if( elem == i ) {
			if( *p=='"' )	p++;
			q = p;
			while( *q != '"' ) q++;
			*q ='\0';
			strcpy( d, p);
			return;
		}
	
		if( *p==';') {
			i++;
			}
		p++;
		}
}
	
	
	









	
	
	
	
 
