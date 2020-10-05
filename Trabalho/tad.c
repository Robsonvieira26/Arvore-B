#include "arvoreB.h"
#include <stdio.h>
#include <stdlib.h>
#define GRAU 6

struct NO {
  int chaves[GRAU - 1], cont; // valores possiveis em um no && cont é a
                              // quantidade de valores nesse no
  struct NO *ptrFilhos[GRAU];
};

ArvB criaNO() {
  ArvB no = (ArvB)malloc(sizeof(struct NO));
  no->cont = 0;
  for (int i = 0; i < GRAU; i++) {
    no->ptrFilhos[i] = NULL;
  }
  return no;
}

ArvB *criaArvB() {
  ArvB *raiz = (ArvB *)malloc(sizeof(ArvB));
  if (raiz != NULL) {
    *raiz = criaNO();
  }

  return raiz;
}

void emOrdemArvB(ArvB *raiz) { // filho esq pai filho dir
  // Em ordem
  ArvB auxArvB = *raiz;
  int i;
  if (auxArvB != NULL) {
    for (i = 0; i < auxArvB->cont; i++) {
      emOrdemArvB(&(auxArvB->ptrFilhos[i]));
      printf("[%d]", auxArvB->chaves[i]);
    }
    emOrdemArvB(&(auxArvB->ptrFilhos[i]));
  }
}

int insereNo(ArvB *raiz, ArvB *pai, int valor) {

  if (ehVaziaArvB(raiz)) {
    return 0;
  }
  // percorre e insere no sem fazer split
  int i = 0;
  for (; i < (*raiz)->cont; i++) {
    if (valor <= (*raiz)->chaves[i]) {
      if (valor == (*raiz)->chaves[i])
        return 1;
      if (insereNo(&((*raiz)->ptrFilhos[i]), raiz, valor))
        break;
      // insere quando nao da pra inserir no no de baixo
      int j = (*raiz)->cont;
      while (j > i) {
        (*raiz)->chaves[j] = (*raiz)->chaves[j - 1];
        j--;
      }

      (*raiz)->chaves[i] = valor;
      (*raiz)->cont++;
      break;
    }
  }
  if (i == (*raiz)->cont) {
    if (!insereNo(&((*raiz)->ptrFilhos[i]), raiz, valor)) {
      (*raiz)->chaves[i] = valor;
      (*raiz)->cont++;
    }
  }
  // so faz split quando o no atual enche
  if (ehCheiaArvB(raiz)) {
    split(raiz, pai);
  }

  return 1;
}

int insereArvB(ArvB *raiz, int valor) { return insereNo(raiz, raiz, valor); }

void split(ArvB *raiz, ArvB *pai) {
  int max = (*raiz)->cont;
  int mediana = (max / 2);

  ArvB left = criaNO();
  ArvB right = criaNO();
  int l = 0;
  for (; l < mediana; l++) {
    left->chaves[l] = (*raiz)->chaves[l];
    left->cont++;
  }
  int k = 0;
  for (; k <= mediana; k++) {
    left->ptrFilhos[k] = (*raiz)->ptrFilhos[k];
  }

  l++;
  int j = 0;
  for (; l < max; l++) {
    right->chaves[j] = (*raiz)->chaves[l];
    right->ptrFilhos[j] = (*raiz)->ptrFilhos[l];
    right->cont++;
    j++;
  }
  j = 0;
  for (; k <= max; k++) {
    right->ptrFilhos[j] = (*raiz)->ptrFilhos[k];
    j++;
  }
  // promovendo o valor
  int promoverValor = (*raiz)->chaves[mediana];
  free(*raiz);
  *raiz = NULL;

  int t = 0;
  if ((*pai) == NULL) {
    (*pai) = criaNO();
  } else {
    for (; t < (*pai)->cont; t++) {
      if (promoverValor < (*pai)->chaves[t]) {

        int j = (*pai)->cont;
        while (j > t) {
          (*pai)->chaves[j] = (*pai)->chaves[j - 1];
          j--;
        }
        j = (*pai)->cont + 1;
        while (j > (t + 1)) {
          (*pai)->ptrFilhos[j] = (*pai)->ptrFilhos[j - 1];
          j--;
        }

        (*pai)->chaves[t] = promoverValor;
        (*pai)->ptrFilhos[t] = left;
        (*pai)->ptrFilhos[t + 1] = right;
        (*pai)->cont++;
        break;
      }
    }
  }
  if (t == (*pai)->cont) {
    (*pai)->chaves[t] = promoverValor;
    (*pai)->ptrFilhos[t] = left;
    (*pai)->ptrFilhos[t + 1] = right;
    (*pai)->cont++;
  }
}
// void liberaArvB(ArvB *raiz) {}

int removeArvB(ArvB *raiz, int valor) { return removeNo(raiz, raiz, valor); }

int removeNo(ArvB *raiz, ArvB *anterior, int valor) {

  if (ehVaziaArvB(raiz)) {
    return 0;
  }

  ArvB no = *raiz;
  int i = 0;
  int auxCount = no->cont;
  for (; i < no->cont; i++) {
    if (valor <= no->chaves[i]) {
      if (valor == no->chaves[i]) {
        int j = i;
        while (j < (no->cont - 1)) {
          no->chaves[j] = no->chaves[j + 1];
          j++;
        }
        no->cont--;
        break;
      }
      if (removeNo(&(no->ptrFilhos[i]), raiz, valor))
        break;
    }
  }
  if(i == auxCount){
    if(!removeNo(&(no->ptrFilhos[i]), raiz, valor)){
      if( i < (GRAU -1) && no->chaves[i] == valor){
        no->cont--;
      }
    }
  }

  if (!temQtdMinima(no->cont)) {
    if (!ehNoFolha(no)) {
      ArvB atual = no->ptrFilhos[i];
      ArvB pai = no;
      while (atual != NULL) {
        pai = atual;
        atual = atual->ptrFilhos[atual->cont];
      }
      no->chaves[i] = pai->chaves[pai->cont-1];
      no->cont++;
      pai->cont--;
      // removeNo(raiz, no->ptrFilhos[])
    }
    if (ehNoFolha(no) && no != *anterior) {
      int j = 0;
      for (; j < (*anterior)->cont; j++) {
        if (valor < (*anterior)->chaves[j])
          break;
      }
      printf("%d\n", j);
      int posPaiChaves = j;
      int posPaiFilho = j;
      if ((j - 1) >= 0 &&
          temQtdMinima((*anterior)->ptrFilhos[(j - 1)]->cont - 1)) {
        posPaiChaves--;
        posPaiFilho--;
      } else if ((j + 1) <= (*anterior)->cont &&
                 temQtdMinima((*anterior)->ptrFilhos[(j + 1)]->cont - 1)) {
        posPaiFilho++;
      }

      if (posPaiFilho != j) {
        ArvB noIrmao = (*anterior)->ptrFilhos[posPaiFilho];

        int t = (*raiz)->cont;
        while (t > i) {
          (*raiz)->chaves[t] = (*raiz)->chaves[t - 1];
          t--;
        }

        (*raiz)->chaves[i] = (*anterior)->chaves[posPaiChaves];
        (*raiz)->cont++;
        int posIrmao = 0;
        if (posPaiFilho < j)
          posIrmao = noIrmao->cont - 1;
        (*anterior)->chaves[posPaiChaves] = noIrmao->chaves[posIrmao];
        if (posPaiFilho > j) {
          t = 0;
          while (t < (noIrmao->cont - 1)) {
            noIrmao->chaves[t] = noIrmao->chaves[t + 1];
            t++;
          }
        }
        noIrmao->cont--;
      }
    }
  }

  return 1;
}

int buscaArvB(ArvB *raiz, int valor) {
  ArvB auxArvB = *raiz;
  int i, existeElemento = 0;
  if (auxArvB != NULL) {
    for (i = 0; i < auxArvB->cont; i++) {
      existeElemento = +buscaArvB(&(auxArvB->ptrFilhos[i]), valor);
      if (auxArvB->chaves[i] == valor)
        return 1;
    }
    existeElemento = +buscaArvB(&(auxArvB->ptrFilhos[i]), valor);
  }
  return existeElemento;
}

int totalNOArvB(ArvB *raiz) {
  if (ehVaziaArvB(raiz)) {
    return 0;
  }
  int i = 0, total = 1;
  for (i = 0; i <= (*raiz)->cont; i++) {
    total = total + totalNOArvB(&((*raiz)->ptrFilhos[i]));
  }
  return total;
}

int ehVaziaArvB(ArvB *raiz) {
  if (raiz == NULL) // raiz é null
    return 1;
  if (*raiz == NULL) // conteudo da raiz é null
    return 1;
  if((*raiz)->cont == 0)
    return 1;
  return 0;
}

int temQtdMinima(int qtd) {
  if (qtd >= ((GRAU / 2) - 1))
    return 1;
  return 0;
}

int ehNoFolha(ArvB raiz) {
  int ehFolha = 1;
  int i = 0;
  for (; i <= raiz->cont; i++) {
    if (!ehVaziaArvB(&(raiz->ptrFilhos[i]))) {
      ehFolha = 0;
      break;
    }
  }
  return ehFolha;
}

int ehCheiaArvB(ArvB *raiz) {
  if (ehVaziaArvB(raiz)) {
    return 0;
  }
  if ((*raiz)->cont == (GRAU - 1)) {
    return 1;
  }
  return 0;
}

void liberaArvB(ArvB *raiz) {
  ArvB auxArvB = *raiz;
  int i, existeElemento = 0;
  if (auxArvB != NULL) {
    for (i = 0; i <= auxArvB->cont; i++) {

      liberaArvB(&(auxArvB->ptrFilhos[i]));
      // printf("=> %d", auxArvB->chaves[i + 1]);
      // liberaArvB(&(auxArvB->ptrFilhos[i + 1]));
    }
    // liberaArvB(&(auxArvB->ptrFilhos[i]));
    free(*raiz);
    *raiz = NULL;
  }
}

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