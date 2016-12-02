/*=======================================================================*/
/*           Trabalho de AED II - Indice remissivo com árvores           */
/* Nome: Arthur Alexsander Martins Teodoro                               */
/* MAtrícula: 0022427         Data: 23/11/2016                           */
/*=======================================================================*/

/*=======================================================================*/
/*                        BIBLIOTECAS USADAS                             */
/*=======================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "listadup.h"
#include "arvoreAVL.h"

/*=======================================================================*/
/*                         ESTRUTURA CRIADA                              */
/*=======================================================================*/
struct noAVL
{
  char plv[33];
  Lista ocorrencias;
  int altura;
  struct noAVL *esq;
  struct noAVL *dir;
};

/*=======================================================================*/
/*CRIA ARVORE BINARIA VAZIA - FUNCAO QUE CRIA ARVORE VAZIA               */
/*IN: VOID   OUT: PONTEIRO PARA ARVORE VAZIA                             */
/*=======================================================================*/
ArvAVL criaArvAVLVazia(void)
{
  return NULL;
}

int maior(int a, int b)
{

  if(a > b)
    return a;
  return b;
}

int altura(ArvAVL raiz)
{

  if(raiz == NULL)
    return 0;
  return raiz->altura;
}

ArvAVL rotacaoDireitaAVL(ArvAVL raiz)
{

  ArvAVL noh1 = raiz->esq;
  ArvAVL noh2 = noh1->dir;

  noh1->dir = raiz;
  raiz->esq = noh2;

  raiz->altura = maior(altura(raiz->esq), altura(raiz->dir))+1;
  noh1->altura = maior(altura(noh1->esq), altura(noh1->dir))+1;

  return noh1;
}
 
ArvAVL rotacaoEsquerdaAVL(ArvAVL raiz)
{
  ArvAVL noh1 = raiz->dir;
  ArvAVL noh2 = noh1->esq;

  noh1->esq = raiz;
  raiz->dir = noh2;

  raiz->altura = maior(altura(raiz->esq), altura(raiz->dir))+1;
  noh1->altura = maior(altura(noh1->esq), altura(noh1->dir))+1;

  return noh1;
}

int pegaBalanceamento(ArvAVL raiz)
{
  if(raiz == NULL)
    return 0;
  return altura(raiz->esq) - altura(raiz->dir);
}

ArvAVL insereArvAVL(ArvAVL raiz, char* palavra)
{

  if(raiz == NULL)
  {
    ArvAVL arv = (ArvAVL) malloc(sizeof(struct noAVL));
    strcpy(arv->plv, palavra);
    arv->ocorrencias = criaLista();
    arv->esq = arv->dir = NULL;
    arv->altura = 1;
    return arv;
  }

  if(strcmp(palavra, raiz->plv) < 0)
    raiz->esq  = insereArvAVL(raiz->esq, palavra);
  else
    raiz->dir = insereArvAVL(raiz->dir, palavra);

  raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

  int balance = pegaBalanceamento(raiz);

  /*LL*/
  if (balance > 1 && strcmp(palavra, raiz->esq->plv) < 0)
    return rotacaoDireitaAVL(raiz);

  /*RR*/
  if (balance < -1 && strcmp(palavra, raiz->dir->plv) > 0)
    return rotacaoEsquerdaAVL(raiz);

  /*LR*/
  if (balance > 1 && strcmp(palavra, raiz->esq->plv) > 0)
  {
    raiz->esq =  rotacaoEsquerdaAVL(raiz->esq);
    return rotacaoDireitaAVL(raiz);
  }

  /*RL*/
  if (balance < -1 && strcmp(palavra, raiz->dir->plv) < 0)
  {
    raiz->dir = rotacaoDireitaAVL(raiz->dir);
    return rotacaoEsquerdaAVL(raiz);
  }

  return raiz;
}

ArvAVL buscaArvAVL(ArvAVL raiz, char* palavra)
{
  if(raiz == NULL)
    return NULL;

  if(strcmp(raiz->plv, palavra) > 0)
    return buscaArvAVL(raiz->esq, palavra);

  if(strcmp(raiz->plv, palavra) < 0)
    return buscaArvAVL(raiz->dir, palavra);

  return raiz;
}

/*=======================================================================*/
/*DESTROI ARVORE BINARIA - FUNCAO QUE DESTROI A ARVORE                   */
/*IN: RAIZ   OUT: PONTEIRO NULO                                          */
/*=======================================================================*/
void destroiArvAVL(ArvAVL raiz)
{

  if(raiz != NULL)
  {
    destroiArvAVL(raiz->esq);
    destroiArvAVL(raiz->dir);
    destroiLista(raiz->ocorrencias);
    free(raiz);
    raiz = NULL;
  }
}

/*=======================================================================*/
/*INSERE OCORRENCIA ARVORE BINARIA - FUNCAO INSERE PAGINA NA ARVORE      */
/*IN: RAIZ   OUT: VOID                                                   */
/*=======================================================================*/
void insereOcorrenciaArvAVL(ArvAVL raiz, char* palavra, int linha)
{

  ArvAVL inserir = buscaArvAVL(raiz, palavra);
  if(inserir != NULL)
  {
    if(!existeLista(inserir->ocorrencias, linha))
      insereLista(inserir->ocorrencias, tamanhoLista(inserir->ocorrencias), linha);
  }

}

/*=======================================================================*/
/*INSERE OCORRENCIA ARVORE BINARIA - FUNCAO INSERE PAGINA NA ARVORE      */
/*IN: RAIZ   OUT: PALAVRA                                                */
/*=======================================================================*/
char* retornaPalavraArvAVL(ArvAVL raiz)
{
  return raiz->plv;
}

/*=======================================================================*/
/*INSERE OCORRENCIA ARVORE BINARIA - FUNCAO INSERE PAGINA NA ARVORE      */
/*IN: RAIZ   OUT: LISTA DO NO                                            */
/*=======================================================================*/
Lista retornaListaArvAVL(ArvAVL raiz)
{
  return raiz->ocorrencias;
}


/*=======================================================================*/
/*INSERE OCORRENCIA ARVORE BINARIA - FUNCAO INSERE PAGINA NA ARVORE      */
/*IN: RAIZ, VETOR DESTINO   OUT: VOID                                    */
/*=======================================================================*/
void caminhaInOrdemArvAVL(ArvAVL raiz, char* vetor)
{
  if(raiz != NULL)
  {
    char string[500];

    caminhaInOrdemArvAVL(raiz->esq, vetor);
    sprintf(string, "%s ", raiz->plv);
    strcat(vetor, string);
    caminhaInOrdemArvAVL(raiz->dir, vetor);
  }
}