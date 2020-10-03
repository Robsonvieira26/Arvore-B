#ifndef HEADER
#define HEADER
typedef struct NO *ArvB;

ArvB *criaArvB(); // feito
void liberaArvB(ArvB *raiz);
int insereArvB(ArvB *raiz, int valor); // feito
int removeArvB(ArvB *raiz, int valor);
int buscaArvB(ArvB *raiz, int valor); // feito
int ehVaziaArvB(ArvB *raiz);          // feito
int totalNOArvB(ArvB *raiz);          // feito
void emOrdemArvB(ArvB *raiz);         // feito
// Minhas funcs
int ehCheiaArvB(ArvB *raiz);
int insereNo(ArvB *raiz, ArvB *pai, int valor);
void split(ArvB *raiz, ArvB *pai);
void espera();
int menu();

#endif