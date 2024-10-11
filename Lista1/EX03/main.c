#include <stdio.h>
#include "ex03.h"

int main() {
    printf("\n Endereco de p[10]: %d", calculate_address_of_p10());
    printf("\n Endereco de p[200].name.midinit: %d", calculate_address_of_p200_name_midinit());
    printf("\n Endereco de p[20].income: %d", calculate_address_of_p20_income());
    printf("\n Endereco de p[20].address[5]: %d", calculate_address_of_p20_address_5());
    printf("\n Endereco de p[5].parents[1].last[10]: %d", calculate_address_of_p5_parents1_last_10());
    
    return 0;
}
