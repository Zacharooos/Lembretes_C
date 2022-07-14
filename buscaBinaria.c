#include <stdio.h>

int buscaBin(int *v, int valor, int tam){
	int inicio = 0, fim = tam, i_meio, v_meio;
	while(inicio <= fim){
		i_meio = (fim+inicio)/2;
		v_meio = v[i_meio];

		if (valor == v_meio){
			return i_meio;
		}

		if (valor < v_meio){
			fim = i_meio - 1;
		}
	
		if (valor > v_meio){
			inicio = i_meio + 1;
		}

	}
	return 999; 
}

int main(){

    int vetor[] = {10, 40, 60, 79, 99, 102, 107, 220};

    int valor, tam = (sizeof(vetor)/4) - 1;

    scanf("%d", &valor);
    
    int resposta = buscaBin(vetor, valor, tam);
    
    if (resposta == 99){
        puts("Não encontrado!");
        return 0;
    }

    printf("Encontrado! Pos: %d\n", resposta);
    return 0;
}