#include <stdio.h>
#include "ex04.h"

int main() {
    Funcionario* funcionarios[2];
    funcionarios[0] = criarFuncionario("Marciano", "Joemir", 5000.0);
    funcionarios[1] = criarFuncionario("Valdemar", "Eliomar", 6000.0);

    Estudante* estudantes[2];
    estudantes[0] = criarEstudante("Tavares", "Murilo", 3.5);
    estudantes[1] = criarEstudante("Ivan", "Kaike", 2.8);

    concederAumento(funcionarios, 2, estudantes, 2);

    imprimirFuncionario(funcionarios[0]);
    imprimirFuncionario(funcionarios[1]);

    liberarFuncionario(funcionarios[0]);
    liberarFuncionario(funcionarios[1]);
    liberarEstudante(estudantes[0]);
    liberarEstudante(estudantes[1]);

    return 0;
}
