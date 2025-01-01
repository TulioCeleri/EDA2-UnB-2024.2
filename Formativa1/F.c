#include <stdio.h>

int main(){
    int D; //valor da diária no dia 1
    int A; //aumento da diária a cada dia
    int N; //dia da chegada ao hotel

    scanf("%d", &D);
    scanf("%d", &A);
    scanf("%d", &N);

    int valor_diaria = D + (N - 1) * A;
    int num_dias = 32 - N;
    int valor_total = num_dias * valor_diaria;

    printf("%d\n", valor_total);

    return 0;
}