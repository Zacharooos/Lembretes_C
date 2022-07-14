#ifndef SORT_H

#define SORT_H

#endif

//Biblioteca de Sorts comentada, todos os principais Sorts e suas complexidades.
//sort.h vs1.4.1

// ATENÇÃO ! >>> para usar utilize >>> #include "sort.h"

//Swap -> Função de troca simples de indices, basta inserir a referência de lista em conjunto ...
// ... com os indices que serão trocados.

void swap(int *v, int i1, int i2){
    int aux = v[i1];
    v[i1] = v[i2];
    v[i2] = aux;
}

// Selection Sort 1.0
// Complexidade O(n²)

/* O algoritmo Selection Sort trabalha criando um subarray ordenado, sempre ele vai sempre buscar o menor número
para a posição atual (começa no 0), após percorrer o vetor inteiro, ele troca a posição do valor na posição 'i' com
o menor valor na posição em que ele está, após isso, ele recomeçar a processo a partir da posição "i+1", até ter 
percorrido todo o vetor. */

void selectionSort(int *v, int tam){
    for(int i = 0; i < tam-1; ++i){ // Laço para percorrer o vetor, 'tam-1' pois o ultimo valor já estará ordenado no fim do processo.
        int menor_valor = v[i], menor_indice = i; // Variáveis para buscar o menor valor e sua posição, comparamos com a posição atual de 'i'
        
        for(int j = i + 1; j < tam; ++j){ // Laço para percorrer o vetor principal a partir do subvetor, sempre começa a partir de 'i' + 1.
            if(v[j] < menor_valor){ // Caso o valor encontrado no vetor principal seja menor que o valor, da posição inicial, realiza a troca.
                menor_valor = v[j]; // Atualizamos ambos o menor valor e sua posição.
                menor_indice = j; 
            }
        }
        swap(v, i, menor_indice); // Trocamos a posição inicial com a posição do menor valor
        // A partir deste ponto, o o subvetor cresce o a checagem começa a partir da posição atual + 1
    } 
}

// Bubble Sort 1.0
// Compara os valores vizinhos e realiza a troca caso o primeiro seja maior que o segundo
// Complexidade O(n²)

/* BubbleSort é um algoritmo de busca bastante ineficiente, seu método de ordenação é sempre trocar o número da posição
atual com a posição posterior caso o segundo número seja menor que o primeiro, ele continuará buscando valores para trocar
até que nenhuma troca seja realizada, simbolizando o fim da ordenação. */

void bubbleSort(int *v, int tam){
    int troca = 1, aux; // Como precisamos saber se houve troca, simbolizamos a mesma ...
    /// ... iniciamos no caso "tem troca (1)" para dar partida ao laço While logo abaixo.
    
    while(troca == 1){ // Enquanto houver troca, o continuaremos verificando o vetor para buscar números desordenados.
        troca = 0; // Definimos no início a troca para zero, assim, se não houver troca chegaremos ao fim.
        
        for(int i = 0; i < tam-1; ++i){
            if(v[i] > v[i+1]){ // Caso o número da posição atual seja menor que o da próxima, realizamos a troca.
                swap(v, i, i+1);
                troca = 1; // Depois redefinimos a variável troca como 1, para dar continuidade ao processo.
                // Quando não houver troca, a variável não será redefinida e encerraremos o laço.
            }   
        }
    }
}

// Insertion Sort 1.0
// Complexidade O(n²)

/* O algorimo InsertionSort também trabalha com subvetores, porém de forma mais interativa, ele pega o primeiro valor
fora do subvetor para e compara com os valores do subvetor de forma decrescente, se ele for menor que que o maior valor
do subvetor, o maior valor do subvetor avança uma posição, esse processo continua até que o valor da próxima posição seja
menor, significando que ele encontrou sua posição, que é a atual, a partir dai o processo reinicia com o próximo número.*/

void insertionSort(int *v, int tam){
    for (int i = 1; i < tam; ++i){ // Começamos a partir da segunda posição pois consideramos a primeira como ja sendo o subvetor.
        int chave = v[i], pos = i; // Salvar o primeiro valor fora do subvetor como "chave", e sua posição i como "pos".
        
        while(v[pos - 1] > chave && pos > 0){ // Enquanto a posição anterior for maior que a chave e a posição for maior que 0 ...
            v[pos] = v[pos-1]; // Jogamos o valor da posição anterior para frente
            pos--; // Vamos para a "posição anterior" do subvetor
        }
        v[pos] = chave; // Quando sair do laço, a posição em que estaremos será maior que as menores do subvetor e menor que as maiores.
        // Sendo assim, só posicionar a chave na nova posição, como feito acima ^^^
    }
}

// Gnome Sort 1.0
// Complexidade: O(n²)

/* O algoritmo Gnome Sort funciona de maneira semelhante ao Bubble Sort, este porém, ao realizar um troca com
um valor anterior que seja maior, continua checando de o valor antes desse também é maior, só parando ao atíngir
um valor que seja menor que o atual*/

void gnomeSort(int *v, int tam){
    int pos = 1, aux; // Como checamos a posição atual e a anterior, começamos pela posição 1
    while(pos < tam){ // Enquanto a posição for menor que o tamanho, não percorremos todo o vetor, portanto continuamos o loop.
        aux = pos; // Salvamos a posição atual, pois o algoritmo irá retornar gradualmente, checar linha 107
        while(v[pos] < v[pos-1] && pos > 0){ //Enquanto valor anterior for maior, continuaremos trocando até atíngir o fim do vetor ou encontrar um valor menor.
            swap(v, pos, pos-1);
            pos--; // Fazemos o decréscimo do marcador de posição para continuar a checagem;
        }
        pos = aux + 1; // Após realizar todas as possíveis trocas, retornamos o algoritmo para a posição antes do ajuste + 1.
    }
}

// Quick Sort 1.2
// Complexidade (n*log n)

/* Dois marcadores percorrem o vetor, um de sentido esquerdo e outro direito, com referência em um pivot que é criado
toda vez que a função for chamada, realizam trocas entre sí de forma que todos os valores a esquerda do pivot sejam menores
que o mesmo, e todos os valores a direita sejam maiores. Após esse processo, o algoritmo usa o próprio pivot para partir o vetor
anterior em vetores menores onde reperirá o mesmo processo até que seja impossível dividir os vetores. Resultando em um vetor final
ordenado */

int particao(int *v, int iEsq, int iDir){ //Função Auxiliar partição, responsável
    int pivot = v[(iEsq+iDir)/2]; // Salva o valor do pivot, para fins comparativos.
    
    while (iEsq <= iDir){ // Laço que deslocará o marcador da esquerda para direita até achar um número >= ao pivot.
        while(v[iEsq] < pivot){
            iEsq++;
        }
        
        while(v[iDir] > pivot){ // Laço que deslocará o marcador da direita para esquerda até achar um número <= ao pivot.
            iDir--;
        }
        
        if (iEsq < iDir){ // Checa se o indíce da esquerda é menor que o da direita, se sim, realiza a troca.
            swap(v, iEsq, iDir);
            iEsq++;
            iDir--;
        } else {
            break; // Caso não seja, significa que todas as trocas pertinentes foram realizadas.
        }
    }
    return iDir; // Retorna o novo pivot.
}

void quicksort(int *v, int inicio, int fim){ //Função principal
    if (inicio < fim){
        int pivot = particao(v, inicio, fim); //Realiza uma sequencia de trocas e retorna e vetor para continuar a divisão.
        quicksort(v, inicio, pivot); // Realiza o mesmo processo até a primeira metade.
        quicksort(v, pivot + 1, fim); // Realiza o mesmo processo a partir da segunda metade.
        //Continua recursivamente até encontrar subvetores de tamanho 1.
    }
}

// Merge Sort 1.0
// Complexidade: (n*log n)
/* MergeSort é um algoritmo que divide um vetor o máximo possível, e depois rearranja o */

void merge(int *v, int e1, int d1, int e2, int d2){ // Função que faz a ordenação "juntando"
    int i = e1, j = e2, k = 0, v2[d2 - e1 + 1]; // Criação de um vetor auxiliar com dois marcadores i, j e um contador k;
    while (i <= d1 && j <= d2){ // Enquando os dois vetores "pais" não forem completamente lidos, continuamos a ordenação
        if (v[i] < v[j]){ // Comparação entre os vetores "pais", o menor valor irá para o vetor auxiliar.
            v2[k] = v[i];
            i++; // Utilizamos o marcador i para percorrer o vetor pai
        } else {
            v2[k] = v[j]; // Caso contrário da comparação anterior
            j++; // Utilizamos o marcador j para percorrer o outro vetor pai
        }
        k++; // Contador do vetor auxiliar, ou seja, o marcador de posição do mesmo
    }

    //Como existe a possibilidade da leitura de um dos vetores pais acabar antes do outro, precisamos ler eles individualmente também.

    while (i <= d1){  // Leitura individual de um vetor pai.
        v2[k] = v[i];
        i++;
        k++;
    }

    while (j <= d2){ // Leitura individual do outro vetor pai.
        v2[k] = v[j];
        j++;
        k++;
    }

    for (i = e1, k = 0; i <= d2; ++i, ++k) { // Laço para transferir os valores ordenados do vetor auxiliar para o principal.
        v[i] = v2[k];
    }
}

void mergeSort(int *v, int esq, int dir){ // Função principal
    if (dir > esq){ // Condição do sort
        int meio = (esq + dir) / 2; // Definir o meio para fazer a divisão
        mergeSort(v, esq, meio); // Dividir no meio, parte anterior
        mergeSort(v, meio + 1, dir); // Dividir no meio, parte posterior

        //Perceba que a função irá entrar em uma pilha recursiva, sendo divida infinitamente até atingir o menor tamanho possível.

        merge(v, esq, meio, meio + 1, dir); // Função que junta as partes separadas ordenadamente
    }
}

// Grupo do HeapSort
// Utiliza construção e desconstrução de Heap para criar a ordenação:
// Complexidade: O(n*log(n))

void sobeHeap(int *v, int i){ //Função sobe heap, sobe o valor da posição i até o seu devido lugar
	int pai = (i-1)/2; // Por definição, o a pai será o valor adotado
	while((pai >= 0) && (v[i] > v[pai])){ // Enquanto pai for maior que 0 e o valor da pos i for maior que o pai, continuamos subindo o valor
		swap(v, i, pai); // Valor troca de lugar com o pai
		
        i = pai; // 'i' passa a ter a posição do pai
		pai = (i-1)/2; // A posição do pai é redefinida pra mais um ciclo
	}
}

void desceHeap(int *v, int pai, int tam){ // Função desce heap, desce o valor da posição n até o seu devido lugar 
	int sonEsq = 2*(pai+1)-1, sonDir = 2*(pai+1), j = pai; // Precisamos descobrir qual "branch" da arvore será escolhida.
	while(sonEsq <= tam){ // O filho da esquerda é referência pois ele normalmente é o menor valor
		if(v[pai] < v[sonEsq]){ // Se o valor do pai for menor que o valor do filho da esquerda ...
			j = sonEsq; // o indice auxiliar será igual ao filho da esquerda
		} 
		if(sonDir <= tam && v[j] < v[sonDir]){ // ...
			j = sonDir;
		}
		if (pai == j){
			break;
		}
		
        swap(v, pai, j);
		
        pai = j;
		sonEsq = 2*(pai+1)-1;
		sonDir = sonEsq + 1; // ...
	}
}

void heapSort(int *v,int pos){
	for(int i=0; pos > i; i++){ // Realiza o sobeHeap para todos os valores do vetor
		sobeHeap(v,i);
	}
    
	for (int i=pos; i>0; i--){
		swap(v, 0, i); // Troca a posição de i com o valor pai (maior valor do Heap)
		desceHeap(v, 0, i-1); // Desce o Heap 
	}
}


// Algoritmo ShellSort
// Complexidade: O(n log n) -/- O(n log n²) }-> Varia dependendo do tamanha do pulo.
/* O algoritmo ShellSort é um algoritmo que utiliza de um método de fatiamento para ordenar o vetor, a cada verificação 
 o algorimo divide o seu pulo por 2, comparando o valor antes do pulo com o valor após o pulo, se o valor posterior for menor
 a troca é realizada e a ordenação continua, após todas as posições serem verificadas, o pulo é dividido novamente, o processo
 continua enquanto o pulo for maior que 0, sendo ente o caso onde terminam as comparações.*/

 // Importante! Perceba que a checagem do salto está sendo feita de maneira inversa, ou seja, estamos checando valores anteriores com o salto!

void shellSort(int *v, int tam){
    int jump = tam/2, aux_v, aux_i; // Definimos aqui o pulo, inicialmente sento o tamanho do vetor sobre 2, o valor e o indice auxiliares
    while(jump > 0){ // Enquanto o pulo for maior que 0, continuaremos as comparações.
        for(int i = 0; i < tam; ++i){ // Percorremos o vetor inteiro a cada atualização de pulo.
            aux_v = v[i]; // Guardamos o valor atual na variável auxiliar de valor
            aux_i = i; // e a posição atual na variável auxiliar de índice
            while (aux_i >= jump && v[aux_i-jump] > aux_v){ // Realiza a troca se o valor do salto for maior que o auxiliar
                v[aux_i] = v[aux_i-jump];
                aux_i = aux_i-jump;
            }
            v[aux_i] = aux_v; 
        }
        jump = jump/2; // Atualiza o salto.
    }
}