#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca (celula *le, int x){
    celula *atual = le->prox;
    while (atual != NULL && atual->dado != x)
    {
        atual = atual->prox;
    }
    if (atual != NULL)
    {
        return atual;
    }
}

celula *busca_rec (celula *le, int x){
    if (le == NULL)
    {
        return NULL;
    }
    else
    {
        if (le->dado == x)
        {
            return le;
        }
    }
    return busca_rec(le->prox, x);
}