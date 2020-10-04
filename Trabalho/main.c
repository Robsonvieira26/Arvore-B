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

  int values[18] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,75};
  int i=0;
  for(;i<18;i++){
    insereArvB(raiz, values[i]);
  }
  emOrdemArvB(raiz);
  printf("\n");
  // if (buscaArvB(raiz, 76))
  //   printf("Achou");
  // else
  //   printf("Nao achou");
  // printf("\n %d \n", totalNOArvB(raiz));
  removeArvB(raiz, 50);
  emOrdemArvB(raiz);
  printf("\nlibera:\n");
  liberaArvB(raiz);
  printf("\neh vazia: %d\n", ehVaziaArvB(raiz));

  // for (;;) {
  //   int op = menu();
  //   printf("sua escolha foi %d\n", op);
  //   switch (op) {
  //   case 1:
  //     raiz = criaArvB();
  //     printf("Arvore Iniciada\n");
  //     espera();
  //     break;
  //   case 2:
  //     printf("Digite o valor a ser Inserido:\n");
  //     int n;
  //     scanf("%d",&n);
  //     insereArvB(raiz, n);
  //     espera();
  //     break;
  //   case 3:
  //     printf("Digite o valor a ser Removido:\n");
  //     espera();
  //     break;
  //   case 4:
  //     printf("Digite o valor a ser Procurado:\n");
  //     espera();
  //     break;
  //   case 5:
  //     printf("A quantidade Total de nos na arvore é: [VALOR]\n");
  //     espera();
  //     break;
  //   case 6:
  //     if (ehVaziaArvB(raiz) == 1)
  //       printf("A arvore esta vazia\n");
  //     if (ehVaziaArvB(raiz) == 0)
  //       printf("A arvore nao esta vazia\n");
  //     espera();
  //     break;
  //   case 7:
  //     printf("Imprimindo Arvore (Em Ordem)\n");
  //     imprimirArv(*raiz);
  //     espera();
  //     break;
  //   case 8:
  //     printf("Arvore Apagada\n");
  //     espera();
  //     break;
  //   case 9:
  //     printf("Saindo...\n");
  //     exit(1);
  //     break;
  //   }
  // }
  return 0;
}
