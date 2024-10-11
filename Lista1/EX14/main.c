#include <stdio.h>
#include "ex14.h"

int main() {
    TConjunto* conjunto1 = criarConjuntoVazio();
    TConjunto* conjunto2 = criarConjuntoVazio();
    TConjunto* uniao = criarConjuntoVazio();
    TConjunto* intersecao = criarConjuntoVazio();
    int n;

    printf("Quantos elementos no conjunto 1? ");
    scanf("%d", &n);
    lerConjunto(conjunto1, n);

    printf("Quantos elementos no conjunto 2? ");
    scanf("%d", &n);
    lerConjunto(conjunto2, n);

    printf("Conjunto 1: ");
    imprimirConjunto(conjunto1);

    printf("Conjunto 2: ");
    imprimirConjunto(conjunto2);

    unirConjuntos(conjunto1, conjunto2, uniao);
    printf("Uniao dos conjuntos: ");
    imprimirConjunto(uniao);

    interseccionarConjuntos(conjunto1, conjunto2, intersecao);
    printf("Interseccao dos conjuntos: ");
    imprimirConjunto(intersecao);

    if (conjuntosIguais(conjunto1, conjunto2)) {
        printf("\n Os conjuntos sao iguais.");
    } else {
        printf("\n Os conjuntos sao diferentes.");
    }

    liberarConjunto(conjunto1);
    liberarConjunto(conjunto2);
    liberarConjunto(uniao);
    liberarConjunto(intersecao);

    return 0;
}
