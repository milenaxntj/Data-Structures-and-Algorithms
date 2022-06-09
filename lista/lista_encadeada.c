#include "lista.h"
#include <string.h>


/***********************************************
* ESPECIFICAÇÃO DOS DADOS
************************************************/

typedef struct no{
	TipoElemento dado;
	struct no    *ant;
	struct no    *prox;
}No;

struct lista{
	No *inicio;
	No *fim;
	int qtde;
};

No* criar_no(TipoElemento elemento){
    No* aux = (No*)malloc(sizeof(No));
    aux->dado = elemento;
    aux->ant = NULL;
    aux->prox = NULL;

    return aux;
}

Lista* lista_criar(){
    Lista* nova = (Lista*)malloc(sizeof(Lista));
    nova->inicio = NULL;
    nova->fim = NULL;
    nova->qtde = 0;

    return nova;
}

void lista_destruir(Lista** endLista){
    No *aux = (No *)malloc(sizeof(No));
    aux = (*endLista)->inicio;

    while (aux != NULL)
    {
        free(aux);
        aux = aux->prox;
    }

    aux = (*endLista);
    free(aux);
}

bool lista_anexar(Lista* l, TipoElemento elemento){
    No* aux = criar_no(elemento);

    if(l->inicio == NULL){
        l->inicio = aux;
    } else {
        aux->ant = l->fim;
        l->fim->prox = aux;
    }
    l->fim = aux;
    l->qtde++;

    return true;
}

bool lista_inserir(Lista* l, TipoElemento elemento, int posicao){
    No* aux = criar_no(elemento);
    
    if(l->inicio == NULL){
        l->inicio = aux;
        l->fim = aux;
    }

    else if(posicao == 0){
        aux->ant = NULL;
        aux->prox = l->inicio;
        l->inicio->ant = aux;
        l->inicio = aux;
    }
    else if(posicao == l->qtde){
        l->fim->prox = aux;
        l->fim = aux;
    } else {
        No* aux2 = l->inicio;
        
        for(int i = 0; i < posicao; i++){
            aux2 = aux2->prox;
        }

        aux->ant = aux2->ant;
        aux->prox = aux2;
        aux2->ant->prox = aux;
        aux2->ant = aux;

    }
    l->qtde++;
    return true;
}

bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco){
    No *aux;
    No *aux2;
    
    if(posicao == 0){
        aux = l->inicio->prox;
        aux2 = l->inicio;

        l->inicio = aux;
        aux->ant= NULL;

    }
    else if(l->qtde == posicao){
        aux = l->fim->ant;
        aux2 = l->fim;

        l->fim = aux;
        aux->prox = NULL;
    }
    else{
        for(int i = 0; i < posicao; i++){
            aux2 = aux2->prox;
        }
        
        aux = aux2->prox;
        aux->ant = aux2->ant;
        aux2->ant->prox = aux;

    }

    aux2->ant = NULL;
    aux2->prox = NULL;

    *endereco = aux2->dado;

    l->qtde--;
}

int lista_removerElemento(Lista* l, TipoElemento elemento){
    No* aux = l->inicio;
    int endereco, posicao;
    for(int i = 0; i < l->qtde; i++){
        
        if(aux->dado == elemento){
            i = posicao;
            lista_removerPosicao(l, i, &endereco);
        }
        aux = aux->prox;
    }

    return posicao;
}

bool lista_substituir(Lista* l, int posicao, TipoElemento novoElemento){
    No *aux;
    if(posicao == 0){ // inicio da lista
        aux = l->inicio;
    }
    else if(posicao == l->qtde){
        aux = l->fim;
    }
    else{
        aux = l->inicio;
        for(int i = 0; i < posicao; i++){
            aux = aux->prox;
        }
    }

    aux->dado = novoElemento;

    return true;    
}

bool lista_vazia(Lista* l){
    if(l->qtde == 0){
        return true;
    }
    else{
        return false;
    }
}

int lista_posicao(Lista* l, TipoElemento elemento){

    No* aux = l->inicio;
    int posicao;
    for(int i = 0; i < l->qtde; i++){  
        if(aux->dado == elemento){
            posicao = i;
            return posicao; // ????
        }
        aux = aux->prox;
    }
}

bool lista_buscar(Lista* l, int posicao, TipoElemento* endereco){
    No* aux = l->inicio;

    for(int i = 0; i < l->qtde; i++){  
        if(i == posicao){
            *endereco = aux->dado;
        }
        aux = aux->prox;
    }

    return true;
}

bool lista_contem(Lista* l, TipoElemento elemento){
    No* aux = l->inicio;
    int verif = -1;
    for(int i = 0; i < l->qtde; i++){
        if(aux->dado == elemento){
            verif++;

        }
        aux = aux->prox;
    }

    if(verif == -1){
        return false;
    } 
    else{
        return true;
    }
}

int lista_tamanho(Lista* l){
    return l->qtde;
}

bool lista_toString(Lista* l, char* str){
}

void lista_imprimir(Lista* l){
    No *aux = l->inicio;
    printf("[");

    for(int i = 0; i < l->qtde; i++){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}
