///
/// leVetor.c                               
/// 

#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 500


int main() {

	int *v;
	int *p;
	int n;
	
	printf("\nEntre com N: ");
	scanf("%d", &n);
	
	 
	v = malloc( n * sizeof(int) );
	p = v;
	
	for( int i=0; i<n ;i++) {
		printf("%ld   %d: ",p, i+1);
	
		scanf("%d", p);
		p++;
		}
	
	p = v;
	printf("\nLidos: ");
	for( int i=0; i<n ;i++) {
		printf( "%d ", *p );
		p++;
		}
		
	printf("\n\n");

	return 0;
}


