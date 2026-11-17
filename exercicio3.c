/*
 * Exercicio 3 - Busca binaria
 * Vetor de 15 elementos. Como a busca binaria EXIGE vetor ordenado,
 * o vetor e ordenado com Bubble Sort antes da busca.
 *
 * Ideia: olhar o elemento do MEIO e descartar metade a cada passo.
 *   valor == vetor[meio] -> achou
 *   valor <  vetor[meio] -> continua pela ESQUERDA (fim = meio - 1)
 *   valor >  vetor[meio] -> continua pela DIREITA  (inicio = meio + 1)
 * Complexidade: O(log n)
 */

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

/* Bubble Sort: compara vizinhos e troca se estiverem fora de ordem.
 * A cada passada, o maior elemento vai para o final.
 * O vetor nao e copiado ao ser passado para a funcao, entao ela
 * ordena o vetor original (por isso e void). */
void bubbleSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {   /* ultimos i ja estao no lugar */
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

/* Retorna a posicao do valor ou -1 se nao encontrar */
int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {                 /* <= : quando inicio == fim ainda sobra 1 elemento */
        int meio = (inicio + fim) / 2;      /* divisao inteira: corta a parte decimal */

        if (vetor[meio] == valor) {
            return meio;
        } else if (valor < vetor[meio]) {
            fim = meio - 1;                 /* descarta o meio e tudo a direita */
        } else {
            inicio = meio + 1;              /* descarta o meio e tudo a esquerda */
        }
    }
    return -1;
}

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    int vetor[15] = {45, 12, 7, 98, 1, 200, 22, 65, 5, 150, 17, 231, 6, 120, 100};
    int valor;

    bubbleSort(vetor, 15);

    printf("Vetor ordenado: ");
    for (int i = 0; i < 15; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Digite o valor a buscar: ");
    scanf("%d", &valor);

    int pos = buscaBinaria(vetor, 15, valor);

    if (pos != -1) {
        printf("Valor %d encontrado na posição %d\n", valor, pos);
    } else {
        printf("Valor não encontrado\n");
    }

    return 0;
}
