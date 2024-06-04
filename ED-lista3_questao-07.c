/*
** Função :
** Autor : Maysa de Lima Maciel
** Data : 01/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int particionar(int vetor[], int inicio, int fim) {
  int pivo = vetor[(inicio + fim) / 2];
  int i = inicio;
  int j = fim;

  while (i <= j) {
    while (vetor[i] < pivo) {
      i++;
    }
    while (vetor[j] > pivo) {
      j--;
    }
    if (i <= j) {
      trocar(&vetor[i], &vetor[j]);
      i++;
      j--;
    }
  }

  return i;
}

void quicksort(int vetor[], int inicio, int fim) {
  if (inicio < fim) {
    int indicePivo = particionar(vetor, inicio, fim);
    quicksort(vetor, inicio, indicePivo - 1); // Ordena a metade esquerda
    quicksort(vetor, indicePivo, fim);        // Ordena a metade direita
  }
}

void valores_aleatorios(int vetor[], int tamanho, int limite) {
  srand(time(NULL));
  for (int i = 0; i < tamanho; i++) {
    vetor[i] = rand() % limite;
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
  int limite = 100;
  int vetor[tamanho];

  valores_aleatorios(vetor, tamanho, limite);

  printf("Vetor original:\n");
  imprimir_vetor(vetor, tamanho);

  quicksort(vetor, 0, tamanho - 1);

  printf("Vetor ordenado:\n");
  imprimir_vetor(vetor, tamanho);

  return 0;
}