#include "tad_vetor.h"

#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct vetor{
    int* vet;
    int tamanho;
    int qntd;
} Lista;

void vet_imprimir(Lista* l){

    for(int i = 0; i < l->qntd; i++){ // print até ultimo valor preenchido do vetor
        printf("%d ", l->vet[i]);
    } 
    
    printf("\n");

}

void dobrar_tamanho(Lista* l){

    int tamanhoNovo = l->tamanho *2;
    int* vetorAux = (int*)calloc(tamanhoNovo, sizeof(int));

    memcpy(vetorAux, l->vet, l->tamanho * sizeof(int)); // alocando valores antigo do vetor no vetor de tamanho novo
    free(l->vet); // limpando memoria do vetor antigo

    l->tamanho = tamanhoNovo; // tamanho dobrado
    l->vet = vetorAux; // vetor antigo se tornando novo vetor criado
}

Lista* vet_criar(int tamanho){

    Lista* l = (Lista*)malloc(sizeof(Lista)); // cria struct "Lista" na heap
    int* vet = (int*)calloc(tamanho, sizeof(int));  // cria vetor de inteiros na heap

    l->vet = vet; // igualando vetor da heap com vetor da struct
    l->tamanho = tamanho;
    l->qntd = 0;

    return l;
}

bool vet_anexar(Lista* l, int elemento){

    if(l->qntd >= l->tamanho){
        dobrar_tamanho(l);   
    }

    l->vet[l->qntd] = elemento; 
    l->qntd++; // +1 elemento alocado
    
    return true;
}

bool vet_inserir(Lista* l, int elemento, int posicao){
    
    if(l->qntd >= l->tamanho){ 
        dobrar_tamanho(l);
    }

    if(posicao > l->qntd){
        l->vet[l->qntd] = elemento; // para não ficar espaços do vetor nao preenchidos 
    }
        
    for(int i = l->qntd - 1; i >= posicao; i--){    //empurrar elementos para frente até liberar a posição
        l->vet[i + 1] = l->vet[i];  
    }

    l->vet[posicao] = elemento;
    
    l->qntd++;

    return true;
}

bool vet_substituir(Lista* l, int posicao, int novoElemento){

    if(l->qntd >= l->tamanho){ 
        dobrar_tamanho(l);
    }

    if(l->qntd > posicao){
        free(&(l->vet[posicao]));   // limpar posição que vai receber novo elemento
    }

    l->vet[posicao] = novoElemento;

    return true;
}

bool vet_removerPosicao(Lista* l, int posicao, int* endereco){
    
    *endereco = l->vet[posicao];    // passar para main por estrategia do scanf elemento que foi excluido pela posição
    for(int i = posicao; i < l->qntd; i++){ // passar valores para tras para ocupar a posição removida
        free(&(l->vet[i]));
        l->vet[i] = l->vet[i+1];
    }
    
    l->qntd--; // -1 numero alocado

    return true;
}

int vet_removerElemento(Lista* l, int elemento){

    for(int i = 0; i < l->qntd; i++){   // verificação elemento por elemento
        if(l->vet[i] == elemento){  // se for o elemento procurado
            free(&(l->vet[i])); // limpar espaço da posição do elemento
            l->qntd--;  // -1 elemento alocado

            while (i <= l->qntd){   // empurrar elementos para tras para ocupar posição do elemento removido 
                l->vet[i] = l->vet[i+1];    
                i++;
            }
        
        return 0;
        }
    }
}

int vet_tamanho(Lista* l){
    
    return l->qntd;
}

bool vet_elemento(Lista* l, int posicao, int* saida){

    *saida = l->vet[posicao];
    return true;
}

int vet_posicao(Lista* l, int elemento){

    for(int i = 0; i < l->qntd; i++){
        if(l->vet[i] == elemento){
            printf("Posicao do elemento: ");
        }
    }
}

void vet_desalocar(Lista** endVetor){

    Lista* l = *endVetor;
    free(l);
    *endVetor = NULL;

}

bool vet_toString(Lista* l, char* string){

    if(l == NULL) {
        return false;
    } 

    string[0] = '\0';

    strcat(string, "["); // insere na string o valor passado

    for(int i = 0; i <= l->qntd; i++){
        char casting[50];

        sprintf(casting, "%d", l->vet[i]);
        strcat(string, casting);

        if(i < l->qntd){
            strcat(string, ",");
        }
    }
    
    strcat(string, "]\n");

    return true;
}
