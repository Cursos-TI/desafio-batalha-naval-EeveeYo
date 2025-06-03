#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define NAVIO_TAM 3
#define HABILIDADE_TAM 5

// Exibe o tabuleiro com números
void exibirTabuleiro(int tab[TAM][TAM]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

// Verifica se pode posicionar o navio na direção escolhida
int podePosicionar(int tab[TAM][TAM], int l, int c, int dir) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        int x = l, y = c;
        if (dir == 0) y += i;                 // horizontal
        else if (dir == 1) x += i;            // vertical
        else if (dir == 2) { x += i; y += i;} // diagonal principal
        else if (dir == 3) { x += i; y -= i;} // diagonal secundária

        if (x < 0 || x >= TAM || y < 0 || y >= TAM || tab[x][y] != 0)
            return 0;
    }
    return 1;
}

// Posiciona navio no tabuleiro
void posicionar(int tab[TAM][TAM], int l, int c, int dir) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (dir == 0) tab[l][c + i] = 3;
        else if (dir == 1) tab[l + i][c] = 3;
        else if (dir == 2) tab[l + i][c + i] = 3;
        else if (dir == 3) tab[l + i][c - i] = 3;
    }
}

// Cria matriz em forma de cone
void criarCone(int cone[HABILIDADE_TAM][HABILIDADE_TAM]) {
    for (int i = 0; i < HABILIDADE_TAM; i++) {
        for (int j = 0; j < HABILIDADE_TAM; j++) {
            if (j >= HABILIDADE_TAM / 2 - i && j <= HABILIDADE_TAM / 2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Cria matriz em forma de cruz
void criarCruz(int cruz[HABILIDADE_TAM][HABILIDADE_TAM]) {
    for (int i = 0; i < HABILIDADE_TAM; i++) {
        for (int j = 0; j < HABILIDADE_TAM; j++) {
            if (i == HABILIDADE_TAM / 2 || j == HABILIDADE_TAM / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Cria matriz em forma de octaedro (losango)
void criarOctaedro(int octaedro[HABILIDADE_TAM][HABILIDADE_TAM]) {
    for (int i = 0; i < HABILIDADE_TAM; i++) {
        for (int j = 0; j < HABILIDADE_TAM; j++) {
            if (abs(i - HABILIDADE_TAM / 2) + abs(j - HABILIDADE_TAM / 2) <= HABILIDADE_TAM / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
}

// Aplica a habilidade no tabuleiro centralizando a matriz em (linha, coluna)
void aplicarHabilidade(int tab[TAM][TAM], int linha, int coluna, int area[HABILIDADE_TAM][HABILIDADE_TAM]) {
    for (int i = 0; i < HABILIDADE_TAM; i++) {
        for (int j = 0; j < HABILIDADE_TAM; j++) {
            int x = linha - HABILIDADE_TAM / 2 + i;
            int y = coluna - HABILIDADE_TAM / 2 + j;
            if (x >= 0 && x < TAM && y >= 0 && y < TAM && area[i][j] == 1 && tab[x][y] == 0) {
                tab[x][y] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posicionar 4 navios: 2 normais (horizontal/vertical) e 2 diagonais
    if (podePosicionar(tabuleiro, 1, 1, 0)) posicionar(tabuleiro, 1, 1, 0); // horizontal
    if (podePosicionar(tabuleiro, 4, 2, 1)) posicionar(tabuleiro, 4, 2, 1); // vertical
    if (podePosicionar(tabuleiro, 0, 7, 2)) posicionar(tabuleiro, 0, 7, 2); // diagonal principal
    if (podePosicionar(tabuleiro, 6, 9, 3)) posicionar(tabuleiro, 6, 9, 3); // diagonal secundária

    // Criar e aplicar áreas de habilidades
    int cone[HABILIDADE_TAM][HABILIDADE_TAM];
    int cruz[HABILIDADE_TAM][HABILIDADE_TAM];
    int octaedro[HABILIDADE_TAM][HABILIDADE_TAM];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, 2, 2, cone);
    aplicarHabilidade(tabuleiro, 5, 5, cruz);
    aplicarHabilidade(tabuleiro, 8, 2, octaedro);

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}