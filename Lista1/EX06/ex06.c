#include "ex06.h"
#include <stdlib.h>
#include <stdio.h>

// Definição da estrutura RATIONAL somente no arquivo .c
 struct RATIONAL{
    int numerator;
    int denominator;
} ;

/**
 * @brief Cria um novo número racional.
 * 
 * @param numerator O numerador do número racional.
 * @param denominator O denominador do número racional.
 * @return Um ponteiro para a estrutura RATIONAL recém-criada.
 */
RATIONAL* createRational(int numerator, int denominator) {
    if (denominator == 0) {
        perror("Erro: Denominador nao pode ser zero.");
        exit(EXIT_FAILURE);
    }
    RATIONAL *r = (RATIONAL *)malloc(sizeof(RATIONAL));
    if (r == NULL) {
        perror("Erro ao alocar memoria para o numero racional.");
        exit(EXIT_FAILURE);
    }
    r->numerator = numerator;
    r->denominator = denominator;
    return r;
}

/**
 * @brief Soma dois números racionais.
 * 
 * @param r1 Primeiro número racional.
 * @param r2 Segundo número racional.
 * @return Um ponteiro para o número racional resultante da soma.
 */
RATIONAL* addRational(RATIONAL *r1, RATIONAL *r2) {
    int num = r1->numerator * r2->denominator + r2->numerator * r1->denominator;
    int denom = r1->denominator * r2->denominator;
    return createRational(num, denom);
}

/**
 * @brief Subtrai dois números racionais.
 * 
 * @param r1 Primeiro número racional.
 * @param r2 Segundo número racional.
 * @return Um ponteiro para o número racional resultante da subtração.
 */
RATIONAL* subtractRational(RATIONAL *r1, RATIONAL *r2) {
    int num = r1->numerator * r2->denominator - r2->numerator * r1->denominator;
    int denom = r1->denominator * r2->denominator;
    return createRational(num, denom);
}

/**
 * @brief Divide dois números racionais.
 * 
 * @param r1 Primeiro número racional (dividendo).
 * @param r2 Segundo número racional (divisor).
 * @return Um ponteiro para o número racional resultante da divisão.
 */
RATIONAL* divideRational(RATIONAL *r1, RATIONAL *r2) {
    if (r2->numerator == 0) {
        perror("Erro: Divisao por zero.");
        exit(EXIT_FAILURE);
    }
    int num = r1->numerator * r2->denominator;
    int denom = r1->denominator * r2->numerator;
    return createRational(num, denom);
}

/**
 * @brief Exibe um número racional no formato "numerador/denominador".
 * 
 * @param r Ponteiro para o número racional a ser exibido.
 */
void printRational(RATIONAL *r) {
    printf("%d/%d\n", r->numerator, r->denominator);
}

/**
 * @brief Libera a memória alocada para uma estrutura RATIONAL.
 * 
 * @param r Ponteiro para o número racional a ser liberado.
 */
void freeRational(RATIONAL *r) {
    free(r);
}
