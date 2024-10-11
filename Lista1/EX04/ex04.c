#include "ex04.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Estudante
struct Estudante {
    char sobrenome[50];  ///< Sobrenome do estudante
    char primeiroNome[50];  ///< Primeiro nome do estudante
    double gpa;  ///< Índice de pontos de graduação
};

// Definição da estrutura Funcionario
struct Funcionario {
    char sobrenome[50];  ///< Sobrenome do funcionário
    char primeiroNome[50];  ///< Primeiro nome do funcionário
    double salario;  ///< Salário do funcionário
};

/**
 * @brief Cria e inicializa um registro de funcionário.
 * 
 * @param sobrenome Sobrenome do funcionário.
 * @param primeiroNome Primeiro nome do funcionário.
 * @param salario Salário do funcionário.
 * @return Ponteiro para a estrutura Funcionario recém-criada.
 */
Funcionario* criarFuncionario(const char* sobrenome, const char* primeiroNome, double salario) {
    Funcionario* funcionario = (Funcionario*)malloc(sizeof(Funcionario));
    if (!funcionario) {
        fprintf(stderr, "\n Erro ao alocar memória para o funcionário.");
        exit(EXIT_FAILURE);
    }
    strcpy(funcionario->sobrenome, sobrenome);
    strcpy(funcionario->primeiroNome, primeiroNome);
    funcionario->salario = salario;
    return funcionario;
}

/**
 * @brief Cria e inicializa um registro de estudante.
 * 
 * @param sobrenome Sobrenome do estudante.
 * @param primeiroNome Primeiro nome do estudante.
 * @param gpa Índice de pontos de graduação do estudante.
 * @return Ponteiro para a estrutura Estudante recém-criada.
 */
Estudante* criarEstudante(const char* sobrenome, const char* primeiroNome, double gpa) {
    Estudante* estudante = (Estudante*)malloc(sizeof(Estudante));
    if (!estudante) {
        fprintf(stderr, "\n Erro ao alocar memória para o estudante.");
        exit(EXIT_FAILURE);
    }
    strcpy(estudante->sobrenome, sobrenome);
    strcpy(estudante->primeiroNome, primeiroNome);
    estudante->gpa = gpa;
    return estudante;
}

/**
 * @brief Libera a memória alocada para um funcionário.
 * 
 * @param funcionario Ponteiro para o funcionário a ser liberado.
 */
void liberarFuncionario(Funcionario* funcionario) {
    free(funcionario);
}

/**
 * @brief Libera a memória alocada para um estudante.
 * 
 * @param estudante Ponteiro para o estudante a ser liberado.
 */
void liberarEstudante(Estudante* estudante) {
    free(estudante);
}

/**
 * @brief Concede um aumento de 10% para funcionários que têm um correspondente no vetor de estudantes com GPA > 3.0.
 * 
 * @param funcionarios Vetor de ponteiros para funcionários.
 * @param numFuncionarios Número de funcionários no vetor.
 * @param estudantes Vetor de ponteiros para estudantes.
 * @param numEstudantes Número de estudantes no vetor.
 */
void concederAumento(Funcionario* funcionarios[], int numFuncionarios, Estudante* estudantes[], int numEstudantes) {
    for (int i = 0; i < numFuncionarios; i++) {
        for (int j = 0; j < numEstudantes; j++) {
            if (strcmp(funcionarios[i]->sobrenome, estudantes[j]->sobrenome) == 0 &&
                strcmp(funcionarios[i]->primeiroNome, estudantes[j]->primeiroNome) == 0 &&
                estudantes[j]->gpa > 3.0) {
                // Aumenta o salário em 10%
                funcionarios[i]->salario *= 1.10;
                break;
            }
        }
    }
}

/**
 * @brief Imprime os dados de um funcionário.
 * 
 * @param funcionario Ponteiro para o funcionário a ser impresso.
 */
void imprimirFuncionario(Funcionario* funcionario) {
    printf("\n Funcionario: %s %s, Salario: %.2f", funcionario->sobrenome, funcionario->primeiroNome, funcionario->salario);
}
