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
    pilha *p = malloc(sizeof(pilha));
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

void pre_ordem(no *raiz) {
    if (raiz == NULL)
        return;

    pilha *p = criar_pilha();
    empilhar(p, raiz);

    while (!pilha_vazia(p)) {
        no *atual = desempilhar(p);
        printf("%d ", atual->dado);

        if (atual->dir != NULL)
            empilhar(p, atual->dir);
        if (atual->esq != NULL)
            empilhar(p, atual->esq);
    }

    free(p);
}