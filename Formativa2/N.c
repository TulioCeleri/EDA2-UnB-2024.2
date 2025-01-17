#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função auxiliar para encontrar o maior nó em uma subárvore
no *encontrar_antecessor(no *r) {
    while (r && r->dir != NULL) {
        r = r->dir;
    }
    return r;
}

// Função para remover um nó da árvore binária de busca
no *remover(no *r, int x) {
    if (r == NULL) {
        return NULL; // Chave não encontrada
    }

    if (x < r->chave) {
        // A chave está na subárvore esquerda
        r->esq = remover(r->esq, x);
    } else if (x > r->chave) {
        // A chave está na subárvore direita
        r->dir = remover(r->dir, x);
    } else {
        // Encontramos o nó a ser removido
        if (r->esq == NULL) {
            // Caso 1: Nó com zero ou um filho (à direita)
            no *temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            // Caso 1: Nó com zero ou um filho (à esquerda)
            no *temp = r->esq;
            free(r);
            return temp;
        } else {
            // Caso 2: Nó com dois filhos
            no *antecessor = encontrar_antecessor(r->esq);
            r->chave = antecessor->chave; // Substitui a chave pelo antecessor
            r->esq = remover(r->esq, antecessor->chave); // Remove o antecessor
        }
    }

    return r; // Retorna a nova raiz após a remoção
}
