/*
* Programa: bst.c
* 
* Implementa árvore binária de busca
*  
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct NO {
	int val;
	struct NO *noE, *noD;
};


void insere( struct NO **root, int valor){
	struct NO *novoNo, *ptr;
	
	novoNo = malloc( sizeof(struct NO) );
	novoNo->val = valor;
	novoNo->noE = NULL;	
	novoNo->noD = NULL;	
	
	if( *root==NULL )    //Árvore vazia
		*root = novoNo;
	else
		if( valor > (*root)->val )

			insere( &( (*root)->noD ), valor);
		else			
			insere( &( (*root)->noE ), valor);		

}

int main() {
	struct NO *raiz;
	
	raiz=NULL;

	insere( &raiz, 10 );
	
	printf("raiz em %ld", raiz);
	
	insere( &raiz, 5 );
	insere( &raiz, 2 );
	insere( &raiz, 8 );	
	insere( &raiz, 7 );	
	insere( &raiz, 1 );	
	insere( &raiz, 3 );	
	
	
	
	return 0;
}


