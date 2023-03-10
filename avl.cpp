#include "arvore.h"

//Função para obter o fator de balanceamento de um nó
int fatorBalanceamento(binaria * no)
{
    if (no == NULL)
        return 0;
    return height(no->esq) - height(no->dir);
}

//Função para fazer a rotação à esquerda
binaria * rotacaoEsq(binaria * x)
{
    binaria * y = x->dir;
    binaria * T2 = y->esq;
 
    // Rotação
    y->esq = x;
    x->dir = T2;
 
    // Atualizar alturas
    x->altura = max(height(x->esq), 
                    height(x->dir)) + 1;
    y->altura = max(height(y->esq), 
                    height(y->dir)) + 1;
 
    // Retornar o novo nó
    return y;
}

// Função para fazer a rotação à direita
binaria * rotacaoDir(binaria * y)
{
    binaria * x = y->esq;
    binaria * T2 = x->dir;
 
    // Rotação
    x->dir = y;
    y->esq = T2;
 
    // Atualizar alturas
    y->altura = max(height(y->esq), 
                    height(y->dir)) + 1;
    x->altura = max(height(x->esq), 
                    height(x->dir)) + 1;
 
    // Retornar o novo nó
    return x;
}

// Função para inserir um nó na árvore
binaria * insereAVL(binaria * raiz, veiculo * dados)
{
    // Se a árvore estiver vazia 
  if (raiz == NULL) 
    return newBinaria(dados);
  
  // Se o nó a ser inserido for menor que o nó raiz 
  if (dados->placa <= raiz->info->placa) 
    raiz->esq  = insere_binaria(raiz->esq, dados); 
  
  // Se o nó a ser inserido for maior que o nó raiz 
  else if (dados->placa > raiz->info->placa) 
    raiz->dir = insere_binaria(raiz->dir, dados); 
  
  // Atualizar a altura do nó 
  raiz->altura = 1 + max(height(raiz->esq), height(raiz->dir)); 
 
  // Obtendo o fator de balanceamento
    int balance = fatorBalanceamento(raiz);
 
    // Se houve desbalanceamento, então há 4 casos
 
    // Esquerda Esquerda
    if (balance > 1 && raiz->info->placa < raiz->esq->info->placa)
        return rotacaoDir(raiz);
 
    // Direita Direita
    if (balance < -1 && raiz->info->placa > raiz->dir->info->placa)
        return rotacaoEsq(raiz);
 
    // Esquerda Direita
    if (balance > 1 && raiz->info->placa > raiz->esq->info->placa)
    {
        raiz->esq = rotacaoEsq(raiz->esq);
        return rotacaoDir(raiz);
    }
 
    // Direita Esquerda
    if (balance < -1 && raiz->info->placa < raiz->esq->info->placa)
    {
        raiz->dir = rotacaoDir(raiz->dir);
        return rotacaoEsq(raiz);
    }
 
    // Retornar o nó (não-modificado)
    return raiz;
}

binaria * preencherAVL(binaria * raiz, no * inicio, string comb){ 
  // Percorrer a lista 
  while(inicio != NULL){ 
        if (inicio->carro->combustivel == comb)
        // Inserir os dados da lista na árvore passando o filtro de combustível
        raiz = insereAVL(raiz, inicio->carro); 
        // Avançar para o próximo nó da lista 
        inicio = inicio->prox;
    } 
  // Retornar a árvore preenchida 
  return raiz; 
}