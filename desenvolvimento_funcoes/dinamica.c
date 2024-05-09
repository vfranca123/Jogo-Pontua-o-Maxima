
#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/array.h"


// Função para encontrar o maior número entre dois números
// Explicação: Esta função recebe dois números e retorna o maior deles.
int biger(int a, int b) {
    // Se o número 'a' for maior que o número 'b', retorna 'a'
    if (a > b) {
        return a;
    } else { // Caso contrário, retorna 'b'
        return b;
    }
}

// Função para calcular a pontuação máxima usando programação dinâmica
// Explicação: Esta função recebe um conjunto de números e seu tamanho, e calcula a pontuação máxima que se pode obter seguindo regras específicas.
int Dinamica(int vet[], int size) {
    // Se o tamanho do conjunto for 0, retorna 0, pois não há números para calcular a pontuação
    if (size == 0) {
        return 0;
    }

    // Variáveis para armazenar a pontuação incluindo e excluindo o número atual
    int in = 0; 
    int ex = 0; 

    // Loop sobre os números do conjunto
    for (int i = 0; i < size; i++) {
        int temp = in; // Variável temporária para armazenar a pontuação incluindo atual

        // Calcula a pontuação incluindo o número atual e armazena em 'in'
        in = ex + vet[i];

        // Calcula a pontuação excluindo o número atual e armazena o maior entre a pontuação anterior e a atual em 'ex'
        ex = biger(temp, ex);
    }

    // Retorna o maior valor entre a pontuação incluindo e a pontuação excluindo
    return biger(in, ex);
}
