#include <stdio.h>

void  main() {
	int num, Num;
	unsigned int b;
	short c;
	
	int  vetor[10];
	char caras[100] = "Esta é uma cadeia de caracteres\n\n";
	
	int matriz[10][20];

	printf("Olá mundo!\n4a versão\n\n");
	printf("endereço de \nnum:\t%ld\nNum:\t%ld \nb:\t%ld\nc:\t%ld \nvetor:\t%ld \ncaras:\t%ld\nmatriz:\t%ld\n", 
		&num, &Num,&b,&c,vetor,caras,matriz );
	
	printf("Tamanho das variáveis: num %d bytes\nb %d bytes\nc %d bytes\nvetor %d bytes\ncaras %d bytes\nmatriz %d bytes\n",
		sizeof(num),sizeof(b),sizeof(c),sizeof(vetor),sizeof(caras),sizeof(matriz));
	
	printf(caras);
	printf("\nEntre com texto: ");
	//fgets(caras, sizeof(caras), stdin );
	scanf("%s", caras);
	printf(caras);
	
	printf("\nFIM\n");	
	
	






}


