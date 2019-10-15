#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void mergeAB(int p, int q, int r, int *v){
  int *w;
  w = malloc ((r-p) * sizeof (int));
  int i = p, j = q;
  int k = 0;

  while (i < q && j < r) {
    if (v[i] <= v[j])  w[k++] = v[i++];
    else  w[k++] = v[j++];
  }
  while (i < q)  w[k++] = v[i++];
  while (j < r)  w[k++] = v[j++];
  for (i = p; i < r; ++i)  v[i] = w[i-p];
  free (w);
}
void mergesort (int p, int r, int v[]){
   if (p < r-1) {                 // 1
      int q = (p + r)/2;          // 2
      mergesort (p, q, v);        // 3
      mergesort (q, r, v);        // 4
      mergeAB (p, q, r, v);     // 5
   }
}
int buscaBinaria(Item *vetor,int tamanho, int chave) {
	int i = 0;
	int f = tamanho -1;
	int meio;
	while (i<=f) {
		meio = (i+f)/2;
		if (vetor[meio]==chave)
			return meio;
		else {
			if (chave>vetor[meio])
				i=meio+1;
			else
				f=meio-1;
		}
	}
	return -1;
}
int main(int argc, char const *argv[])
{
    int n, m, j, num, posi;
    int **vetor_n = malloc(2000 * sizeof(int *));
    for (int i = 0; i < 2000; i++)
    {
        vetor_n[i] = malloc(1000000 * sizeof(int));
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         vetor_n[i][j]=i;
    //     }
    // }
    //  for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("%d",vetor_n[i][j]);
    //     }
    //     printf("\n");
    // }
    scanf("%d", &n); //vizinhanças
    scanf("%d", &m); //lugares que ele ja esteve
    scanf("%d", &j); //lugar que ele vai visitar
    int *vetor_m = malloc(m * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &vetor_n[i][num]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &vetor_m[i]);
    }
    mergesort(0,m,vetor_m);
    for (int i = 0; i < j; i++)
    {
        scanf("%d", &num);
        posi=buscaBinaria(vetor_m,m,num);
        if(posi!=-1){
            printf("Eu vou estar la\n");
        }else{
            for(int j = 0 ; j < m; j++) {
                //para cada posição lugar que julius esteve veja quais são visinhos
                //se algum desses lugares for visinho "eu vou estar la"
                posi=buscaBinaria(v)
            }       
        }

    }
    
    return 0;
}
