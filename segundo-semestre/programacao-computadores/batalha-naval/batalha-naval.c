#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define NAVIO 3

void inicializar_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionar_navio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    if (direcao == 0) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

void posicionar_navio_diagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    if (direcao == 0) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }
    } else {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha + i][coluna - i] = NAVIO;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializar_tabuleiro(tabuleiro);

    posicionar_navio(tabuleiro, 1, 2, 0);
    posicionar_navio(tabuleiro, 4, 5, 1);

    posicionar_navio_diagonal(tabuleiro, 0, 0, 0);
    posicionar_navio_diagonal(tabuleiro, 5, 9, 1);

    exibir_tabuleiro(tabuleiro);

    return 0;
}