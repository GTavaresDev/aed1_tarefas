#include <stdio.h>
#include <stdlib.h>
#include "ex14.h"

struct TConjunto {
    int elementos[MAX_SIZE];  
    int tamanho;              
};

/**
 * @brief Cria um conjunto vazio, alocando memória dinamicamente.
 * 
 * @return Um ponteiro para a estrutura TConjunto recém-criada.
 */
TConjunto* criarConjuntoVazio() {
    TConjunto* conjunto = (TConjunto*)malloc(sizeof(TConjunto));
    if (conjunto != NULL) {
        conjunto->tamanho = 0;
    }
    return conjunto;
}

/**
 * @brief Lê os elementos do conjunto fornecidos pelo usuário.
 * 
 * @param conjunto Ponteiro para a estrutura TConjunto a ser preenchida.
 * @param n Número de elementos a serem inseridos no conjunto.
 */
void lerConjunto(TConjunto* conjunto, int n) {
    if (n > MAX_SIZE) {
        printf("\n Erro: O conjunto não pode ter mais de %d elementos.", MAX_SIZE);
        return;
    }
    conjunto->tamanho = n;
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &conjunto->elementos[i]);
    }
}

/**
 * @brief Realiza a união de dois conjuntos.
 * 
 * @param conjunto1 Ponteiro para o primeiro conjunto.
 * @param conjunto2 Ponteiro para o segundo conjunto.
 * @param resultado Ponteiro para o conjunto que armazenará o resultado da união.
 */
void unirConjuntos(TConjunto* conjunto1, TConjunto* conjunto2, TConjunto* resultado) {
    criarConjuntoVazio(resultado);
    for (int i = 0; i < conjunto1->tamanho; i++) {
        resultado->elementos[resultado->tamanho++] = conjunto1->elementos[i];
    }
    for (int i = 0; i < conjunto2->tamanho; i++) {
        int jaExiste = 0;
        for (int j = 0; j < resultado->tamanho; j++) {
            if (conjunto2->elementos[i] == resultado->elementos[j]) {
                jaExiste = 1;
                break;
            }
        }
        if (!jaExiste) {
            resultado->elementos[resultado->tamanho++] = conjunto2->elementos[i];
        }
    }
}

/**
 * @brief Realiza a interseção de dois conjuntos.
 * 
 * @param conjunto1 Ponteiro para o primeiro conjunto.
 * @param conjunto2 Ponteiro para o segundo conjunto.
 * @param resultado Ponteiro para o conjunto que armazenará o resultado da interseção.
 */
void interseccionarConjuntos(TConjunto* conjunto1, TConjunto* conjunto2, TConjunto* resultado) {
    criarConjuntoVazio(resultado);
    for (int i = 0; i < conjunto1->tamanho; i++) {
        for (int j = 0; j < conjunto2->tamanho; j++) {
            if (conjunto1->elementos[i] == conjunto2->elementos[j]) {
                resultado->elementos[resultado->tamanho++] = conjunto1->elementos[i];
                break;
            }
        }
    }
}

/**
 * @brief Verifica se dois conjuntos são iguais.
 * 
 * @param conjunto1 Ponteiro para o primeiro conjunto.
 * @param conjunto2 Ponteiro para o segundo conjunto.
 * @return 1 se os conjuntos forem iguais, 0 caso contrário.
 */
int conjuntosIguais(TConjunto* conjunto1, TConjunto* conjunto2) {
    if (conjunto1->tamanho != conjunto2->tamanho) {
        return 0;
    }
    for (int i = 0; i < conjunto1->tamanho; i++) {
        int encontrado = 0;
        for (int j = 0; j < conjunto2->tamanho; j++) {
            if (conjunto1->elementos[i] == conjunto2->elementos[j]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Imprime os elementos de um conjunto.
 * 
 * @param conjunto Ponteiro para o conjunto a ser impresso.
 */
void imprimirConjunto(TConjunto* conjunto) {
    printf("{ ");
    for (int i = 0; i < conjunto->tamanho; i++) {
        printf("%d ", conjunto->elementos[i]);
    }
    printf("\n }");
}

/**
 * @brief Libera a memória alocada para um conjunto.
 * 
 * @param conjunto Ponteiro para o conjunto a ser liberado.
 */
void liberarConjunto(TConjunto* conjunto) {
    free(conjunto);
}
