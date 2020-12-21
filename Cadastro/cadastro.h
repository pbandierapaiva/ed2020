/* 
* cadastro.h
*
* Arquivo de cabeçalhos e definições 
*/

#define MAXLIN 1000
#define MAXSTR 200


void extrai( char *lin,  int elem, char *d );
void criaIndex(char *nomearq, char *nomeind);

typedef struct CADASTRO {
	char nome[MAXSTR];
	unsigned long loc;
	} Cadastro;

