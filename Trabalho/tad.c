#include "arvoreB.h"
#define GRAU 5

struct no {
  int countKeys;
  int keys[GRAU - 1];
  struct no *childrens[GRAU];
};

BTree createBTree() {
  BTree btree = (BTree)malloc(sizeof(NO));
  if (btree != NULL) {
    *btree = NULL;
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

int insertBtre(BTree btree, int value) {
  if (btree == NULL) {
    return 0;
  }
  if (isEmpty(btree)) {
    *btree = createNode();
    (*btree)->countKeys++;
    (*btree)->keys[0] = value;
    return 0;
  }

  int i = 0;
  for (; i < (*btree)->countKeys; i++) {
    if (value <= (*btree)->keys[i]) {
      if (value == (*btree)->keys[i])
        return 0;
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
    (*btree)->keys[i] = value;
    (*btree)->countKeys++;
  }
  if (isFull(btree)) {
    printf("split\n");

    int max = (*btree)->countKeys;
    int mediana = floor(max/2);
    int arrayLeft[mediana];

    printf("%d %d %d %d %f\n", (int)floor(max/2), (int)ceil(max/2), max, max/2, max/2);
    
    int i=0;
    for(;i<max;i++){

    }
  }

  return 1;
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
