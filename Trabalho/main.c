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

  // int values[30] = {10,  20,  30,  40,  50,  60,  70,  80,  90,  100,
  //                   110, 120, 130, 140, 150, 160, 170, 180, 190, 200,
  //                   210, 22,  23,  24,  25,  26,  27,  28,  29,  30};
  // int i = 0;
  // for (; i < 17; i++) {
  //   printf("inserindo:%d \n", values[i]);
  //   insereArvB(raiz, values[i]);
  // }
  // insereArvB(raiz, 0);
  // insereArvB(raiz, 5);
  // insereArvB(raiz, 15);
  // printf("\n");
  // printf("Imprimindo arvore em Ordem\n");
  // emOrdemArvB(raiz);

  // printf("\nremovendo:%d \n", 6);
  // removeArvB(raiz, 120);
  // emOrdemArvB(raiz);

  // printf("\n");
  // printf("Imprimindo arvore em Ordem\n");
  // emOrdemArvB(raiz);

  int values[30] = {1, 2, 3, 4, 5 ,6 ,7 ,8, 9, 10, 11, 12, 13, 14, 15, 16,
  17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}; int i = 0; for (;
  i < 30; i++) {
    printf("inserindo:%d \n", values[i]);
    insereArvB(raiz, values[i]);
  }
  printf("\n");
  printf("Imprimindo arvore em Ordem\n");
  emOrdemArvB(raiz);
  int removendo[10] = {4, 17, 20, 10, 11, 22, 19, 25, 21, 4};
  i = 0;
  printf("\nremovendo:%d \n", removendo[i]);
  removeArvB(raiz, removendo[i]);
  emOrdemArvB(raiz);

  i++;
  printf("\nremovendo:%d \n", removendo[i]);
  removeArvB(raiz, removendo[i]);
  emOrdemArvB(raiz);

  i++;
  printf("\nremovendo:%d \n", removendo[i]);
  removeArvB(raiz, removendo[i]);
  emOrdemArvB(raiz);

  i++;
  printf("\nremovendo:%d \n", removendo[i]);
  removeArvB(raiz, removendo[i]);
  emOrdemArvB(raiz);

  i++;
  printf("\nremovendo:%d \n", removendo[i]);
  removeArvB(raiz, removendo[i]);
  emOrdemArvB(raiz);

  i++;
  printf("\nremovendo:%d \n", removendo[i]);
  removeArvB(raiz, removendo[i]);
  emOrdemArvB(raiz);

  i++;
  printf("\nremovendo:%d \n", removendo[i]);
  removeArvB(raiz, removendo[i]);
  emOrdemArvB(raiz);

  i++;
  printf("\nremovendo:%d \n", removendo[i]);
  removeArvB(raiz, removendo[i]);
  emOrdemArvB(raiz);

  i++;
  printf("\nremovendo:%d \n", removendo[i]);
  removeArvB(raiz, removendo[i]);
  emOrdemArvB(raiz);

  i++;
  printf("\nremovendo:%d \n", removendo[i]);
  removeArvB(raiz, removendo[i]);
  emOrdemArvB(raiz);
  printf("\n");
  printf("Imprimindo arvore em Ordem\n");
  emOrdemArvB(raiz);
  return 0;
}
