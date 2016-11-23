/*=======================================================================*/
/*                Trabalho de AED II - Indice remissivo                  */
/* Nome: Arthur Alexsander Martins Teodoro                               */
/* MAtrícula: 0022427         Data: 13/09/2016                           */
/*=======================================================================*/
#ifndef _INDICEREMISSIVO_
#define _INDICEREMISSIVO_

#include "listadup.h"
#include "lista.h"
#include "hashEncadeada.h"

extern int contaPalavrasChave(const char* arqPalvrasChave);

extern void inserirPalavrasHash(Hash hash, const char* arqPalvrasChave, char** vetor);
extern void inserirPalavrasLista(ListaPalavra lista, const char* arqPalvrasChave, char** vetor);
extern void inserirPalavrasArvBin(ArvBin *raiz, const char* arqPalvrasChave);

extern char* buscaPalavra(int *inicio, int *fim, char* frase);

extern void criaIndiceHash(Hash hash, const char* texto);
extern void criaIndiceLista(ListaPalavra lista, const char* texto);
extern void criaIndiceArvBin(ArvBin arv, const char* texto);

extern void filtragemPalavras(char* palavra);
extern char** criaVetor(int tam);
extern void destroiVetor(char** vetor, int tam);

extern void geraSaidaHash(Hash hash, const char* arq, char** vetor, int tam);
extern void geraSaidaLista(ListaPalavra lista, const char* arq, char** vetor, int tam);

#endif