#include <stdio.h>
#include <stdlib.h>
#define RED 1
#define BLACK 0

typedef struct NO *ArvLLRB;

struct NO
{
    int info;
    int cor;
    struct NO *esq;
    struct NO *dir;
};

void criaArvore(ArvLLRB *T)
{
    *T = NULL;
}

struct NO *rotacionaEsquerda(struct NO *A)
{
    struct NO *B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO *rotacionaDireita(struct NO *A)
{
    struct NO *B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}
int cor(struct NO *H)
{
    if (H == NULL)
    {
        return BLACK;
    }
    else
        return H->cor;
}
void TrocaCor(struct NO *H)
{
    H->cor = !H->cor;
    if (H->esq != NULL)
        H->esq->cor = !H->esq->cor;
    if (H->dir != NULL)
        H->dir->cor = !H->dir->cor;
}
struct NO *move2EsqRED(struct NO *H)
{
    TrocaCor(H);
    if (cor(H->dir->esq) == RED)
    {
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        TrocaCor(H);
    }
    return H;
}
struct NO *move2DirRED(struct NO *H)
{
    TrocaCor(H);
    if (cor(H->esq->esq) == RED)
    {
        H = rotacionaDireita(H);
        TrocaCor(H);
    }
    return H;
}
struct NO *balancear(struct NO *H)
{
    if (cor(H->dir) == RED)
        H = rotacionaEsquerda(H);

    if (H->esq != NULL && cor(H->dir) == RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);
    if (cor(H->esq) == RED && cor(H->dir) == RED)
        TrocaCor(H);
    return H;
}
struct NO *insereNo(struct NO *H, int valor, int *resp)
{
    if (H == NULL)
    {
        struct NO *novo;
        novo = malloc(sizeof(struct NO));
        if (novo == NULL)
        {
            *resp = 0;
            // printf("ok1");
            return NULL;
        }
    novo->info = valor;
    novo->cor = RED;
    novo->dir = NULL;
    novo->esq = NULL;
    *resp = 1;
    return novo;
    }
    if (valor == H->info)
    {
        // printf("ok2");
        *resp = 0;
    }
    else
    {
        if (valor < H->info)
        {
            H->esq = insereNo(H->esq, valor, resp);
        }
        else
            H->dir = insereNo(H->dir, valor, resp);
    }
    if (cor(H->dir) == RED && cor(H->esq) == BLACK)
        H = rotacionaEsquerda(H);
    if (cor(H->esq) == RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);
    if (cor(H->esq) == RED && cor(H->dir) == RED)
        TrocaCor(H);
    return H;
}
int insere_ArvLLRB(ArvLLRB *raiz, int valor)
{
    int resp;
    *raiz = insereNo(*raiz, valor, &resp);
    if ((*raiz) != NULL)
        (*raiz)->cor = BLACK;
    return resp;
}
struct NO *removerMenor(struct NO *H)
{
    if (H->esq == NULL)
    {
        free(H);
        return NULL;
    }
    if (cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
        H = move2EsqRED(H);
    H->esq = removerMenor(H->esq);
    return balancear(H);
}
struct NO *procuraMenor(struct NO *atual)
{
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while (no2 != NULL)
    {
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

struct NO *remove_NO(struct NO *H, int valor)
{
    if (valor < H->info)
    {
        if (cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
            H = move2EsqRED(H);
        H->esq = remove_NO(H->esq, valor);
    }
    else
    {
        if (cor(H->esq) == RED)
            H = rotacionaEsquerda(H);
        if (valor == H->info && (H->dir == NULL))
        {
            free(H);
            return NULL;
        }
        if (cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK)
            H = move2DirRED(H);
        if (valor == H->info)
        {
            struct NO *x = procuraMenor(H->dir);
            H->info = x->info;
            H->dir = removerMenor(H->dir);
        }
        else
        {
            H->dir = remove_NO(H->dir, valor);
        }
    }
    return balancear(H);
}
ArvLLRB consulta_ArvLLRB(ArvLLRB T, int dado)
{
    ArvLLRB achou;
    if (T == NULL)
        return NULL;
    if (T->info == dado)
        return T;
    achou = consulta_ArvLLRB(T->esq, dado);
    if (achou == NULL)
        achou = consulta_ArvLLRB(T->dir, dado);
    return achou;
}
int remove_arvore_ArvLLRB(ArvLLRB *raiz, int valor)
{
    if (consulta_ArvLLRB(*raiz, valor) != NULL)
    {
        struct NO *h = *raiz;
        *raiz = remove_NO(h, valor);
        if (*raiz != NULL)
            (*raiz)->cor = BLACK;
        return 1;
    }
    else
    {
        return 0;
    }
}
void imprimeInOrder(ArvLLRB T)
{
    if (T == NULL)
        return;
    if (T->esq != NULL)
        imprimeInOrder(T->esq);
    printf("%d ", T->info);
    if (T->dir != NULL)
        imprimeInOrder(T->dir);
}
int main(int argc, char const *argv[])
{
    int num_cases;
    int num, resultado;
    ArvLLRB *raiz; 
    raiz = malloc (sizeof(struct NO));
    criaArvore(raiz);
    scanf("%d", &num_cases);
    for (int i = 0; i < num_cases; i++)
    {
        scanf("%d", &num);
        resultado = insere_ArvLLRB(raiz, num);
        // printf("%d\n", resultado);
    }
    // imprimeInOrder(*raiz);

    while (scanf("%d", &num) != EOF)
    {
        if (consulta_ArvLLRB(*raiz, num) != NULL)
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
