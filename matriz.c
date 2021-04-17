///
/// matriz.c                               
/// 

#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 500
#define LIN	20
#define COL	20

int main() {

// Alocação ESTÁTICA
	int mat[LIN][COL];

	int i, j;
	
	for( i=0; i < LIN ; i++) {
		for( j=0; j<COL; j++ ) {
			mat[i][j]=i*j;
			}
	
		}	
		
	
	for( i=0; i < LIN ; i++) {
		printf("\n");
		for( j=0; j<COL; j++ ) {
			printf("%d\t",mat[i][j]);
			}
		}

// Alocação DINÂMICA

	int *matd = NULL;
	
	int lin, col;	
	
	char entra[20];
		
	printf("\n\nNúmero de linhas: ");
	fgets( entra, 20, stdin);
	lin = atoi( entra );
		
	printf("\nNúmero de colunass: ");
	fgets( entra, 20, stdin);
	col = atoi( entra );


	printf("Alocando matriz de %d x %d\n\n", lin,col);

	// alocação dinâmica:
	
	matd = malloc( lin*col*sizeof(int) );
	
	for( i=0; i<lin; i++) {
		for( j=0; j<col; j++) {
		matd[ i*col + j ] = i*j;		
		}
	}
	
	for( i=0; i<lin; i++) {
		printf("\n");
		for( j=0; j<col; j++) {
		printf("%d\t", matd[ i*col + j ]);		
		}
	}
	
	free(matd);

	return 0;
}


