#ifndef EX01_H
#define EX01_H

//Como uma boa pratica eu vou deixar a implementação para o .c
typedef struct NumerosComplex NumerosComplex;  

// Prototipação das funções
NumerosComplex* create_complex(double real, double imaginario);
double modulo_complex(NumerosComplex *c);
NumerosComplex* add_complex(NumerosComplex *c1, NumerosComplex *c2);
NumerosComplex* multiply_complex(NumerosComplex *c1, NumerosComplex *c2);
NumerosComplex* negate_complex(NumerosComplex *c);
void print_complex(NumerosComplex *c);
void free_complex(NumerosComplex *c);  

#endif // EX01_H