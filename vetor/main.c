//main.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tad_vetor.h"

int main(){
	Lista* l = vet_criar(10);

	vet_anexar(l, 10);
	vet_anexar(l, 20);
	vet_anexar(l, 30);
	vet_imprimir(l); // [10,20,30]
	
	vet_inserir(l, 15, 1);
	vet_imprimir(l); // [10,15,20,30]
	
	vet_inserir(l, 5, 0);
	vet_imprimir(l); // [5,10,15,20,30]
	
	int elemento;
	if (vet_removerPosicao(l, 1, &elemento)){
	    printf("O elemento %d foi removido\n", elemento); // O elemento 10 foi removido
	    vet_imprimir(l); // [5,15,20,30]
	}
	
	// if (vet_removerPosicao(l, 10, &elemento) == false){
	if (!vet_removerPosicao(l, 10, &elemento)){
	    printf("Remocao invalida\n");
	} 
	
	char str[200];
	vet_toString(l, str);
	printf("%s", str); //[5,15,20,30]

}