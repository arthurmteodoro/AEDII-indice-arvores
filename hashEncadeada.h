/*=======================================================================*/
/*                Trabalho de AED II - Indice remissivo                  */
/* Nome: Arthur Alexsander Martins Teodoro                               */
/* MAtrícula: 0022427         Data: 23/11/2016                           */
/*=======================================================================*/
#ifndef _HASHENCADEADA_
#define _HASHENCADEADA_

#include "listadup.h"

typedef struct palavra *Palavra;
typedef struct hash *Hash;

extern Hash criaHash(int tam);
extern void destroiHash(Hash hash);
extern int funcaoHash(char* palavra, int tam);
extern Palavra insereHash(Hash hash, char* palavra);
extern Palavra buscaHash(Hash hash, char* palavra);
extern void insereOcorrenciaHash(Hash hash, char* palavra, int linha);
extern int tamanhoHash(Hash hash);
extern char* retornaPalavraHash(Palavra plv);
extern Lista retornaListaHash(Palavra plv);
extern void printaHash(Hash hash);
extern int colisaoHash(Hash hash);

#endif