#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    char conteudo;
    struct no *esq;
    struct no *dir;
} tNo;

typedef tNo *tAbp;

void criaArvore(tAbp *T)
{
    *T = NULL;
}
int vazia(tAbp T)
{
    return (T == NULL);
}
tAbp busca(tAbp T, char dado)
{
    tAbp achou;
    if (T == NULL)
        return NULL;
    if (T->conteudo == dado)
        return T;
    if (T->conteudo > dado)
        return T = busca(T->esq, dado);
    else
        return busca(T->dir, dado);
    return achou;
}
void imprimePreOrder(tAbp T)
{
    if (T == NULL)
        return;

    printf("%c  ", T->conteudo);
    if (T->esq != NULL)
        imprimePreOrder(T->esq);
    if (T->dir != NULL)
        imprimePreOrder(T->dir);
}
void imprimeInOrder(tAbp T)
{
    if (T == NULL)
        return;
    if (T->esq != NULL)
        imprimeInOrder(T->esq);
    printf("%c  ", T->conteudo);
    if (T->dir != NULL)
        imprimeInOrder(T->dir);
}
void imprimePosOrder(tAbp T)
{
    if (T == NULL)
        return;
    if (T->esq != NULL)
        imprimePosOrder(T->esq);
    if (T->dir != NULL)
        imprimePosOrder(T->dir);
    printf("%c  ", T->conteudo);
}
int insereAbp(tAbp T, char dado)
{
    tNo *novoNo, *atual, *p;
    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL)
        return 0;
    if (novoNo == NULL)
        return 0;
    novoNo->conteudo = dado;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    if (T == NULL)
    {
        T = novoNo;
        return 1;
    }
    atual = T;
    while (atual != NULL)
    {
        p = atual;
        if (atual->conteudo > dado)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    if (p->conteudo > dado)
        p->esq = novoNo;
    else
        p->dir = novoNo;
    return 1;
}

int insereNaoVazia(tAbp *T, char dado)
{
    int ok;
    if (dado > (*T)->conteudo)
        ok = insereNaoVazia((&(*T)->dir), dado);
    else if (dado < (*T)->conteudo)
        ok = insereNaoVazia((&(*T)->esq), dado);
    return ok;
}

int main(int argc, char const *argv[])
{
    char dado;
    tAbp arvore = malloc (sizeof(tAbp));
    for(int i=97 ; i < 106; i++){
        insereAbp(arvore,i);
    }
    imprimeInOrder(arvore);
    printf("\n");
    imprimePosOrder(arvore);
    printf("\n");
    imprimePreOrder(arvore);
    printf("\n");
    return 0;
}
