typedef struct NO *ArvB;

ArvB criaArvB();
void liberaArvB(ArvB *raiz);
int insereArvB(ArvB *raiz, int valor);
int removeArvB(ArvB *raiz, int valor);
int buscaArvB(ArvB *raiz, int valor);
int ehVaziaArvB(ArvB *raiz);
int totalNOArvB(ArvB *raiz);
