static int flowV(gragh g, int v)
{
    node *t;
    int x = 0;
    for (t = g->adj[v]; t != NULL; t = t->next)
    {
        x += t->flow;
    }
    return x;
}

int graphFlow(graph g, int s, int t)
{
    int v, val = flowV(g, s);
    for (v = 0; v < v->v; v++)
    {
        if ((v != s) && (v != t))
            if (flowV(g, v) != 0)
                return 0;
        if (val + flowV(g, t) != 0)
            return 0;
        if (val <= 0)
            return 0;
        return val;
    }
}

void graphmaxflow(grafph g, int s, int t)
{
    int x, d;
    node *st[max];
    while ((d = graphpfs(g, s, t, st)) != 0)
    {
        for (x = t; x != t; x = st[x]->dup->v)
        {
            st[x]->flowt += d;
            st[x]->dup->flow -= d;
        }
    }
}