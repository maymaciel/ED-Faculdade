/*
** Função :
** Autor : Maysa de Lima Maciel
** Data : 01/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int vetor[], int tamanho, int *num_comparacoes,
                 int *num_trocas) {
  int i, j;
  for (i = 0; i < tamanho - 1; i++) {
    for (j = 0; j < tamanho - i - 1; j++) {
      (*num_comparacoes)++;
      if (vetor[j] > vetor[j + 1]) {
        (*num_trocas)++;
        int temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
  }
}

void valores_aleatorios(int vetor[], int tamanho) {
  srand(time(NULL));
  for (int i = 0; i < tamanho; i++) {
    vetor[i] = rand() % 100;
  }
}

void imprimir_vetor(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main() {
  int tamanho;

  printf("Digite a quantidade de elementos do vetor: ");
  scanf("%d", &tamanho);

  int vetor[tamanho];
  valores_aleatorios(vetor, tamanho);

  printf("Vetor original:\n");
  imprimir_vetor(vetor, tamanho);

  int num_comparacoes = 0;
  int num_trocas = 0;
  bubble_sort(vetor, tamanho, &num_comparacoes, &num_trocas);

  printf("Vetor ordenado:\n");
  imprimir_vetor(vetor, tamanho);

  printf("Numero de comparacoes: %d\n", num_comparacoes);
  printf("Numero de trocas: %d\n", num_trocas);

  return 0;
}