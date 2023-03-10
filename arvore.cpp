#include "arvore.h"

//Função para criar um novo nó 
binaria * newBinaria(veiculo * dados){ 
  binaria * tmp = new binaria; 
  // Inserindo os dados 
  tmp->info = dados; 
  tmp->dir = NULL; 
  tmp->esq = NULL; 
  tmp->altura = 1;
  return tmp; 
} 

//Função para calcular a altura de um nó 
int height(binaria * N){ 
  if (N == NULL) 
    return 0; 
  return N->altura; 
} 

//Função para inserir um nó na árvore de busca 
binaria *insere_binaria(binaria * raiz, veiculo * dados){ 
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
  // Retorna a árvore atualizada 
  return raiz; 
}

//Função para calcular a altura máxima da árvore 
int altura_arvore(binaria * raiz){ 
  if (raiz == NULL) 
    return 0; 
  return 1 + max(height(raiz->esq), height(raiz->dir)); 
} 

//Função para preencher a árvore de busca com os dados da lista principal 
binaria * preencher_arvore(binaria * raiz, no * inicio, string dir){ 
  // Percorrer a lista 
  while(inicio != NULL){ 
        if (inicio->carro->direcao == dir)
        // Inserir os dados da lista na árvore passando o filtro de combustível
        raiz = insere_binaria(raiz, inicio->carro); 
        // Avançar para o próximo nó da lista 
        inicio = inicio->prox;
    } 
  // Retornar a árvore preenchida 
  return raiz; 
}

//Função para imprimir a árvore binária em pré-ordem
void imprimirPreOrdem(binaria * arv) {
    if (arv != NULL) {
        cout << arv->info->modelo << " ";
        cout << arv->info->marca << " ";
        cout << arv->info->tipo << " ";
        cout << arv->info->ano << " ";
        cout << arv->info->km << " ";
        cout << arv->info->potencia << " ";
        cout << arv->info->combustivel << " ";
        cout << arv->info->cambio << " ";
        cout << arv->info->direcao << " ";
        cout << arv->info->cor << " ";
        cout << arv->info->porta << " ";
        cout << arv->info->placa << " ";
        cout << arv->info->valor << endl;
        imprimirPreOrdem(arv->esq);
        imprimirPreOrdem(arv->dir);
    }
}

//função para desalocar uma árvore binária
void encerra_binaria(binaria * raiz){
    if(raiz == NULL)
        return;
    encerra_binaria(raiz->esq);
    encerra_binaria(raiz->dir);
    delete(raiz);
}