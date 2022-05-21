#include<stdio.h>
#include "pilha.h"

int main(){

    Pilha* p = pilha_criar();
    pilha_empilhar(p, 1);
    pilha_empilhar(p, 2);
    pilha_empilhar(p, 3);
    pilha_empilhar(p, 4);
    pilha_imprimir(p);
    int elemento;
    pilha_desempilhar(p, &elemento);
    printf("%d ", elemento);
    pilha_desempilhar(p, &elemento);
    printf("%d ", elemento);
}