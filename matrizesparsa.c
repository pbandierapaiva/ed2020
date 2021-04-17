///
/// matrizesparsa.c                               
/// 

#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 500

	typedef struct tNo {
		int valor;
		int coluna;
		struct tNo *prox;
	} NO;
	
	typedef struct {
		NO *plinhas;
		int lin;
		int col;
	
	} MATRIZ;

void insere( MATRIZ *m, int lin, int col, int val) {
	NO *tmpNo, *atual, *ant;
	
	atual = m->plinhas[lin];
	
	while( atual != NULL && atual->coluna < col ){
		ant = atual;	
		atual = atual->prox;
	}
	if( atual!= NULL && atual->coluna==col ) {
		if( val==0 ) {
			if( ant==NULL ) m->plinhas[lin] = atual->prox;
			else ant->prox = atual->prox;
			free(atual);
			}
		else atual->valor = val;
		}
	else if(val!=0) {
		tmpNo = malloc( sizeof(NO));
		tmpNo->valor = val;
		tmpNo->coluna = col;
		
		tmpNo->prox = atual;
		if( ant==NULL ) m->plinhas[lin] = tmpNo;
		else ant->prox = tmpNo;
		
		}
	}
}

int valor(MATRIZ *m, int lin, int col) {
	NO *atual;
	
	if( lin >= m->linhas || col >= m->colunas || lin<0 || col < 0)
		return 0;
	
	atual = m->plinhas[lin];
	
	while( atual!=NULL && atual->colunas > col)
		atual = atual->prox;
	if( atual!=NULL && atual->colunas ==col )
		return atual->valor;
	return 0;
}



int main() {

 
 	MATRIZ mat;

	char entra[20];

	// Define tamanho da matriz		
	printf("\n\nNúmero de linhas: ");
	fgets( entra, 20, stdin);
	mat.lin = atoi( entra );
		
	printf("\nNúmero de colunass: ");
	fgets( entra, 20, stdin);
	mat.col = atoi( entra );


	printf("Definindo matriz de %d x %d\n\n", mat.lin,mat.col);


	// Alocar espaço para ponteiros para linhas
	mat.plinhas = malloc( mat.lin * sizeof(NO) );
	for( i=0; i<mat.lin; i++) {
		mat.plinhas[i].prox = NULL;	 
		}
		
	// Matriz esparsa vazia
	
	insere(&mat, 320, 400, 155);
	insere(&mat, 23, 4, 33);	
	insere(&mat, 1, 120, 3);
	insere(&mat, 23, 65, 100);

	printf("ACHOU O VALOR:   %d", valor(&mat,23,65);


	return 0;
}


