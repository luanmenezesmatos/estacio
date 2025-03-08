# Documentação do Projeto: Batalha de Cartas - Super Trunfo

## 1. Introdução
Este projeto implementa um jogo de batalha de cartas no estilo **Super Trunfo** utilizando a linguagem C. O jogo permite cadastrar duas cartas e compará-las atributo por atributo para determinar a vencedora.

## 2. Estrutura do Código
O programa é composto pelas seguintes seções principais:
- Definição da estrutura `Carta`
- Função `calcular_atributos`
- Função `ler_carta`
- Função `comparar_cartas`
- Função `main`

## 3. Estrutura de Dados
A estrutura `Carta` armazena as informações de cada carta, incluindo:

```c
typedef struct {
    char estado[50];  // Nome do estado
    int codigo;  // Código único da carta
    char nome[50];  // Nome da cidade
    unsigned long int populacao;  // População da cidade
    float area;  // Área total da cidade (km²)
    float pib;  // Produto Interno Bruto (PIB) da cidade
    int pontos_turisticos;  // Número de pontos turísticos
    float densidade_populacional;  // Densidade populacional calculada
    float pib_per_capita;  // PIB per capita calculado
    float super_poder;  // Super poder da carta
} Carta;
```

## 4. Funcionalidades

### 4.1 Cálculo dos Atributos (`calcular_atributos`)
Essa função recebe uma carta e calcula os seguintes valores:
- **Densidade populacional**: `população / área`
- **PIB per capita**: `PIB / população`
- **Super Poder**: Soma de todos os atributos mais `(1 / densidade_populacional)`, garantindo que cidades menos densas tenham mais vantagem.

```c
void calcular_atributos(Carta *c) {
    if (c->area > 0) {
        c->densidade_populacional = c->populacao / c->area;
    } else {
        c->densidade_populacional = 0;
    }
    if (c->populacao > 0) {
        c->pib_per_capita = c->pib / c->populacao;
    } else {
        c->pib_per_capita = 0;
    }
    if (c->densidade_populacional > 0) {
        c->super_poder = c->populacao + c->area + c->pib + c->pontos_turisticos + c->pib_per_capita + (1 / c->densidade_populacional);
    } else {
        c->super_poder = c->populacao + c->area + c->pib + c->pontos_turisticos + c->pib_per_capita;
    }
}
```

### 4.2 Entrada de Dados (`ler_carta`)
A função `ler_carta` recebe os dados de entrada do usuário e preenche a estrutura `Carta`. Após a entrada dos valores, a função `calcular_atributos` é chamada para calcular os valores derivados.

```c
void ler_carta(Carta *c) {
    printf("Digite o nome do estado: ");
    scanf(" %49[^\n]", c->estado);
    printf("Digite o código da carta: ");
    scanf("%d", &c->codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]", c->nome);
    printf("Digite a população: ");
    scanf("%lu", &c->populacao);
    printf("Digite a área em km²: ");
    scanf("%f", &c->area);
    printf("Digite o PIB: ");
    scanf("%f", &c->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontos_turisticos);
    
    calcular_atributos(c);
}
```

### 4.3 Comparação das Cartas (`comparar_cartas`)
Essa função compara duas cartas e determina qual delas vence em cada um dos atributos.

```c
void comparar_cartas(Carta c1, Carta c2) {
    printf("\nComparação de Cartas:\n");
    printf("População: Carta %d venceu (%d)\n", c1.populacao > c2.populacao ? 1 : 2, c1.populacao > c2.populacao);
    printf("Área: Carta %d venceu (%d)\n", c1.area > c2.area ? 1 : 2, c1.area > c2.area);
    printf("PIB: Carta %d venceu (%d)\n", c1.pib > c2.pib ? 1 : 2, c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos ? 1 : 2, c1.pontos_turisticos > c2.pontos_turisticos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", c1.densidade_populacional < c2.densidade_populacional ? 1 : 2, c1.densidade_populacional < c2.densidade_populacional);
    printf("PIB per Capita: Carta %d venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita ? 1 : 2, c1.pib_per_capita > c2.pib_per_capita);
    printf("Super Poder: Carta %d venceu (%d)\n", c1.super_poder > c2.super_poder ? 1 : 2, c1.super_poder > c2.super_poder);
}
```

### 4.4 Função Principal (`main`)
A função `main` executa o fluxo principal do programa:
1. Solicita os dados das duas cartas.
2. Realiza a comparação entre elas.
3. Exibe os resultados.

```c
int main() {
    Carta carta1, carta2;
    
    printf("Cadastro da Carta 1:\n");
    ler_carta(&carta1);
    printf("\nCadastro da Carta 2:\n");
    ler_carta(&carta2);
    
    comparar_cartas(carta1, carta2);
    
    return 0;
}
```

## 5. Conclusão
Este projeto implementa um sistema simples e eficiente para comparar cartas de Super Trunfo baseadas em atributos de cidades. Ele serve como um ótimo exercício de manipulação de estruturas em C e aplicação de lógica condicional para comparações de atributos.