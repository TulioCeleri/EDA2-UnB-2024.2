#include <stdio.h>

int main() {
    int D; // Quantidade total de disciplinas
    scanf("%d", &D);
    
    int year, semester, m;
    
    while (scanf("%d %d %d", &year, &semester, &m) != EOF) {
        int max_failures = -1; // Inicializa o número máximo de reprovações como um valor impossível
        int discipline_codes[D]; // Array para armazenar códigos de disciplinas com máximas reprovações
        int discipline_count = 0; // Contador para disciplinas com máxima reprovação
        
        for (int i = 0; i < m; i++) {
            int code, enrolled, passed;
            scanf("%d %d %d", &code, &enrolled, &passed);
            
            int failures = enrolled - passed; // Calcula as reprovações
            
            // Verifica se essa disciplina tem o máximo de reprovações até agora
            if (failures > max_failures) {
                max_failures = failures;
                discipline_count = 0; // Reinicia o contador
                discipline_codes[discipline_count++] = code;
            } else if (failures == max_failures) {
                discipline_codes[discipline_count++] = code;
            }
        }
        
        // Ordena as disciplinas com maior reprovação em ordem crescente
        for (int i = 0; i < discipline_count - 1; i++) {
            for (int j = i + 1; j < discipline_count; j++) {
                if (discipline_codes[i] > discipline_codes[j]) {
                    int temp = discipline_codes[i];
                    discipline_codes[i] = discipline_codes[j];
                    discipline_codes[j] = temp;
                }
            }
        }
        
        // Imprime o semestre e os códigos das disciplinas com maior reprovação
        printf("%d/%d\n", year, semester);
        for (int i = 0; i < discipline_count; i++) {
            printf("%d ", discipline_codes[i]);
        }
        printf("\n\n");
    }
    
    return 0;
}
