#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "busca.h"

// da esquerda para a direita
bool busca_horizontal_direta(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1) {
    int tam_palavra = (int)strlen(palavra);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= (n - tam_palavra); j++) {
            int k;
            for (k = 0; k < tam_palavra; k++) {
                if (matriz[i][j + k] != palavra[k]) {
                    break;
                }
            }
            if (k == tam_palavra) {
                *x0 = i;
                *y0 = j;
                *x1 = i;
                *y1 = j + tam_palavra - 1;
                return true;
            }
        }
    }
    return false;
}

// da direita para a esquerda
bool busca_horizontal_reversa(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1)
{
    int tam_palavra = (int)strlen(palavra);
    for (int i = (m - 1); i >= 0; i--) {
        for (int j = (n - 1); j >= (tam_palavra - 1); j--) {
            int k;
            for (k = 0; k < tam_palavra; k++) {
                if (matriz[i][j - k] != palavra[k]) {
                    break;
                }
            }
            if (k == tam_palavra) {
                *x0 = i;
                *y0 = j;
                *x1 = i;
                *y1 = j - tam_palavra + 1;
                return true;
            }
        }
    }
    return false;
}

// de cima para baixo
bool busca_vertical_direta(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1)
{
    int tam_palavra = (int)strlen(palavra);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= (m - tam_palavra); i++) {
            int k;
            for (k = 0; k < tam_palavra; k++) {
                if (matriz[i + k][j] != palavra[k]) {
                    break;
                }
            }
            if (k == tam_palavra) {
                *x0 = i;
                *y0 = j;
                *x1 = i + tam_palavra - 1;
                *y1 = j;
                return true;
            }
        }
    }
    return false;
}

// de baixo ppara cima
bool busca_vertical_reversa(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1)
{
    int tam_palavra = (int)strlen(palavra);
    for (int j = 0; j < n; j++) {
        for (int i = (m - 1); i >= (tam_palavra - 1); i--) {
            int k;
            for (k = 0; k < tam_palavra; k++) {
                if (matriz[i - k][j] != palavra[k]) {
                    break;
                }
            }
            if (k == tam_palavra) {
                *x0 = i;
                *y0 = j;
                *x1 = i - tam_palavra + 1;
                *y1 = j;
                return true;
            }
        }
    }
    return false;
}

// da esquerda para a direita, de cima para baixo
bool busca_diagonal_principal_direta(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1)
{
    int tam_palavra = (int)strlen(palavra);
    for (int i = 0; i <= m - tam_palavra; i++) {
        for (int j = 0; j <= n - tam_palavra; j++) {
            int k;

            for (k = 0; k < tam_palavra; k++) {
                if (matriz[i + k][j + k] != palavra[k]) {
                    break;
                }
            }
            if (k == tam_palavra) {
                *x0 = i;
                *y0 = j;
                *x1 = i + tam_palavra - 1;
                *y1 = j + tam_palavra - 1;
                return true;
            }
        }
    }
    return false;
}

//da esquerda para a direita, de baixo para cima
bool busca_diagonal_principal_reversa(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1)
{
    int tam_palavra = (int)strlen(palavra);
    for (int i = m - 1; i >= tam_palavra - 1; i--) {

        for (int j = 0; j <= n - tam_palavra; j++) {
            int k;

            for (k = 0; k < tam_palavra; k++) {
                if (matriz[i - k][j + k] != palavra[k]) {
                    break;
                }
            }
            if (k == tam_palavra) {
                *x0 = i;
                *y0 = j;
                *x1 = i - tam_palavra + 1;
                *y1 = j + tam_palavra - 1;
                return true;
            }
        }
    }
    return false;
}

// da direita para a esquerda, de cima para baixo
bool busca_diagonal_sec_direta(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1)
{
    int tam_palavra = (int)strlen(palavra);
    for (int i = 0; i <= m - tam_palavra; i++) {

        for (int j = n - 1; j > tam_palavra; j--) {
            int k;

            for (k = 0; k < tam_palavra; k++) {
                if (matriz[i + k][j - k] != palavra[k]) {
                    break;
                }
            }
            if (k == tam_palavra) {
                *x0 = i;
                *y0 = j;
                *x1 = i + tam_palavra - 1;
                *y1 = j - tam_palavra + 1;
                return true;
            }
        }
    }
    return false;
}

//da direita para a esquerda, de baixo para cima
bool busca_diagonal_sec_reversa(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1)
{
    int tam_palavra = (int)strlen(palavra);
    for (int i = m - 1; i >= tam_palavra - 1; i--) {

        for (int j = n - 1; j >= tam_palavra - 1; j--) {
            int k;

            for (k = 0; k < tam_palavra; k++) {
                if (matriz[i - k][j - k] != palavra[k]) {
                    break;
                }
            }
            if (k == tam_palavra) {
                *x0 = i;
                *y0 = j;
                *x1 = i - tam_palavra + 1;
                *y1 = j - tam_palavra + 1;
                return true;
            }
        }
    }
    return false;
}

void busca(char** matriz, int m, int n, char* palavra, int* x0, int* y0, int* x1, int* y1)
{
    printf("entrei na busca");
    if (busca_horizontal_direta(matriz, m, n, palavra, x0, y0, x1, y1))
    {
        printf("Palavra '%s' ocorre na horizontal direta, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]\n", palavra, *x0 + 1, *y0 + 1, *x1 + 1, *y1 + 1);
    }
    else if (busca_horizontal_reversa(matriz, m, n, palavra, x0, y0, x1, y1))
    {
        printf("Palavra '%s' ocorre na horizontal reversa, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]\n", palavra, *x0 + 1, *y0 + 1, *x1 + 1, *y1 + 1);
    }
    else if (busca_vertical_direta(matriz, m, n, palavra, x0, y0, x1, y1))
    {
        printf("Palavra '%s' ocorre na vertical direta, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]\n", palavra, *x0 + 1, *y0 + 1, *x1 + 1, *y1 + 1);
    }
    else if (busca_vertical_reversa(matriz, m, n, palavra, x0, y0, x1, y1))
    {
        printf("Palavra '%s' ocorre na vertical reversa, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]\n", palavra, *x0 + 1, *y0 + 1, *x1 + 1, *y1 + 1);
    }
    else if (busca_diagonal_principal_direta(matriz, m, n, palavra, x0, y0, x1, y1))
    {
        printf("Palavra '%s' ocorre na diagonal principal direta, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]\n", palavra, *x0 + 1, *y0 + 1, *x1 + 1, *y1 + 1);
    }
    else if (busca_diagonal_principal_reversa(matriz, m, n, palavra, x0, y0, x1, y1))
    {
        printf("Palavra '%s' ocorre na diagonal principal reversa, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]\n", palavra, *x0 + 1, *y0 + 1, *x1 + 1, *y1 + 1);
    }
    else if (busca_diagonal_sec_direta(matriz, m, n, palavra, x0, y0, x1, y1))
    {
        printf("Palavra '%s' ocorre na diagonal secundaria direta, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]\n", palavra, *x0 + 1, *y0 + 1, *x1 + 1, *y1 + 1);
    }
    else if (busca_diagonal_sec_reversa(matriz, m, n, palavra, x0, y0, x1, y1))
    {
        printf("Palavra '%s' ocorre na diagonal secundaria reversa, iniciando na posicao [%d,%d] e terminando na posicao [%d,%d]\n", palavra, *x0 + 1, *y0 + 1, *x1 + 1, *y1 + 1);
    }
    else
    {
        printf("Palavra '%s' nao encontrada.\n", palavra);
    }

}


void busca_palavras(int m, int n, char** matriz)
{

    char palavra[100];
    int x0, y0, x1, y1;

    printf("\nBem-vindo a pesquisa! Para sair da pesquisa digite QUIT\n");

    while(true) {
        printf("Digite a palavra para buscar: ");

        scanf("%s", palavra);

        if (strcmp(palavra, "QUIT") == 0) break;

        busca(matriz, m, n, palavra, &x0, &y0, &x1, &y1);

    }
}
