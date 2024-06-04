/*
** Função :
** Autor : Maysa de Lima Maciel
** Data : 01/06/2024
** Observações:
*/

#include <stdbool.h>
#include <stdio.h>

bool primo(int num) {
  if (num <= 1)
    return false;
  if (num == 2)
    return true;
  if (num % 2 == 0)
    return false;
  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0)
      return false;
  }
  return true;
}

void encontrar_primos(int num) {
  for (int i = 2; i <= num / 2; i++) {
    if (primo(i) && primo(num - i)) {
      printf("%d = %d + %d\n", num, i, num - i);
      return;
    }
  }
}

int main() {
  for (int num = 700; num <= 1100; num += 2) {
    encontrar_primos(num);
  }
  return 0;
}