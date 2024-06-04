/*
** Função :
** Autor : Maysa de Lima Maciel
** Data : 01/06/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double real;
  double imaginaria;
} Complexo;

Complexo *criar_complexo(double real, double imaginaria) {
  Complexo *num_complexo = (Complexo *)malloc(sizeof(Complexo));
  if (num_complexo != NULL) {
    num_complexo->real = real;
    num_complexo->imaginaria = imaginaria;
  }
  return num_complexo;
}

void destruir_complexo(Complexo *num_complexo) { free(num_complexo); }

void ler_complexo(Complexo *num_complexo) {
  printf("Digite a parte real: ");
  scanf("%lf", &num_complexo->real);
  printf("Digite a parte imaginaria: ");
  scanf("%lf", &num_complexo->imaginaria);
}

void somar_complexos(Complexo *resultado, Complexo *num1, Complexo *num2) {
  resultado->real = num1->real + num2->real;
  resultado->imaginaria = num1->imaginaria + num2->imaginaria;
}

void subtrair_complexos(Complexo *resultado, Complexo *num1, Complexo *num2) {
  resultado->real = num1->real - num2->real;
  resultado->imaginaria = num1->imaginaria - num2->imaginaria;
}

void multiplicar_complexos(Complexo *resultado, Complexo *num1,
                           Complexo *num2) {
  resultado->real =
      num1->real * num2->real - num1->imaginaria * num2->imaginaria;
  resultado->imaginaria =
      num1->real * num2->imaginaria + num1->imaginaria * num2->real;
}

void dividir_complexos(Complexo *resultado, Complexo *num1, Complexo *num2) {
  double denominador =
      num2->real * num2->real + num2->imaginaria * num2->imaginaria;
  resultado->real =
      (num1->real * num2->real + num1->imaginaria * num2->imaginaria) /
      denominador;
  resultado->imaginaria =
      (num1->imaginaria * num2->real - num1->real * num2->imaginaria) /
      denominador;
}

void mostrar_complexo(Complexo *num_complexo) {
  printf("(%lf,%lf)\n", num_complexo->real, num_complexo->imaginaria);
}

int main() {
  Complexo *num1, *num2, *resultado;

  num1 = criar_complexo(2.0, 3.0);
  num2 = criar_complexo(1.0, -2.0);
  resultado = criar_complexo(0.0, 0.0);

  somar_complexos(resultado, num1, num2);
  printf("Soma: ");
  mostrar_complexo(resultado);

  subtrair_complexos(resultado, num1, num2);
  printf("Subtracao: ");
  mostrar_complexo(resultado);

  multiplicar_complexos(resultado, num1, num2);
  printf("Multiplicacao: ");
  mostrar_complexo(resultado);

  dividir_complexos(resultado, num1, num2);
  printf("Divisao: ");
  mostrar_complexo(resultado);

  // Liberando a memória alocada
  destruir_complexo(num1);
  destruir_complexo(num2);
  destruir_complexo(resultado);

  return 0;
}