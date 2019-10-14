#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned long int atual;
    unsigned long int prox;
    unsigned long int ant;
} end;

static void mergeAB(int p, int q, int r, end *v)
{
    end *w;
    w = malloc((r - p) * sizeof(end));
    int i = p, j = q;
    int k = 0;

    while (i < q && j < r)
    {
        if (v[i].atual <= v[j].atual)
        {
            w[k] = v[i];
            i++;
            k++;
        }
        else
        {
            w[k] = v[j];
            j++;
            k++;
        }
    }
    while (i < q)
    {
        w[k] = v[i];
        i++;
        k++;
    }
    while (j < r)
    {
        w[k] = v[j];
        j++;
        k++;
    }
    for (i = p; i < r; ++i)
    {
        v[i] = w[i - p];
    }
    free(w);
}
void mergesort(int p, int r, end *v)
{
    if (p < r - 1)
    {                        // 1
        int q = (p + r) / 2; // 2
        mergesort(p, q, v);  // 3
        mergesort(q, r, v);  // 4
        mergeAB(p, q, r, v); // 5
    }
}
int buscaBinaria(end *vetor, int tamanho, unsigned long chave)
{
    int i = 0;
    int f = tamanho - 1;
    int meio;
    while (i <= f)
    {
        meio = (i + f) / 2;
        if (vetor[meio].atual == chave)
            return meio;
        else
        {
            if (chave > vetor[meio].atual)
                i = meio + 1;
            else
                f = meio - 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int t = 0, posi = 0, ultimo;
    end *pilha = malloc(250000 * sizeof(end));
    end *v = malloc(250000 * sizeof(end));
    unsigned long int atual, prox, ant, contador = 0, primeiro;
    end ptr1, ptr2;
    while (scanf("%lx%lx%lx", &atual, &ant, &prox) == 3)
    {
        v[contador].atual = atual;
        v[contador].prox = prox;
        v[contador].ant = ant;
        contador++;
    }
    ptr1.atual = v[0].atual;
    ptr1.ant = v[0].ant;
    ptr1.prox = v[0].prox;
    ptr2.atual = v[1].atual;
    ptr2.ant = v[1].ant;
    ptr2.prox = v[1].prox;
    int teste = 0;
    mergesort(0, contador, v);
    // end *v2 = malloc(250000 * sizeof(end));
    // for(int i = 0 ; i < contador ; i ++){
    //     v2[i].atual=v[i].atual;
    // }
    posi = buscaBinaria(v, contador, ptr2.prox);
    v[posi].ant = ptr1.ant;
    posi = buscaBinaria(v, contador, ptr1.ant);
    v[posi].prox = ptr2.prox;

    while (posi != -1)
    {
        ultimo = posi;
        posi = buscaBinaria(v, contador, v[posi].ant);
    }
    // if(buscaBinaria(v,contador,12)){
    //    printf("ok");
    // }
    posi = ultimo;
    while (posi != -1)
    {
        printf("%lx %lx %lx\n", v[posi].atual, v[posi].ant, v[posi].prox);
        posi = buscaBinaria(v, contador, v[posi].prox);
    }
    printf("\n");
    posi = buscaBinaria(v, contador, ptr1.atual);
    // printf("**%lx**\n",ptr2.atual);
    while (v[posi].prox != ptr2.atual)
    {
        printf("%lx\n", v[posi].atual);
        // printf("**%lx**\n",v[posi].prox);
        posi = buscaBinaria(v, contador, v[posi].prox);
    }
    printf("%lx\n", v[posi].atual);
    printf("%lx\n", v[posi].prox);

    return 0;
}
