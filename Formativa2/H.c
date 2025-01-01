#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct pilha {
    no *dados[100]; 
    int topo;
} pilha;

pilha *criar_pilha() {
    pilha *p = (pilha *)malloc(sizeof(pilha));
    p->topo = -1;
    return p;
}

void empilhar(pilha *p, no *no) {
    if (p->topo == 99) {
        printf("Erro: pilha cheia\n");
        return;
    }
    p->dados[++(p->topo)] = no;
}

no *desempilhar(pilha *p) {
    if (p->topo == -1) {
        printf("Erro: pilha vazia\n");
        return NULL;
    }
    return p->dados[(p->topo)--];
}

bool pilha_vazia(pilha *p) {
    return p->topo == -1;
}

void pos_ordem(no *raiz) {
    if (raiz == NULL)
        return;

    pilha *p1 = criar_pilha();
    pilha *p2 = criar_pilha();
    empilhar(p1, raiz);

    while (!pilha_vazia(p1)) {
        no *atual = desempilhar(p1);
        empilhar(p2, atual);

        if (atual->esq != NULL)
            empilhar(p1, atual->esq);
        if (atual->dir != NULL)
            empilhar(p1, atual->dir);
    }

    while (!pilha_vazia(p2)) {
        no *temp = desempilhar(p2);
        printf("%d ", temp->dado);
    }

    free(p1);
    free(p2);
}