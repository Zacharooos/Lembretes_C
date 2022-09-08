
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    // Função malloc retorna um ponteiro para um endereço de memória onde começa a alocação dinâmica.
    // Por padrão ela retorna um ponteiro Void (genérico), para evitar isso, precisamos transformalo em (int *)
    int *ponteiro = (int *) malloc( 3 * sizeof(int));
    // (int *) -> casting para retorar ponteiro de inteiros, sem isso, seria um ponteiro genérico.
    // malloc( tamanho,  )

    *ponteiro = 3;
    ponteiro[1] = 2;
    ponteiro[2] = 1;

    for(int i = 0; i < 3; ++i){
        printf("%d\n", ponteiro[i]);
    }

    puts("Realloc!");
    ponteiro = realloc(ponteiro, 5*sizeof(int));

    ponteiro[3] = 0;
    ponteiro[4] = -1;

    for(int i = 0; i < 5; ++i){
        printf("%d\n", ponteiro[i]);
    }

    // Precisamos liberar a memória alocada dinâmicamente, para isso usamos a função free()
    free(ponteiro); 

    return 0;
}
