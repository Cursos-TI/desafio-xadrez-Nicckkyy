#include <stdio.h>

// Função recursiva para o movimento da Torre
void movimento_torre(int casas, char direcao) {
    if (casas == 0) {
        return; // Base case: não há mais casas para mover
    }

    // Imprime a direção do movimento
    switch (direcao) {
        case 'C': printf("Cima\n"); break;
        case 'B': printf("Baixo\n"); break;
        case 'E': printf("Esquerda\n"); break;
        case 'D': printf("Direita\n"); break;
        default: return; // Direção inválida
    }

    // Recursão: move uma casa e chama novamente para a próxima
    movimento_torre(casas - 1, direcao);
}

// Função recursiva para o movimento do Bispo com loops aninhados
void movimento_bispo(int casas_verticais, int casas_horizontais, int direcao_vertical, int direcao_horizontal) {
    if (casas_verticais == 0 || casas_horizontais == 0) {
        return; // Base case: não há mais casas para mover
    }

    // Move verticalmente
    if (direcao_vertical == 1) {
        printf("Cima\n");
    } else if (direcao_vertical == -1) {
        printf("Baixo\n");
    }

    // Move horizontalmente
    if (direcao_horizontal == 1) {
        printf("Direita\n");
    } else if (direcao_horizontal == -1) {
        printf("Esquerda\n");
    }

    // Recursão para o próximo movimento
    movimento_bispo(casas_verticais - 1, casas_horizontais - 1, direcao_vertical, direcao_horizontal);
}

// Função recursiva para o movimento da Rainha
void movimento_rainha(int casas, char direcao) {
    if (casas == 0) {
        return;
    }

    // Combina movimentos da Torre e Bispo
    if (direcao == 'C' || direcao == 'B') {
        movimento_torre(1, direcao);
    } else if (direcao == 'E' || direcao == 'D') {
        movimento_torre(1, direcao);
    } else {
        movimento_bispo(casas, casas, (direcao == 'C' ? 1 : -1), (direcao == 'D' ? 1 : -1));
    }

    movimento_rainha(casas - 1, direcao);
}

// Função com loops aninhados para o movimento do Cavalo (em "L")
void movimento_cavalo(int casas) {
    for (int i = 0; i < casas; i++) {
        for (int j = 0; j < 2; j++) {
            // Cima (duas casas) e direita (uma casa)
            if (j == 0) {
                printf("Cima\n");
                printf("Cima\n");
            } else {
                printf("Direita\n");
            }
        }
    }
}

int main() {
    int casas = 3; // Defina o número de casas para movimentar

    // Movimentos da Torre
    printf("Movimento da Torre:\n");
    movimento_torre(casas, 'C');  // Cima
    movimento_torre(casas, 'B');  // Baixo
    movimento_torre(casas, 'E');  // Esquerda
    movimento_torre(casas, 'D');  // Direita
    printf("\n");

    // Movimentos do Bispo
    printf("Movimento do Bispo:\n");
    movimento_bispo(casas, casas, 1, 1);  // Cima e Direita
    movimento_bispo(casas, casas, -1, -1);  // Baixo e Esquerda
    printf("\n");

    // Movimentos da Rainha
    printf("Movimento da Rainha:\n");
    movimento_rainha(casas, 'C');  // Cima
    movimento_rainha(casas, 'D');  // Direita
    printf("\n");

    // Movimentos do Cavalo
    printf("Movimento do Cavalo:\n");
    movimento_cavalo(casas);
    printf("\n");

    return 0;
}
