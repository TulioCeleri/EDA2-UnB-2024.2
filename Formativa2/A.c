#include <stdio.h>
#include <stdlib.h>

// Estrutura de uma célula da lista encadeada
typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

// Estrutura da tabela hash
typedef struct {
  celula *tb; // vetor de cabeças das listas encadeadas
  int M;      // tamanho da tabela hash
  int N;      // total de chaves presentes na tabela
} TH;

// Função para inserir uma chave na tabela hash
void THinsere(TH *h, int ch) {
  int pos = ch % h->M;

  celula *atual = &h->tb[pos];
  while (atual->prox != NULL) {
    if (atual->prox->dado == ch) {
      return; // Chave já existe
    }
    atual = atual->prox;
  }

  celula *novo = (celula *)malloc(sizeof(celula));
  if (novo == NULL) {
    perror("Erro ao alocar memória");
    exit(EXIT_FAILURE);
  }
  novo->dado = ch;
  novo->prox = h->tb[pos].prox;
  h->tb[pos].prox = novo;
  h->N++;
}

// Função para remover uma chave da tabela hash
int THremove(TH *h, int ch) {
  int pos = ch % h->M;

  celula *atual = &h->tb[pos];
  while (atual->prox != NULL) {
    if (atual->prox->dado == ch) {
      celula *removido = atual->prox;
      atual->prox = removido->prox;
      free(removido);
      h->N--;
      return 0; // Chave encontrada e removida
    }
    atual = atual->prox;
  }
  return -1; // Chave não encontrada
}

// Função para buscar uma chave na tabela hash
int THbusca(TH *h, int ch) {
  int pos = ch % h->M;

  celula *atual = h->tb[pos].prox; // Primeiro elemento real da lista
  while (atual != NULL) {
    if (atual->dado == ch) {
      return 1; // Chave encontrada
    }
    atual = atual->prox;
  }
  return 0; // Chave não encontrada
}
