#include <stdio.h>

int menorDeTres(int a, int b, int c) {
    int menor = a;

    if (b < menor) {
        menor = b;
    }
    if (c < menor) {
        menor = c;
    }

    return menor;
}

int calculaBombons(int *ingrediente, int consumo) {
    int qtd = *ingrediente / consumo;
    *ingrediente -= qtd * consumo;
    return qtd;
}

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // Cálculo dos bombons de cada tipo
    int num_crocantes = calculaBombons(&a, 5);
    b -= 25 * num_crocantes;
    c -= 20 * num_crocantes;

    int num_mistos = calculaBombons(&b, 25);
    c -= 25 * num_mistos;

    int num_trad = calculaBombons(&c, 50);

    // Cálculo das caixas sortidas, prediletas e especiais
    int caixa_sortida = 0, caixa_predileta = 0, caixa_especial = 0;

    if (num_trad >= 10 && num_mistos >= 10 && num_crocantes >= 10) {
        caixa_sortida = menorDeTres(num_trad / 10, num_mistos / 10, num_crocantes / 10);
        num_trad -= caixa_sortida * 10;
        num_mistos -= caixa_sortida * 10;
        num_crocantes -= caixa_sortida * 10;
    }

    if (num_mistos >= 20 && num_crocantes >= 10) {
        caixa_predileta = menorDeTres(num_mistos / 20, num_crocantes / 10, num_crocantes / 10);
        num_mistos -= caixa_predileta * 20;
        num_crocantes -= caixa_predileta * 10;
    }

    if (num_crocantes >= 30) {
        caixa_especial = num_crocantes / 30;
    }

    printf("%d %d %d\n", caixa_especial, caixa_predileta, caixa_sortida);
    return 0;
}