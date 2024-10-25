#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

void insere_antes (celula *le, int x, int y){
    celula *atual = le;
    celula *anterior = NULL;

    while (atual != NULL && atual->dado != y)
    {
        anterior = atual;
        atual = atual->prox;
    }

    celula *novo = malloc(sizeof(celula));
    novo->dado = x;

    if (atual)
    {
        anterior->prox = novo;
        novo->prox = atual;
    }
    else
    {
        anterior->prox = novo;
        novo->prox = NULL;
    }
}