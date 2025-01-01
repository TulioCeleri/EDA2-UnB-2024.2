#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct no{
    char str[MAX];
    struct no *prox;
} no;

typedef struct pilha{
    no *inicio;
    int cont;
}pilha;

void inicializa_pilha(pilha *p){
    p->inicio = NULL;
    p->cont = 0;
}

no *cria_no(char *str){
    no *novo = malloc(sizeof(no));
    novo->prox = NULL;
    strcpy(novo->str, str);
    return novo;
}

void empilha(pilha *p, char *str){
    no *novo = cria_no(str);
    novo->prox = p->inicio;
    p->inicio = novo;
    p->cont++;
}

int desempilha(pilha *p){
    if(p->inicio == NULL){
        return 0;
    }
    p->inicio = p->inicio->prox;
    p->cont--;
    return 1;
}

int pilha_vazia(pilha *p){
    return p->inicio == NULL;
}

char *topo(pilha *p){
    if(p->inicio == NULL){
        return NULL;
    }
    return p->inicio->str;
}

int main(void){
    pilha p;
    inicializa_pilha(&p);

    char instrucao[MAX];
    while (scanf(" %s", instrucao) == 1)
    {   
        if (strcmp(instrucao, "desfazer") == 0)
        //retorna 0 se as strings forem iguais
        {
            if (pilha_vazia(&p))
            {
                printf("NULL\n");
            }
            else
            {
                printf("%s\n", topo(&p));
                desempilha(&p);
            }
        }
        else
        {
            char txt[MAX];
            getchar();
            scanf("%[^\n]s", txt);
            empilha(&p, txt);
        }
    }
    
    return 0;
}