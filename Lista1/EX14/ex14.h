#ifndef EX14_H
#define EX14_H

#define MAX_SIZE 20

typedef struct TConjunto TConjunto;

TConjunto* criarConjuntoVazio();
void lerConjunto(TConjunto* conjunto, int n);
void unirConjuntos(TConjunto* conjunto1, TConjunto* conjunto2, TConjunto* resultado);
void interseccionarConjuntos(TConjunto* conjunto1, TConjunto* conjunto2, TConjunto* resultado);
int conjuntosIguais(TConjunto* conjunto1, TConjunto* conjunto2);
void imprimirConjunto(TConjunto* conjunto);
void liberarConjunto(TConjunto* conjunto);

#endif
