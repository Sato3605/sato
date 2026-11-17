# Exercícios: Busca e Ordenação em C

## Arquivos

| Arquivo | Conteúdo |
|---|---|
| `exercicio1.c` | Busca sequencial (primeira ocorrência) |
| `exercicio2.c` | Busca sequencial com valores repetidos (todas as posições) |
| `exercicio3.c` | Busca binária + Bubble Sort |
| `exercicio4.c` | Busca binária mostrando quantos elementos são descartados |
| `exercicio5.c` | Pesquisa binária passo a passo pelo 100 |
| Exercícios 6 e 7 | Teóricos, respondidos neste README |

## Como compilar e rodar

```
gcc -Wall -Wextra exercicio1.c -o exercicio1.exe
exercicio1.exe
```

`-Wall -Wextra` mostra avisos de erros comuns (variável não inicializada, `printf` com formato errado...).

---

## Busca sequencial

- Olha **um elemento por vez**, do início ao fim.
- Funciona com vetor **desordenado**.
- **Melhor caso:** 1 comparação (valor na primeira posição).
- **Pior caso:** n comparações (valor na última posição **ou não existe**).
- Complexidade: **O(n)**.

```c
for (int i = 0; i < tamanho; i++) {
    if (vetor[i] == valor) return i;   // return para na 1ª ocorrência
}
return -1;                              // -1 = "não achei"
```

**Para achar todas as ocorrências (Ex. 2):** tire o `return` de dentro do `for`, use um **contador** e só diga "não encontrado" **depois** do `for`. Essa versão sempre faz n comparações.

---

## Busca binária

- **Exige vetor ordenado.** Se o vetor estiver desordenado, o programa não dá erro, mas pode dizer "não encontrado" mesmo com o valor no vetor.
- Olha o **meio** e descarta **metade** a cada passo.
- Complexidade: **O(log n)**.
- Máximo de comparações: `piso(log2(n)) + 1` → 15 elementos: 4 | 31 elementos: 5.

### As 3 linhas que precisa saber de cor

```c
while (inicio <= fim) {                  // 1
    int meio = (inicio + fim) / 2;       // 2
    if (vetor[meio] == valor) return meio;
    else if (valor < vetor[meio]) fim = meio - 1;     // 3
    else inicio = meio + 1;
}
return -1;
```

1. **`inicio <= fim`, com `<=` e não `<`**: quando `inicio == fim` ainda sobra **1 elemento** pra testar.
2. **`(inicio + fim) / 2`**: divisão de `int` **corta a parte decimal** → `(4 + 9) / 2 = 6`, não 6,5.
3. **`meio - 1` e `meio + 1`**: o meio **já foi testado**, então ele sai junto. Com `inicio = meio`, o programa pode entrar em **loop infinito**.

### Direção (crescente)

- Valor **menor** que o meio → **ESQUERDA** (`fim = meio - 1`)
- Valor **maior** que o meio → **DIREITA** (`inicio = meio + 1`)

### Contar descartados (Ex. 4)

- Elementos em jogo: `fim - inicio + 1`
- Descartados = em jogo antes − em jogo depois

---

## Métodos de ordenação

Os três são **O(n²)**.

| Método | Palavra-chave | O que faz |
|---|---|---|
| **Bubble Sort** | vizinhos | Compara e troca **pares vizinhos**. O maior vai pro fim a cada passada. |
| **Selection Sort** | menor | **Acha o menor** do restante e coloca na posição atual. |
| **Insertion Sort** | encaixar | Pega o próximo e **encaixa** na parte já ordenada (como cartas na mão). |

Exemplo com `{5, 3, 8, 1}`:
- **Bubble**, 1ª passada: `{3, 5, 1, 8}` → o 8 foi pro fim.
- **Selection**, 1º passo: `{1, 3, 8, 5}` → o menor (1) foi pra frente.
- **Insertion**, 1º passo: `{3, 5, 8, 1}` → o 3 foi encaixado antes do 5.

**Vetor passado pra função não é copiado**: a função altera o vetor original, por isso o `bubbleSort` pode ser `void`. Já um `int` comum **é copiado**.

---

## Respostas dos exercícios teóricos

### Exercício 5

`A = {1, 5, 6, 7, 12, 17, 22, 45, 65, 98, 100, 120, 150, 200, 231}`, procurando o **100**:

| Passo | inicio | fim | meio | A[meio] | Decisão |
|---|---|---|---|---|---|
| 1 | 0 | 14 | 7 | 45 | 100 > 45 → direita |
| 2 | 8 | 14 | 11 | 120 | 100 < 120 → esquerda |
| 3 | 8 | 10 | 9 | 98 | 100 > 98 → direita |
| 4 | 10 | 10 | 10 | 100 | encontrado |

- **Binária: 4 comparações.**
- **Sequencial: 11 comparações** (o 100 está no índice 10, então olha os índices de 0 a 10).

### Exercício 6: **VERDADEIRA**

Com 15 elementos:
- **Mínimo 1:** o valor está logo no meio.
- **Máximo 4:** cada passo reduz os elementos em jogo, 15 → 7 → 3 → 1.

### Exercício 7: **FALSA**

É o contrário. Em ordem crescente, os menores ficam à esquerda. Se o valor é **menor** que o meio, a busca continua pela **esquerda**. Se é maior, pela direita.

---

## Erros que cometi no quiz (revisar!)

- **Pior caso da sequencial é n**, não n/2. n/2 é o caso médio.
- **`meio` usa divisão inteira**: `13 / 2 = 6`.
- **`inicio = meio + 1`**, nunca `inicio = meio`.
- **`while (inicio <= fim)`**: compara posições, e precisa do `<=`.
- **Bubble = vizinhos**, Selection = menor, Insertion = encaixar.
