/*=======================================================================*/
/*                Trabalho de AED II - Indice remissivo                  */
/* Nome: Arthur Alexsander Martins Teodoro                               */
/* MAtrícula: 0022427         Data: 13/09/2016                           */
/*=======================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include "listadup.h"

struct no
{
	int valor;
	struct no *prox;
	struct no *ant;
};

struct listadup
{
	int tam;
	struct no *inicio;
	struct no *fim;
};

typedef struct no *Nodo;

Lista criaLista(void)
{
	Lista p = (Lista) malloc(sizeof(struct listadup));
	p->tam = 0;
	p->inicio = NULL;
	p->fim = NULL;
	return p;
};

int insereLista(Lista p,int pos ,int valor)
{
	//cria um no e coloca seu valor
	Nodo no = (Nodo) malloc(sizeof(struct no));
	no->valor = valor;
	//caso for o primeiro numero a ser inserido
	if(p->tam == 0)
	{
		p->inicio = no;
		p->fim = no;
		no->prox = NULL;
		no->ant = NULL;
		p->tam++;
		return p->tam;
	}
	//se a posicao for a maior que o tamanho = inserir no fim
	if(pos >= p->tam)
	{
		no->prox = NULL;
		Nodo aux = p->fim;
		aux->prox = no;
		no->ant = aux;
		p->fim = no;
		p->tam++;
		return p->tam;
	}
	//inserir no inicio da lista
	if(pos <= 0)
	{
		no->ant = NULL;
		Nodo aux = p->inicio;
		aux->ant = no;
		no->prox = aux;
		p->inicio = no;
		p->tam++;
		return p->tam;
	}
	//caso normal, inserir no meio da lista
	//primeiro tem que colocar o ponteiro aux no lugar que quero inserir
	Nodo aux = p->inicio;
	for(aux=p->inicio; pos != 0; aux=aux->prox)
	{
		pos--;
	}
	//depois de colocar no aux no lugar eh so mudar os ponteiros
	no->ant = aux->ant;
	no->prox = aux;
	aux->ant->prox = no;
	aux->ant = no;
	p->tam++;
	return p->tam;
};

int vaziaLista(Lista p)
{
	return(p->tam == 0);
};

int retiraListaPos(Lista p, int pos)
{
	if(!vaziaLista(p))
	{
		//cria um ponteiro auxiliar
		Nodo aux = NULL;
		//caso especial, existe so uma posicao;
		if(p->tam == 1)
		{
			aux = p->inicio;
			free(aux);
			p->inicio = NULL;
			p->fim = NULL;
			p->tam--;
			return p->tam;
		};
		//caso especial, tirar a primeira posicao;
		if(pos == 0)
		{
			aux = p->inicio;
			p->inicio = aux->prox;
			aux->prox->ant = aux->ant;
			free(aux);
			p->tam--;
			return p->tam;
		};
		//caso especial, tirar a ultima posicao;
		if(pos >= p->tam)
		{
			aux = p->fim;
			p->fim = aux->ant;
			aux->ant->prox = aux->prox;
			free(aux);
			p->tam--;
			return p->tam;
		};
		//caso normal, retirar do meio
		aux = p->inicio;
		for(aux=p->inicio; pos != 0; aux=aux->prox)
		{
			pos--;
		};
		aux->ant->prox = aux->prox;
		aux->prox->ant = aux->ant;
		free(aux);
		p->tam--;
		return p->tam;
	}
	else
	{
		return -1;
	}
};

void printaLista(Lista l, FILE* arquivo)
{
	Nodo aux = l->inicio;
	while(aux != NULL)
	{
		fprintf(arquivo, "%d  ", aux->valor);
		aux = aux->prox;
	};
	fprintf(arquivo, "\n");
};

void destroiLista(Lista l)
{
	while(!vaziaLista(l))
	{
		retiraListaPos(l,0);
	}
	free(l);
};

void mudaValorLista(Lista l, int pos, int valor)
{
	if(vaziaLista(l))
	{
		return;
	}
	if(l->tam > pos)
	{
		Nodo aux = l->inicio;
		for(aux = l->inicio; pos != 0; aux = aux->prox)
		{
			pos--;
		};
		aux->valor = valor;
	}
	return;
};

int tamanhoLista(Lista l)
{
	 return l->tam;
}

int existeLista(Lista l, int valor)
{
	Nodo aux = l->inicio;
	while(aux != NULL)
	{
		if(aux->valor == valor)
			return 1;
		aux = aux->prox;
	}
	return 0;
}