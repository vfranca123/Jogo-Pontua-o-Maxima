#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/array.h"

#ifndef alternativo_H
#define alternativo_H

struct Tuple {
    int* sequence;
    int score;
};

int helper(int* sequence, int start, int n, struct Tuple* memo);
int alternativo(int* seq, int n);

#endif