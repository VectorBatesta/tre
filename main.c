/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vitor
 *
 * Created on 3 de Maio de 2019, 13:13
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int id;
}obj;

typedef struct noArv *ponteiro;

typedef struct noArv{
    obj elemento;
    ponteiro direita;
    ponteiro esquerda;
}noArv;

/////////////////////////////

void iniciaArvore(ponteiro *arvore){
    *arvore = NULL;
}

bool estaVazia(ponteiro *arvore){
    return (*arvore == NULL);
}

bool inserirArvore(ponteiro *arvore, obj x){
    if (*arvore == NULL){
        *arvore = (ponteiro) malloc(sizeof(noArv));
        (*arvore)->esquerda = NULL;
        (*arvore)->direita = NULL;
        (*arvore)->elemento = x;
        return(true);
    }
    
    if((*arvore)->elemento.id == x.id){
        return(false);
    }
    
    if((*arvore)->elemento.id > x.id)
        return(inserirArvore(&(*arvore)->esquerda, x));
    else
        return(inserirArvore(&(*arvore)->direita, x));
}

int tamArv(ponteiro *arvore){
    if (estaVazia(&(*arvore)))
        return 0;
    else{
        return(tamArv(&(*arvore)->direita) + tamArv(&(*arvore)->esquerda) + 1);
    }
}

bool pesquisaArv(ponteiro *arvore, int x){
    if (*arvore == NULL)
        return 0;
    
    if ((*arvore)->elemento.id == x)
        return 1;
    
    if ((*arvore)->elemento.id > x)
        return(pesquisaArv(&(*arvore)->esquerda, x));
    else
        return(pesquisaArv(&(*arvore)->direita, x));
}



ponteiro maxESQ(ponteiro *arvore){
    ponteiro aux;
    aux = *arvore;
    while(aux->esquerda != NULL)
        aux = aux->esquerda;
    return(aux);
}

//ESCOLHER UM DOS DOIS /\ \/
/*
ponteiro minDIR(ponteiro *arvore){
    ponteiro aux;
    aux = *arvore;
    while(aux->direita != NULL)
        aux = aux->direita;
    return(aux);
}
*/



bool removeArv(ponteiro *arvore, int x){
    if (*arvore == NULL)
        return 0;
    
    if ((*arvore)->elemento.id == x){
        ponteiro temp;
        temp = *arvore;
        
        if ((*arvore)->esquerda == NULL && (*arvore)->direita != NULL) //esquerda null
            *arvore = (*arvore)->direita;
        if ((*arvore)->direita == NULL && (*arvore)->esquerda != NULL) //direita null
            *arvore = (*arvore)->esquerda;
        if ((*arvore)->direita == NULL && (*arvore)->esquerda == NULL) //direita E esquerda null
            *arvore = NULL;
        if ((*arvore)->direita != NULL && (*arvore)->esquerda != NULL){ //ambos tem algo
            ponteiro aux;
            aux = maxESQ((*arvore)->esquerda);
            *arvore = aux;
        }
        
        free(temp);
        return 1;
    }
    
    if ((*arvore)->elemento.id > x)
        return(removeArv(&(*arvore)->esquerda, x));
    else
        return(removeArv(&(*arvore)->direita, x));
}








/*
 * 
 */
int main(int argc, char** argv) {
    ponteiro raiz;
    iniciaArvore(&raiz);
    
    obj objeto;
    int escolha;
    
    for(int i = 0; i < 5; i++){
        printf("escolha um numero a ser inserido: ");
        scanf("%i", &escolha);
        objeto.id = escolha;
        inserirArvore(&raiz, objeto);
    }
    
    printf("\n");

    for(int i = 0; i < 5; i++){
        printf("escolha um numero a ser pesquisado: ");
        scanf("%i", &escolha);
        if(pesquisaArv(&raiz, escolha))
            printf(" = sim\n");
        else
            printf(" = NAO\n");
    }
    
    
    
    
    
    
    
    
    
    
    
    //estaVazia(&raiz);
    
    
    return (EXIT_SUCCESS);
}

