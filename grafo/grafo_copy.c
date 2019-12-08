#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
            visitaPConta(g, v->vertices, cor, count);
        }
        v = v->prox;
    }
    cor[u] = VERMELHO;
    *count += 1;
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
    visitaPConta(g, 0, cor, count);
}
void inicializaGrafoD(GRAFOLISTA *g, int *d, int *p, int s)
{
    int v;
    for (v = 0; v < g->vertices; v++)
    {
        d[v] = INT_MAX / 2;
        p[v] = -1;
    }
    d[s] = 0;
}
void relaxa(GRAFOLISTA *g, int *d, int *p, int u, int v)
{
    ADJACENCIA *ad = g->adj[u].cab;
    while (ad && ad->vertices != v)
    {
        ad = ad->prox;
    }
    if (ad)
    {
        if (d[v] > d[u] + ad->peso)
        {
            p[v] = d[u] + ad->peso;
            p[v] = u;
        }
    }
}
bool existeAberto(GRAFOLISTA *g, int *aberto)
{
    int i;
    for (i = 0; i < g->vertices; i++)
    {
        if (aberto[i])
            return (true);
    }
    return (false);
}
int menorDist(GRAFOLISTA *g, int *aberto, int *d)
{
    int i;
    for (i = 0; i < g->vertices; i++)
        if (aberto[i])
            break;
    if (i == g->vertices)
        return (-1);
    int menor = i;
    for (i = menor + 1; i < g->vertices; i++)
    {
        if (aberto[i] && (d[menor] > d[i]))
            menor = i;
    }
    return (menor);
}
int *dijkstra(GRAFOLISTA *g, int s)
{
    int *d = malloc(g->vertices * sizeof(int));
    int p[g->vertices];
    bool aberto[g->vertices];
    inicializaGrafoD(g, d, p, s);

    int i;
    for (i = 0; i < g->vertices; i++)
    {
        aberto[i] = true;
    }
    while (existeAberto(g, aberto))
    {
        int u = menorDist(g, aberto, d);
        aberto[u] = false;
        ADJACENCIA *ad = g->adj[u].cab;
        while (ad)
        {
            relaxa(g, d, p, u, ad->vertices);
            ad = ad->prox;
        }
    }
    return (d);
}
int main(int argc, char const *argv[])
{
    GRAFOLISTA *gr = criaGrafo(8);

    int count = 0;
    criaAresta(gr, 0, 1, 2);

    
    imprimeGRAFO(gr);
    profundidadeConta(gr, &count);
    printf("Numero de vértices: %d", count);

    return 0;
}
