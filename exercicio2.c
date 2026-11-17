/*
 * Exercicio 2 - Busca sequencial com valores repetidos
 * Mostra TODAS as posicoes onde o valor aparece.
 * Se nao encontrar, exibe "Valor não encontrado".
 *
 * Diferenca para o Exercicio 1: nao pode ter return dentro do for,
 * senao a busca para na primeira ocorrencia.
 * Sempre faz n comparacoes, porque precisa olhar o vetor inteiro.
 */

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

/* Imprime cada posicao encontrada e retorna quantas vezes achou */
int buscaSequencialTodas(int vetor[], int tamanho, int valor) {
    int quant = 0;   /* contador de ocorrencias */

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            printf("Valor %d encontrado na posição %d\n", valor, i);
            quant++;
        }
    }

    /* So da para concluir que NAO achou depois de olhar o vetor todo */
    if (quant == 0) {
        printf("Valor não encontrado\n");
    } else {
        printf("Quantidade de vezes que o valor %d foi encontrado: %d\n", valor, quant);
    }

    return quant;
}

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    /* 8 e 15 aparecem 3 vezes cada, para testar as repeticoes */
    int vetor[10] = {23, 7, 8, 15, 8, 32, 15, 4, 15, 8};
    int valor;

    printf("Digite o valor a buscar: ");
    scanf("%d", &valor);

    buscaSequencialTodas(vetor, 10, valor);

    return 0;
}
