#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se o navio pode ser posicionado
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    // Orientação: 0 = horizontal, 1 = vertical

    if (orientacao == 0) {
        // Verifica se ultrapassa os limites
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0)
                return 0; // Já tem navio
        }
    } else {
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0)
                return 0;
        }
    }

    return 1;
}

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 0) {
            tabuleiro[linha][coluna + i] = 3;
        } else {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas para o navio horizontal (linha, coluna)
    int linhaH = 2, colunaH = 4;

    // Coordenadas para o navio vertical (linha, coluna)
    int linhaV = 5, colunaV = 6;

    // Verifica e posiciona navio horizontal
    if (podePosicionarNavio(tabuleiro, linhaH, colunaH, 0)) {
        posicionarNavio(tabuleiro, linhaH, colunaH, 0);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
        return 1;
    }

    // Verifica e posiciona navio vertical
    if (podePosicionarNavio(tabuleiro, linhaV, colunaV, 1)) {
        posicionarNavio(tabuleiro, linhaV, colunaV, 1);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
        return 1;
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}