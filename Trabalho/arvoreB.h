#ifndef HEADER
#define HEADER
typedef struct no **BTree;
typedef struct no *NO;

BTree createBTree();
NO createNode();
int insertBtre(BTree btree, int value);
int isEmpty(BTree btree);
int isFull(BTree btree);

#endif