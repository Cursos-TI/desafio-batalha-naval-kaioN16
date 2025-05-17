#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3

int esta_ocupado(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] != 0;
}

int posiciona_horizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        if (esta_ocupado(tabuleiro, linha, coluna + i)) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[linha][coluna + i] = NAVIO;

    return 1;
}

int posiciona_vertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        if (esta_ocupado(tabuleiro, linha + i, coluna)) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[linha + i][coluna] = NAVIO;

    return 1;
}

int posiciona_diagonal_principal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        if (esta_ocupado(tabuleiro, linha + i, coluna + i)) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[linha + i][coluna + i] = NAVIO;

    return 1;
}

int posiciona_diagonal_secundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO + 1 < 0) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        if (esta_ocupado(tabuleiro, linha + i, coluna - i)) return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[linha + i][coluna - i] = NAVIO;

    return 1;
}

void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
            tabuleiro[i][j] = 0;

    if (!posiciona_horizontal(tabuleiro, 1, 2))
        printf("Falha ao posicionar navio horizontal\n");

    if (!posiciona_vertical(tabuleiro, 5, 0))
        printf("Falha ao posicionar navio vertical\n");

    if (!posiciona_diagonal_principal(tabuleiro, 0, 6))
        printf("Falha ao posicionar navio diagonal principal\n");

    if (!posiciona_diagonal_secundaria(tabuleiro, 6, 9))
        printf("Falha ao posicionar navio diagonal secundária\n");

    exibir_tabuleiro(tabuleiro);

    return 0;
}
