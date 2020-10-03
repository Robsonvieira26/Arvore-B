#include "arvoreB.h"
#include <stdio.h>
#include <stdlib.h>
#define GRAU 5

int insereNo(ArvB no, int valor, int *pos);

struct NO {
  int chaves[GRAU - 1], cont; // valores possiveis em um no && cont é a
                              // quantidade de valores nesse no
  struct NO *ptrFilhos[GRAU];
};

ArvB *criaArvB() {
  ArvB *raiz = (ArvB *)malloc(sizeof(ArvB));
  if (raiz != NULL){
    *raiz = (ArvB) malloc(sizeof(struct NO));
    (*raiz)->cont = 3;
    (*raiz)->chaves[0] = 2;
    (*raiz)->chaves[1] = 3;
    (*raiz)->chaves[2] = 5;
  }
    
  return raiz;
}

void imprimirArv(ArvB raiz) { // filho esq pai filho dir
  // Em ordem
  int i;
  if (raiz) {
    for (i = 0; i < raiz->cont; i++) {
      imprimirArv(raiz->ptrFilhos[i]);
      printf("%d ", raiz->chaves[i]);
    }
    imprimirArv(raiz->ptrFilhos[i]);
  }
}

// void liberaArvB(ArvB *raiz) {}
int insereArvB(ArvB *raiz, int valor) {
  if(ehVaziaArvB(raiz)) {
    (*raiz) = (ArvB) malloc (sizeof(struct NO));
    (*raiz)->cont = 1;
    (*raiz)->chaves[0] = valor;
    return 1;
  }

  int i = 0;
  int insert = insereNo(*raiz, valor, &i);
  if(!insereNo) return 2;
  printf("%d\n", insert);

  for(int a=0;a<(GRAU-1);a++){
    printf("valor: %d - i: %d\n",(*raiz)->chaves[a], a);
  }
}

int insereNo(ArvB no, int valor, int *pos){
  int i = *pos;

  while (i < no->cont && valor > no->chaves[i] ) {
    i++;
  }

  if (no->chaves[i] == valor) {
    return 0;
  }

  int j = i,aux;
  aux = no->chaves[j];
  no->chaves[j] = valor;

  while (j < no->cont) {
    j++;
    no->chaves[j] = aux;
  }

  no->cont++;
  *pos = i;
  return 1;
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
    printf("|[7] Imprimir                |\n");
    printf("|[8] Apagar                  |\n");
    printf("|[9] Sair do Programa        |\n");
    printf("------------------------------\n");
    printf("|[O] Escolha: ");
    scanf("%d", &op);
    printf("------------------------------\n");
  } while (op < 0 || op > 9);
  return op;
}
void espera() {
  system("pause");
  system("cls");
}