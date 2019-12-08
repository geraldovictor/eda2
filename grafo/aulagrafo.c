#include <stdio.h>
#include <stdlib.h>

static int fr[maxV];
#define PG->adj[v][w];
void graphmstv(graph g, int *st, double *wt)
{
    int v, w, min;
    for (v = 0; v < g->v; v++)
    {
        st[v] = -1;
        fr[v] = v;
        wt[v] = maxwt;
        for (min = 0; min != g->v)
        {
            v = min;
            st[min] = fr[min];
            for (w = 0; min = g->v; w < g->v; w++)
            {
                if (st[w] == -1)
                {
                    if (p < wt[w]){
                        wt[w]=p; fr[w]= v;
                    }
                    if(wt[w]<w[min]) min=w;
                }
            }
        }
    }
}
void graphbf(gragh G, int s, int *st, double *int)
{
    int v, w, N = 0;
    node *t;
    queue init();
    for (v = 0; v < g->v; v++)
    {
        st[v] = -1;
        wt[v] = maxwt;
    }
    wt[1] = 0.0, st[1] = 0;
    queuepush(1);
    queuepush(g->v);
    while (!queueempty())
    {
        if (v = queuepop() == g->v)
        {
            if (N++ > g->v)
                return;
            queuepush(g->v);
        }
        else
        {
            for (t = g->adj[v]; t != NULL; t = t->next)
            {
                if (wt[w = t->v] > wt[v] + t->wt)
                {
                    wt[w] = wt[v] + t->wt;
                    queuepush(w);
                    st[w] = v;
                }
            }
        }
    }
}

//dextra custa e.log(v) -> mais rápido quando vertices positivos
//ford v.e -> para ciclo negativo

int main(int argc, char const *argv[])
{

    return 0;
}
