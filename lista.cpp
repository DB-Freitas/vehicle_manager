#include "lista.h"

//Inicia a lista principal.
ptlista * inicia_lista(){
    ptlista * tmp = new ptlista;
    tmp->tam = 0;
    tmp->lista = NULL;
    return tmp;
}

//Carrega o BD dos veiculos na estrutura.
void carregar_BD(ptlista * inicio){
    
    ifstream myfile("BD_veiculos_3.txt");
    if (myfile.is_open()){
        
        no * ant;
        
        while (!myfile.eof()){
            
            no * tmp = new no;
            tmp->carro = new veiculo;
            
            myfile >> tmp->carro->modelo;
            myfile >> tmp->carro->marca;
            myfile >> tmp->carro->tipo;
            myfile >> tmp->carro->ano;
            myfile >> tmp->carro->km;
            myfile >> tmp->carro->potencia;
            myfile >> tmp->carro->combustivel;
            myfile >> tmp->carro->cambio;
            myfile >> tmp->carro->direcao;
            myfile >> tmp->carro->cor;
            myfile >> tmp->carro->porta;
            myfile >> tmp->carro->placa;
            myfile >> tmp->carro->valor;
            
            //Condição para o primeiro elemento.
            if(inicio->lista == NULL){
                tmp->prox = NULL;
                inicio->lista = tmp;
                inicio->lista->prox = NULL;
                ant = inicio->lista;
            }
            else{
                tmp->prox = ant->prox;
                ant->prox = tmp;
                ant = tmp;
            }  
            inicio->tam++;
        }
        myfile.close();
    }
    else{
        cout <<"Nao foi possivel abrir o arquivo." << endl;         
    }
}
 
//Desaloca as estruturas.
void encerra_lista(no * iniciolista){
     
    no * ant = iniciolista;
    no * pont = iniciolista->prox;
     
    while (pont != NULL){
        delete(ant->carro);
        delete(ant);
        ant = pont;
        pont = pont->prox;
    }
    delete(ant->carro);
    delete(ant);
    delete(iniciolista);
}

//Salva as alterações no arquivo txt.
void salvar(no * iniciolista, int tam){
    
    no * tmp = iniciolista;
    int i = 0;
    ofstream myfile("BD_veiculos_3.txt");
    if (myfile.is_open()){
        while (tmp != NULL){
            if(i < tam -1){
                myfile << tmp->carro->modelo << " " << tmp->carro->marca << " " << tmp->carro->tipo << " " << tmp->carro->ano << " " << tmp->carro->km << " " << tmp->carro->potencia << " " << tmp->carro->combustivel  
                       << " " << tmp->carro->cambio<< " " << tmp->carro->direcao<< " " << tmp->carro->cor<< " " << tmp->carro->porta<< " " << tmp->carro->placa<< " " << tmp->carro->valor << endl;
            }
            else{
                myfile << tmp->carro->modelo << " " << tmp->carro->marca << " " << tmp->carro->tipo << " " << tmp->carro->ano << " " << tmp->carro->km << " " << tmp->carro->potencia << " " << tmp->carro->combustivel  
                       << " " << tmp->carro->cambio<< " " << tmp->carro->direcao<< " " << tmp->carro->cor<< " " << tmp->carro->porta<< " " << tmp->carro->placa<< " " << tmp->carro->valor;
            }
            i++;
            tmp = tmp->prox;
        }
        myfile.close();
        cout << "Dados salvos." << endl;
    }
    else{
        cout << "Nao foi possivel abrir o arquivo." << endl;
    }
}

//Exibe os veiculos.
void mostrar(no * iniciolista){
     
    no * tmp = iniciolista;
     
    if (tmp == NULL)
        cout << "Lista vazia" << endl;
    while(tmp != NULL){

        cout << tmp->carro->modelo << " ";
        cout << tmp->carro->marca << " ";
        cout << tmp->carro->tipo << " ";
        cout << tmp->carro->ano << " ";
        cout << tmp->carro->km << " ";
        cout << tmp->carro->potencia << " ";
        cout << tmp->carro->combustivel << " ";
        cout << tmp->carro->cambio << " ";
        cout << tmp->carro->direcao << " ";
        cout << tmp->carro->cor << " ";
        cout << tmp->carro->porta << " ";
        cout << tmp->carro->placa << " ";
        cout << tmp->carro->valor << endl;
        tmp = tmp->prox; 
    }
}

//Inclui um veiculo na estrutura.
int incluir(no * iniciolista){
    
    no * ant = iniciolista;
    no * pont = iniciolista->prox;
    
    while (ant->prox != NULL){
        ant = pont;
        pont = pont->prox;
    }
    no * tmp = new no;
    tmp->carro = new veiculo;
    
    cout << "Entre com os dados do veiculo" << endl;
    cout << "Modelo: " << endl;
    cin >> tmp->carro->modelo;
    cout << "Marca: " << endl;
    cin >> tmp->carro->marca;
    cout << "Tipo: " << endl;
    cin >> tmp->carro->tipo;
    cout << "Ano: " << endl;
    cin >> tmp->carro->ano;
    cout << "KM: " << endl;
    cin >> tmp->carro->km;
    cout << "Potencia: " << endl;
    cin >> tmp->carro->potencia;
    cout << "Combustivel: " << endl;
    cin >> tmp->carro->combustivel;
    cout << "Cambio: " << endl;
    cin >> tmp->carro->cambio;
    cout << "Direcao: " << endl;
    cin >> tmp->carro->direcao;
    cout << "Cor: " << endl;
    cin >> tmp->carro->cor;
    cout << "Porta: " << endl;
    cin >> tmp->carro->porta;
    cout << "Placa (XXX9999): " << endl;
    cin >> tmp->carro->placa;
    cout << "Valor (99999.00: " << endl;
    cin >> tmp->carro->valor;
    
    tmp->prox = pont;
    ant->prox = tmp;
    
    return 1;
}

//Busca pela placa e apresenta a opção de exclusão.
int buscar_remover(ptlista * inicio, string placa){
    
    int op = -1, retorno, verific = -1;
    no * ant = inicio->lista;
    no * pont = inicio->lista->prox;
    
    if (ant == NULL){
        cout << "Lista Vazia." << endl;
    }
    if (ant->carro->placa == placa){
        cout << "Veiculo encontrado." << endl;
        
        cout << ant->carro->modelo << " " << ant->carro->marca << " " << ant->carro->tipo << " " << ant->carro->ano << " " << ant->carro->km << " " << ant->carro->potencia << " ";
        cout << ant->carro->combustivel << " " << ant->carro->cambio << " " << ant->carro->direcao << " " << ant->carro->cor << " " << ant->carro->porta << " " << ant->carro->placa << " " << ant->carro->valor << endl;
        cout << endl;
        retorno = 0;

        cout << "Excluir veiculo? " << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Nao" << endl;
        cin >> op;
        
        if (op == 1){
            inicio->lista = inicio->lista->prox;
            cout << "Veiculo excluido." << endl;
            inicio->tam--;
            verific = 0;
        }
    }
    while (pont != NULL && verific != 0){
        
        if(pont->carro->placa == placa){
            
            cout << "Veiculo encontrado: " << endl;
            cout << pont->carro->modelo << " " << pont->carro->marca << " " << pont->carro->tipo << " " << pont->carro->ano << " " << pont->carro->km << " " << pont->carro->potencia << " ";
            cout << pont->carro->combustivel << " " << pont->carro->cambio << " " << pont->carro->direcao << " " << pont->carro->cor << " " << pont->carro->porta << " " << pont->carro->placa << " " << pont->carro->valor << endl;
            cout << endl;       
            retorno = 0;
            
            cout << "Excluir veiculo? " << endl;
            cout << "1 - Sim" << endl;
            cout << "2 - Nao" << endl;
            cout << endl;
            cin >> op;
            
            if (op == 1){
                ant->prox = pont->prox;
                cout << "Veiculo excluido." << endl;
                inicio->tam--;
                verific = 0;
            }
            else
                break;
        }
        else{
            ant = pont;
            pont = pont->prox;
        }
    }
    if (pont == NULL && retorno != 0){
        retorno = -1;
    }
    return retorno;
}