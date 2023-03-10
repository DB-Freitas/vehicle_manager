#ifndef ARVORE_H
#define ARVORE_H

#include "lista.h"

using namespace std;

typedef struct arvoreBinaria_{
    veiculo * info;
    arvoreBinaria_ * esq;
    arvoreBinaria_ * dir;
    int altura;
}binaria;

binaria * newBinaria(veiculo * dados);

int height(binaria * N);

binaria *insere_binaria(binaria * raiz, veiculo * dados);

int altura_arvore(binaria * raiz);

binaria * preencher_arvore(binaria * raiz, no * inicio, string dir);

void imprimirPreOrdem(binaria * arv);

void encerra_binaria(binaria * raiz);

#endif
