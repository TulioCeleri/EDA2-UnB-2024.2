#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p){
    if (p->prox == NULL || p == NULL)
    {
        return 0;
    }
    else
    {
        p->prox = p->prox->prox;  
        return 1;
    }
}

void remove_elemento (celula *le, int x){
    celula *aux, *anterior;
    aux = le->prox;
    if (le->prox != NULL)
    {
        //x é o primeiro elemento?
        if (le->prox->dado == x)
        {
            le->prox = le->prox->prox;
        }
        //x nao é o primeiro elemento
        else
        {
            while (aux->prox && aux->dado != x)
            {
                anterior = aux;
                aux = aux->prox;
            }
            if (aux->dado == x)
            {
                anterior->prox = aux->prox;
            } 
        }
    }
}

void remove_todos_elementos( celula *le, int x){
    celula *anterior = le;
    celula *atual = le->prox;

    while (atual != NULL) {
        if (atual->dado == x) {
            anterior->prox = atual->prox;
            atual = anterior->prox;
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}