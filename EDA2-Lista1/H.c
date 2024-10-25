#include <stdio.h>
#include <stdlib.h>

typedef float Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define cmpexch(A, B) {if(less(A, B)) exch(A, B);}

void bubblesort(Item *v, int l, int r){
    for (int i = l; i < r; i++){
        for (int j = l; j < r; j++)
            cmpexch(v[j+1], v[j]);
    }
}

int main(){
    float D; //Dificuldade do salto
    float notas[7]; //Notas dos juízes

    scanf("%f", &D);
    for (int i = 0; i < 7; i++)
    {
        scanf("%f", &notas[i]);
    }

    bubblesort(notas, 0, 6);

    notas[0] = 0.0;
    notas[6] = 0.0;

    float media = 0.0;
    for (int i = 0; i < 7; i++)
    {
        media += notas[i];
    }
    float nota_final = (media/5) * D;
    
    printf("%.1f\n", nota_final);

    return 0;
}