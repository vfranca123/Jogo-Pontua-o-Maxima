#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/alternativo.h"
#include "../interfaces/array.h"
int auxiliar(int* sequencia, int inicio, int n, struct Tupla* memo) {
    // Se a sequência estiver vazia, retorna 0
    if (inicio >= n) {
        return 0;
    }
    // Se houver apenas um elemento na sequência, retorna o próprio valor
    if (inicio == n - 1) {
        return sequencia[inicio];
    }
    // Verifica se o valor já foi calculado e armazenado na memoização
    if (memo[inicio].sequencia != NULL) {
        return memo[inicio].pontuacao;
    }
    // Calcula a pontuação incluindo o elemento atual
    int incluindo = sequencia[inicio] + auxiliar(sequencia, inicio + 2, n, memo);
    // Calcula a pontuação excluindo o elemento atual
    int excluindo = auxiliar(sequencia, inicio + 1, n, memo);
    // Armazena o máximo entre a pontuação incluindo e excluindo na memoização
    memo[inicio].sequencia = sequencia;
    memo[inicio].pontuacao = (incluindo > excluindo) ? incluindo : excluindo;
    return memo[inicio].pontuacao;
}

int alternativo(int* seq, int n) {
    // Aloca memória para a memoização
    struct Tupla* memo = (struct Tupla*)calloc(n, sizeof(struct Tupla));
    // Chama a função auxiliar para calcular a pontuação máxima
    int resultado = auxiliar(seq, 0, n, memo);
    // Libera a memória alocada para a memoização
    free(memo);
    return resultado;
}




