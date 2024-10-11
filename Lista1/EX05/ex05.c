#include "ex05.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Estudante {
    char sobrenome[50];
    char primeiroNome[50];
    double gpa;
};

struct Funcionario {
    char sobrenome[50];
    char primeiroNome[50];
    double salario;
};

/**
 * @brief Lê registros de funcionários e estudantes de arquivos externos e concede um aumento de 10% 
 *        para funcionários que têm um correspondente no arquivo de estudantes com GPA > 3.0.
 * 
 * @param arquivoFuncionarios Nome do arquivo que contém os registros dos funcionários.
 * @param arquivoEstudantes Nome do arquivo que contém os registros dos estudantes.
 * @param arquivoSaida Nome do arquivo de saída com os salários atualizados.
 */
void concederAumentoArquivo(const char* arquivoFuncionarios, const char* arquivoEstudantes, const char* arquivoSaida) {
    FILE *fFuncionarios = fopen(arquivoFuncionarios, "r");
    FILE *fEstudantes = fopen(arquivoEstudantes, "r");
    FILE *fSaida = fopen(arquivoSaida, "w");

    if (!fFuncionarios || !fEstudantes || !fSaida) {
        fprintf(stderr, "\n Erro ao abrir arquivos.");
        exit(EXIT_FAILURE);
    }

    Funcionario func;
    Estudante est;

    // Leitura e aumento de salários
    while (fscanf(fFuncionarios, "%s %s %lf", func.sobrenome, func.primeiroNome, &func.salario) != EOF) {
        int aumento = 0;  // Flag para verificar se o salário será aumentado

        rewind(fEstudantes);  // Retorna ao início do arquivo de estudantes
        while (fscanf(fEstudantes, "%s %s %lf", est.sobrenome, est.primeiroNome, &est.gpa) != EOF) {
            if (strcmp(func.sobrenome, est.sobrenome) == 0 &&
                strcmp(func.primeiroNome, est.primeiroNome) == 0 &&
                est.gpa > 3.0) {
                func.salario *= 1.10;  // Aumento de 10%
                aumento = 1;
                break;
            }
        }

        // Escreve no arquivo de saída, com ou sem aumento
        fprintf(fSaida, "\n %s %s %.2lf", func.sobrenome, func.primeiroNome, func.salario);
    }

    fclose(fFuncionarios);
    fclose(fEstudantes);
    fclose(fSaida);
}
