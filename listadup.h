/*=======================================================================*/
/*                Trabalho de AED II - Indice remissivo                  */
/* Nome: Arthur Alexsander Martins Teodoro                               */
/* MAtrícula: 0022427         Data: 13/09/2016                           */
/*=======================================================================*/

#ifndef _LISTA_DUP_LA_
#define _LISTA_DUP_LA_

typedef struct listadup *Lista;

extern Lista criaLista(void);
extern int insereLista(Lista p,int pos ,int valor);
extern int vaziaLista(Lista p);
extern int retiraListaPos(Lista p, int pos);
extern void printaLista(Lista l, FILE* arquivo);
extern void destroiLista(Lista l);
extern void mudaValorLista(Lista l, int pos, int valor);
extern int tamanhoLista(Lista l);
extern int existeLista(Lista l, int valor);

#endif