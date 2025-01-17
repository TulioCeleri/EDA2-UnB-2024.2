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

void empilhar(pilha *p, no *n) {
    if (p->topo == 99) {
        printf("Erro: pilha cheia\n");
        return;
    }
    p->dados[++(p->topo)] = n;
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

void liberar_pilha(pilha *p) {
    free(p);
}

void em_ordem(no *raiz) {
    pilha *p = criar_pilha();
    no *atual = raiz;

    while (atual != NULL || !pilha_vazia(p)) {
        // Navega até o nó mais à esquerda
        while (atual != NULL) {
            empilhar(p, atual);
            atual = atual->esq;
        }

        // Processa o nó no topo da pilha
        atual = desempilhar(p);
        printf("%d ", atual->dado);

        // Navega para a subárvore direita
        atual = atual->dir;
    }

    liberar_pilha(p);
}
