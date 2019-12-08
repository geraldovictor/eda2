#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <map>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;
#define true 1
#define false 0
#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2

typedef int bln;
typedef int TIPOPESO;

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
    GRAFOLISTA *g = (GRAFOLISTA *)malloc(sizeof(GRAFOLISTA));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *)malloc(v * sizeof(VERTICE));
    for (int i = 0; i < v; i++)
        g->adj[i].cab = NULL;
    return (g);
}
ADJACENCIA *criaAdj(int v, int peso)
{
    ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
    temp->vertices = v;
    temp->peso = peso;
    temp->prox = NULL;
    return (temp);
}
bln criaAresta(GRAFOLISTA *gr, int vi, int vf, TIPOPESO p)
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

void profundidadeConta(GRAFOLISTA *g, int *count, int *lista, int tam, int *maior)
{
    int cor[g->vertices];

    int u;
    for (u = 0; u < g->vertices; u++)
    {
        cor[u] = BRANCO;
    }
    int i = 0;
    for (u = lista[i]; i < tam; u = lista[++i])
    {
        // printf("%d",u);
        if (cor[u] == BRANCO)
        {
            visitaPConta(g, u, cor, count);
            if((*count) > (*maior)){
                *maior = *count;
            }
            *count = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    int num_esp, num_rel;
    int count = 0, maior=0;
    char nome[31];
    char predador[31];
    char presa[31];
    map<string, int> cadeia;
    map<string, int>::iterator itmap;
    map<string, int>::iterator itmap2;
    while ((scanf("%d%d", &num_esp, &num_rel)))
    {
        if(num_esp == 0 && num_rel == 0) break;
        GRAFOLISTA *gr = criaGrafo(num_esp);
        int *lista = (int *)malloc(2 * num_rel * sizeof(int));
        //como faço pra ele percorrer só os que foram digitados
        for (int i = 0; i < num_esp; i++)
        {
            scanf("%s", nome);
            cadeia[nome] = i;
        }
        for (int i = 0; i < num_rel; i++)
        {
            scanf("%s", predador);
            scanf("%s", presa);
            itmap = cadeia.find(predador);
            itmap2 = cadeia.find(presa);
            criaAresta(gr, itmap->second, itmap2->second, 1);
            criaAresta(gr, itmap2->second, itmap->second, 1);
            lista[i] = itmap->second;
            lista[i + num_rel] = itmap2->second;
        }
        if (num_rel > 0)
        {
            num_rel *= 2;
            // for (size_t k = 0; k < num_rel; k++)
            // {
            //     printf("%d", lista[k]);
            // }

            profundidadeConta(gr, &count, lista, num_rel,&maior);
            printf("%d\n", maior);
        }else{
            printf("%d\n", maior+1);
        }
            free(gr);
            free(lista);
            count = 0;
            maior = 0;
    }
    return 0;
}
