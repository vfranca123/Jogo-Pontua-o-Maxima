#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../interfaces/array.h" 

DynamicArray* createDynamicArray() {
    // Alocando memória para a estrutura DynamicArray
    DynamicArray *dynArray = (DynamicArray*)malloc(sizeof(DynamicArray));
    // Verificando se a alocação foi bem sucedida
    if (dynArray == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    // Alocando memória para o array de inteiros
    dynArray->array = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    // Verificando se a alocação foi bem sucedida
    if (dynArray->array == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    // Inicializando o tamanho e a capacidade do vetor
    dynArray->size = 0;
    dynArray->capacity = INITIAL_CAPACITY;
    return dynArray;
}

// Função para redimensionar o vetor
void resize(DynamicArray *dynArray, int newCapacity) {
    // Realocando memória para o array com a nova capacidade
    dynArray->array = (int*)realloc(dynArray->array, newCapacity * sizeof(int));
    // Verificando se a realocação foi bem sucedida
    if (dynArray->array == NULL) {
        printf("Erro: Falha ao realocar memória.\n");
        exit(EXIT_FAILURE);
    }
    // Atualizando a capacidade do vetor
    dynArray->capacity = newCapacity;
}
// Função para adicionar um elemento ao vetor
void addElement(DynamicArray *dynArray, int element) {
    // Verificando se o vetor precisa ser redimensionado
    if (dynArray->size >= dynArray->capacity) {
        resize(dynArray, dynArray->capacity * 2);
    }
    // Adicionando o elemento ao final do vetor e atualizando o tamanho
    dynArray->array[dynArray->size++] = element;
}
// Função para remover um elemento do vetor
void removeElement(DynamicArray *dynArray, int index) {
    if (index < 0 || index >= dynArray->size) {
        printf("Erro: Índice inválido.\n");
        return;
    }
    for (int i = index; i < dynArray->size - 1; i++) {
        dynArray->array[i] = dynArray->array[i + 1];
    }
    dynArray->size--;
}
// Função para exibir os elementos do vetor
void displayArray(DynamicArray *dynArray) {
    printf("Elementos do vetor: ");
    // Percorrendo o vetor e imprimindo seus elementos
    for (int i = 0; i < dynArray->size; i++) {
        printf("%d ", dynArray->array[i]);
    }
    printf("\n");
}





