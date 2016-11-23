/*=======================================================================*/
/*                Trabalho de AED II - Indice remissivo                  */
/* Nome: Arthur Alexsander Martins Teodoro                               */
/* MAtrícula: 0022427         Data: 23/11/2016                           */
/*=======================================================================*/
#ifndef _ARVOREBIN_
#define _ARVOREBIN_

#include "listadup.h"

typedef struct no *ArvBin;

extern ArvBin criaArvBinVazia(void);
extern ArvBin insereArvBin(ArvBin arv, char* palavra);
extern ArvBin buscaArvBin(ArvBin raiz, char* palavra);
extern void destroiArvBin(ArvBin raiz);
extern void insereOcorrenciaArvBin(ArvBin raiz, char* palavra, int linha);
extern char* retornaPalavraArvBin(ArvBin raiz);
extern Lista retornaListaArvBin(ArvBin raiz);
extern void caminhaInOrdemArvBin(ArvBin raiz, char* resultado);

#endif