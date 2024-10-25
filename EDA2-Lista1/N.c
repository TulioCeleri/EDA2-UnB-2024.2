#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    celula *atual_l1 = l1->prox;
    celula *atual_l2 = l2->prox;
    celula *atual_l3 = l3;
    while (atual_l1 != NULL && atual_l2 != NULL)
    {
        if (atual_l1->dado <= atual_l2->dado)
        {
            atual_l3->prox = atual_l1;
            atual_l1 = atual_l1->prox;
        }
        else
        {
            atual_l3->prox = atual_l2;
            atual_l2 = atual_l2->prox;
        }
        atual_l3 = atual_l3->prox;
    }
    
    while (atual_l1 != NULL) {
        atual_l3->prox = atual_l1;
        atual_l1 = atual_l1->prox;
        atual_l3 = atual_l3->prox;
    }
    
    while (atual_l2 != NULL) {
        atual_l3->prox = atual_l2;
        atual_l2 = atual_l2->prox;
        atual_l3 = atual_l3->prox;
    }

    atual_l3->prox = NULL;
    
}