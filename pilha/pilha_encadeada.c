#include "pilha.h"

/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *prox;
}No;

struct pilha{
	No *topo;
	int qtdeElementos;
};

/**************************************
* IMPLEMENTAÇÃO*
**************************************/
// Desenvolva as funções
Pilha* pilha_criar(){
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = NULL;
	p->qtdeElementos = 0;

	return p;
}

void pilha_destruir(Pilha** endereco){


}

bool pilha_empilhar(Pilha* p, TipoElemento elemento){

	No* n = (No*)malloc(sizeof(No));
	n->dado = elemento;
	n->prox = NULL;

	if(p->qtdeElementos > 0){
		n->prox = p->topo; 
	}
	
	p->topo = n;
	p->qtdeElementos++;

	return true;
}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida){

	No* aux = p->topo->prox; // guarda o anterior que será o topo

	free(p->topo);
	p->topo = aux;
	p->qtdeElementos--;
	return true;

}

bool pilha_topo(Pilha* p, TipoElemento* saida){

	*saida = p->topo->dado;
	return true;

}

bool pilha_vazia(Pilha* p){

	if(p->qtdeElementos > 0){
		return true;
	} else {
		return false;
	}

}

void pilha_imprimir(Pilha* p){

	printf("[");
	No* aux = p->topo;
	for(int i = 0; i < p->qtdeElementos; i++){
		printf("%d ", aux->dado);
		aux = aux->prox;
	}
	printf("]\n");

}

int pilha_tamanho(Pilha* p){

	return p->qtdeElementos - 1;

}

Pilha* pilha_clone(Pilha* p){

	Pilha* clone = (Pilha*)malloc(sizeof(Pilha));
	No* aux = p->topo;
	clone->topo = p->topo;
	clone->qtdeElementos = p->qtdeElementos;

	for(int i = 0; i < p->qtdeElementos; i++){

		pilha_empilhar(clone, aux->dado);
        aux = aux->prox;
	}
	
	return clone;
}

void pilha_inverter(Pilha* p){
	Pilha* aux = pilha_criar();

	TipoElemento elemento = -1;

	while (pilha_vazia(p) != 0){
		pilha_desempilhar(p, &elemento);
		pilha_empilhar(aux, elemento);
	}

	p->topo = aux->topo;
	p->qtdeElementos = aux->qtdeElementos;
	free(aux);
}

bool pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor){

    for (int i = 0; i < tamVetor; i++){
        pilha_empilhar(p, vetor[i]);
    }

    return true;
}

bool pilha_toString(Pilha* f, char* str);