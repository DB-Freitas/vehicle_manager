/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Douglas B. Freitas
 *
 * Created on 26 de Janeiro de 2023, 16:27
 */
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

#include "lista.h"
#include "arvore.h"
#include "avl.h"

using namespace std;

int main(int argc, char** argv) {
    
    int op = -1, opsalvar = -1, carregar = 0;
    string placa;
    
    //iniciando as estruturas.
    ptlista * inicio =  inicia_lista();
    binaria * raiz = NULL;
    binaria * raizAVL = NULL;
    
    carregar_BD(inicio);
    
    while (op != 0){
       
        cout << endl;
        cout << "_____MENU_____" << endl << endl;
        cout << "1 - Relatorio da lista principal." << endl;
        cout << "2 - Incluir veiculo." << endl;
        cout << "3 - Buscar veiculo por placa." << endl;
        cout << "4 - Construir arvore binaria de busca." << endl;
        cout << "5 - Construir arvore AVL." << endl;
        cout << "6 - Imprimir em pre-ordem." << endl;
        cout << "0 - Sair." << endl;    
        cin >> op;
        cout << endl;
        
        switch(op){
        
            case 1:{
                mostrar(inicio->lista);
                cout << endl << "Numero de veiculos: " << inicio->tam << endl;
                break;
            }
            case 2:{
                if (incluir(inicio->lista) == 1){
                    inicio->tam++;
                    cout << "Veiculo inserido com sucesso" << endl;
                }
                else
                    cout << "Nao foi possivel inserir" << endl;
                break;
            }
            case 3:{
                cout << "Digite a placa do veiculo (letras e numeros XXX9999): " << endl;
                cin >> placa;
                cout << endl;
                if (buscar_remover(inicio, placa) == -1){
                    cout << "Veiculo nao encontrado" << endl;
                }
                break;
            }
            case 4:{
                string dir;
                cout << "Entre com o tipo de direcao desejada(Hidraulica/Eletrica): " << endl;
                cin >> dir;
                raiz = preencher_arvore(raiz, inicio->lista, dir);
                cout << "Altura maxima da arvore: " << altura_arvore(raiz) << endl; 
                break;
            }
            case 5:{
                string comb;
                cout << "Entre com o tipo de combustivel desejado(Flex/Diesel/Gasolina): " << endl;
                cin >> comb;
                raizAVL = preencherAVL(raizAVL, inicio->lista, comb);
                cout << "Altura maxima da arvore: " << altura_arvore(raizAVL) << endl; 
                break;
            }
            case 6:{
                int arvoreopcao;
                cout << "Qual arvore deseja imprimir?" << endl;
                cout << "1 - Arvore Binaria de Busca." << endl;
                cout << "2 - Arvore AVL." << endl;
                cin >> arvoreopcao;
                if (arvoreopcao == 1){
                    imprimirPreOrdem(raiz);
                    break;
                }
                else{
                    imprimirPreOrdem(raizAVL);
                    break;
                }
            }
            case 0:{
                cout << "Deseja salvar as alteracoes? " << endl;               
                cout << "1 - Sim" << endl;
                cout << "2 - Nao" << endl;
                cin >> opsalvar;
                if (opsalvar == 1){
                    salvar(inicio->lista, inicio->tam);
                }
                break;
            }    
            default:
                cout << "Entrada invalida, digite novamente: " << endl;
                break;
        }
    }
    
    //Desaloca o espaço de memoria utilizado.
    encerra_lista(inicio->lista);
    encerra_binaria(raiz);
    encerra_binaria(raizAVL);
    imprimirPreOrdem(raiz);
    return 0;
}
