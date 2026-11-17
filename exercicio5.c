/*Dado o vetor ordenado A = {1, 5, 6, 7, 12, 17, 22, 45, 65, 98, 100, 120, 150, 200, 231}, mostre passo a
passo a pesquisa binária pelo elemento 100. Quantas comparações foram feitas? E se a pesquisa fosse
seqüencial, quantas comparações seriam feitas?

 * Exercicio 5 - Pesquisa binaria passo a passo pelo elemento 100
 * A = {1, 5, 6, 7, 12, 17, 22, 45, 65, 98, 100, 120, 150, 200, 231}
 *
 * Resposta esperada:
 *   Passo | inicio | fim | meio | A[meio] | decisao
 *     1   |   0    | 14  |  7   |   45    | 100 > 45  -> direita
 *     2   |   8    | 14  |  11  |   120   | 100 < 120 -> esquerda
 *     3   |   8    | 10  |  9   |   98    | 100 > 98  -> direita
 *     4   |   10   | 10  |  10  |   100   | encontrado
 *   Binaria: 4 comparacoes | Sequencial: 11 comparacoes
 *
 * Este programa imprime esses passos para conferir.
 */

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

/* Busca binaria que imprime cada passo e retorna o numero de comparacoes */
int buscaBinariaPassoAPasso(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    int comparacoes = 0;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoes++;

        printf("Passo %d: inicio=%d fim=%d meio=%d -> A[%d]=%d\n",
               comparacoes, inicio, fim, meio, meio, vetor[meio]);

        if (vetor[meio] == valor) {
            printf("  %d == %d -> encontrado na posição %d\n", valor, vetor[meio], meio);
            return comparacoes;
        } else if (valor < vetor[meio]) {
            printf("  %d < %d -> continua pela esquerda\n", valor, vetor[meio]);
            fim = meio - 1;
        } else {
            printf("  %d > %d -> continua pela direita\n", valor, vetor[meio]);
            inicio = meio + 1;
        }
    }
    printf("Valor não encontrado\n");
    return comparacoes;
}

/* Busca sequencial que conta quantas comparacoes foram feitas */
int buscaSequencialComparacoes(int vetor[], int tamanho, int valor) {
    int comparacoes = 0;
    for (int i = 0; i < tamanho; i++) {
        comparacoes++;
        if (vetor[i] == valor) {
            break;
        }
    }
    return comparacoes;
}

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    int A[15] = {1, 5, 6, 7, 12, 17, 22, 45, 65, 98, 100, 120, 150, 200, 231};

    printf("--- Pesquisa binária pelo 100 ---\n");
    int compBin = buscaBinariaPassoAPasso(A, 15, 100);

    int compSeq = buscaSequencialComparacoes(A, 15, 100);

    printf("\nComparações na busca binária:    %d\n", compBin);
    printf("Comparações na busca sequencial: %d\n", compSeq);

    return 0;
}
