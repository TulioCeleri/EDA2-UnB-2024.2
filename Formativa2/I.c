#include <stdio.h>
#include <string.h>

// Função para reconstruir a árvore e calcular o percurso posfixo
void calculaPosfixo(char *prefixo, char *infixo, int n, char *resultado, int *indice) {
    if (n <= 0) return;

    // O primeiro caractere do prefixo é a raiz
    char raiz = prefixo[0];

    // Encontrar a posição da raiz no infixo
    int posRaiz = strchr(infixo, raiz) - infixo;

    // Processar a subárvore esquerda
    calculaPosfixo(prefixo + 1, infixo, posRaiz, resultado, indice);

    // Processar a subárvore direita
    calculaPosfixo(prefixo + 1 + posRaiz, infixo + posRaiz + 1, n - posRaiz - 1, resultado, indice);

    // Adicionar a raiz no percurso posfixo
    resultado[(*indice)++] = raiz;
}

int main() {
    int c; // Número de casos de teste
    scanf("%d", &c);

    while (c--) {
        int n; // Número de nodos da árvore
        char prefixo[53], infixo[53]; // Strings para os percursos prefixo e infixo
        scanf("%d %s %s", &n, prefixo, infixo);

        char posfixo[53]; // String para armazenar o percurso posfixo
        int indice = 0;

        // Calcular o percurso posfixo
        calculaPosfixo(prefixo, infixo, n, posfixo, &indice);

        posfixo[indice] = '\0'; // Finalizar a string posfixa

        // Imprimir o percurso posfixo
        printf("%s\n", posfixo);
    }

    return 0;
}
