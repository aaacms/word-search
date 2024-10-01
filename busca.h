#ifndef BUSCA_H
#define BUSCA_H
#include <stdbool.h>

bool busca_horizontal_direta(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1);
bool busca_horizontal_reversa(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1);
bool busca_vertical_direta(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1);
bool busca_vertical_reversa(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1);

bool busca_diagonal_principal_direta(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1);
bool busca_diagonal_principal_reversa(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1);
bool busca_diagonal_sec_direta(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1);
bool busca_diagonal_sec_reversa(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1);

void busca_palavras(int m, int n, char** matriz);


#endif //BUSCA_H
