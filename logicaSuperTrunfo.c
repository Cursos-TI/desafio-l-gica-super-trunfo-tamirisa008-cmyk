#include <stdio.h>
#include <string.h>

// =============================================
// SUPER TRUNFO - DESAFIO NÍVEL AVENTUREIRO
// =============================================
// - Cadastro de 2 cartas (países)
// - Menu interativo com switch
// - Comparação de atributos usando if-else
// - Regra especial: Densidade Demográfica vence o MENOR valor
// =============================================

// Estrutura da Carta
typedef struct {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade; // populacao / area
} Carta;

int main() {
    Carta c1, c2;
    int opcao;

    // ===== Cadastro da primeira carta =====
    printf("Digite o nome do 1º país: ");
    scanf(" %[^\n]", c1.nomePais);
    printf("População: ");
    scanf("%d", &c1.populacao);
    printf("Área (km²): ");
    scanf("%f", &c1.area);
    printf("PIB (em bilhões US$): ");
    scanf("%f", &c1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &c1.pontosTuristicos);
    c1.densidade = c1.populacao / c1.area;

    // ===== Cadastro da segunda carta =====
    printf("\nDigite o nome do 2º país: ");
    scanf(" %[^\n]", c2.nomePais);
    printf("População: ");
    scanf("%d", &c2.populacao);
    printf("Área (km²): ");
    scanf("%f", &c2.area);
    printf("PIB (em bilhões US$): ");
    scanf("%f", &c2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &c2.pontosTuristicos);
    c2.densidade = c2.populacao / c2.area;

    // ===== Menu Interativo =====
    printf("\n===== SUPER TRUNFO - NÍVEL AVENTUREIRO =====\n");
    printf("Comparando cartas:\n");
    printf("Carta 1: %s\n", c1.nomePais);
    printf("Carta 2: %s\n\n", c2.nomePais);

    printf("Escolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    // ===== Comparação usando switch + if-else =====
    printf("\n=================================\n");
    switch (opcao) {
        case 1: // População
            printf("Comparando POPULAÇÃO:\n");
            printf("%s: %d habitantes\n", c1.nomePais, c1.populacao);
            printf("%s: %d habitantes\n", c2.nomePais, c2.populacao);
            if (c1.populacao > c2.populacao)
                printf("Vencedor: %s\n", c1.nomePais);
            else if (c2.populacao > c1.populacao)
                printf("Vencedor: %s\n", c2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 2: // Área
            printf("Comparando ÁREA:\n");
            printf("%s: %.2f km²\n", c1.nomePais, c1.area);
            printf("%s: %.2f km²\n", c2.nomePais, c2.area);
            if (c1.area > c2.area)
                printf("Vencedor: %s\n", c1.nomePais);
            else if (c2.area > c1.area)
                printf("Vencedor: %s\n", c2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 3: // PIB
            printf("Comparando PIB:\n");
            printf("%s: %.2f bilhões US$\n", c1.nomePais, c1.pib);
            printf("%s: %.2f bilhões US$\n", c2.nomePais, c2.pib);
            if (c1.pib > c2.pib)
                printf("Vencedor: %s\n", c1.nomePais);
            else if (c2.pib > c1.pib)
                printf("Vencedor: %s\n", c2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Comparando PONTOS TURÍSTICOS:\n");
            printf("%s: %d pontos\n", c1.nomePais, c1.pontosTuristicos);
            printf("%s: %d pontos\n", c2.nomePais, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Vencedor: %s\n", c1.nomePais);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Vencedor: %s\n", c2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 5: // Densidade Demográfica (vence menor)
            printf("Comparando DENSIDADE DEMOGRÁFICA (vence MENOR valor):\n");
            printf("%s: %.2f hab/km²\n", c1.nomePais, c1.densidade);
            printf("%s: %.2f hab/km²\n", c2.nomePais, c2.densidade);
            if (c1.densidade < c2.densidade)
                printf("Vencedor: %s\n", c1.nomePais);
            else if (c2.densidade < c1.densidade)
                printf("Vencedor: %s\n", c2.nomePais);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }

    printf("=================================\n");

    return 0;
}