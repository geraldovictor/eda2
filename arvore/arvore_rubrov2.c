#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct No
{
    Item item;
    struct No *l, *r;
    Item red, black;
} node;

typedef node *link;
link raiz;
Item itemNull;

void rotacionaDir(link *raiz)
{
    link x = (*raiz)->l;
    (*raiz)->l = x->r;
    x->r = (*raiz);
    (*raiz) = x;
}

void rotacionaEsq(link *raiz)
{
    link x = (*raiz)->r;
    (*raiz)->r = x->l;
    x->l = (*raiz);
    (*raiz) = x;
}

int red(link raiz)
{
    if (raiz == NULL)
        return 0;
    return raiz->red;
}

node *novo_no(int x)
{
    node *novo = (node *)malloc(sizeof(node));
    novo->item = x;
    novo->l = novo->r = NULL;
    return novo;
}

void insereR(link *raiz, Item x, int sw)
{
    if ((*raiz) == NULL)
    {
        (*raiz) = novo_no(x);
        return;
    }
    if (red((*raiz)->l) && red((*raiz)->r))
    {
        (*raiz)->red = 1;
        (*raiz)->l->red = 0;
        (*raiz)->r->red = 0;
    }
    if (x < (*raiz)->item)
    {
        insereR(&(*raiz)->l, x, 0);
        if (red((*raiz)) && red((*raiz)->l) && sw)
        {
            rotacionaDir(raiz);
        }
        if (red((*raiz)->l) && red((*raiz)->l->l))
        {
            rotacionaDir(raiz);
            (*raiz)->red = 0;
            (*raiz)->r->red = 1;
        }
    }
    else
    {
        insereR(&(*raiz)->r, x, 1);
        if (red((*raiz)) && red((*raiz)->r) && !sw)
        {
            rotacionaEsq(raiz);
        }
        if (red((*raiz)->r) && red((*raiz)->r->r))
        {
            rotacionaEsq(raiz);
            (*raiz)->red = 0;
            (*raiz)->l->red = 1;
        }
    }
}

void insere(Item x)
{
    insereR(&raiz, x, 0);
    raiz->red = 0;
}

int buscaR(link raiz, int v)
{
    if (raiz == NULL)
        return itemNull;
    int t = raiz->item;
    if (v == t || v == 0)
    {
        return raiz->item;
    }
    if (v < t)
    {
        return buscaR(raiz->l, v);
    }
    else
    {
        return buscaR(raiz->r, v);
    }
}

int busca(int v)
{
    return buscaR(raiz, v);
}

int main(int argc, char const *argv[])
{
    int num_casos,num;
    scanf("%d", &num_casos);
    for (int i = 0; i < num_casos; i++)
    {
        scanf("%d", &num);
        insere(num);

    }

    while (scanf("%d", &num) != EOF)
    {
        if (busca(num))
        {
            printf("sim\n");
        }
        else
        {
            printf("nao\n");
        }
    }
    return 0;
}
