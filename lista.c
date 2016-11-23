/*=======================================================================*/
/*                Trabalho de AED II - Indice remissivo                  */
/* Nome: Arthur Alexsander Martins Teodoro                               */
/* MAtrícula: 0022427         Data: 13/09/2016                           */
/*=======================================================================*/

/*=======================================================================*/
/*                        BIBLIOTECAS USADAS                             */
/*=======================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "listadup.h"
#include "lista.h"

/*=======================================================================*/
/*                         ESTRUTURA CRIADA                              */
/*=======================================================================*/
struct palavra
{
	char plv[33];
	Lista ocorrencias;
};

struct no
{
	struct palavra *valor;
	struct no *prox;
	struct no *ant;
};

typedef struct no *No;

struct lista
{
	int tam;
	struct no *inicio;
	struct no *fim;
};

/*=======================================================================*/
/*CRIA LISTA - FUNCAO DE CRIACAO DA LISTA                                */
/*IN: VOID   OUT: PONTEIRO PARA LISTA                                    */
/*=======================================================================*/
ListaPalavra criaListaPalavra(int tam)
{
	ListaPalavra h = (ListaPalavra) malloc(sizeof(struct lista));
	h->inicio = NULL;
	h->fim = NULL;
	h->tam = 0;
	return h;
}

/*=======================================================================*/
/*DESTROI LISTA - FUNCAO DE DESTRUICAO DA LISTA                          */
/*IN: PONTEIRO PARA LISTA   OUT: VOID                                    */
/*=======================================================================*/
void destroiListaPalavra(ListaPalavra lista)
{
	No retirar = lista->inicio;
	while(retirar != NULL)
	{
		lista->inicio = retirar->prox;
		destroiLista(retirar->valor->ocorrencias);
		free(retirar);
		retirar = lista->inicio;
	}
	lista = NULL;
}

/*=======================================================================*/
/*INSERE LISTA - FUNCAO RESPONSAVEL POR INSERIR PALAVRA                  */
/*IN: LISTA E PALAVRA A INSERIR   OUT: PONTEIRO PARA PALAVRA             */
/*=======================================================================*/
Palavra insereListaPalavra(ListaPalavra lista, char* palavra)
{
	No insere = (No) malloc(sizeof(struct no));
	Palavra plv = (Palavra) malloc(sizeof(struct palavra));

	insere->valor = plv;
	strcpy(plv->plv, palavra);
	plv->ocorrencias = criaLista();

	if(lista->inicio == NULL)
	{
		insere->ant = NULL;
		insere->prox = NULL;
		lista->inicio = insere;
		lista->fim = insere;
		return plv;
	}

	insere->prox = lista->inicio;
	lista->inicio->ant = insere;
	insere->ant = NULL;
	lista->inicio = insere;
	lista->tam++;
	return plv;

}

/*=======================================================================*/
/*BUSCA LISTA - FUNCAO DE BUSCA DA LISTA                                 */
/*IN: LISTA E PALAVRA A BUSCAR   OUT: PONTEIRO PARA PALAVRA              */
/*=======================================================================*/
Palavra buscaListaPalavra(ListaPalavra lista, char* palavra)
{
	No olhar = lista->inicio;
	while(olhar != NULL && strcmp(olhar->valor->plv, palavra))
	{
		olhar = olhar->prox;
	}

	if(olhar == NULL)
		return NULL;

	return olhar->valor;
}

/*=======================================================================*/
/*INSERE OCORRENCIA - FUNCAO RESPONSAVEL POR INSERIR LINHA               */
/*IN: LISTA, PALAVRA E LINHA   OUT: VOID                                  */
/*=======================================================================*/
void insereOcorrenciaLista(ListaPalavra lista, char* palavra, int linha)
{
	Palavra plv = buscaListaPalavra(lista, palavra);
	if(plv != NULL)
	{
		if(!existeLista(plv->ocorrencias, linha))
			insereLista(plv->ocorrencias, tamanhoLista(plv->ocorrencias), linha);
	}
}

/*=======================================================================*/
/*TAMANHO LISTA - FUNCAO RESPONSAVEL POR RETORNAR TAMANHO DA LISTA       */
/*IN: LISTA   OUT: INT                                                   */
/*=======================================================================*/
int tamanhoListaPalavra(ListaPalavra lista)
{
	return lista->tam;
}

/*=======================================================================*/
/*RETORNA PALAVRA - FUNCAO QUE RETORNA A STRING DA STRUCT                */
/*IN: PALAVRA   OUT: CHAR*                                               */
/*=======================================================================*/
char* retornaPalavraLista(Palavra plv)
{
	return plv->plv;
}

/*=======================================================================*/
/*RETORNA LISTA - FUNCAO QUE RETORNA A LISTA DA STRUCT                   */
/*IN: PALAVRA   OUT: LISTA                                               */
/*=======================================================================*/
Lista retornaListaPalavra(Palavra plv)
{
	return plv->ocorrencias;
}