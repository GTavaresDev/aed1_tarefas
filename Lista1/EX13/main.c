#include <stdio.h>
#include "ex13.h"

int main() {
    int n;
    printf("Digite o tamanho das matrizes: ");
    scanf("%d", &n);

    TMatriz* A = criarMatriz(n);
    TMatriz* B = criarMatriz(n);

    printf("\n Preenchendo matriz A:");
    preencherMatriz(A);

    printf("\n Preenchendo matriz B:");
    preencherMatriz(B);

    TMatriz* C = somarMatrizes(A, B);
    if (C != NULL) {
        printf("\n Resultado da soma:");
        imprimirMatriz(C);
        liberarMatriz(C);
    }

    TMatriz* D = multiplicarMatrizes(A, B);
    if (D != NULL) {
        printf("\n Resultado da multiplicacao:");
        imprimirMatriz(D);
        liberarMatriz(D);
    }

    liberarMatriz(A);
    liberarMatriz(B);

    return 0;
}
