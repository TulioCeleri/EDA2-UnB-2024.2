#include <stdio.h>
#include <string.h>

#define TAMANHO_TABELA (1 << 21)

typedef long long ll;

typedef struct {
    ll idColonia;
    char nomeAlimento[11];
    int ocupado;
} Entrada;

static Entrada tabelaHash[TAMANHO_TABELA];

unsigned int funcaoHashString(const char *str) {
    unsigned int h = 5381;
    while (*str) {
        h = ((h << 5) + h) + (unsigned char)(*str++);
    }
    return h;
}

unsigned int funcaoHashPar(ll colonia, const char *alimento) {
    unsigned long long h = (unsigned long long)colonia;
    h ^= (unsigned long long)funcaoHashString(alimento) << 16;
    h *= 2654435761;
    return (unsigned int)(h & (TAMANHO_TABELA - 1));
}

int main(void) {
    ll colonia;
    char alimento[11];

    while (scanf("%lld %s", &colonia, alimento) == 2) {
        unsigned int pos = funcaoHashPar(colonia, alimento);

        while (1) {
            if (!tabelaHash[pos].ocupado) {
                tabelaHash[pos].ocupado = 1;
                tabelaHash[pos].idColonia = colonia;
                strcpy(tabelaHash[pos].nomeAlimento, alimento);
                break;
            } else {
                if (tabelaHash[pos].idColonia == colonia &&
                    strcmp(tabelaHash[pos].nomeAlimento, alimento) == 0) {
                    printf("%lld\n", colonia);
                    break;
                }
                pos = (pos + 1) & (TAMANHO_TABELA - 1);
            }
        }
    }

    return 0;
}
