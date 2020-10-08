#include "arvoreBGrupoALR.h"
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

  printf("Arvore de grau %d\nObs: possui %d valores por no e %d filhos\n\n\n",
         GRAU, GRAU - 1, GRAU);
  ArvB *raiz = criaArvB();

  printf("Inserindo Valores de 1 a 30\n");
  int i;
  for (i = 1; i <= 30; i++) {
    insereArvB(raiz, i);
  }

  printf("Valores em ordem\n");
  emOrdemArvB(raiz);

  printf("\n\nRemovendo o valor 4\n");
  removeArvB(raiz, 4);

  printf("-Valores na arvore-\n");
  emOrdemArvB(raiz);

  printf("\n\nBuscando o valor 4\n");
  if (buscaArvB(raiz, 4))
    printf("O numero foi encontrado\n");
  else
    printf("O numero nao foi encontrado\n");

  printf("\nInserindo novamente o valor 4\n");
  insereArvB(raiz, 4);

  printf("\nBuscando o valor 4\n");
  if (buscaArvB(raiz, 4))
    printf("O numero foi encontrado\n");
  else
    printf("O numero nao foi encontrado\n");

  printf("\nEsta arvore possui %d nos\n", totalNOArvB(raiz));

  printf("\nRemovendo o intervalo de 10 a 15\n");
  for (i = 10; i <= 15; i++)
    removeArvB(raiz, i);

  printf("\n-Valores na arvore-\n");
  emOrdemArvB(raiz);

  printf("\nEsta arvore possui %d nos\n", totalNOArvB(raiz));

  printf("\nLiberando arvore\n");
  liberaArvB(raiz);

  printf("Valores restantes:\n");
  emOrdemArvB(raiz);

  return 0;
}
