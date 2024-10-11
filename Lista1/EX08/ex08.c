#include "ex08.h"
#include <stdio.h>
#include <stdlib.h>

struct RATIONAL {
    int numerator;   
    int denominator;
};

/**
 * @brief Cria e inicializa um número racional.
 * 
 * @param numerator O numerador do número racional.
 * @param denominator O denominador do número racional.
 * @return Ponteiro para a estrutura RATIONAL recém-criada.
 */
RATIONAL* criarRacional(int numerator, int denominator) {
    if (denominator == 0) {
        fprintf(stderr, "\n Erro: Denominador não pode ser zero.");
        exit(EXIT_FAILURE);
    }
    RATIONAL* r = (RATIONAL*)malloc(sizeof(RATIONAL));
    if (!r) {
        fprintf(stderr, "\n Erro ao alocar memória.");
        exit(EXIT_FAILURE);
    }
    r->numerator = numerator;
    r->denominator = denominator;
    return r;
}

/**
 * @brief Libera a memória alocada para um número racional.
 * 
 * @param r Ponteiro para o número racional a ser liberado.
 */
void liberarRacional(RATIONAL* r) {
    free(r);
}

/**
 * @brief Verifica se dois números racionais são iguais multiplicando o denominador de um pelo numerador do outro.
 * 
 * @param r1 Primeiro número racional.
 * @param r2 Segundo número racional.
 * @return 1 se forem iguais, 0 caso contrário.
 * 
 * @details O método utiliza a comparação de frações pelo produto cruzado, ou seja:
 * - r1 é igual a r2 se e somente se (r1->numerator * r2->denominator) == (r2->numerator * r1->denominator).
 */
int equal2(RATIONAL* r1, RATIONAL* r2) {
    return (r1->numerator * r2->denominator) == (r2->numerator * r1->denominator);
}
