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
  ArvB *raiz = criaArvB();

  int values[9] = {10, 90, 50, 70, 35, 25, 33, 12, 0};
  int i = 0;
  for (; i < 9; i++) {
    printf("inserindo:%d \n", values[i]);
    insereArvB(raiz, values[i]);
  }
  printf("\n");
  printf("Imprimindo arvore em Ordem\n");
  emOrdemArvB(raiz);
  printf("\n");
  // if (buscaArvB(raiz, 76))
  //   printf("Achou");
  // else
  //   printf("Nao achou");
  // printf("\n %d \n", totalNOArvB(raiz));
  printf("Removendo 0");
  removeArvB(raiz, 0);
  printf("\n");
  printf("Imprimindo arvore em Ordem\n");
  emOrdemArvB(raiz);
  return 0;
}
