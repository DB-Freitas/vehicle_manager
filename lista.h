#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

using namespace std;

typedef struct Tveiculo{
        string modelo;
        string marca;
        string tipo;
        int ano;
        int km;
        float potencia;
        string combustivel;             
        string cambio;
        string direcao;
        string cor;
        int porta;
        string placa;
        float valor;
}veiculo;

typedef struct no_{
    veiculo * carro;
    no_ * prox;
}no;

typedef struct ptlista_{
    int tam;
    no * lista;
}ptlista;

ptlista * inicia_lista();

void carregar_BD(ptlista * inicio);

void encerra_lista(no * iniciolista);

void salvar(no * iniciolista, int tam);

void mostrar(no * iniciolista);

int incluir(no * iniciolista);

int buscar_remover(ptlista * inicio, string placa);

#endif /* LISTA_H */

