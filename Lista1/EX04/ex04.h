#ifndef REGISTRO_H
#define REGISTRO_H

typedef struct Estudante Estudante;
typedef struct Funcionario Funcionario;

// Protótipos das funções
Funcionario* criarFuncionario(const char* sobrenome, const char* primeiroNome, double salario);
Estudante* criarEstudante(const char* sobrenome, const char* primeiroNome, double gpa);
void liberarFuncionario(Funcionario* funcionario);
void liberarEstudante(Estudante* estudante);
void concederAumento(Funcionario* funcionarios[], int numFuncionarios, Estudante* estudantes[], int numEstudantes);
void imprimirFuncionario(Funcionario* funcionario);

#endif
