# Super Trunfo de Países - Comparação Avançada

Este é o desafio final do Super Trunfo! Aqui, você poderá comparar cartas de países com base em dois atributos escolhidos dinamicamente.

## 📌 Funcionalidades
- Permite que o jogador escolha **dois atributos diferentes** para comparar.
- Implementa regras especiais para **densidade demográfica** (menor valor vence).
- Calcula a **soma dos atributos** para determinar o vencedor.
- Garante **menus interativos dinâmicos** usando `switch`.
- Trata **empates** corretamente.

---

## 🛠️ Como Compilar e Executar

### ✅ Requisitos:
- Um compilador C (ex: `gcc`)
- Terminal ou prompt de comando

### 🔧 Compilar o código:
```bash
gcc super_trunfo.c -o super_trunfo
```

### ▶️ Executar o programa:
```bash
./super_trunfo
```

---

## 🎮 Exemplo de Uso

### Passo 1: Escolha o primeiro atributo
```bash
Escolha um atributo para comparar:
1 - População
2 - Área
3 - PIB
4 - Expectativa de Vida
5 - Densidade Demográfica
Digite o número do atributo: 3
```

### Passo 2: Escolha o segundo atributo (diferente do primeiro)
```bash
Escolha um atributo para comparar:
1 - População
2 - Área
3 - PIB (Já escolhido - não disponível)
4 - Expectativa de Vida
5 - Densidade Demográfica
Digite o número do atributo: 5
```

### Passo 3: Resultado da comparação
```bash
Resultado:
Brasil: 1.80 + 25.10 = 26.90 pontos
Argentina: 0.50 + 16.20 = 16.70 pontos
Brasil venceu!
```