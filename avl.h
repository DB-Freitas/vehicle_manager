#ifndef AVL_H
#define AVL_H

#include "arvore.h"

using namespace std;

int fatorBalanceamento(binaria * no);

binaria * rotacaoEsq(binaria * x);

binaria * rotacaoDir(binaria * y);

binaria * insereAVL(binaria * raiz, veiculo * dados);

binaria * preencherAVL(binaria * raiz, no * inicio, string comb);

#endif
