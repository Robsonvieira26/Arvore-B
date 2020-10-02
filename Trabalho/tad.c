#include "arvoreB.h"
#include <stdio.h>
#include <stdlib.h>
#define GRAU 3

struct NO {
  int chaves[GRAU - 1], cont; // valores possiveis em um no && cont é a
                              // quantidade de valores nesse no
  struct NO *ptrFilhos[GRAU];
};

ArvB *criaArvB() {
  ArvB *raiz = (ArvB *)malloc(sizeof(ArvB));
  if (raiz != NULL)
    *raiz = NULL;
  return raiz;
}

void imprimirArv(ArvB raiz) {
  int i;
  if (raiz) {
    for (i = 0; i < raiz->cont; i++) {
      imprimirArv(raiz->ptrFilhos[i]);
      printf("%d ", raiz->chaves[i + 1]); //?? pq + 1
    }
    imprimirArv(raiz->ptrFilhos[i]);
  }
}

// void liberaArvB(ArvB *raiz) {}
int insereArvB(ArvB *raiz, int valor) {
  
}
// int removeArvB(ArvB *raiz, int valor) {}
// int buscaArvB(ArvB *raiz, int valor) {}

int ehVaziaArvB(ArvB *raiz) {
  if (raiz == NULL) // raiz é null
    return 1;
  if (*raiz == NULL) // conteudo da raiz é null
    return 1;
  return 0;
}
// int totalNOArvB(ArvB *raiz) {}

int menu() {
  int op;
  do {
    printf("==============================\n");
    printf("|        ARVORE B MENU       |\n");
    printf("|        GRAU %d              |\n", GRAU);
    printf("==============================\n");
    printf("|[1] Iniciar Arvore B        |\n");
    printf("|[2] Inserir um Valor        |\n");
    printf("|[3] Remover um Valor        |\n");
    printf("|[4] Procurar um Valor       |\n");
    printf("|[5] Total de Nos            |\n");
    printf("|[6] Arvore Vazia?           |\n");
    printf("|[7] Apagar                  |\n");
    printf("|[8] Sair do Programa        |\n");
    printf("------------------------------\n");
    printf("|[O] Escolha: ");
    scanf("%d", &op);
    printf("------------------------------\n");
  } while (op < 0 || op > 8);
  return op;
}
void espera() {
  system("pause");
  system("cls");
}