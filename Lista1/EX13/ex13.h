#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct TMatriz TMatriz;

TMatriz* criarMatriz(int n);
void liberarMatriz(TMatriz* matriz);
void preencherMatriz(TMatriz* matriz);
TMatriz* somarMatrizes(TMatriz* A, TMatriz* B);
TMatriz* multiplicarMatrizes(TMatriz* A, TMatriz* B);
TMatriz* calcularInversa(TMatriz* matriz);
void imprimirMatriz(TMatriz* matriz);

#endif
