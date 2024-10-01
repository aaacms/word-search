#ifndef BUSCA_H
#define BUSCA_H

char** aloca_matriz (int m, int n);
void desaloca_matriz (int m, char** mat);
void preenche_matriz (int m, int n, char **mat);
void mostra_matriz (int m, int n, char **mat);
int** soma_matriz (int m, int n, int** mat1, int** mat2);


#endif //BUSCA_H
