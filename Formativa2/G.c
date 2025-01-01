#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct pilha{
    no *dados[100];
    int topo;
} pilha;

pilha *criar_pilha(){
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

no *desempilhar (pilha *p){
    if (p->topo == -1)
    {
        return NULL;
    }
    return p->dados[(p->topo)--];
}

bool pilha_vazia(pilha *p){
    return p->topo == -1;
}

void em_ordem (no *raiz){
    if (raiz == NULL)
    {
        return;
    }
    pilha *p = criar_pilha();
    no *atual = raiz;

    while (atual != NULL || !pilha_vazia(p))
    {
        while (atual != NULL)
        {
            empilhar(p, atual);
            atual = atual->esq;
        }
        atual = desempilhar(p);
        printf("%d ", atual->dado);
        atual = atual->dir;
    }
    free(p);
}

// void inserir(no **r, int x){
//     if (*r == NULL)
//     {
//         *r = malloc(sizeof(no));
//         (*r)->dado = x;
//         (*r)->dir = NULL;
//         (*r)->esq = NULL;
//     }
//     else
//     {
//         if (x < (*r)->dado)
//         {
//             inserir(&((*r)->esq), x);
//         }
//         else
//         {
//             inserir(&((*r)->dir), x);
//         }
//     } 
// }

// int main(void){
//     no *raiz = NULL;
//     inserir(&raiz, 30);
//     inserir(&raiz, 54);
//     inserir(&raiz, 44);
//     em_ordem(raiz);

//     return 0;
// }