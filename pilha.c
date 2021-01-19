/*
* Programa: pilha.c
* 
* Implementa pilha
*  
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Pilha {
	int val;
	struct Pilha *prox;
};


void push( int valor, struct Pilha *pPilha ) {
	struct Pilha *novoNo, *paux;
	
	novoNo = malloc( sizeof(struct Pilha) );
	novoNo->val = valor;
	novoNo->prox = NULL;

	novoNo->prox = pPilha->prox;
	pPilha->prox = novoNo;
	
	printf("\nInserido: %d", valor);
	return;
}

int pop( struct Pilha *pPilha ) {
	int valor;
	struct Pilha *paux;
	
	if( ! pPilha->prox ){
		printf("\npilha vazia\n");
		return 0;
		}
		
	valor = pPilha->prox->val;
	paux = pPilha->prox;
	pPilha->prox = pPilha->prox->prox;
	free(paux);
	
	return valor;
}

int peek( struct Pilha pPilha ) {
	if( !pPilha.prox ){
		printf("\npilha vazia\n");
		return 0;
		}
	return pPilha.prox->val;
}



int main() {
	struct Pilha pilha;
	pilha.prox = NULL;
	pilha.val =0;

	push(1, &pilha);
	push(2, &pilha);
	push(3, &pilha);
	push(4, &pilha);
	push(5, &pilha);
	printf( "\nretirado:  %d",  pop(&pilha) );
	printf( "\nretirado:  %d",  pop(&pilha) );
	printf( "\nretirado:  %d",  pop(&pilha) );
	printf( "\nretirado:  %d",  pop(&pilha) );
	push(6, &pilha);
	push(7, &pilha);

	printf( "\nretirado:  %d",  pop(&pilha) );
	printf( "\nretirado:  %d",  pop(&pilha) );
	
	printf( "\nretirado:  %d",  pop(&pilha) );
	printf( "\nretirado:  %d",  pop(&pilha) );
	
	

}

