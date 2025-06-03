#include <stdio.h>

#define TAM 10
#define TAMANHO_NAVIO 3
#define VALOR_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n    ");
    for (int i = 0; i < TAM; i++)
        printf("%2d ", i);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d |", i);
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se o navio pode ser posicionado
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        switch (orientacao) {
            case 0: c += i; break;               // Horizontal →
            case 1: l += i; break;               // Vertical ↓
            case 2: l += i; c += i; break;       // Diagonal ↘
            case 3: l += i; c -= i; break;       // Diagonal ↙
        }

        if (l < 0 || l >= TAM || c < 0 || c >= TAM)
            return 0;
        if (tabuleiro[l][c] != 0)
            return 0;
    }

    return 1;
}

// Posiciona o navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        switch (orientacao) {
            case 0: c += i; break;
            case 1: l += i; break;
            case 2: l += i; c += i; break;
            case 3: l += i; c -= i; break;
        }

        tabuleiro[l][c] = VALOR_NAVIO;
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Navio 1 - Horizontal em (0,0)
    if (podePosicionar(tabuleiro, 0, 0, 0))
        posicionarNavio(tabuleiro, 0, 0, 0);
    else
        printf("Erro ao posicionar navio horizontal.\n");

    // Navio 2 - Vertical em (3,0)
    if (podePosicionar(tabuleiro, 3, 0, 1))
        posicionarNavio(tabuleiro, 3, 0, 1);
    else
        printf("Erro ao posicionar navio vertical.\n");

    // Navio 3 - Diagonal ↘ em (0,6)
    if (podePosicionar(tabuleiro, 0, 6, 2))
        posicionarNavio(tabuleiro, 0, 6, 2);
    else
        printf("Erro ao posicionar navio diagonal ↘.\n");

    // Navio 4 - Diagonal ↙ em (0,9)
    if (podePosicionar(tabuleiro, 0, 9, 3))
        posicionarNavio(tabuleiro, 0, 9, 3);
    else
        printf("Erro ao posicionar navio diagonal ↙.\n");

    exibirTabuleiro(tabuleiro);

    return 0;
}