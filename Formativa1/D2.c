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

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int num_crocantes = 0, num_mistos = 0, num_trad = 0;
    int ingredienteA = 0, ingredienteB = 0, ingredienteC = 0;
// Calcular numero de crocantes
    if (a / 5 > 0) {
        num_crocantes = a / 5;
        ingredienteA = 5 * num_crocantes;
        ingredienteB = 25 * num_crocantes;
        ingredienteC = 20 * num_crocantes;
    }
    //Novas quantidades de ingredientes
    a = a - ingredienteA; 
    b = b - ingredienteB;
    c = c - ingredienteC;


//Calcular numero de mistos
    ingredienteA = 0, ingredienteB = 0, ingredienteC = 0;
    if (b / 25 > 0) {
        num_mistos = b / 25;
        ingredienteB = 25 * num_mistos;
        ingredienteC = 25 * num_mistos;
    }
    
    //Novas quantidades de ingredientes
    b = b - ingredienteB;
    c = c - ingredienteC;


//Calcular numero de tradicionais
    ingredienteA = 0, ingredienteB = 0, ingredienteC = 0;
    if (c / 50 > 0) {
        num_trad = c / 50;
        ingredienteC = 50 * num_trad;
    }
    
    //Novas quantidades de ingredientes
    c = c - ingredienteC;

    
//Caixas de bombons
    //Numero de caixas sortidas
    int caixa_sortida = 0;
    int numA = 0, numB = 0, numC = 0;
    if (num_trad >= 10 && num_mistos >= 10 && num_crocantes >= 10) {
        numA = num_trad / 10;
        numB = num_mistos / 10;
        numC = num_crocantes / 10;
        caixa_sortida = menorDeTres(numA, numB, numC);
    }
    
    num_trad = num_trad - caixa_sortida * 10;
    num_mistos = num_mistos - caixa_sortida * 10;
    num_crocantes = num_crocantes - caixa_sortida * 10;
    
    //Numero de caixas prediletas
    int caixa_predileta = 0;
    numA = 0, numB = 0, numC = 0;
    if (num_mistos >= 20 && num_crocantes >= 10)
    {
        numB = num_mistos / 20;
        numC = num_crocantes / 10;
        if (numB < numC)
        {
            caixa_predileta = numB;
        } else {
            caixa_predileta = numC;
        }
    }

    //Numero de caixas especiais
    int caixa_especial = 0;
    numA = 0, numB = 0, numC = 0;
    if (num_crocantes >= 30)
    {
        numC = num_crocantes / 30;
        caixa_especial = numC;
    }
    
    printf("%d %d %d\n", caixa_especial, caixa_predileta, caixa_sortida);
    return 0;
}