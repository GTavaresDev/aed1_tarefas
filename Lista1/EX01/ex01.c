#include "ex01.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct NumerosComplex {
    double real;         
    double imaginario;    
};

/**
 * @brief Cria um número complexo.
 * 
 * Esta função aloca memória e inicializa um número complexo com os valores
 * fornecidos para a parte real e imaginária.
 * 
 * @param real Parte real do número complexo.
 * @param imaginario Parte imaginária do número complexo.
 * @retval Um ponteiro para o número complexo criado.
 */
NumerosComplex* create_complex(double real, double imaginario) {
    NumerosComplex *c = (NumerosComplex *)malloc(sizeof(NumerosComplex));
    if (c == NULL) {
        perror("Erro ao alocar memoria para o numero complexo");
        exit(EXIT_FAILURE);
    }
    c->real = real;
    c->imaginario = imaginario;
    return c;
}

/**
 * @brief Calcula o módulo de um número complexo.
 * 
 * Esta função calcula e retorna o módulo de um número complexo, que é
 * dado pela fórmula sqrt(a^2 + b^2), onde a é a parte real e b é a
 * parte imaginária do número complexo.
 * 
 * @param c Ponteiro para o número complexo.
 * @retval O módulo do número complexo (valor real).
 */
double modulo_complex(NumerosComplex *c) {
    return sqrt(c->real * c->real + c->imaginario * c->imaginario);
}

/**
 * @brief Soma dois números complexos.
 * 
 * Esta função realiza a soma de dois números complexos, retornando um
 * número complexo resultante da operação (a + c) + (b + d)i, onde
 * a e b são as partes real e imaginária do primeiro número, e c e d
 * são as partes real e imaginária do segundo número.
 * 
 * @param c1 Ponteiro para o primeiro número complexo.
 * @param c2 Ponteiro para o segundo número complexo.
 * @retval Um ponteiro para o número complexo resultante da soma.
 */
NumerosComplex* add_complex(NumerosComplex *c1, NumerosComplex *c2) {
    return create_complex(c1->real + c2->real, c1->imaginario + c2->imaginario);
}

/**
 * @brief Multiplica dois números complexos.
 * 
 * Esta função realiza a multiplicação de dois números complexos, retornando
 * um número complexo resultante da operação (a * c – b * d) + (a * d + b * c)i,
 * onde a e b são as partes real e imaginária do primeiro número, e c e d
 * são as partes real e imaginária do segundo número.
 * 
 * @param c1 Ponteiro para o primeiro número complexo.
 * @param c2 Ponteiro para o segundo número complexo.
 * @retval Um ponteiro para o número complexo resultante da multiplicação.
 */
NumerosComplex* multiply_complex(NumerosComplex *c1, NumerosComplex *c2) {
    return create_complex(
        c1->real * c2->real - c1->imaginario * c2->imaginario,
        c1->real * c2->imaginario + c1->imaginario * c2->real
    );
}

/**
 * @brief Calcula o oposto de um número complexo.
 * 
 * Esta função retorna o oposto de um número complexo, ou seja, (-a) + (-b)i,
 * onde a e b são as partes real e imaginária do número complexo.
 * 
 * @param c Ponteiro para o número complexo.
 * @retval Um ponteiro para o número complexo que é o oposto.
 */
NumerosComplex* negate_complex(NumerosComplex *c) {
    return create_complex(-c->real, -c->imaginario);
}

/**
 * @brief Exibe um número complexo.
 * 
 * Esta função imprime a representação de um número complexo na forma
 * "a + bi" ou "a - bi", dependendo do sinal da parte imaginária.
 * 
 * @param c Ponteiro para o número complexo a ser exibido.
 */
void print_complex(NumerosComplex *c) {
    if (c->imaginario >= 0)
        printf("%.2f + %.2fi\n", c->real, c->imaginario);
    else
        printf("%.2f - %.2fi\n", c->real, -c->imaginario);
}

/**
 * @brief Libera a memória de um número complexo.
 * 
 * Esta função libera a memória alocada para um número complexo.
 * 
 * @param c Ponteiro para o número complexo a ser liberado.
 */
void free_complex(NumerosComplex *c) {
    free(c);
}