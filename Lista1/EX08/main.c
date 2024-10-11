#include <stdio.h>
#include "ex08.h"

int main() {
    RATIONAL* r1 = criarRacional(1, 2);
    RATIONAL* r2 = criarRacional(2, 4);

    if (equal2(r1, r2)) {
        printf("\n Os numeros racionais sao iguais.");
    } else {
        printf("\n Os numeros racionais nao sao iguais.");
    }

    liberarRacional(r1);
    liberarRacional(r2);

    return 0;
}
