#include "ex13.h"
#include <stdlib.h>
#include <stdio.h>

// Definição da estrutura TMatriz
typedef struct TMatriz {
    int n;          ///< Tamanho da matriz (n x n)
    double** dados; ///< Dados da matriz (ponteiro para ponteiro)
} TMatriz;

/**
 * @brief Cria e aloca uma matriz quadrada de tamanho n.
 * 
 * @param n Tamanho da matriz.
 * @return Ponteiro para a estrutura TMatriz recém-criada.
 */
TMatriz* criarMatriz(int n) {
    TMatriz* matriz = (TMatriz*)malloc(sizeof(TMatriz));
    if (!matriz) {
        perror("Erro ao alocar memória para a matriz");
        exit(EXIT_FAILURE);
    }
    matriz->n = n;
    matriz->dados = (double**)malloc(n * sizeof(double*));
    if (!matriz->dados) {
        perror("Erro ao alocar memória para os dados da matriz");
        free(matriz);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        matriz->dados[i] = (double*)malloc(n * sizeof(double));
        if (!matriz->dados[i]) {
            perror("Erro ao alocar memoria para uma linha da matriz");
            exit(EXIT_FAILURE);
        }
    }
    return matriz;
}

/**
 * @brief Libera a memória alocada para uma matriz.
 * 
 * @param matriz Ponteiro para a estrutura TMatriz a ser liberada.
 */
void liberarMatriz(TMatriz* matriz) {
    if (!matriz) return;
    for (int i = 0; i < matriz->n; i++) {
        free(matriz->dados[i]);
    }
    free(matriz->dados);
    free(matriz);
}

/**
 * @brief Preenche a matriz com valores fornecidos pelo usuário.
 * 
 * @param matriz Ponteiro para a estrutura TMatriz a ser preenchida.
 */
void preencherMatriz(TMatriz* matriz) {
    printf("Preenchendo matriz de tamanho %d:\n", matriz->n);
    for (int i = 0; i < matriz->n; i++) {
        for (int j = 0; j < matriz->n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%lf", &matriz->dados[i][j]);
        }
    }
}

/**
 * @brief Imprime uma matriz.
 * 
 * @param matriz Ponteiro para a matriz a ser impressa.
 */
void imprimirMatriz(TMatriz* matriz) {
    for (int i = 0; i < matriz->n; i++) {
        for (int j = 0; j < matriz->n; j++) {
            printf("%.2lf ", matriz->dados[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Soma duas matrizes e retorna o resultado.
 * 
 * @param A Primeira matriz.
 * @param B Segunda matriz.
 * @return Ponteiro para a matriz resultante da soma.
 */
TMatriz* somarMatrizes(TMatriz* A, TMatriz* B) {
    if (A->n != B->n) {
        printf("Erro: Matrizes de tamanhos diferentes\n");
        return NULL;
    }
    TMatriz* C = criarMatriz(A->n);
    for (int i = 0; i < A->n; i++) {
        for (int j = 0; j < A->n; j++) {
            C->dados[i][j] = A->dados[i][j] + B->dados[i][j];
        }
    }
    return C;
}

/**
 * @brief Multiplica duas matrizes e retorna o resultado.
 * 
 * @param A Primeira matriz.
 * @param B Segunda matriz.
 * @return Ponteiro para a matriz resultante da multiplicação.
 */
TMatriz* multiplicarMatrizes(TMatriz* A, TMatriz* B) {
    if (A->n != B->n) {
        printf("\n Erro: Matrizes de tamanhos diferentes");
        return NULL;
    }
    TMatriz* C = criarMatriz(A->n);
    for (int i = 0; i < A->n; i++) {
        for (int j = 0; j < A->n; j++) {
            C->dados[i][j] = 0;
            for (int k = 0; k < A->n; k++) {
                C->dados[i][j] += A->dados[i][k] * B->dados[k][j];
            }
        }
    }
    return C;
}

/**
 * @brief Calcula a inversa de uma matriz (não implementado completamente).
 * 
 * @param matriz Ponteiro para a matriz cuja inversa será calculada.
 * @return Ponteiro para a matriz inversa (ainda não implementado).
 */
TMatriz* calcularInversa(TMatriz* matriz) {
    printf("\n Funcao de calculo da inversa ainda nao implementada.");
    return NULL;
}
