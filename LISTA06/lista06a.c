#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
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
tAbp busca2(tAbp T, int dado)
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
tAbp busca1(tAbp T, int dado)
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

    printf("%d ", T->conteudo);
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
    printf("%d ", T->conteudo);
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
    printf("%d ", T->conteudo);
}
int insereAbp(tAbp *T, int dado)
{
    tNo *novoNo, *atual, *p;
    novoNo = malloc(sizeof(tNo));
    atual = malloc(sizeof(tNo));
    p = malloc(sizeof(tNo));

    if (novoNo == NULL)
        return 0;
    novoNo->conteudo = dado;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    if (*T == NULL)
    {
        *T = novoNo;
        return 1;
    }
    atual = *T;
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

int insereRaiz(tAbp *T, int dado)
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
int insereDir(tAbp T, int vPai, int vFilho)
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
int insereEsq(tAbp T, int vPai, int vFilho)
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
void erd(tAbp r)
{
    if (r != NULL)
    {
        erd(r->esq);
        printf("%d ", r->conteudo);
        erd(r->dir);
    }
}
int main(int argc, char const *argv[])
{
    int dado, pai, filho;
    tAbp arvore = malloc(sizeof(tAbp));
    criaArvore(&arvore);
    while (scanf("%d", &dado) != EOF)
    {
        insereAbp(&arvore, dado);
    }
    imprimePreOrder(arvore);
    printf(".\n");
    imprimeInOrder(arvore);
    printf(".\n");
    imprimePosOrder(arvore);
    printf(".\n");
    return 0;
}
