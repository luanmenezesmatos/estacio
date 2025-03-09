#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 5
#define TAMANHO_HABILIDADE 5

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

void aplicar_habilidade(int tabuleiro[TAMANHO][TAMANHO], int origem_x, int origem_y, int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int x = origem_x + i - 2;
            int y = origem_y + j - 2;
            if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && habilidade[i][j] == 1) {
                tabuleiro[x][y] = HABILIDADE;
            }
        }
    }
}

void definir_habilidade_cone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (j >= 2 - i && j <= 2 + i) ? 1 : 0;
        }
    }
}

void definir_habilidade_cruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (i == 2 || j == 2) ? 1 : 0;
        }
    }
}

void definir_habilidade_octaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (abs(i - 2) + abs(j - 2) <= 2) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializar_tabuleiro(tabuleiro);

    posicionar_navio(tabuleiro, 1, 2, 0);
    posicionar_navio(tabuleiro, 4, 5, 1);

    int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    
    definir_habilidade_cone(habilidade_cone);
    definir_habilidade_cruz(habilidade_cruz);
    definir_habilidade_octaedro(habilidade_octaedro);

    aplicar_habilidade(tabuleiro, 2, 2, habilidade_cone);
    aplicar_habilidade(tabuleiro, 6, 6, habilidade_cruz);
    aplicar_habilidade(tabuleiro, 8, 4, habilidade_octaedro);

    exibir_tabuleiro(tabuleiro);

    return 0;
}