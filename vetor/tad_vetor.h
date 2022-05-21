#ifndef _TAD_VETOR_
#define _TAD_VETOR_

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/********************************************
 * DADOS
 *******************************************/
typedef struct vetor Lista;

/********************************************
 * OPERAÇÕES
 *******************************************/

// 1. Criar uma nova sequência
Lista* vet_criar(int tamanho);

// 10. Imprimir a sequência
void vet_imprimir(Lista* l);

// 2. Inserir um elemento no final da sequência
//(dobrar se nao tiver espaço)
bool vet_anexar(Lista* l, int elemento);

// 3. Inserir um elemento em qualquer posição da sequência
//(dobrar se nao tiver espaço)
bool vet_inserir(Lista* l, int elemento, int posicao);

// 4. Substituir um elemento em uma determinada posição
bool vet_substituir(Lista* l, int posicao, int novoElemento);

// 5. Remover um elemento de uma determinada posição
bool vet_removerPosicao(Lista* l, int posicao, int* endereco);

// 6. Remover um elemento de acordo com o seu valor. Caso haja valores repetidos remover apenas a primeira ocorrência.
int vet_removerElemento(Lista* l, int elemento);

// 7. Recuperar quantos elementos estão armazenados na sequência.
int vet_tamanho(Lista* l);

// 8. Recuperar qual elemento está armazenado em uma determinada posição
bool vet_elemento(Lista* l, int posicao, int* saida);

// 9. Recuperar a posição em que um determinado elemento está armazenado. Caso haja valores repetidos, recuperar a primeira ocorrência.
int vet_posicao(Lista* l, int elemento);

// 11. Desalocar
void vet_desalocar(Lista** endVetor);

// 12. Devolve o vetor na forma de String
bool vet_toString(Lista* l, char* string);

#endif

