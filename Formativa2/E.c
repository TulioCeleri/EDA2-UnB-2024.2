#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar o caractere e sua frequência
typedef struct {
    int ascii;
    int freq;
} CharFreq;

// Função de comparação para ordenar por frequência e valor ASCII
int compara(const void *a, const void *b) {
    CharFreq *x = (CharFreq *)a;
    CharFreq *y = (CharFreq *)b;
    if (x->freq == y->freq) {
        return x->ascii - y->ascii; // Ordem crescente por valor ASCII
    }
    return x->freq - y->freq; // Ordem crescente por frequência
}

int main() {
    char linha[1001]; // Buffer para a linha de entrada
    int primeiraSaida = 1;

    while (fgets(linha, sizeof(linha), stdin)) {
        int frequencias[128] = {0}; // Frequências para caracteres ASCII (32-127)
        CharFreq resultados[128];
        int total = 0;

        // Contar frequências
        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] != '\n') {
                frequencias[(int)linha[i]]++;
            }
        }

        // Preencher resultados com caracteres presentes
        for (int i = 32; i < 128; i++) {
            if (frequencias[i] > 0) {
                resultados[total].ascii = i;
                resultados[total].freq = frequencias[i];
                total++;
            }
        }

        // Ordenar resultados
        qsort(resultados, total, sizeof(CharFreq), compara);

        // Imprimir resultados
        if (!primeiraSaida) {
            printf("\n");
        }
        primeiraSaida = 0;

        for (int i = 0; i < total; i++) {
            printf("%d %d\n", resultados[i].ascii, resultados[i].freq);
        }
        printf("\n");
    }

    return 0;
}
