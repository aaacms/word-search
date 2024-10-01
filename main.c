#include <stdio.h>
#include "matriz.h"
#include "busca.h"

int main() {
    printf("Bem-vindo ao caca-palavras!\n");

    int m, n;
    printf("Digite a quantidade de linhas:");
    scanf("%d", &m);
    printf("Digite a quantidade de colunas:");
    scanf("%d", &n);

    char **matriz = aloca_matriz(m, n);

    preenche_matriz(m, n, matriz);
    mostra_matriz(m, n, matriz);

    busca_palavras(m, n, matriz);

    printf("\n\nOBRIGADA POR JOGAR!\n\n");

    desaloca_matriz(m, matriz);

    return 0;
}
