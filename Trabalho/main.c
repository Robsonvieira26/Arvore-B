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
  BTree btree = createBTree();
  insertBtre(btree, 5);
  insertBtre(btree, 2);
  insertBtre(btree, 4);
  insertBtre(btree, 1);
  insertBtre(btree, 65);
  insertBtre(btree, 7);
  printf("%p",btree);
  return 0;
}
