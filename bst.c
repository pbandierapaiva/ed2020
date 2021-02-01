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
	
	//printf("\n dentro do insere endereço %ld", *root);
	if( (*root) ==NULL ) {   //Árvore vazia
		novoNo = malloc( sizeof(struct NO) );
		novoNo->val = valor;
		novoNo->noE = NULL;	
		novoNo->noD = NULL;
		*root = novoNo;
		}
	else
		{
		if( valor > (*root)->val )
			insere( &( (*root)->noD ), valor);
		else			
			insere( &( (*root)->noE ), valor);		
		}
}

struct NO *pai( struct NO *raiz, struct NO *q ) {
	struct NO *res=NULL;
	if( raiz == q ) return NULL;

	if( raiz->val > q->val ) {
		if( raiz->noE == q ) return raiz;
		return pai( raiz->noE, q);
		}
	else {
		if( raiz->noD == q ) return raiz;
		return pai(raiz->noE, q);
		}	
}

struct NO *maior( struct NO *no ) {
	if( no->noD == NULL) return no;
	return maior(no->noD);
}


void apaga( struct NO *raiz, struct NO *no ) {
	struct NO *p, *tmp;
	
	p = pai(raiz, no);
	if( no->noE ==NULL && no->noD==NULL ) {
		if( p->noD==no )
			p->noD=NULL;
		if( p->noE==no )
			p->noE=NULL;
		}
	else {
		if( no->noE && no->noD ) { // tem filho dos dois lados
			//Vamos colocar o lado esquerdo primeiro
			tmp = maior( no->noE );
			tmp->noD = no->noD;
			if( p->noD == no) {
				p->noD = no->noE;
				}
			if( p->noE == no) {
				p->noE = no->noE;
				}
			}
		else {
			if( no->noE ) {  // só tem filho à esquerda
				if( p->noE == no)  p->noE = no->noE;
				if( p->noD == no)  p->noD = no->noE;
				}
			else {  // só tem filho à direita
				if( p->noE == no)  p->noE = no->noD;
				if( p->noD == no)  p->noD = no->noD;
				}
			}
		}
	free(no);
}

void printErd( struct NO *no ) {
	if( no->noE )
		printErd(no->noE);
	if( no->noD )
		printErd(no->noD);
}

void printErd2( struct NO *no ) {
	if( no ) {
		printErd(no->noE);
		printf("%d ", no->val);
		printErd(no->noD);
	}	
}



int main() {
	struct NO *raiz, *tmp;
	
	raiz=NULL;
	
	insere( &raiz, 10 );
	
	
	insere( &raiz, 5 );
	insere( &raiz, 2 );
	insere( &raiz, 8 );	
	insere( &raiz, 7 );	
	insere( &raiz, 1 );	
	insere( &raiz, 3 );	
	
	printErd(raiz);
	printf("\n");
	
	tmp = pai(raiz, raiz->noE->noE);
	printf("\n\nValor %d \n", tmp->val   );
	
	apaga(raiz, tmp);
	printf("\n\nValor %d \n", raiz->noE->noD->noD->val)	;
	
	
	return 0;
}

//             10
//           5
//       2       8
//    1    3   7 
//
//
//
//




