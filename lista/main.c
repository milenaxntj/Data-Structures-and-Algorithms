#include "lista.h"
#include<string.h>

int main(){

    Lista *l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 40);
    lista_imprimir(l); // [10 20 40]
    printf("\ninserir 30\n");

    lista_inserir(l, 30, 2);
    lista_imprimir(l); // [10 20 30 40]

    lista_anexar(l, 100);
    lista_anexar(l, 60);
    lista_anexar(l, 80);

    lista_inserir(l, 70, 6);
    lista_imprimir(l); //[10 20 30 40 100 60 70 80]
    printf("\nsubstituir posicaoo 4\n");

    lista_substituir(l, 4, 50); //[10 20 30 40 50 60 70 80]
    lista_imprimir(l);

    printf("###############################\n\n");

    int elemento = 40; // elemento para procurar
    int posicao = lista_posicao(l, elemento);

    if(posicao == -1){
        printf("o elemento %d nao foi encontrado", elemento); // o elemento 40 nao foi encontrado
    }
    else{
        printf("o elemento %d esta na posicao %d", elemento, posicao); // o elemento 40 esta na posicao 3
    }

    printf("\n\n###############################\n\n");

    int elemento2;
    int posicao2 = 2; // POSICAO A SER EXTRAIDA DO DADO
    lista_buscar(l, posicao2, &elemento2);
    printf("Elemento %d encontrado na posicao %d", elemento2, posicao2); // Elemento 30 encontrado na posicao 2


    return 0;
}