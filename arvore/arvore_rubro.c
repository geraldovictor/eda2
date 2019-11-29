#include <stdio.h>
#include <stdlib.h>
#define RED 1;
#define BLACK 0;

typedef struct NO* ArvLLRB;

struct NO{
    int info;
    int cor;
    struct NO *esq;
    struct NO *dir;
};

ArvLLRB* raiz;

struct NO* rotacionaEsquerda(struct NO* A){
    struct NO* B = A->dir;
    A->dir=B->esq;
    B->esq= A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO* rotacionaDireita(struct NO* A){
    struct NO* B = A->esq;
    A->esq=B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}
void cor(struct NO* H){
    if(H == NULL)
        return BLACK;
    else 
        return H->cor;
}
void TrocaCor(struct NO* H){
    H->cor = !H->cor;
    if(H->esq != NULL)
        H->esq->cor = !H->esq->cor;
    if(H->dir != NULL)
        H->dir->cor = !H->dir->cor;
}
struct NO* move2EsqRED(struct NO* H){
    TrocaCor(H);
    if(cor(H->dir->esq) == RED) {
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        TrocaCor(H);
    }
    return H;
}
struct NO* move2DirRED(struct NO* H){
    TrocaCor(H);
    if(cor(H->esq->esq) == RED) {
        H = rotacionaDireita(H);
        TrocaCor(H);
    }
    return H;
}
struct NO* balancear(struct NO* H){
    if(cor(H->dir) ==RED)
        H = rotacionaEsquerda(H);

    if(H->esq != NULL && cor(H->dir)== RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        TrocaCor(H);
    return H;
    
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
