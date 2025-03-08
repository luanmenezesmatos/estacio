#include <stdio.h>
#include <string.h>

#define NUM_CARTAS 2
#define NUM_ATRIBUTOS 5

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int expectativa_vida;
    float densidade_demografica;
} Carta;

void exibir_opcoes() {
    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Expectativa de Vida\n");
    printf("5 - Densidade Demográfica\n");
}

int escolher_atributo(int escolhido) {
    int opcao;
    do {
        printf("Digite o número do atributo: ");
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > NUM_ATRIBUTOS || opcao == escolhido) {
            printf("Opção inválida ou já escolhida. Tente novamente.\n");
        }
    } while (opcao < 1 || opcao > NUM_ATRIBUTOS || opcao == escolhido);
    return opcao;
}

float obter_valor_atributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.expectativa_vida;
        case 5: return c.densidade_demografica;
        default: return 0;
    }
}

void determinar_vencedor(Carta c1, Carta c2, int atributo1, int atributo2) {
    float valor1_c1 = obter_valor_atributo(c1, atributo1);
    float valor1_c2 = obter_valor_atributo(c2, atributo1);
    float valor2_c1 = obter_valor_atributo(c1, atributo2);
    float valor2_c2 = obter_valor_atributo(c2, atributo2);

    int pontos_c1 = 0, pontos_c2 = 0;

    if (atributo1 == 5) {
        pontos_c1 += (valor1_c1 < valor1_c2) ? 1 : 0;
        pontos_c2 += (valor1_c2 < valor1_c1) ? 1 : 0;
    } else {
        pontos_c1 += (valor1_c1 > valor1_c2) ? 1 : 0;
        pontos_c2 += (valor1_c2 > valor1_c1) ? 1 : 0;
    }

    if (atributo2 == 5) {
        pontos_c1 += (valor2_c1 < valor2_c2) ? 1 : 0;
        pontos_c2 += (valor2_c2 < valor2_c1) ? 1 : 0;
    } else {
        pontos_c1 += (valor2_c1 > valor2_c2) ? 1 : 0;
        pontos_c2 += (valor2_c2 > valor2_c1) ? 1 : 0;
    }

    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    printf("\nResultado:\n");
    printf("%s: %0.2f + %0.2f = %0.2f pontos\n", c1.nome, valor1_c1, valor2_c1, soma_c1);
    printf("%s: %0.2f + %0.2f = %0.2f pontos\n", c2.nome, valor1_c2, valor2_c2, soma_c2);

    if (soma_c1 > soma_c2) {
        printf("%s venceu!\n", c1.nome);
    } else if (soma_c2 > soma_c1) {
        printf("%s venceu!\n", c2.nome);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    Carta cartas[NUM_CARTAS] = {
        {"Brasil", 214000000, 8515767, 1.8, 75, 25.1},
        {"Argentina", 45100000, 2780400, 0.5, 77, 16.2}
    };

    printf("Bem-vindo ao Super Trunfo de Países!\n");

    exibir_opcoes();
    int atributo1 = escolher_atributo(-1);
    printf("\nAtributo 1 escolhido. Agora escolha outro atributo:\n");
    exibir_opcoes();
    int atributo2 = escolher_atributo(atributo1);

    determinar_vencedor(cartas[0], cartas[1], atributo1, atributo2);

    return 0;
}
