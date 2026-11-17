/*
 * Exercicio 1 - Busca sequencial
 * Vetor de 10 elementos com valores inseridos diretamente no codigo.
 *
 * Ideia: percorrer o vetor do inicio ao fim comparando cada elemento.
 * Funciona com vetor DESORDENADO.
 * Melhor caso: 1 comparacao | Pior caso: n comparacoes | O(n)
 */

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

/* Retorna a posicao da PRIMEIRA ocorrencia ou -1 se nao encontrar */
int buscaSequencial(int vetor[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return i;   /* achou: o return encerra a funcao na hora */
        }
    }
    return -1;          /* -1 nunca e um indice valido: significa "nao achei" */
}

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);   /* acentos no terminal do Windows */
#endif

    int vetor[10] = {23, 7, 41, 15, 8, 32, 19, 4, 50, 11};
    int valor;

    printf("Digite o valor a buscar: ");
    scanf("%d", &valor);

    int pos = buscaSequencial(vetor, 10, valor);

    if (pos != -1) {
        printf("Valor %d encontrado na posição %d\n", valor, pos);
    } else {
        printf("Valor não encontrado\n");
    }

    return 0;
}
