#include <stdio.h>
#include <string.h>

// Estrutura da Carta
typedef struct {
    char estado;
    char codigo[4];
    char nomecidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Limpar buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Calcular densidade populacional
float calcularDensidade(unsigned long int populacao, float area) {
    return (float)populacao / area;
}

// Calcular PIB per capita
float calcularPIBPerCapita(float pib, unsigned long int populacao) {
    return (pib * 1000000000.0f) / (float)populacao;
}

int main() {
    Carta carta1, carta2;

    // ===== Entrada Carta 1 =====
    printf("=== Cadastro da carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);
    limparBuffer();
    printf("Código: ");
    scanf("%3s", carta1.codigo);
    limparBuffer();
    printf("Nome da cidade: ");
    fgets(carta1.nomecidade, sizeof(carta1.nomecidade), stdin);
    carta1.nomecidade[strcspn(carta1.nomecidade, "\n")] = '\0';
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // ===== Entrada Carta 2 =====
    printf("\n=== Cadastro da carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    limparBuffer();
    printf("Código: ");
    scanf("%3s", carta2.codigo);
    limparBuffer();
    printf("Nome da cidade: ");
    fgets(carta2.nomecidade, sizeof(carta2.nomecidade), stdin);
    carta2.nomecidade[strcspn(carta2.nomecidade, "\n")] = '\0';
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculos
    carta1.densidadePopulacional = calcularDensidade(carta1.populacao, carta1.area);
    carta2.densidadePopulacional = calcularDensidade(carta2.populacao, carta2.area);

    carta1.pibPerCapita = calcularPIBPerCapita(carta1.pib, carta1.populacao);
    carta2.pibPerCapita = calcularPIBPerCapita(carta2.pib, carta2.populacao);

    // ===== Comparação escolhida =====
    // Aqui você escolhe qual atributo comparar
    // Exemplo: População (maior vence)
    printf("\nComparação de cartas (Atributo: População)\n");
    printf("Carta 1 - %s (%c): %lu\n", carta1.nomecidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%c): %lu\n", carta2.nomecidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomecidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomecidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
