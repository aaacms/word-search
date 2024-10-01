#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

char** aloca_matriz(int m, int n) {
    char** x = (char**)malloc(m * sizeof(char*));
    if (x == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        x[i] = (char*)malloc(n * sizeof(char));
        if (x[i] == NULL) {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }
    }
    return x;
}

void desaloca_matriz(int m, char** mat) {
    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);
}

void remove_espaco(char *str) {
    int j = 0;
    int tamanho = (int)strlen(str);

    for (int i = 0; i < tamanho; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void preenche_matriz(int m, int n, char** mat) {
    char* text = (char*)malloc(m * n * sizeof(char) + 1);
    if (text == NULL) {
        printf("Erro ao alocar mem�ria para o texto.\n");
        exit(1);
    }

    getchar();

    printf("Digite o texto para o caca-palavras: ");
    fgets(text, m * n + 1, stdin);

    text[strcspn(text, "\n")] = '\0';
    remove_espaco(text);

    int len = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (len < strlen(text)) {
                mat[i][j] = text[len++];
            } else {
                mat[i][j] = ' ';
            }
        }
    }
    free(text);
}

void mostra_matriz(int m, int n, char** mat) {
    printf("\n    ");
    for (int i = 0; i < n; i++) {
        printf("\033[30;45m %d ", i + 1);
        if (i < n - 1) {
            printf("\033[0m|");
        }
    }
    printf("\n");
    for (int i = 0; i < m; i++) {
        printf("\033[30;45m %d \033[0m| ", i + 1);
        for (int j = 0; j < n; j++) {
            printf("%c", mat[i][j]);
            if (j < n - 1) {
                printf(" | ");
            }
        }
        printf("\n");
    }
}
