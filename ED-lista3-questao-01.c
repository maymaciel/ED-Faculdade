/*
** Função : 
** Autor : Maysa de Lima Maciel
** Data : 30/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenar_selecao(int vetor[], int tamanho) {
    int i, j, indice_minimo;

    for (i = 0; i < tamanho-1; i++) {
        indice_minimo = i;
        for (j = i+1; j < tamanho; j++) {
            if (vetor[j] < vetor[indice_minimo]) {
                indice_minimo = j;
            }
        }
        troca(&vetor[indice_minimo], &vetor[i]);
    }
}

void gerar_vetor_ale(int vetor[], int tamanho, int limite_inferior, int limite_superior) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = (rand() % (limite_superior - limite_inferior + 1)) + limite_inferior;
    }
}

void imprimir_vetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho = 10;
    int limite_inferior = 0;
    int limite_superior = 100;
    int vetor[tamanho];

    srand(time(0));

    gerar_vetor_ale(vetor, tamanho, limite_inferior, limite_superior);

    printf("Vetor: ");
    imprimir_vetor(vetor, tamanho);

    ordenar_selecao(vetor, tamanho);

    printf("Vetor ordenado: ");
    imprimir_vetor(vetor, tamanho);

    return 0;
}