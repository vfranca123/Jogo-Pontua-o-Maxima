#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/array.h"

#ifndef alternativo_H
#define alternativo_H

struct Tupla {
    int* sequencia;
    int pontuacao;
};

int auxiliar(int* sequencia, int inicio, int n, struct Tupla* memo);
int alternativo(int* seq, int n);

#endif