#include "lista.h"
#include <string.h>

#define TAM_INICIAL 10

typedef struct lista{
    TipoElemento* vet;
    int tamanho;
    int qntd;
};

Lista* lista_criar(){
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    TipoElemento* novoVetor = (TipoElemento*)calloc(TAM_INICIAL, sizeof(TipoElemento));

    novaLista->qntd = 0;
    novaLista->tamanho = TAM_INICIAL;
    novaLista->vet = novoVetor;

    return novaLista;
}

void lista_destruir(Lista** endLista){

}

bool lista_anexar(Lista* l, TipoElemento elemento){
    l->vet[l->qntd] = elemento;
    l->qntd++;
}

bool lista_inserir(Lista* l, TipoElemento elemento, int posicao){

    if(posicao > l->qntd){
        l->vet[l->qntd] = elemento;
    }
    else{
        for(int i = l->qntd - 1; i >= posicao; i--){
            l->vet[i + 1] = l->vet[i];  
        }
        l->vet[posicao] = elemento;    
    }   
    l->qntd++;

    return true;
}

bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco){
    
    *endereco = l->vet[posicao]; 
    for(int i = posicao; i < l->qntd; i++){ 
        free(&(l->vet[i]));
        l->vet[i] = l->vet[i+1];
    }
    
    l->qntd--;
    return true;
}
int lista_removerElemento(Lista* l, TipoElemento elemento){

    for(int i = 0; i < l->qntd; i++){   
        if(l->vet[i] == elemento){ 
            free(&(l->vet[i])); 

            while (i <= l->qntd){   
                l->vet[i] = l->vet[i+1];    
                i++;
            }
        l->qntd--;  
        return 0;
        }
    }
}
bool lista_substituir(Lista* l, int posicao, TipoElemento novoElemento){
    for(int i = 0; i < l->qntd; i++){
        if(i == posicao){
            l->vet[i] = novoElemento;
            return true;
        }
    }
}

bool lista_vazia(Lista* l){
    if(l->qntd == 0){
        return true;
    }
    else{
        return false;
    }
}

int lista_posicao(Lista* l, TipoElemento elemento){
    int posicao = -1;

    for(int i = 0; i < l->qntd; i++){
        if(l->vet[i] == elemento){
            posicao = i;
            return posicao;
        }
    }
}

bool lista_buscar(Lista* l, int posicao, TipoElemento* endereco){
    for(int i = 0; i < l->qntd; i++){
        if(i == posicao){
            *endereco = l->vet[i];
            return true;
        }
    }
}

bool lista_contem(Lista* l, TipoElemento elemento){
    int aux = -1;
    for(int i = 0; i < l->qntd; i++){
        if(l->vet[i] == elemento){
            aux++;
        }
    }

    if(aux == -1){
        return false;
    } 
    else{
        return true;
    }

}

int lista_tamanho(Lista* l){
    return l->qntd;
}

bool lista_toString(Lista* l, char* str);
void lista_imprimir(Lista* l){

    printf("[");
    for(int i = 0; i < l->qntd; i++){
        printf("%d ", l->vet[i]);
    } 
    
    printf("]\n");
}
