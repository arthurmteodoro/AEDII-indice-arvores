/*=======================================================================*/
/*                Trabalho de AED II - Indice remissivo                  */
/* Nome: Arthur Alexsander Martins Teodoro                               */
/* MAtrícula: 0022427         Data: 23/11/2016                           */
/*=======================================================================*/
#ifndef _ARVOREAVL_
#define _ARVOREAVL_

#include "listadup.h"

typedef struct noAVL *ArvAVL;

extern ArvAVL criaArvAVLVazia(void);
extern int maior(int a, int b);
extern int altura(ArvAVL raiz);
extern ArvAVL rotacaoDireitaAVL(ArvAVL raiz);
extern ArvAVL rotacaoEsquerdaAVL(ArvAVL raiz);
extern int pegaBalanceamento(ArvAVL raiz);
extern ArvAVL insereArvAVL(ArvAVL raiz, char* palavra);
extern ArvAVL buscaArvAVL(ArvAVL raiz, char* palavra);
extern void destroiArvAVL(ArvAVL raiz);
extern void insereOcorrenciaArvAVL(ArvAVL raiz, char* palavra, int linha);
extern char* retornaPalavraArvAVL(ArvAVL raiz);
extern Lista retornaListaArvAVL(ArvAVL raiz);
extern void caminhaInOrdemArvAVL(ArvAVL raiz, char* vetor);

#endif