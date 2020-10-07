#ifndef HEADER
#define HEADER
typedef struct NO *ArvB;

ArvB *criaArvB();                      // feito
void liberaArvB(ArvB *raiz);           // feito
int insereArvB(ArvB *raiz, int valor); // feito
int removeArvB(ArvB *raiz, int valor); // feito
int buscaArvB(ArvB *raiz, int valor); // feito
int ehVaziaArvB(ArvB *raiz);          // feito
int totalNOArvB(ArvB *raiz);          // feito
void emOrdemArvB(ArvB *raiz);         // feito
// Minhas funcs
int ehNull(ArvB *raiz);
int ehCheiaArvB(ArvB *raiz);
int insereNo(ArvB *raiz, ArvB *pai, int valor);
int removeNo(ArvB *raiz, ArvB *anterior, int valor);
int removeReorganiza(ArvB *autal, ArvB *anteriore,  ArvB *no);
int removeIrmao(ArvB *atual, ArvB *anterior, int j);
int removeAtualEInsereIrmao(ArvB *atual, ArvB *anterior, int j);
int underflow(ArvB *atual, ArvB *anterior, int j);
int temQtdMinima(int qtd);
int ehNoFolha(ArvB raiz);
void split(ArvB *raiz, ArvB *pai);
void espera();
int menu();

#endif