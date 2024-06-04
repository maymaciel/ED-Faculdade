/*
** Função :
** Autor : Maysa de Lima Maciel
** Data : 30/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char sigla[4];
  char cidade[51];
  char pais[31];
  float taxa;
  int capacidade;
} aeroporto;

void ler_aeroporto(aeroporto *aero) {
  printf("Digite a sigla: ");
  scanf(" %3s", aero->sigla);
  printf("Digite a cidade: ");
  scanf(" %[^\n]", aero->cidade);
  printf("Digite o pais: ");
  scanf(" %[^\n]", aero->pais);
  printf("Digite a taxa: ");
  scanf("%f", &aero->taxa);
  printf("Digite a capacidade: ");
  scanf("%d", &aero->capacidade);
}

void escrever_aeroporto(aeroporto *aero) {
  printf("Sigla: %s\n", aero->sigla);
  printf("Cidade: %s\n", aero->cidade);
  printf("Pais: %s\n", aero->pais);
  printf("Taxa: %.2f\n", aero->taxa);
  printf("Capacidade: %d\n", aero->capacidade);
}

void excluir_aeroporto(aeroporto **aeroportos, int *tamanho, int indice) {
  free(aeroportos[indice]);
  for (int i = indice; i < *tamanho - 1; i++) {
    aeroportos[i] = aeroportos[i + 1];
  }
  (*tamanho)--;
  aeroportos = realloc(aeroportos, (*tamanho) * sizeof(aeroporto *));
}

int main() {
  int opcao, tamanho = 0;
  aeroporto **aeroportos = NULL;

  do {
    printf("\nMenu:\n");
    printf("1. Adicionar aeroporto\n");
    printf("2. Listar aeroportos\n");
    printf("3. Excluir aeroporto\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      tamanho++;
      aeroportos = realloc(aeroportos, tamanho * sizeof(aeroporto *));
      aeroportos[tamanho - 1] = malloc(sizeof(aeroporto));
      ler_aeroporto(aeroportos[tamanho - 1]);
      break;
    case 2:
      for (int i = 0; i < tamanho; i++) {
        printf("\nAeroporto %d:\n", i + 1);
        escrever_aeroporto(aeroportos[i]);
      }
      break;
    case 3:
      if (tamanho == 0) {
        printf("Nenhum aeroporto para excluir.\n");
      } else {
        int indice;
        printf("Digite o indice do aeroporto a ser excluido (1 a %d): ",
               tamanho);
        scanf("%d", &indice);
        if (indice < 1 || indice > tamanho) {
          printf("Indice invalido.\n");
        } else {
          excluir_aeroporto(aeroportos, &tamanho, indice - 1);
          printf("Aeroporto excluido.\n");
        }
      }
      break;
    case 4:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida. Tente novamente.\n");
    }
  } while (opcao != 4);

  for (int i = 0; i < tamanho; i++) {
    free(aeroportos[i]);
  }
  free(aeroportos);
  return 0;
}