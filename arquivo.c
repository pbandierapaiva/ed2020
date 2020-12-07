///
/// arquivo.c                               
/// Trabalhando com arquivos

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTR 500

int main() {
	char nomeArquivo[MAXSTR];
	char linha[MAXSTR];
	FILE *fp;
	
	
	printf("Entre com o nome do arquivo: ");
	fgets(nomeArquivo, MAXSTR-1, stdin);
	nomeArquivo[strlen(nomeArquivo)-1] = '\0';
		
	fp = fopen( nomeArquivo, "r");
	
	if( ! fp ) {
		printf("Arquivo não encontrado: '%s' \n", nomeArquivo);
		exit(-1);
		}
	
	while( ! feof(fp) ) {
		fgets( linha, MAXSTR-1, fp);
		printf(linha);
		}
		
	fclose( fp );
	
	
	return 0;
}


