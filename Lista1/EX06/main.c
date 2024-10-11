#include <stdio.h>
#include "ex06.h"

int main() {
    RATIONAL *r1 = createRational(3, 4);  
    RATIONAL *r2 = createRational(5, 6);  

    RATIONAL *sum = addRational(r1, r2);
    printf("Soma: ");
    printRational(sum);

    RATIONAL *diff = subtractRational(r1, r2);
    printf("Subtracao: ");
    printRational(diff);

    RATIONAL *quotient = divideRational(r1, r2);
    printf("Divisao: ");
    printRational(quotient);

    freeRational(r1);
    freeRational(r2);
    freeRational(sum);
    freeRational(diff);
    freeRational(quotient);

    return 0;
}
