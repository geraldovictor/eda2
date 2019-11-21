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

int main(int argc, char const *argv[])
{
    
    return 0;
}
