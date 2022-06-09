#include "lista.h"
#include<string.h>

int main(){

    Lista *l = lista_criar();
    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 40);
    lista_imprimir(l); // [10 20 40]
    lista_inserir(l, 30, 2);
    lista_imprimir(l); // [10 20 30 40]
    lista_anexar(l, 100);
    lista_anexar(l, 60);
    lista_anexar(l, 80);
    lista_inserir(l, 70, 6);
    lista_imprimir(l); //[10 20 30 40 50 60 70 80]
    printf(" substituido valor na posicao");
    printf("\n");

    lista_substituir(l, 4, 50);
    lista_imprimir(l);

    return 0;
}