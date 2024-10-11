#include <stdio.h>
#include "ex02.h"

int main() {
    // Criando dois números reais
    struct realtype *r1 = createRealtype(3, 141592);  // 3.141592
    struct realtype *r2 = createRealtype(2, 718281);  // 2.718281

    // Exibindo os números reais
    printf("Numero 1: ");
    printRealtype(r1);
    printf("Numero 2: ");
    printRealtype(r2);

    // Soma
    struct realtype *sum = addRealtype(r1, r2);
    printf("Soma: ");
    printRealtype(sum);

    // Subtração
    struct realtype *diff = subtractRealtype(r1, r2);
    printf("Diferenca: ");
    printRealtype(diff);

    // Multiplicação
    struct realtype *prod = multiplyRealtype(r1, r2);
    printf("Produto: ");
    printRealtype(prod);

    // Liberando memória
    freeRealtype(r1);
    freeRealtype(r2);
    freeRealtype(sum);
    freeRealtype(diff);
    freeRealtype(prod);

    return 0;
}
