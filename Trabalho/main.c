#include "arvoreB.h"
#include <stdio.h>
#include <stdlib.h>

/*
Grupo ALR
Integrantes:
Aristeu Alves Ferreira Neto - 11911BCC027
Loredana Romano Devico - 11911BCC001
Robson Roberto Vieira Junior - 11911BCC056
*/

int main() {
  ArvB *t = criaArvB();
  int i;
  for (i = 1; i <= 30; i++) {
    insereArvB(t, i);
  }

  emOrdemArvB(t);

  // Casos de teste

  removeArvB(t, 4);
  insereArvB(t, 4);

  // removeFromBTree(t, 10);
  // insertInBTree(t, 10);

  // removeFromBTree(t, 20);
  // removeFromBTree(t, 17);

  // removeFromBTree(t, 15); [!]

  removeArvB(t, 17);
  removeArvB(t, 20);
  removeArvB(t, 10);
  removeArvB(t, 11);
  removeArvB(t, 22);
  removeArvB(t, 19);
  removeArvB(t, 25);
  removeArvB(t, 21);
  removeArvB(t, 4);

  printf("\n");

  emOrdemArvB(t);
  return 0;
}
