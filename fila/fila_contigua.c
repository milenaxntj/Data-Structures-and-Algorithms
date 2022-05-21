#include "fila.h"

#define TAM_INICIAL 5
/**************************************
* DADOS
**************************************/
struct fila {
	TipoElemento* vetor;
	int tamVetor;
	int inicio;
	int fim;
	int qtdeElementos;
};

/**************************************
* IMPLEMENTAÇÃO
**************************************/

Fila* fila_criar(){

    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->vetor = (TipoElemento*)calloc(TAM_INICIAL, sizeof(TipoElemento));
    f->tamVetor = TAM_INICIAL;
    f->qtdeElementos = 0;
    f->inicio = 0;
    f->fim = f->qtdeElementos - 1;

    return f;
}

void fila_destruir(Fila** enderecoFila){
    
} 

bool fila_inserir(Fila* f, TipoElemento elemento){

    f->vetor[f->qtdeElementos] = elemento;
    f->qtdeElementos++;
    f->fim++;

    return true;

}

bool fila_remover(Fila* f, TipoElemento* saida){

    *saida = f->vetor[f->inicio];

    free(f->vetor[f->inicio]);
    f->vetor[f->inicio] = NULL;
    
    for(int i = 0; i < f->qtdeElementos; i++){

        f->vetor[i] = f->vetor[i + 1];

    }
    
    f->qtdeElementos--;
    f->fim--;

} // estratégia do scanf

bool fila_primeiro(Fila* f, TipoElemento* saida){

    *saida = f->vetor[f->inicio];

} // estratégia do scanf

bool fila_vazia(Fila* f){
    
    if(f->qtdeElementos == 0){
        return true;
    } else { 
        return false;
    }

}

int fila_tamanho(Fila* f){
    
    return f->qtdeElementos;

}

void fila_imprimir(Fila* f){
    
    for(int i = 0; i < f->qtdeElementos; i++){
        printf("%d", f->vetor[i]);
    }
}

Fila* fila_clone(Fila* f){

    Fila* clone = (Fila*)malloc(sizeof(Fila));
    clone->vetor = (Fila*)calloc(f->tamVetor, sizeof(Fila));
    clone->tamVetor = f->tamVetor;
    clone->inicio = f->inicio;
    clone->fim = f->fim;
    clone->qtdeElementos = f->qtdeElementos;

    return clone;
}

bool fila_toString(Fila* f, char* str){

}

bool fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor){

    for(int i = 0; i < tamVetor; i++){
        
        f->vetor[f->qtdeElementos] = vetor[0];
        f->qtdeElementos++;
    }
    
    return true;
}