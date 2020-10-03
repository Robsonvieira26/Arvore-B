#include "arvoreB.h"
#include <stdio.h>
#include <stdlib.h>
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
  if (isEmpty(btree)) {
    *btree = createNode();
    (*btree)->countKeys++;
    (*btree)->keys[0] = value;
    return 0;
  }

  for (int i = 0; i < (*btree)->countKeys; i++) {
    if (value <= (*btree)->keys[i]) {
      if (value == (*btree)->keys[i])
        return 0;
      insertBtre(&(*btree)->childrens[i], value);
    }
  }
  

  // if (!isFull(&previous)) {
  //   for (int l = 0; l < previous->countKeys; l++) {
  //     if (value < previous->keys[l]) {
  //       previous->keys[l] = value;
  //     }
  //   }
  // }

  printf("DEU BOM KRAI");

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
