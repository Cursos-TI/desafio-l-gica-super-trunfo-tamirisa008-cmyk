#include <stdio.h>
#include <string.h>

// =============================================
// SUPER TRUNFO - NÍVEL MESTRE
// Comparações Avançadas com Dois Atributos
// =============================================

typedef struct {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade; // populacao / area
} Carta;

// Função para exibir menu de atributos, removendo a opção já escolhida
void exibirMenu(int ignorar) {
    printf("\nEscolha o atributo para comparação:\n");
    if(ignorar != 1) printf("1 - População\n");
    if(ignorar != 2) printf("2 - Área\n");
    if(ignorar != 3) printf("3 - PIB\n");
    if(ignorar != 4) printf("4 - Pontos Turísticos\n");
    if(ignorar != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
}

// Função para pegar o valor do atributo escolhido
float valorAtributo(Carta c, int atributo) {
    switch(atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidade;
        default: return 0;
    }
}

// Função para imprimir o nome do atributo
void nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica"); break;
    }
}

// Função que decide o vencedor de um atributo
int vencedorAtributo(Carta c1, Carta c2, int atributo) {
    float v1 = valorAtributo(c1, atributo);
    float v2 = valorAtributo(c2, atributo);
    if(atributo == 5) { // densidade, vence menor
        return (v1 < v2) ? 1 : (v2 < v1 ? 2 : 0);
    } else { // demais atributos, vence maior
        return (v1 > v2) ? 1 : (v2 > v1 ? 2 : 0);
    }
}

int main() {
    Carta c1, c2;
    int attr1, attr2;

    // ===== Cadastro das cartas =====
    printf("Digite o nome do 1º país:\n");
    scanf(" %[^\n]", c1.nomePais);
    printf("População:\n");
    scanf("%d", &c1.populacao);
    printf("Área (km²):\n");
    scanf("%f", &c1.area);
    printf("PIB (em bilhões US$):\n");
    scanf("%f", &c1.pib);
    printf("Número de pontos turísticos:\n");
    scanf("%d", &c1.pontosTuristicos);
    c1.densidade = c1.populacao / c1.area;

    printf("\nDigite o nome do 2º país:\n");
    scanf(" %[^\n]", c2.nomePais);
    printf("População:\n");
    scanf("%d", &c2.populacao);
    printf("Área (km²):\n");
    scanf("%f", &c2.area);
    printf("PIB (em bilhões US$):\n");
    scanf("%f", &c2.pib);
    printf("Número de pontos turísticos:\n");
    scanf("%d", &c2.pontosTuristicos);
    c2.densidade = c2.populacao / c2.area;

    // ===== Menu para escolha dos atributos =====
    printf("\n===== SUPER TRUNFO - NÍVEL MESTRE =====\n");
    printf("Cartas: %s x %s\n", c1.nomePais, c2.nomePais);

    // Primeiro atributo
    exibirMenu(0);
    scanf("%d", &attr1);
    while(attr1 < 1 || attr1 > 5) {
        printf("Opção inválida! Tente novamente.\n");
        exibirMenu(0);
        scanf("%d", &attr1);
    }

    // Segundo atributo
    exibirMenu(attr1);
    scanf("%d", &attr2);
    while(attr2 < 1 || attr2 > 5 || attr2 == attr1) {
        printf("Opção inválida ou repetida! Tente novamente.\n");
        exibirMenu(attr1);
        scanf("%d", &attr2);
    }

    // ===== Comparação individual =====
    printf("\n=========================================\n");
    printf("Comparando cartas: %s x %s\n", c1.nomePais, c2.nomePais);
    printf("Atributos escolhidos: ");
    nomeAtributo(attr1);
    printf(" e ");
    nomeAtributo(attr2);
    printf("\n\n");

    int v1 = vencedorAtributo(c1, c2, attr1);
    int v2 = vencedorAtributo(c1, c2, attr2);

    // Mostrar resultados de cada atributo
    printf("%s:\n", (attr1 == 1 ? "População" : attr1 == 2 ? "Área" : attr1 == 3 ? "PIB" : attr1 == 4 ? "Pontos Turísticos" : "Densidade Demográfica"));
    printf("- %s: %.2f\n", c1.nomePais, valorAtributo(c1, attr1));
    printf("- %s: %.2f\n", c2.nomePais, valorAtributo(c2, attr1));
    printf("Vencedor no atributo: %s\n\n", v1 == 1 ? c1.nomePais : v1 == 2 ? c2.nomePais : "Empate");

    printf("%s:\n", (attr2 == 1 ? "População" : attr2 == 2 ? "Área" : attr2 == 3 ? "PIB" : attr2 == 4 ? "Pontos Turísticos" : "Densidade Demográfica"));
    printf("- %s: %.2f\n", c1.nomePais, valorAtributo(c1, attr2));
    printf("- %s: %.2f\n", c2.nomePais, valorAtributo(c2, attr2));
    printf("Vencedor no atributo: %s\n\n", v2 == 1 ? c1.nomePais : v2 == 2 ? c2.nomePais : "Empate");

    // ===== Soma dos atributos =====
    float soma1 = valorAtributo(c1, attr1) + valorAtributo(c1, attr2);
    float soma2 = valorAtributo(c2, attr1) + valorAtributo(c2, attr2);

    printf("SOMA FINAL:\n");
    printf("- %s: %.2f\n", c1.nomePais, soma1);
    printf("- %s: %.2f\n", c2.nomePais, soma2);

    printf(">>> VENCEDOR: %s\n", soma1 > soma2 ? c1.nomePais : soma2 > soma1 ? c2.nomePais : "EMPATE");
    printf("=========================================\n");

    return 0;
}