#include "arvoreB.h"
#include <stdio.h>
#include <stdlib.h>
#define GRAU 6 // qtd de chaves -1

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

  if (ehNull(raiz)) {
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

  if (ehNull(raiz)) {
    return 0;
  }

  int i = 0;
  int auxCount = (*raiz)->cont;
  for (; i < (*raiz)->cont; i++) {
    if (valor <= (*raiz)->chaves[i]) {
      if (valor == (*raiz)->chaves[i]) {
        int j = i;
        while (j < ((*raiz)->cont - 1)) {
          (*raiz)->chaves[j] = (*raiz)->chaves[j + 1];
          j++;
        }
        (*raiz)->cont--;
        if (!ehNoFolha(*raiz))
          removeReorganiza(&((*raiz)->ptrFilhos[i]), raiz, raiz);
        break;
      }
      if (removeNo(&((*raiz)->ptrFilhos[i]), raiz, valor))
        break;
    }
  }
  if (i == auxCount) {
    if (!removeNo(&((*raiz)->ptrFilhos[i]), raiz, valor)) {
      if (i < (GRAU - 1) && (*raiz)->chaves[i] == valor) {
        (*raiz)->cont--;
        if (!ehNoFolha(*raiz))
          removeReorganiza(&((*raiz)->ptrFilhos[i]), raiz, raiz);
      }
    }
  }

  if (!temQtdMinima((*raiz)->cont)) {
    int j = 0; // posicao do filho no pai
    for (; j < (*anterior)->cont; j++) {
      if (valor < (*anterior)->chaves[j])
        break;
    }

    if ((*raiz) != *anterior) {
      int op1 = removeIrmao(raiz, anterior, j);
      if (!op1) {
        if (ehNoFolha(*raiz)) {
          removeAtualEInsereIrmao(raiz, anterior, j);
        } else {
          underflow(raiz, anterior, j);
        }
      }
    }
  }

  return 1;
}

int removeReorganiza(ArvB *atual, ArvB *anterior, ArvB *no) {
  if (ehNull(atual)) {
    int i = 0, valor = (*anterior)->chaves[(*anterior)->cont - 1];
    for (; i < (*no)->cont; i++) {
      if (valor < (*no)->chaves[i])
        break;
    }
    int t = (*no)->cont;
    while (t > i) {
      (*no)->chaves[t] = (*no)->chaves[t - 1];
      t--;
    }

    (*no)->chaves[i] = valor;
    (*no)->cont++;
    (*anterior)->cont--;
    return 1;
  }
  if (removeReorganiza(&(*atual)->ptrFilhos[(*atual)->cont - 1], atual, no)) {
    if (!temQtdMinima((*atual)->cont)) {
      int j = 0, valor = (*atual)->chaves[0];
      for (; j <= (*anterior)->cont; j++) {
        if (valor <= (*anterior)->chaves[j])
          break;
      }
      if ((*atual) != *anterior) {
        int op1 = removeIrmao(atual, anterior, j);
        if (!op1) {
          if (ehNoFolha(*atual)) {
            removeAtualEInsereIrmao(atual, anterior, j);
          } else {
            underflow(atual, anterior, j);
          }
        }
      }
      return 1;
    }
  }
  return 0;
}

int removeAtualEInsereIrmao(ArvB *atual, ArvB *anterior,
                            int j) { // o j e a posicao do atual no anterior
  if ((j - 1) >= 0) {                // checa se existe no a esquerda
    ArvB noIrmao = (*anterior)->ptrFilhos[j - 1];

    noIrmao->chaves[noIrmao->cont] = (*anterior)->chaves[j - 1];
    noIrmao->cont++;

    int y = 0;
    for (; y < (*atual)->cont; y++) {
      noIrmao->chaves[noIrmao->cont + y] = (*atual)->chaves[y];
      noIrmao->cont++;
    }

    (*atual)->cont = 0;
    free(*atual);
    atual = NULL;

    int t = j - 1; // j posicao a ser removida do no anterior
    while (t < ((*anterior)->cont - 1)) {
      (*anterior)->chaves[t] = (*anterior)->chaves[t + 1];
      t++;
    }
    t = j;
    while (t < (*anterior)->cont) {
      (*anterior)->ptrFilhos[t] = (*anterior)->ptrFilhos[t + 1];
      t++;
    }
    (*anterior)->ptrFilhos[(*anterior)->cont] = NULL;
    (*anterior)->cont--;
  } else {
    ArvB noIrmao = (*anterior)->ptrFilhos[j + 1];
    (*atual)->chaves[(*atual)->cont] = (*anterior)->chaves[j];
    (*atual)->cont++;
    int t = 0;
    for (; t < noIrmao->cont; t++) {
      (*atual)->chaves[(*atual)->cont] = noIrmao->chaves[t];
      (*atual)->cont++;
    }
    free(noIrmao);

    t = j; // j posicao a ser removida do no anterior
    while (t < ((*anterior)->cont - 1)) {
      (*anterior)->chaves[t] = (*anterior)->chaves[t + 1];
      t++;
    }
    t = j + 1;
    while (t < (*anterior)->cont) {
      (*anterior)->ptrFilhos[t] = (*anterior)->ptrFilhos[t + 1];
      t++;
    }
    (*anterior)->ptrFilhos[(*anterior)->cont] = NULL;
    (*anterior)->cont--;
  }
}

int removeIrmao(ArvB *atual, ArvB *anterior,
                int j) { // o i e a posicao do valor no atual
  if ((j - 1) >= 0 && temQtdMinima((*anterior)->ptrFilhos[(j - 1)]->cont - 1)) {
    int posPaiFilho = j - 1;
    ArvB noIrmao = (*anterior)->ptrFilhos[posPaiFilho];

    int t = (*atual)->cont;
    while (t > 0) {
      (*atual)->chaves[t] = (*atual)->chaves[t - 1];
      t--;
    }
    t = (*atual)->cont + 1;
    while (t > 0) {
      (*atual)->ptrFilhos[t] = (*atual)->ptrFilhos[t - 1];
      t--;
    }

    (*atual)->chaves[0] = (*anterior)->chaves[posPaiFilho];
    (*atual)->ptrFilhos[0] = noIrmao->ptrFilhos[noIrmao->cont];
    (*atual)->cont++;
    (*anterior)->chaves[posPaiFilho] = noIrmao->chaves[noIrmao->cont - 1];
    noIrmao->ptrFilhos[noIrmao->cont] = NULL;
    noIrmao->cont--;
    return 1;
  } else if ((j + 1) <= (*anterior)->cont &&
             temQtdMinima((*anterior)->ptrFilhos[(j + 1)]->cont - 1)) {
    int posPaiFilho = j + 1;
    ArvB noIrmao = (*anterior)->ptrFilhos[posPaiFilho];

    (*atual)->chaves[(*atual)->cont] = (*anterior)->chaves[j];
    (*atual)->cont++;
    (*atual)->ptrFilhos[(*atual)->cont] = noIrmao->ptrFilhos[0];
    (*anterior)->chaves[j] = noIrmao->chaves[0];

    int t = 0;
    while (t < (noIrmao->cont - 1)) {
      noIrmao->chaves[t] = noIrmao->chaves[t + 1];
      t++;
    }
    t = 0;
    while (t < noIrmao->cont) {
      noIrmao->ptrFilhos[t] = noIrmao->ptrFilhos[t + 1];
      t++;
    }
    noIrmao->ptrFilhos[noIrmao->cont] = NULL;
    noIrmao->cont--;

    return 1;
  }
  return 0;
}

int underflow(ArvB *atual, ArvB *anterior, int j) {
  if ((j - 1) >= 0) {
    ArvB noIrmao = (*anterior)->ptrFilhos[j - 1];

    noIrmao->chaves[noIrmao->cont] = (*anterior)->chaves[j - 1];
    noIrmao->cont++;

    int l = 0; // colocando todos os elemento do no atual parao noIrmao
    for (; l < (*atual)->cont; l++) {
      noIrmao->chaves[noIrmao->cont] = (*atual)->chaves[l];
      noIrmao->cont++;
    }
    int posFilho = noIrmao->cont - (*atual)->cont;
    for (l = 0; l <= (*atual)->cont; l++) {
      noIrmao->ptrFilhos[posFilho + l] = (*atual)->ptrFilhos[l];
    }
    free(*atual);

    l = j - 1; // removendo o elemento que foi colocado no noIrmao
    while (l < ((*anterior)->cont - 1)) {
      (*anterior)->chaves[l] = (*anterior)->chaves[l + 1];
      l++;
    }

    l = j;
    while (l < (*anterior)->cont) {
      (*anterior)->ptrFilhos[l] = (*anterior)->ptrFilhos[l + 1];
      l++;
    }
    (*anterior)->ptrFilhos[(*anterior)->cont] = NULL;
    (*anterior)->cont--;

    if ((*anterior)->cont == 0) {
      ArvB aux = *anterior;
      *anterior = *atual;
      free(aux);
    }

  } else {
    (*atual)->chaves[(*atual)->cont] = (*anterior)->chaves[j];
    (*atual)->cont++;
    ArvB noIrmao = (*anterior)->ptrFilhos[j + 1];
    int t = 0;
    for (; t < noIrmao->cont; t++) {
      (*atual)->chaves[(*atual)->cont] = noIrmao->chaves[t];
      (*atual)->cont++;
    }
    int posFilho = (*atual)->cont - noIrmao->cont;
    for (t = 0; t <= noIrmao->cont; t++) {
      (*atual)->ptrFilhos[posFilho + t] = noIrmao->ptrFilhos[t];
    }
    free(noIrmao);

    t = j; // j posicao a ser removida do no anterior
    while (t < ((*anterior)->cont - 1)) {
      (*anterior)->chaves[t] = (*anterior)->chaves[t + 1];
      t++;
    }
    t = j + 1;
    while (t < (*anterior)->cont) {
      (*anterior)->ptrFilhos[t] = (*anterior)->ptrFilhos[t + 1];
      t++;
    }
    (*anterior)->ptrFilhos[(*anterior)->cont] = NULL;
    (*anterior)->cont--;

    if ((*anterior)->cont == 0) {
      ArvB aux = *anterior;
      *anterior = *atual;
      free(aux);
    }
  }
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
  if (ehNull(raiz)) {
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

int ehNull(ArvB *raiz){
  if(raiz == NULL)
    return 1;
  if(*raiz == NULL)
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
    if (!ehNull(&(raiz->ptrFilhos[i]))) {
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
