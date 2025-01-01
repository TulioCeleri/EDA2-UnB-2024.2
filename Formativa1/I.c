#include <stdio.h>

int main(){
    int N; // tamanho do vetor
    scanf("%d", &N);
    int vetor[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vetor[i]);
    }
    
    long long soma = 0;
    for (int i = 0; i < N; i++)
    {
        soma += vetor[i];
    }
    double media = soma / N;
    int encontrou = 0;
    
    for (int i = 0; i < N; i++)
    {
        if (vetor[i] > media)
        {
            if (encontrou)
            {
                printf(" ");
            }
            printf("%d", vetor[i]);
            encontrou = 1;
        }
    }

    if (encontrou == 0)
    {
        printf("0\n");
    }
    
    

    return 0;
}