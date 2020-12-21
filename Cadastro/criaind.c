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

	criaIndex("/data/datasets/ed2020/cad2020.csv","/data/datasets/ed2020/cad2020.ind");
	
}

void criaIndex(char *nomearq, char *nomeind) {
	FILE *entra, *sai;
	char linha[MAXLIN];
	char dado[MAXSTR];
	Cadastro cad;
	
	entra = fopen(nomearq, "r");
	sai = fopen(nomeind, "wb");
	
	if( !entra || !sai ) {
		printf("\nErro de abertura de arquivo\n\n");
		return;
		}
	
	while( fgets( linha, MAXLIN, entra ) ) {
		extrai( linha, 1, dado );
		strcpy(cad.nome, dado);
		cad.loc = ftell(entra);
		
		fwrite( &cad, sizeof(cad), 1, sai );
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
	
	
	









	
	
	
	
 
