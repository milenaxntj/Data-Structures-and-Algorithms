    #include "fila.h"

/**************************************
* DADOS
**************************************/
typedef struct no{
    int dado;
    struct no* prox;
}No;

struct fila {
    No* inicio;
    No* fim;
    int qtde;
};

/**************************************
* IMPLEMENTAÇÃO
**************************************/
Fila* fila_criar(){

    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->qtde = 0;
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

void fila_destruir(Fila** enderecoFila){

}

bool fila_inserir(Fila* f, TipoElemento elemento){

    No* n = (No*)malloc(2*sizeof(No));
    n->dado = elemento;
    n->prox = NULL;

    if(f->qtde == 0){
        f->inicio = n;
        f->fim = n;
    } else {
        f->fim->prox = n;
        f->fim = n;
    }


    return true;
}

bool fila_remover(Fila* f, TipoElemento* saida){
    *saida = f->inicio->dado;
    
    No* i = f->inicio;

    f->inicio = f->inicio->prox;
    free(i);

} // estratégia do scanf
bool fila_primeiro(Fila* f, TipoElemento* saida){

    *saida = f->inicio->dado;

}// estratégia do scanf
bool fila_vazia(Fila* f){
    if(f->qtde == 0){
        return true;
    } else {
        return false;
    }
}
int fila_tamanho(Fila* f){
    return f->qtde -1;
}
void fila_imprimir(Fila* f){

}
Fila* fila_clone(Fila* f){
    Fila* clone = fila_criar();
    No* aux = f->inicio;

    for(int i = 0; i < f->qtde; i++){
        fila_inserir(clone, aux->dado);
        aux = aux->prox;
    }

    return clone;
}
bool fila_toString(Fila* f, char* str);
bool fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor){

    for (int i = 0; i < tamVetor; i++)
    {
        fila_inserir(f, vetor[i]);
    }

    return true;
}
