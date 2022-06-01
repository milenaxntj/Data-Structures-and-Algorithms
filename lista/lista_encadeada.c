#include "lista.h"

#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/**************************************
* DADOS
**************************************/

typedef struct no{
	TipoElemento dado;
	struct no    *ant;
	struct no    *prox;
} No;

typedef struct {
	No *inicio;
	No *fim;
	int qtde;
} Lista;

/**************************************
* IMPLEMENTAÇÃO*
**************************************/
// Desenvolva as funções

Lista* lista_criar(){

    Lista* nova = (Lista*)malloc(sizeof(Lista));

    nova->qtde = 0;
    nova->inicio = NULL;
    nova->fim = NULL;

    return nova;

}

void lista_destruir(Lista** endereco);

bool lista_anexar(Lista* l, TipoElemento elemento){

    No* aux = (No*)malloc(sizeof(No));

    aux->dado = elemento;

    if(l->inicio = NULL){
        aux->ant = NULL;
        l->inicio = aux;
    } else {
        aux->ant = l->fim;
        l->fim->prox = aux;
    }

    aux->prox = NULL;
    l->fim = aux;
    l->qtde++;
    return true;
}

bool lista_inserir(Lista* l, TipoElemento elemento, int posicao){

}

void lista_imprimir(Lista* l){

	printf("[");
	No* aux = l->inicio;
	for(int i = 0; i < l->qtde; i++){
		printf("%d ", aux->dado);
		aux = aux->prox;
	}
	printf("]\n");

}

bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco);
int lista_removerElemento(Lista* l, TipoElemento elemento);

bool lista_substituir(Lista* l, int posicao, TipoElemento novoElemento);
int lista_posicao(Lista* l, TipoElemento elemento);
bool lista_buscar(Lista* l, int posicao, TipoElemento* endereco);

int lista_tamanho(Lista* l);
bool lista_vazia(Lista* l);
bool lista_toString(Lista* l, char* str);