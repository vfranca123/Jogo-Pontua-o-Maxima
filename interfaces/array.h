#include <stdio.h>
#include <stdlib.h>

#ifndef array_H
#define array_H
// Definindo a capacidade inicial do vetor
#define INITIAL_CAPACITY 1

// Definindo a estrutura de dados para o vetor dinâmico
typedef struct {
    int *array;     // Array para armazenar os elementos
    int size;       // Tamanho atual do vetor
    int capacity;   // Capacidade atual do vetor
} DynamicArray;

DynamicArray* createDynamicArray();//cria o vetor dinamico  
void resize(DynamicArray *dynArray, int newCapacity);// Função para redimensionar o vetor
void addElement(DynamicArray *dynArray, int element); // Adicionando elementos ao vetor
void removeElement(DynamicArray *dynArray, int index);// Removendo um elemento do vetor
void displayArray(DynamicArray *dynArray);// Exibindo os elementos do vetor após a remoção

#endif