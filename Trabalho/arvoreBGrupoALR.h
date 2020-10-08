#ifndef HEADER
#define HEADER
typedef struct NO *ArvB;

ArvB *criaArvB();
void liberaArvB(ArvB *raiz);
int insereArvB(ArvB *raiz, int valor);
int removeArvB(ArvB *raiz, int valor);
int buscaArvB(ArvB *raiz, int valor);
int ehVaziaArvB(ArvB *raiz);
int totalNOArvB(ArvB *raiz);
void emOrdemArvB(ArvB *raiz);

// Funcoes pessoais
#define GRAU 6
int ehCheiaArvB(ArvB *raiz);
int insereNo(ArvB *raiz, ArvB *pai, int valor);
int removeNo(ArvB *raiz, ArvB *anterior, int valor);
int removeReorganiza(ArvB *autal, ArvB *anteriore, ArvB *no);
int removeIrmao(ArvB *atual, ArvB *anterior, int j);
int removeAtualEInsereIrmao(ArvB *atual, ArvB *anterior, int j);
int underflow(ArvB *atual, ArvB *anterior, int j);
int temQtdMinima(int qtd);
int ehNoFolha(ArvB raiz);
void split(ArvB *raiz, ArvB *pai);

#endif