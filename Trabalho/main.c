#include "arvoreB.h"

/*
Grupo ALR
Integrantes:
Aristeu Alves Ferreira Neto - 11911BCC027
Loredana Romano Devico - 11911BCC001
Robson Roberto Vieira Junior - 11911BCC056
*/

int main() {
  BTree btree = createBTree();
  insertBtre(btree, 10);
  insertBtre(btree, 15);
  insertBtre(btree, 5);
  insertBtre(btree, 80);
  insertBtre(btree, 20);
  insertBtre(btree, 65);
  insertBtre(btree, 70);
  insertBtre(btree, 3);
  insertBtre(btree, 1);
  insertBtre(btree, 16);
  insertBtre(btree, 17);
  insertBtre(btree, 18);
  insertBtre(btree, 19);
  insertBtre(btree, 12);
  insertBtre(btree, 13);
  printf("%p\n", btree);
  return 0;
}
