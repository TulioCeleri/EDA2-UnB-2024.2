#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da árvore binária de busca
typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função que procura o valor máximo em uma árvore binária de busca
no *maximo(no *r) {
    // A função retorna o nó mais à direita da árvore
    if (r == NULL) {
        return NULL; // A árvore está vazia
    }
    while (r->dir != NULL) {
        r = r->dir; // Navega para o nó à direita
    }
    return r; // Retorna o nó com o maior valor
}

