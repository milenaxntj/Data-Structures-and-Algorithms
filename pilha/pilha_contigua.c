#include "pilha.h"
#include <string.h>

#define TAM_INICIAL 5

/**************************************
* DADOS
**************************************/
struct pilha {
	TipoElemento* vetor;
	int tamVetor;
	int qtdeElementos;
};

/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Desenvolva as funções

Pilha* pilha_criar(){

    Pilha* p = (Pilha*)malloc(sizeof(Pilha));

    p->vetor = (int*)calloc(TAM_INICIAL, sizeof(int));
    p->tamVetor = TAM_INICIAL;
    p->qtdeElementos = 0;

    return p;

}

void pilha_destruir(Pilha** endereco){

    Pilha* aux = *endereco;

    free(aux);
    endereco = NULL;

}

bool pilha_empilhar(Pilha* p, TipoElemento elemento){

    p->vetor[p->qtdeElementos] = elemento;
    p->qtdeElementos++;
    return true;
}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida){

    *saida = p->vetor[p->qtdeElementos - 1];
    free(&(p->vetor[p->qtdeElementos - 1]));
    p->qtdeElementos--;
    return true;

}

bool pilha_topo(Pilha* p, TipoElemento* saida){
    
    *saida = p->vetor[p->qtdeElementos] - 1;
    return true;

}

bool pilha_vazia(Pilha* p){

    if(p->vetor[p->qtdeElementos] == 0){
        return true;
    } else {
        return false;
    }

}

void pilha_imprimir(Pilha* p){

    for(int i = 0; i < p->qtdeElementos; i++){
        printf("%d", p->vetor[i]);
    }

}

int pilha_tamanho(Pilha* p){

    return p->qtdeElementos;

}

Pilha* pilha_clone(Pilha* p){

    Pilha* clone = (Pilha*)malloc(sizeof(Pilha));

    clone->qtdeElementos = p->qtdeElementos;
    clone->vetor = (int*)calloc(clone->qtdeElementos, sizeof(int));
    clone->tamVetor = p->tamVetor;

    for(int i = 0; i < clone->qtdeElementos; i++){
        clone->vetor[i] = p->vetor[i];
    }

    return clone;
}

void pilha_inverter(Pilha* p){

    Pilha* reverso = pilha_clone(p);
    int final = pilha_tamanho(p) - 1;
    
    for(int i = 0; i < reverso->qtdeElementos; i++){
        reverso->vetor[i] = p->vetor[final];
        final--;
    }
}

bool pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor){
    
    for (int i = 0; i < tamVetor; i++)
    {
        pilha_empilhar(p, vetor[i]);
    }

    return true;
}

bool pilha_toString(Pilha* f, char* str){

    str[0] = '\0';

    strcat(str, "["); // insere na string o valor passado

    for (int i = 0; i < f->qtdeElementos; i++)
    {
        char casting[50];

        sprintf(casting, "%d", f->vetor[i]);
        strcat(str, casting);

        if (i < (f->qtdeElementos) - 1)
        {
            strcat(str, ",");
        }
    }

    strcat(str, "]\n");

    return true;
}


