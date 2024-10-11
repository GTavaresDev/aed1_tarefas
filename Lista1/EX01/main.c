#include "ex01.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    NumerosComplex *c1 = create_complex(3.0, 4.0);
    NumerosComplex *c2 = create_complex(1.0, 2.0);
    NumerosComplex *result;

    result = add_complex(c1, c2);
    printf("Soma: ");
    print_complex(result);
    free_complex(result);

    result = multiply_complex(c1, c2);
    printf("Multiplicacao: ");
    print_complex(result);
    free_complex(result); 

    result = negate_complex(c1);
    printf("Negacao de c1: ");
    print_complex(result);
    free_complex(result);  

    printf("Modulo de c1: %.2f\n", modulo_complex(c1));

    free_complex(c1);
    free_complex(c2);

    return 0;
}
