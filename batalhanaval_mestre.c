#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define VALOR_NAVIO 3
#define VALOR_HABILIDADE 5

void inicializar_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
            tabuleiro[i][j] = 0;
}

void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void construir_cone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= TAMANHO_HABILIDADE / 2 - i && j <= TAMANHO_HABILIDADE / 2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

void construir_cruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

void construir_octaedro(int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - TAMANHO_HABILIDADE / 2) + abs(j - TAMANHO_HABILIDADE / 2) <= TAMANHO_HABILIDADE / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
}

void aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                        int origem_linha, int origem_coluna) {
    int offset = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha_tab = origem_linha + i - offset;
            int coluna_tab = origem_coluna + j - offset;

            if (linha_tab >= 0 && linha_tab < TAMANHO_TABULEIRO &&
                coluna_tab >= 0 && coluna_tab < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    if (tabuleiro[linha_tab][coluna_tab] == 0)
                        tabuleiro[linha_tab][coluna_tab] = VALOR_HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    inicializar_tabuleiro(tabuleiro);

    tabuleiro[2][2] = VALOR_NAVIO;
    tabuleiro[2][3] = VALOR_NAVIO;
    tabuleiro[2][4] = VALOR_NAVIO;
    tabuleiro[5][5] = VALOR_NAVIO;
    tabuleiro[6][5] = VALOR_NAVIO;
    tabuleiro[7][5] = VALOR_NAVIO;

    construir_cone(cone);
    construir_cruz(cruz);
    construir_octaedro(octaedro);

    aplicar_habilidade(tabuleiro, cone, 3, 3);       // Cone centrado em (3,3)
    aplicar_habilidade(tabuleiro, cruz, 6, 5);       // Cruz centrada em (6,5)
    aplicar_habilidade(tabuleiro, octaedro, 5, 8);   // Octaedro centrado em (5,8)

    exibir_tabuleiro(tabuleiro);

    return 0;
}
