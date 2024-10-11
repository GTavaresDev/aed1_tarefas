#ifndef STRUCT_EXAMPLE_H
#define STRUCT_EXAMPLE_H

typedef struct nametype nametype;

typedef struct person person;

struct person* createPerson();
int calculate_address_of_p10();
int calculate_address_of_p200_name_midinit();
int calculate_address_of_p20_income();
int calculate_address_of_p20_address_5();
int calculate_address_of_p5_parents1_last_10();
void freePerson(struct person* p);

#endif
