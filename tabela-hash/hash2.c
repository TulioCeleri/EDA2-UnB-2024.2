#include <stdio.h>
#include <stdlib.h>

#define TAM 31

typedef struct no {
    int chave;
    struct no *prox;
} no;

typedef struct{
    no *inicio;
    int tam;
} Lista;

void inicializarLista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

void inserir_na_Lista(Lista *l, int valor){
    no *novo = malloc(sizeof(no));
    if(novo){
        novo->chave = valor;
        novo->prox = l->inicio;
        l->inicio = novo;
        l->tam++;
    }
    else 
        printf("Erro ao alocar memória\n");
}

int buscar_na_lista(Lista *l, int valor){
    no *aux = l->inicio;
    while(aux){
        if(aux->chave == valor)
            return aux->chave;
        aux = aux->prox;
    }
    return 0;
}

void imprimir_lista(Lista *l){
    no *aux = l->inicio;
    printf("Tam: %d: ", l->tam);
    while(aux){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
}

void inicializarTabela(Lista t[]){
    int i;
    for (i = 0; i < TAM; i++)
    {
        inicializarLista(&t[i]);
    }
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(Lista t[], int valor){
    int id = funcaoHash(valor);
    inserir_na_Lista(&t[id], valor);
}

int busca(Lista t[], int chave){
    int id = funcaoHash(chave);
    printf("\nIndice gerado: %d\n", id);
    return buscar_na_lista(&t[id], chave);
}

void imprimir(int t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%d = %d\n", i, t[i]);
    }
}

int main(){

    int opcao, valor, retorno, tabela[TAM];

    inicializarTabela(tabela);

    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(tabela, valor);
                break;
            case 2:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                retorno = busca(tabela, valor);
                if (retorno != 0){
                    printf("\tValor encontrado: %d\n", retorno);
                } else {
                    printf("\tValor não encontrado!\n");
                }
                break;
            case 3:
                imprimir(tabela);
                break;
            default:
                printf("Opção inválida\n");
        }

    } while (opcao != 0);
    return 0;
}