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
	char dado[MAXLIN];

	
	fp = fopen("/data/datasets/ed2020/cad2020.csv", "r");
	
	if( ! fp ) {
		printf("\nErro de abertura de arquivo\n\n");
		return -1;
		}
		
	while( fgets( linha, MAXLIN, fp ) ) {
		extrai( linha, 1, dado );
		printf("\n%s", dado );
	}
	
}

void extrai( char *lin,  int elem, char *d ) {

	char *p, *q;
	int i=0;
	
	p = lin;
	
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
	
	
	









	
	
	
	
 
