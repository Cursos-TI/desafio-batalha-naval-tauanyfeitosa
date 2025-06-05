#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

/*
 * Programa em C para posicionar dois navios de tamanho 3 em um tabuleiro 10x10
 * (Batalha Naval simplificado) e exibir as coordenadas ocupadas pelos navios.
 *
 * - O tabuleiro é representado por uma matriz 10x10, inicializada com 0 (água).
 * - Dois navios de tamanho fixo 3:
 *     * Um navio posicionado horizontalmente.
 *     * Outro navio posicionado verticalmente.
 * - As partes dos navios são marcadas com o valor 3 na matriz.
 * - Coordenadas de cada parte dos navios são exibidas no console.
 */

#define TAMANHO_NAVIO 3
#define LINHAS 10
#define COLUNAS 10

int main() {
    // Declaração e inicialização do tabuleiro (inicia todas as posições com 0)
    int tabuleiro[LINHAS][COLUNAS];
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0;  // 0 representa água
        }
    }

    // Vetores que representam cada navio (todos os valores = 3)
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO]   = {3, 3, 3};

    /*
     * Definição das coordenadas iniciais (linha e coluna) de cada navio.
     * Em C, índices de matriz vão de 0 a 9 para um tabuleiro 10x10.
     *
     * - navioHorizontal: mesma linha, colunas em sequência.
     *   Exemplo de início em (2,3) ⇒ ocupa (2,3), (2,4), (2,5).
     *
     * - navioVertical: mesma coluna, linhas em sequência.
     *   Exemplo de início em (5,6) ⇒ ocupa (5,6), (6,6), (7,6).
     */
    int startLinhaHorizontal = 2;
    int startColunaHorizontal = 3;

    int startLinhaVertical = 5;
    int startColunaVertical = 6;

    // Validações de limites dos navios
    if (startColunaHorizontal < 0 || startColunaHorizontal + TAMANHO_NAVIO > COLUNAS) {
        printf("Erro: Navio horizontal excede limites do tabuleiro.\n");
        return 1;
    }
    if (startLinhaHorizontal < 0 || startLinhaHorizontal >= LINHAS) {
        printf("Erro: Linha inicial do navio horizontal inválida.\n");
        return 1;
    }
    if (startLinhaVertical < 0 || startLinhaVertical + TAMANHO_NAVIO > LINHAS) {
        printf("Erro: Navio vertical excede limites do tabuleiro.\n");
        return 1;
    }
    if (startColunaVertical < 0 || startColunaVertical >= COLUNAS) {
        printf("Erro: Coluna inicial do navio vertical inválida.\n");
        return 1;
    }

    // Verificar sobreposição antes de posicionar
    for (int offset = 0; offset < TAMANHO_NAVIO; offset++) {
        int linH = startLinhaHorizontal;
        int colH = startColunaHorizontal + offset;
        if (tabuleiro[linH][colH] != 0) {
            printf("Erro: Sobreposição ao posicionar navio horizontal em (%d,%d).\n", linH, colH);
            return 1;
        }
    }
    for (int offset = 0; offset < TAMANHO_NAVIO; offset++) {
        int linV = startLinhaVertical + offset;
        int colV = startColunaVertical;
        if (tabuleiro[linV][colV] != 0) {
            printf("Erro: Sobreposição ao posicionar navio vertical em (%d,%d).\n", linV, colV);
            return 1;
        }
    }

    // Posicionar navio horizontal na matriz e exibir suas coordenadas
    printf("Navio Horizontal (tamanho %d) ocupa:\n", TAMANHO_NAVIO);
    for (int offset = 0; offset < TAMANHO_NAVIO; offset++) {
        int lin = startLinhaHorizontal;
        int col = startColunaHorizontal + offset;
        tabuleiro[lin][col] = navioHorizontal[offset];
        printf("  (%d, %d)\n", lin, col);
    }

    // Posicionar navio vertical na matriz e exibir suas coordenadas
    printf("Navio Vertical (tamanho %d) ocupa:\n", TAMANHO_NAVIO);
    for (int offset = 0; offset < TAMANHO_NAVIO; offset++) {
        int lin = startLinhaVertical + offset;
        int col = startColunaVertical;
        tabuleiro[lin][col] = navioVertical[offset];
        printf("  (%d, %d)\n", lin, col);
    }

    // Exibição completa do tabuleiro (opcional, apenas para visualização)
    printf("\nTabuleiro 10x10 (0 = água, 3 = navio):\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
