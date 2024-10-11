#include "ex07.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct RATIONAL {
    int numerator;
    int denominator;
} RATIONAL;

/**
 * @brief Calcula o máximo divisor comum (MDC) entre dois números inteiros.
 * 
 * @param a Primeiro número.
 * @param b Segundo número.
 * @return O MDC de a e b.
 */
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

/**
 * @brief Reduz um número racional aos seus termos mínimos.
 * 
 * @param r Ponteiro para a estrutura RATIONAL que será reduzida.
 */
void reduceRational(RATIONAL *r) {
    int divisor = gcd(r->numerator, r->denominator);
    r->numerator /= divisor;
    r->denominator /= divisor;
    if (r->denominator < 0) {  // Garantir que o denominador seja sempre positivo
        r->numerator = -r->numerator;
        r->denominator = -r->denominator;
    }
}

/**
 * @brief Verifica se dois números racionais são iguais.
 * 
 * @param r1 Primeiro número racional.
 * @param r2 Segundo número racional.
 * @return 1 se forem iguais, 0 caso contrário.
 */
int equal(RATIONAL *r1, RATIONAL *r2) {
    // Reduzir ambos os racionais aos seus termos mínimos
    reduceRational(r1);
    reduceRational(r2);

    // Verificar igualdade entre numeradores e denominadores
    return (r1->numerator == r2->numerator && r1->denominator == r2->denominator);
}

/**
 * @brief Cria um novo número racional.
 * 
 * @param numerator O numerador do número racional.
 * @param denominator O denominador do número racional.
 * @return Um ponteiro para a estrutura RATIONAL recém-criada.
 */
RATIONAL* createRational(int numerator, int denominator) {
    if (denominator == 0) {
        perror("Erro: Denominador não pode ser zero.");
        exit(EXIT_FAILURE);
    }
    RATIONAL *r = (RATIONAL *)malloc(sizeof(RATIONAL));
    if (r == NULL) {
        perror("Erro ao alocar memória para o número racional.");
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
        perror("Erro: Divisão por zero.");
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
