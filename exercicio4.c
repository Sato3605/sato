/*
 * Exercicio 4 - Busca binaria mostrando os descartes
 * A cada divisao do vetor, mostra quantos elementos foram descartados.
 *
 * Elementos ainda em jogo = fim - inicio + 1
 * Descartados na divisao  = em jogo antes - em jogo depois
 */

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

void bubbleSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int emJogoAntes = fim - inicio + 1;

        if (vetor[meio] == valor) {
            return meio;
        } else if (valor < vetor[meio]) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }

        /* se inicio passou de fim, nao sobrou nenhum elemento */
        int emJogoDepois = (inicio <= fim) ? (fim - inicio + 1) : 0;
        printf("Divisão: %d elementos descartados (restam %d)\n",
               emJogoAntes - emJogoDepois, emJogoDepois);
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
