#ifndef RATIONAL_H
#define RATIONAL_H

typedef struct RATIONAL RATIONAL;


RATIONAL* createRational(int numerator, int denominator);
RATIONAL* addRational(RATIONAL *r1, RATIONAL *r2);
RATIONAL* subtractRational(RATIONAL *r1, RATIONAL *r2);
RATIONAL* divideRational(RATIONAL *r1, RATIONAL *r2);
void printRational(RATIONAL *r);
void freeRational(RATIONAL *r);
int equal(RATIONAL *r1, RATIONAL *r2); 
void reduceRational(RATIONAL *r); 

#endif
