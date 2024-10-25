#include <stdio.h>
#include <string.h>

// Função que converte a sigla para minúsculo
void converte_sigla(char *str, int tam){
    for (int i = 0; i < tam; i++)
    {
        str[i] = str[i] + 32;
    }
    
}

int main(){
    char nome_aeroporto[100005], sigla[4];
    scanf("%s", nome_aeroporto);
    scanf("%s", sigla);

    int tam_aeroporto = strlen(nome_aeroporto);
    int tam_sigla = strlen(sigla);


    if (sigla[2] == 'X')
    {
        tam_sigla = 2;
    }
    
    converte_sigla(sigla, tam_sigla);

    int j = 0;
    for (int i = 0; i < tam_aeroporto && j < tam_sigla; i++)
    {
        if(nome_aeroporto[i] == sigla[j]){
            j++;
        }
    }
    
    if(j == tam_sigla)
        printf("Sim\n");
    else
        printf("Nao\n");
    
    return 0;
}