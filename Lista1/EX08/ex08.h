#ifndef RATIONAL_H
#define RATIONAL_H

typedef struct RATIONAL RATIONAL;

RATIONAL* criarRacional(int numerator, int denominator);
void liberarRacional(RATIONAL* r);
int equal2(RATIONAL* r1, RATIONAL* r2);

#endif
