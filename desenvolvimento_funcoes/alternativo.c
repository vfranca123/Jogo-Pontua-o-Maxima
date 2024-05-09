#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/alternativo.h"
#include "../interfaces/array.h"





int helper(int* sequence, int start, int n, struct Tuple* memo) {
    // Se a sequência estiver vazia, retorna 0
    if (start >= n) {
        return 0;
    }
    // Se houver apenas um elemento na sequência, retorna o próprio valor
    if (start == n - 1) {
        return sequence[start];
    }
    // Verifica se o valor já foi calculado e armazenado na memoização
    if (memo[start].sequence != NULL) {
        return memo[start].score;
    }
    // Calcula a pontuação incluindo o elemento atual
    int incluindo = sequence[start] + helper(sequence, start + 2, n, memo);
    // Calcula a pontuação excluindo o elemento atual
    int excluindo = helper(sequence, start + 1, n, memo);
    // Armazena o máximo entre a pontuação incluindo e excluindo na memoização
    memo[start].sequence = sequence;
    memo[start].score = (incluindo > excluindo) ? incluindo : excluindo;
    return memo[start].score;
}

int alternativo(int* seq, int n) {
    // Aloca memória para a memoização
    struct Tuple* memo = (struct Tuple*)calloc(n, sizeof(struct Tuple));
    // Chama a função helper para calcular a pontuação máxima
    int result = helper(seq, 0, n, memo);
    // Libera a memória alocada para a memoização
    free(memo);
    return result;
}



