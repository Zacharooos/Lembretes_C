#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int a = 4;
    int b = 10;

    int *azao, *bzao;

    azao = &a;
    bzao = &b;

    printf("pA = %p, pB = %p\n", azao, bzao);
    printf("a + b = %d\n", *azao + *bzao);

    //

    int c[5] = {4, 3, 2, 1};
    int *czao = c;

    for (int i = 0; i < 5; i++){
        printf("vet[%d] = %d\n", i, *czao);
        czao = czao+1;
    }
    

    return 0;
}