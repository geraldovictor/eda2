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
  {                      // 1
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
void desempilha(int *t)
{
  *t -= 1;
}

void empilha(end *pilha, end *v, int *t, int posi)
{
  pilha[*t] = v[posi];
  *t += 1;
}
int main(int argc, char const *argv[])
{
  int t = 0, posi = 0;
  end *pilha = malloc(250000 * sizeof(end));
  end *v = malloc(250000 * sizeof(end));
  unsigned long int atual, prox, ant, contador = 0, primeiro, ultimo;
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

  if (contador > 2)
  {
    mergesort(0, contador, v);

    unsigned long next = ptr1.prox;

    for (size_t i = 0; i < contador; i++)
    {
      posi = buscaBinaria(v, contador, next);
      if (posi != -1)
      {
        if (next == ptr2.atual)
        {
          break;
        }
        else
        {
          empilha(pilha, v, &t, posi);
        }
        next = v[posi].prox;
      }
    }
    //    for(int i =0 ; i < t ; i++){
    //        printf("%lx\n", pilha[i].atual);
    //    }
    unsigned long aux_anterior = ptr2.ant;
    //    printf("%d\n", t);
    while (t > 0)
    {
      // a partir do prt2 quero ver se os anteriri dele é igual ao topo da pilha
      if (aux_anterior == pilha[t - 1].atual)
      {
        aux_anterior = pilha[t - 1].ant;
        desempilha(&t);
      }
      else
      {
        printf("insana\n");
        break;
      }
    }
    if (t == 0)
      printf("sana\n");
    //    printf("%d\n", t);
  }
  else
  {
    if (ptr1.prox == ptr2.atual && ptr2.ant == ptr1.atual)
    {
      printf("sana\n");
    }
    else
    {
      printf("insana\n");
    }
  }
  free(v);
  free(pilha);
  return 0;
}
