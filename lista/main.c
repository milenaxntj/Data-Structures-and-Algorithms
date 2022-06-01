#include<stdio.h>
#include "lista.h"

int main(){

    Lista* l = lista_criar();
    lista_anexar(l, 10);
    lista_imprimir(l);
}
