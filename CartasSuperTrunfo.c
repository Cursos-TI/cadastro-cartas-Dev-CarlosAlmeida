#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Cartas
// Tema 3 - Nível Mestre: Batalha das Cartas
// Objetivo: Comparar duas cartas utilizando atributos calculados e Super Poder.


// Estrutura da carta
// ---------------------------------------------------------------------
struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao; // agora unsigned long int
    float area;
    float pib;
    int pontosTuristicos;

    // Atributos calculados
    float densidadePop;
    float pibPerCapita;
    float superPoder;
};

// Função para calcular atributos derivados

void calcularAtributos(struct Carta *c) {
    c->densidadePop = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;

    // Super Poder = soma de todos os atributos numéricos
    // incluindo 1/densidade (quanto menor densidade, maior poder)

    c->superPoder =
        (float)c->populacao +
        c->area +
        c->pib +
        (float)c->pontosTuristicos +
        c->pibPerCapita +
        (1.0f / c->densidadePop);
}

// Função para comparar atributos e retornar 1 (carta1 vence) ou 0 (carta2 vence)

int compararMaior(float a, float b) {
    return a > b ? 1 : 0;
}

int compararMenor(float a, float b) { // para densidade populacional
    return a < b ? 1 : 0;
}

// Função para ler dados de uma carta

void lerCarta(struct Carta *c, int numero) {
    printf("\n=== Cadastro da Carta %d ===\n", numero);

    printf("Estado (A-H): ");
    scanf(" %c", &c->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", c->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", c->nomeCidade);

    printf("População: ");
    scanf("%lu", &c->populacao);

    printf("Área (km²): ");
    scanf("%f", &c->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &c->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c->pontosTuristicos);
}

int main() {

  // Área para definição das variáveis para armazenar as propriedades das cidades

    struct Carta carta1, carta2; //

  // Área para entrada de dados
    
    lerCarta(&carta1, 1);    
    lerCarta(&carta2, 2);   

    // Cálculo de densidade populacional, PIB per capita e Super Poder

    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    // Área para exibição dos dados da cidade

    printf("\n=== Comparação de Cartas ===\n");

    printf("População: Carta 1 venceu (%d)\n", compararMaior(carta1.populacao, carta2.populacao));
    printf("Área: Carta 1 venceu (%d)\n", compararMaior(carta1.area, carta2.area));
    printf("PIB: Carta 1 venceu (%d)\n", compararMaior(carta1.pib, carta2.pib));
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", compararMaior(carta1.pontosTuristicos, carta2.pontosTuristicos));
 
    // Densidade populacional: o menor vence

    printf("Densidade Populacional: Carta 1 venceu (%d)\n",
           compararMenor(carta1.densidadePop, carta2.densidadePop));

    printf("PIB per Capita: Carta 1 venceu (%d)\n",
           compararMaior(carta1.pibPerCapita, carta2.pibPerCapita));

    printf("Super Poder: Carta 1 venceu (%d)\n",
           compararMaior(carta1.superPoder, carta2.superPoder));

    
return 0;
} 
