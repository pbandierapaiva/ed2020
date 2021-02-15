/*
* Programa: hash.c
* 
* Implementa hash
*  
*/

#define TABMAX 10000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "cadastro.h"


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

struct Pilha {
	char nome[300];
	unsigned long int local;
	struct Pilha *prox;
};

void insereBalde(char *chave, unsigned long loc, struct Pilha **pilha) {
	struct Pilha *novoNo, *tmp, *ant;
	
	novoNo = malloc( sizeof(struct Pilha) );
	strcpy( novoNo->nome,chave );
	novoNo->local = loc;
	novoNo->prox = NULL;
	
	if( *pilha == NULL ) 
		*pilha = novoNo;
	else {
		tmp = *pilha;
		while( tmp->prox != NULL )
			tmp= tmp->prox;
		tmp->prox = novoNo;		
		}
	}

int tamBalde(  struct Pilha *pilha ){
	int conta=0;
	struct Pilha *tmp;
	
	tmp = pilha;
	
	while( tmp != NULL ) {
		conta++;
		tmp = tmp->prox;
		}
	return conta;
	}


int main() {
	int i;
	FILE *entra; //, *sai;
	char linha[MAXLIN];
	char nome[MAXSTR];

	
	struct Pilha *hashtable[TABMAX],  *hash0table[TABMAX];
	for( i=0; i<TABMAX; i++) {
		hashtable[i]=NULL;
		hash0table[i]=NULL;
		}
	
	entra = fopen("/data/datasets/ed2020/cadastro2020.csv", "r");
	if( !entra ) {
		printf("\nErro de abertura de arquivo\n\n");
		return -1;
		}	
		
	while( ! feof(entra) ){
		fgets( linha, MAXLIN, entra );
		extrai( linha, NOME, nome );

		insereBalde( nome, ftell(entra), &hashtable[ hash( nome, TABMAX )]);
		insereBalde( nome, ftell(entra), &hash0table[ hash0( nome, TABMAX )]);
		}
	
	fclose(entra);
	
	
	// Conta quantos itens em cada balde
	FILE *out;
	
	out = fopen("results_hash_1M.csv","w");
	
	fprintf( out, "i,comhash,comhash0\n");	
	for(i=0; i< TABMAX; i++) {
		fprintf(out, "%d,%d,%d\n", i, tamBalde(hashtable[i]), tamBalde(hash0table[i]) );
	}
	fclose(out);
	return 0;
}	
	




