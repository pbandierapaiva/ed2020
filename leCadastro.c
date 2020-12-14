///
/// leCadastro.c                               
/// Lê dados de servidores em CSV

#include <stdio.h>
#include <string.h>

#define MAXSTR 500


int main() {
	
	FILE *arq;
	
	char linha[MAXSTR];
			
	//arq = fopen("/data/datasets/ed2020/cadastro2019.csv", "r");
	arq = fopen("cadastro2019.csv", "r");
	if( arq==NULL ) {
		printf("Ocorreu um problema na abertura do arquivo.");
		return -1;
		} 
	
	while( ! feof(arq) ) {
		fgets( linha, MAXSTR, arq );
		printf("\n%s\n", linha );
	
		}
	
	
	return 0;
}


