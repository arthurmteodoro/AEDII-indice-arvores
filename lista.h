/*=======================================================================*/
/*                Trabalho de AED II - Indice remissivo                  */
/* Nome: Arthur Alexsander Martins Teodoro                               */
/* MAtrícula: 0022427         Data: 13/09/2016                           */
/*=======================================================================*/
#ifndef _ListaPalavra_
#define _ListaPalavra_

#include "listadup.h"

typedef struct palavra *Palavra;
typedef struct lista *ListaPalavra;

extern ListaPalavra criaListaPalavra(int tam);
extern void destroiListaPalavra(ListaPalavra lista);
extern Palavra insereListaPalavra(ListaPalavra lista, char* palavra);
extern Palavra buscaListaPalavra(ListaPalavra lista, char* palavra);
extern void insereOcorrenciaLista(ListaPalavra lista, char* palavra, int linha);
extern int tamanhoListaPalavra(ListaPalavra lista);
extern char* retornaPalavraLista(Palavra plv);
extern Lista retornaListaPalavra(Palavra plv);

#endif