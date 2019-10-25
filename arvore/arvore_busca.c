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
tAbp busca2(tAbp T, char dado)
{
    tAbp achou;
    if (T == NULL)
        return NULL;
    if (T->conteudo == dado)
        return T;
    achou = busca2(T->esq, dado);
    if (achou == NULL)
        achou = busca2(T->dir, dado);
    return achou;
}
tAbp busca1(tAbp T, char dado)
{
    tAbp achou;
    if (T == NULL)
        return NULL;
    if (T->conteudo == dado)
        return T;
    if (T->conteudo > dado)
        return T = busca1(T->esq, dado);
    else
        return busca1(T->dir, dado);
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
int insereRaiz(tAbp *T, char dado)
{
    tNo *novoNo;
    if (*T != NULL)
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
int insereDir(tAbp T, char vPai, char vFilho)
{
    tNo *f, *p, *novoNo;
    f = busca2(T, vFilho);
    if (f != NULL)
        return 0;
    p = busca2(T, vPai);
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
int insereEsq(tAbp T, char vPai, char vFilho)
{
    tNo *f, *p, *novoNo;
    f = busca2(T, vFilho);
    if (f != NULL)
        return 0;
    p = busca2(T, vPai);
    if (p == NULL)
        return 0;
    if (p->esq != NULL)
        return 0;
    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL)
        return 0;
    novoNo->conteudo = vFilho;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    p->esq = novoNo;
    return 1;
}
tAbp 
int main(int argc, char const *argv[])
{
    char dado, pai, filho;
    tAbp arvore = malloc(sizeof(tAbp));
    criaArvore(&arvore);
    insereRaiz(&arvore, 'h');
    for (int i = 0; i < 11; i++)
    {
        scanf(" %c", &dado);
        if (dado == 'd')
        {
            scanf(" %c", &pai);
            scanf(" %c", &filho);
            insereDir(arvore, pai, filho);
        }
        if (dado == 'e')
        {
            scanf(" %c", &pai);
            scanf(" %c", &filho);
            insereEsq(arvore, pai, filho);
        }
    }
    imprimePreOrder(arvore);
    printf("\n");
    imprimeInOrder(arvore);
    printf("\n");
    imprimePosOrder(arvore);
    printf("\n");
    return 0;
}
