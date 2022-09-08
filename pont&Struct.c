#include <stdlib.h>
#include <stdio.h>


typedef struct node{
    int cod;
    char nome[10];

}node;

int main(){

    node *p = (node*) malloc(sizeof(node));

    if (p == NULL){
        printf("Erro de alocação\n");
        return 0;
    } else {
        printf("Ensira o código:\n");
        scanf("%d", p->cod);
        fflush(stdin);

        printf("Ensira o nome:\n");
        scanf("%s", p->nome);
        fflush(stdin);

        system("pause");
        system("cls");

        printf("Código = %d\nNome = %s\n", p->cod, p->nome);
    }

    return 0;
}