/*=======================================================================*/
/*                Trabalho de AED II - Indice remissivo                  */
/* Nome: Arthur Alexsander Martins Teodoro                               */
/* MAtrícula: 0022427         Data: 13/09/2016                           */
/*=======================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "lista.h"
#include "hashEncadeada.h"
#include "arvoreBin.h"
#include "arvoreAVL.h"

#include "indice.h"

int main(int argc, char const *argv[])
{
	/*Verificação de erros*/
	if(argc != 4)
	{
		printf("ERRO - Quantidade de arquivos inválida\n");
		printf("USO: ./main.out <palavraschave> <texto> <saida>\n");
		exit(1);
	}
	FILE* arqTeste1 = fopen(argv[1], "rt");
	FILE* arqTeste2 = fopen(argv[2], "rt");
	if(arqTeste1 == NULL || arqTeste2 == NULL)
	{
		printf("ERRO - arquivos de palavras chave ou texto nao existem\n");
		exit(1);
	}
	fclose(arqTeste1);
	fclose(arqTeste2);
	/*Fim da verificação de erros*/

	/*Le a quantidade de palavras, cria a hash e o vetor*/
	float inicio = (double)clock()/CLOCKS_PER_SEC;
	int quantPalavras = contaPalavrasChave(argv[1]);
	int tamHash = quantPalavras;
	Hash h;
	ListaPalavra lista;
	char** vetor;
	ArvBin raizBin;
	ArvAVL raizAVL;

	tamHash = quantPalavras*0.65;

	if(O == 1 || O == 2)
	{
		vetor = criaVetor(quantPalavras);
		if(O == 1)
			h = criaHash(tamHash);

		if(O == 2)
			lista = criaListaPalavra(quantPalavras);
	}

	if(O == 3)
		raizBin = criaArvBinVazia();
	if(O == 4)
		raizAVL = criaArvAVLVazia();

	/*Inserção das palavras na ED*/
	if(O == 1)
		inserirPalavrasHash(h, argv[1], vetor);
	if(O == 2)
		inserirPalavrasLista(lista, argv[1], vetor);
	if(O == 3)
		raizBin = inserirPalavrasArvBin(raizBin, argv[1]);
	if(O == 4)
		raizAVL = inserirPalavrasArvAVL(raizAVL, argv[1]);

	/*Criação do índice*/
	if(O == 1) 
		criaIndiceHash(h, argv[2]);
	if(O == 2)
		criaIndiceLista(lista, argv[2]);
	if(O == 3)
		criaIndiceArvBin(raizBin, argv[2]);
	if(O == 4)
		criaIndiceArvAVL(raizAVL, argv[2]);

	/*geração da saída*/
	if(O == 1)
		geraSaidaHash(h, argv[3], vetor, quantPalavras);
	if(O == 2)
		geraSaidaLista(lista, argv[3], vetor, quantPalavras);
	if(O == 3)
		geraSaidaArvBin(raizBin, argv[3]);
	if(O == 4)
		geraSaidaArvAVL(raizAVL, argv[3]); 
	/*Fim da criação do indice*/

	if(O == 1 || O == 2)
		destroiVetor(vetor, quantPalavras);

	if(O == 1)
		destroiHash(h);
	if(O == 2)
		destroiListaPalavra(lista);
	if(O == 3)
		destroiArvBin(raizBin);
	if(O == 4)
		destroiArvAVL(raizAVL);

	float fim = (double)clock()/CLOCKS_PER_SEC;
	float tempo = fim - inicio;
	printf("O tempo total foi %f\n", tempo);

	return 0;
}