#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2

typedef int bool;
typedef int TIPOPESO;

typedef struct grafo
{
    int vertices;
    int arestas;
    TIPOPESO **adj;

} GRAFO;

typedef struct adjacencia
{
    int vertices;
    TIPOPESO peso;
    struct adjacencia *prox;

} ADJACENCIA;

typedef struct vertice
{
    //os dados armazenados ficam aqui
    ADJACENCIA *cab;
} VERTICE;

typedef struct grafolista
{
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFOLISTA;

GRAFOLISTA *criaGrafo(int v)
{
    GRAFOLISTA *g = malloc(sizeof(GRAFOLISTA));
    g->vertices = v;
    g->arestas = 0;
    g->adj = malloc(v * sizeof(VERTICE));
    for (int i = 0; i < v; i++)
        g->adj[i].cab = NULL;
    return (g);
}
ADJACENCIA *criaAdj(int v, int peso)
{
    ADJACENCIA *temp = malloc(sizeof(ADJACENCIA));
    temp->vertices = v;
    temp->peso = peso;
    temp->prox = NULL;
    return (temp);
}
bool criaAresta(GRAFOLISTA *gr, int vi, int vf, TIPOPESO p)
{
    if (!gr)
        return (false);
    if ((vf < 0) || (vi >= gr->vertices))
        return (false); //vi = vertice inicial vf = vertice final
    if ((vi < 0) || (vi >= gr->vertices))
        return (false);
    ADJACENCIA *novo = criaAdj(vf, p);
    novo->prox = gr->adj[vi].cab;
    gr->adj[vi].cab = novo;
    gr->arestas++;
    return (true);
}
void imprimeGRAFO(GRAFOLISTA *gr)
{
    printf("Vértices: %d. Arestas: %d. \n", gr->vertices, gr->arestas);
    int i;
    for (i = 0; i < gr->vertices; i++)
    {
        printf("v%d: ", i);
        ADJACENCIA *ad = gr->adj[i].cab;
        while (ad)
        {
            printf("v%d(%d) ", ad->vertices, ad->peso);
            ad = ad->prox;
        }
        printf("\n");
    }
}
void visitaP(GRAFOLISTA *g, int u, int *cor)
{
    cor[u] = AMARELO;
    ADJACENCIA *v = g->adj[u].cab;
    while (v)
    {
        if (cor[v->vertices] == BRANCO)
            visitaP(g, v->vertices, cor);
        v = v->prox;
    }
    cor[u] = VERMELHO;
}
void visitaPConta(GRAFOLISTA *g, int u, int *cor, int *count)
{
    cor[u] = AMARELO;
    ADJACENCIA *v = g->adj[u].cab;
    while (v)
    {
        if (cor[v->vertices] == BRANCO)
        {
            visitaPConta(g, v->vertices, cor);
            *count += 1;
        }
        v = v->prox;
    }
    cor[u] = VERMELHO;
    //preciso contar só os nos que se conectam com alguem
    
}
void profundidade(GRAFOLISTA *g)
{
    int cor[g->vertices];

    int u;
    for (u = 0; u < g->vertices; u++)
    {
        cor[u] = BRANCO;
    }
    for (u = 0; u < g->vertices; u++)
    {
        if (cor[u] == BRANCO)
            visitaP(g, u, cor);
    }
}
void profundidadeConta(GRAFOLISTA *g, int *count)
{
    int cor[g->vertices];

    int u;
    for (u = 0; u < g->vertices; u++)
    {
        cor[u] = BRANCO;
    }
    for (u = 0; u < g->vertices; u++)
    {
        if (cor[u] == BRANCO)
            visitaPConta(g, u, cor, count);
    }
}
int main(int argc, char const *argv[])
{
    int count;
    GRAFOLISTA *gr = criaGrafo(5);
    criaAresta(gr, 0, 1, 2);
    criaAresta(gr, 1, 2, 4);
    criaAresta(gr, 2, 0, 12);
    criaAresta(gr, 2, 4, 40);
    criaAresta(gr, 3, 1, 3);
    criaAresta(gr, 4, 3, 8);

    imprimeGRAFO(gr);
    profundidadeConta(gr, &count);
    printf("Numero de vértices: %d", count);
    return 0;
}
