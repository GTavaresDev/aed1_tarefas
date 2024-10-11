#include "ex02.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct realtype {
    int left;  
    int right;  
};

struct realtype* createRealtype(int left, int right) {
    struct realtype *r = (struct realtype *)malloc(sizeof(struct realtype));
    if (r == NULL) {
        perror("Erro ao alocar memoria para o numero real");
        exit(EXIT_FAILURE);
    }
    r->left = left;
    r->right = right;
    return r;
}

/**
 * @brief Retorna o valor real representado por uma estrutura realtype.
 * 
 * Esta função calcula e retorna o número real completo, somando a parte inteira (left)
 * e a parte fracionária (right).
 * 
 * @param r Ponteiro para a estrutura realtype.
 * @retval O valor real (double) representado pela estrutura.
 */
double realValue(struct realtype *r) {
    double right_part = r->right / pow(10, (int)log10(r->right) + 1);  // Converte a parte direita para decimal
    return r->left + (r->left < 0 ? -right_part : right_part);
}

/**
 * @brief Soma dois números reais representados por estruturas realtype.
 * 
 * Esta função realiza a soma de dois números reais e retorna uma nova estrutura realtype
 * que representa o número resultante da operação.
 * 
 * @param r1 Ponteiro para o primeiro número real.
 * @param r2 Ponteiro para o segundo número real.
 * @retval Um ponteiro para o número real resultante da soma.
 */
struct realtype* addRealtype(struct realtype *r1, struct realtype *r2) {
    double sum = realValue(r1) + realValue(r2);
    int left_part = (int)sum;
    int right_part = fabs(sum - left_part) * pow(10, 6); // Aproximação para 6 casas decimais
    return createRealtype(left_part, right_part);
}

/**
 * @brief Subtrai dois números reais representados por estruturas realtype.
 * 
 * Esta função realiza a subtração de dois números reais e retorna uma nova estrutura realtype
 * que representa o número resultante da operação.
 * 
 * @param r1 Ponteiro para o primeiro número real.
 * @param r2 Ponteiro para o segundo número real.
 * @retval Um ponteiro para o número real resultante da subtração.
 */
struct realtype* subtractRealtype(struct realtype *r1, struct realtype *r2) {
    double diff = realValue(r1) - realValue(r2);
    int left_part = (int)diff;
    int right_part = fabs(diff - left_part) * pow(10, 6); // Aproximação para 6 casas decimais
    return createRealtype(left_part, right_part);
}

/**
 * @brief Multiplica dois números reais representados por estruturas realtype.
 * 
 * Esta função realiza a multiplicação de dois números reais e retorna uma nova estrutura realtype
 * que representa o número resultante da operação.
 * 
 * @param r1 Ponteiro para o primeiro número real.
 * @param r2 Ponteiro para o segundo número real.
 * @retval Um ponteiro para o número real resultante da multiplicação.
 */
struct realtype* multiplyRealtype(struct realtype *r1, struct realtype *r2) {
    double prod = realValue(r1) * realValue(r2);
    int left_part = (int)prod;
    int right_part = fabs(prod - left_part) * pow(10, 6); // Aproximação para 6 casas decimais
    return createRealtype(left_part, right_part);
}

/**
 * @brief Exibe o número real representado por uma estrutura realtype.
 * 
 * Esta função imprime o número real na forma "left.right", onde `left` é a parte inteira
 * e `right` é a parte fracionária.
 * 
 * @param r Ponteiro para o número real a ser exibido.
 */
void printRealtype(struct realtype *r) {
    printf("%d.%06d\n", r->left, r->right);
}

/**
 * @brief Libera a memória alocada para uma estrutura realtype.
 * 
 * Esta função libera a memória alocada para um número real representado por uma estrutura realtype.
 * 
 * @param r Ponteiro para o número real a ser liberado.
 */
void freeRealtype(struct realtype *r) {
    free(r);
}
