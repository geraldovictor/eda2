#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
    struct no *esq;
    struct no *dir;
} tNo;

typedef tNo *tArvBin;

void criaArvore(tArvBin *T)
{
    *T = NULL;
}
int vazia(tArvBin T)
{
    return (T == NULL);
}
tArvBin busca(tArvBin T, int dado)
{
    tArvBin achou;
    if (T == NULL)
        return NULL;
    if (T->conteudo == dado)
        return T;
    achou = busca(T->esq, dado);
    if (achou == NULL)
        achou = busca(T->dir, dado);
    return achou;
}
int insereRaiz(tArvBin *T, int dado)
{
    tNo *novoNo;
    if (T != NULL)
        return 0;
    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL)
        return 0;
    novoNo->conteudo = dado;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    *T = novoNo;

    return 1;
}
int insereDir(tArvBin T, int vPai, int vFilho)
{
    tNo *f, *p, *novoNo;
    f = busca(T, vFilho);
    if (f != NULL)
        return 0;
    p = busca(T, vPai);
    if (p == NULL)
        return 0;
    if (p->dir != NULL)
        return 0;
    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL)
        return 0;
    novoNo->conteudo = vFilho;
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    p->dir = novoNo;
    return 1;
}
int insereEsq(tArvBin T, int vPai, int vFilho)
{
    tNo *f, *p, *novoNo;
    f = busca(T, vFilho);
    if (f == NULL)
        return 0;
    p = busca(T, vPai);
    if (p == NULL)
        return 0;
    if (p->esq != NULL)
        return 0;
    novoNo = malloc(sizeof(tNo));
    novoNo->conteudo = vFilho;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    p->esq = novoNo;
    return 1;
}
void imprimePreOrder(tArvBin T)
{
    if (T == NULL)
        return;

    printf("%d  ", T->conteudo);
    if (T->esq != NULL)
        imprimePreOrder(T->dir);
    if (T->esq != NULL)
        imprimePreOrder(T->esq);
}
void imprimeInOrder(tArvBin T)
{
    if (T == NULL)
        return;
    if (T->esq != NULL)
        imprimeInOrder(T->esq);
    printf("%d  ", T->conteudo);
    if (T->dir != NULL)
        imprimeInOrder(T->dir);
    
}
void imprimePosOrder(tArvBin T)
{
    if (T == NULL)
        return;
    if (T->esq != NULL)
        imprimePosOrder(T->esq);
    if (T->dir != NULL)
        imprimePosOrder(T->dir);
    printf("%d  ", T->conteudo);
    
}
int main(int argc, char const *argv[])
{

    return 0;
}
