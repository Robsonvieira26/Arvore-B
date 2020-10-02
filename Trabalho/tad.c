#include <stdio.h>
#include <stdlib.h>
#include "arvoreB.h"
#define GRAU 3

struct NO
{
  int chaves[GRAU - 1]; // valores possiveis em um no
  struct NO *ptrFilhos[GRAU];
};

ArvB criaArvB()
{
  ArvB *raiz = (ArvB *)malloc(sizeof(ArvB));
  if (raiz != NULL)
    *raiz = NULL;
  return raiz;
}

void liberaArvB(ArvB *raiz)
{
}

int insereArvB(ArvB *raiz, int valor) {}
int removeArvB(ArvB *raiz, int valor) {}
int buscaArvB(ArvB *raiz, int valor) {}
int ehVaziaArvB(ArvB *raiz) {}
int totalNOArvB(ArvB *raiz) {}

int menu()
{
  int op;
  do
  {
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
void espera()
{
  system("pause");
  system("cls");
}