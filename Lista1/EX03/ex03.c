#include "ex03.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

struct nametype {
    char first[10];
    char midinit;
    char last[20];
};

struct person {
    struct nametype name;
    int birthday[2];
    struct nametype parents[2];
    int income;
    int numchildren;
    char address[20];
    char city[10];
    char state[2];
};

/**
 * @brief Cria uma nova pessoa.
 * 
 * @return Um ponteiro para a estrutura person recém-criada.
 */
struct person* createPerson() {
    struct person *p = (struct person *)malloc(sizeof(struct person));
    if (p == NULL) {
        perror("Erro ao alocar memoria para a pessoa");
        exit(EXIT_FAILURE);
    }
    return p;
}

/**
 * @brief Calcula o endereço inicial da variável p[10].
 * 
 * @return O endereço em bytes.
 */
int calculate_address_of_p10() {
    return 100 + sizeof(struct person) * 10;
}

/**
 * @brief Calcula o endereço inicial da variável p[200].name.midinit.
 * 
 * @return O endereço em bytes.
 */
int calculate_address_of_p200_name_midinit() {
    return 100 + sizeof(struct person) * 200 + offsetof(struct person, name) + offsetof(struct nametype, midinit);
}

/**
 * @brief Calcula o endereço inicial da variável p[20].income.
 * 
 * @return O endereço em bytes.
 */
int calculate_address_of_p20_income() {
    return 100 + sizeof(struct person) * 20 + offsetof(struct person, income);
}

/**
 * @brief Calcula o endereço inicial da variável p[20].address[5].
 * 
 * @return O endereço em bytes.
 */
int calculate_address_of_p20_address_5() {
    return 100 + sizeof(struct person) * 20 + offsetof(struct person, address) + sizeof(char) * 5;
}

/**
 * @brief Calcula o endereço inicial da variável p[5].parents[1].last[10].
 * 
 * @return O endereço em bytes.
 */
int calculate_address_of_p5_parents1_last_10() {
    return 100 + sizeof(struct person) * 5 + offsetof(struct person, parents) + sizeof(struct nametype) + offsetof(struct nametype, last) + sizeof(char) * 10;
}

/**
 * @brief Libera a memória alocada para uma estrutura person.
 * 
 * @param p Ponteiro para a pessoa a ser liberada.
 */
void freePerson(struct person* p) {
    free(p);
}
