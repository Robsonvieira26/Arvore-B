#include "arvoreB.h"
#define GRAU 4

struct no {
  int countKeys;
  int keys[GRAU - 1];
  struct no *childrens[GRAU];
};

BTree createBTree() {
  BTree btree = (BTree)malloc(sizeof(NO));
  if (btree != NULL) {
    *btree = createNode();
  }
  return btree;
}

NO createNode() {
  NO no = (NO)malloc(sizeof(struct no));
  no->countKeys = 0;
  for (int i = 0; i < GRAU; i++) {
    no->childrens[i] = NULL;
  }
  return no;
}
int insereNo(BTree btree, BTree previous, int value) {

  if (isEmpty(btree)) {
    return 0;
  }
  // percorre e insere no sem fazer split
  // todo falta acessar o no filho
  int i = 0;
  for (; i < (*btree)->countKeys; i++) {
    if (value <= (*btree)->keys[i]) {
      if (value == (*btree)->keys[i])
        return 0;
      if (insereNo(&((*btree)->childrens[i]), btree, value))
        break;
      // insere quando nao da pra inserir no no de baixo
      int j = (*btree)->countKeys;
      while (j > i) {
        (*btree)->keys[j] = (*btree)->keys[j - 1];
        j--;
      }

      (*btree)->keys[i] = value;
      (*btree)->countKeys++;
      break;
    }
  }
  if (i == (*btree)->countKeys) {
    if (!insereNo(&((*btree)->childrens[i]), btree, value)) {
      (*btree)->keys[i] = value;
      (*btree)->countKeys++;
    }
  }
  // so faz split quando o no atual enche
  if (isFull(btree)) {
    printf("split\n");

    int max = (*btree)->countKeys;
    int mediana = (max / 2);

    NO left = createNode();
    NO right = createNode();
    int l = 0;
    for (; l < mediana; l++) {
      left->keys[l] = (*btree)->keys[l];
      left->countKeys++;
    }
    int k=0;
    for(;k <= mediana; k++){
      left->childrens[k] = (*btree)->childrens[k];
    }

    l++;
    int j = 0;
    for (; l < max; l++) {
      right->keys[j] = (*btree)->keys[l];
      right->childrens[j] = (*btree)->childrens[l];
      right->countKeys++;
      j++;
    }
    j=0;
    for (; k <= max; k++) {
      right->childrens[j] = (*btree)->childrens[k];
      j++;
    }
    // promovendo o valor
    int promoverValor = (*btree)->keys[mediana];
    free(*btree);
    *btree = NULL;

    int t = 0;
    if ((*previous) == NULL) {
      (*previous) = createNode();
    } else {
      for (; t < (*previous)->countKeys; t++) {
        if (promoverValor < (*previous)->keys[t]) {

          int j = (*previous)->countKeys;
          while (j > t) {
            (*previous)->keys[j] = (*previous)->keys[j - 1];
            j--;
          }
          j = (*previous)->countKeys + 1;
          while (j > (t + 1)) {
            (*previous)->childrens[j] = (*previous)->childrens[j - 1];
            j--;
          }

          (*previous)->keys[t] = promoverValor;
          (*previous)->childrens[t] = left;
          (*previous)->childrens[t + 1] = right;
          (*previous)->countKeys++;
          break;
        }
      }
    }
    if (t == (*previous)->countKeys) {
      (*previous)->keys[t] = promoverValor;
      (*previous)->childrens[t] = left;
      (*previous)->childrens[t + 1] = right;
      (*previous)->countKeys++;
    }
  }

  return 1;
}

int insertBtre(BTree btree, int value) {
  return insereNo(btree, btree, value);
  printf("%p\n", *btree);
}

int isEmpty(BTree btree) {
  if (btree == NULL) {
    return 1;
  }
  if (*btree == NULL) {
    return 1;
  }
  return 0;
}

int isFull(BTree btree) {
  if (isEmpty(btree)) {
    return 0;
  }
  if ((*btree)->countKeys == (GRAU - 1)) {
    return 1;
  }
  return 0;
}
