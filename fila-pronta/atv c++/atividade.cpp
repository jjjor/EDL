#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct tipoCelula{
    int item;
    tipoCelula *prox;
};

int pilha_contador;
tipoCelula *topo;


bool criar_pilha(){ //inicia a pilha com valor 0
    topo = NULL;
    pilha_contador = 0;  
}

bool destruir_pilha(){
    int aux;
    tipoCelula *temp;

    if(pilha_vazia()){
        return false;
    }
    else{
        while(topo != NULL){
            temp = topo;
            temp -> prox = NULL;
            topo = topo -> prox;

            free(temp);
        };
        pilha_contador = 0;
        return true;
    }
}

bool pilha_vazia(){ //verifica se a pilha ta vazia
    if(topo == NULL){
        return true;
    }
    
    else{
        return false;
    }
}

bool pilha_tamanho(){ //tamanho da pilha
    return pilha_contador;
}


bool pilha_push(int valor){ //empilhar
    tipoCelula *nova_celula = (tipoCelula*)malloc(sizeof(tipoCelula));

    if(nova_celula == NULL){ //caso seja negado pelo OS
        return false;
    }

    else{
        nova_celula-> item = valor;
        nova_celula -> prox = topo;

        topo = nova_celula;
        pilha_contador++;
        return true;
    }
}


bool pilha_pop(int &valor){ //desempilhar
    tipoCelula *temp;

    if(pilha_vazia()){
        return false;
    }
    else{
        valor = topo -> item;
        temp = topo;
        topo = topo -> prox;

        temp -> prox = NULL;

        free(temp);
        pilha_contador--;
        return true;
    }
}

bool pilha_get(int &valor){ //pega o elemento do topo
    if(pilha_vazia()){
        return false;
    }
    else{
        valor = topo -> item;
        return true;
    }
}

int main(){

    system ("pause");
    return 0;
    
}








