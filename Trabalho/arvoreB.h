#ifndef HEADER
#define HEADER
typedef struct NO *ArvB;

ArvB *criaArvB(); // feito
void liberaArvB(ArvB *raiz);
int insereArvB(ArvB *raiz, int valor);
int removeArvB(ArvB *raiz, int valor);
int buscaArvB(ArvB *raiz, int valor);
int ehVaziaArvB(ArvB *raiz);
int totalNOArvB(ArvB *raiz);
void imprimirArv(ArvB raiz);
// Minhas funcs
void espera();
int menu();

#endif