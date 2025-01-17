#include <stdlib.h>

typedef struct {
  int *tb; // tabela hash
  int M;   // tamanho da tabela hash
  int N;   // total de chaves presentes na tabela
} TH;

extern int aumentaTamanho(int M);

// Função auxiliar para redimensionar a tabela hash
void redimensiona(TH *h) {
  int novoTamanho = aumentaTamanho(h->M);
  int *novaTabela = malloc(novoTamanho * sizeof(int));
  if (novaTabela == NULL) {
    perror("Erro ao redimensionar a tabela hash");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < novoTamanho; i++) {
    novaTabela[i] = -1; // Inicializar com o símbolo de vazio
  }

  // Reinsere todas as chaves na nova tabela
  int tamanhoAntigo = h->M;
  int *tabelaAntiga = h->tb;

  h->tb = novaTabela;
  h->M = novoTamanho;
  h->N = 0; // Será atualizado durante a reinserção

  for (int i = 0; i < tamanhoAntigo; i++) {
    if (tabelaAntiga[i] != -1) {
      THinsere(h, tabelaAntiga[i]);
    }
  }

  free(tabelaAntiga);
}

// Função para inserir uma chave na tabela hash
void THinsere(TH *h, int ch) {
  if (THbusca(h, ch)) return; // Evitar chaves duplicadas

  if (h->N > h->M / 2) {
    redimensiona(h); // Redimensionar a tabela se a ocupação for maior que 50%
  }

  int pos = ch % h->M;
  while (h->tb[pos] != -1) {
    pos = (pos + 1) % h->M; // Sondagem linear
  }

  h->tb[pos] = ch;
  h->N++;
}

// Função para buscar uma chave na tabela hash
int THbusca(TH *h, int ch) {
  int pos = ch % h->M;

  for (int i = 0; i < h->M; i++) {
    int idx = (pos + i) % h->M;
    if (h->tb[idx] == -1) {
      return 0; // Chave não encontrada
    }
    if (h->tb[idx] == ch) {
      return 1; // Chave encontrada
    }
  }

  return 0; // Chave não encontrada após percorrer a tabela
}

// Função para remover uma chave da tabela hash
int THremove(TH *h, int ch) {
  int pos = ch % h->M;

  for (int i = 0; i < h->M; i++) {
    int idx = (pos + i) % h->M;
    if (h->tb[idx] == -1) {
      return -1; // Chave não encontrada
    }
    if (h->tb[idx] == ch) {
      h->tb[idx] = -1; // Marca como vazio
      h->N--;

      // Reinserir as chaves seguintes no intervalo
      for (int j = (idx + 1) % h->M; h->tb[j] != -1; j = (j + 1) % h->M) {
        int chaveParaReinserir = h->tb[j];
        h->tb[j] = -1;
        h->N--; // Removida temporariamente
        THinsere(h, chaveParaReinserir);
      }

      return 0; // Chave removida com sucesso
    }
  }

  return -1; // Chave não encontrada
}
