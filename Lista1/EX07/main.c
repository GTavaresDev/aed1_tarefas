#include "ex07.h"
#include <stdio.h>

int main() {
    RATIONAL *r1 = createRational(6, 8);  
    RATIONAL *r2 = createRational(3, 4);

    printf("Numeros racionais:\n");
    printRational(r1);
    printRational(r2);

    if (equal(r1, r2)) {
        printf("\n Os numeros racionais sao iguais.");
    } else {
        printf("\n Os numeros racionais sao diferentes.");
    }

    // Liberar memória
    freeRational(r1);
    freeRational(r2);

    return 0;
}
