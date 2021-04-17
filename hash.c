/*
* Programa: hash.c
* 
* Implementa hash
*  
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


unsigned int hash(const char *key, unsigned int size)
{
	int hash = 401;
	int c;

	while (*key != '\0') {
		hash = ((hash << 4) + (int)(*key)) % size;
		key++;
	}

	return hash % size;

}


unsigned int hash0(const char *key, unsigned int size)
{
	unsigned int i;
	unsigned int hash = 0;
	/*loop through all the chars*/
	for ( i=0 ; key && key[i] ; i++ )
		{
		/*add all the ASCIIs*/
		hash += key[i];
		}
	/*convert hash code to fit it inside the range*/
	hash = hash % size;
	return hash;
}


int main() {
	int tam;
	char chave[300];
	
	printf("\nEntre com tamanho da tabela: ");
	fgets(chave,300,stdin);
	tam = atoi(chave);
	
	
	while( 1 ) {
	
		printf("\nEntre com chave: ");
		fgets(chave, 300, stdin);
		
		printf("retornou: %d e hash0: %d  \n", hash( chave, tam ), hash0( chave, tam ));
	}
	return 0;
}	
	




