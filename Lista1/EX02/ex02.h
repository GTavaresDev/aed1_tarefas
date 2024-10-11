#ifndef EX02_H
#define EX02_H

typedef struct realtype realtype;

struct realtype* createRealtype(int left, int right);
double realValue(struct realtype *r);
struct realtype* addRealtype(struct realtype *r1, struct realtype *r2);
struct realtype* subtractRealtype(struct realtype *r1, struct realtype *r2);
struct realtype* multiplyRealtype(struct realtype *r1, struct realtype *r2);
void printRealtype(struct realtype *r);
void freeRealtype(struct realtype *r);

#endif
