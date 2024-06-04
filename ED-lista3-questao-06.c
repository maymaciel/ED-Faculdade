/*
** Função :
** Autor : Maysa de Lima Maciel
** Data : 01/06/2024
** Observações:
*/

#include <math.h>
#include <stdio.h>

double raiz_quadrada(double n) {
  double x = n / 2.0;

  while (fabs(x * x - n) > 0.0001) {
    double temp = x;
    x = 0.5 * (x + n / x);
    if (fabs(temp - x) < 0.0001)
      break;
  }

  return x;
}

int main() {
  double n;

  printf("Digite um numero para calcular a raiz quadrada: ");
  scanf("%lf", &n);

  if (n < 0) {
    printf("Nao e possivel calcular a raiz quadrada de um numero negativo.\n");
  } else {
    double raiz = raiz_quadrada(n);
    printf("A raiz quadrada de %.0lf e aproximadamente %.0lf\n", n, raiz);
  }

  return 0;
}