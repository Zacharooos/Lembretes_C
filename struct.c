#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int altura;
    int largura;
} retangulo;

typedef struct {
    int x;
    int y;
} posicao;

typedef struct{
    char tipo;
    retangulo retangulo;
    posicao posicao;
} terreno;

int main(){

    retangulo ret1 = {10, 5};
    posicao pos1 = {1143, -2948};

    terreno itaiaia = {'D', ret1, pos1};

    printf("ret alt  = %d, ret lar = %d\n", itaiaia.retangulo.altura, itaiaia.retangulo.largura);
    printf("ret posx = %d, posy    = %d\n", itaiaia.posicao.x, itaiaia.posicao.y);
    printf("%c\n", itaiaia.tipo);

    return 0;
}