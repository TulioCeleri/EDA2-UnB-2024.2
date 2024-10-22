#include <stdio.h>
#include <string.h>

void Inteiro_Romano(int num, char *roman){
    int inteiros[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *romanos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    roman[0] = '\0';

    for (int i = 0; i < 13; i++)
    {
        while(num >= inteiros[i]){
            strcat(roman, romanos[i]);
            num -= inteiros[i];
        }
    }
    
}

int main(){
    int n;
    scanf("%d", &n);

    int numeros[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &numeros[i]);
    }

    for (int i = 0; i < n; i++)
    {
        char romano[20];
        Inteiro_Romano(numeros[i], romano);
        printf("%s\n", romano);
    }
    

    return 0;
}