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
        novo->prox = NULL;
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
    for (i = 0; i < TAM; i++) {
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

void imprimir(Lista t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("Indice %d= ", i);
        imprimir_lista(&t[i]);
        printf("\n");
    }
}

void remover_da_tabela(Lista l[], int valor) {
    int id = funcaoHash(valor);

    no *atual = l[id].inicio;
    no *anterior = NULL;

    while (atual != NULL) {
        if (atual->chave == valor) {
            // Encontrou o elemento a ser removido
            if (anterior == NULL) {
                // O nó a ser removido é o primeiro da lista
                l[id].inicio = atual->prox;
            } else {
                // Nó está no meio ou no final da lista
                anterior->prox = atual->prox;
            }

            free(atual);  // Libera a memória do nó removido
            l[id].tam--;  // Atualiza o tamanho da lista
            printf("Elemento %d removido do bucket %d.\n", valor, id);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    // Se chegou aqui, o elemento não foi encontrado
    printf("Elemento %d não encontrado na tabela.\n", valor);
}

int main(){

    int opcao, valor, retorno;
    Lista tabela[TAM];

    inicializarTabela(tabela);

    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n\t4 - Remover\n");
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
                    printf("\tValor nao encontrado!\n");
                }
                break;
            case 3:
                imprimir(tabela);
                break;
            case 4:
                printf("Digite um valor para ser removido: ");
                scanf("%d", &valor);
                remover_da_tabela(tabela, valor);
                break;
            default:
                printf("Opçao invalida\n");
        }
    } while (opcao != 0);
    return 0;
}