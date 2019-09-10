#include <stdio.h>
#include <stdlib.h>

static void mergeAB(int p, int q, int r, int v[]){
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

typedef struct{
  int mecha;
}pato;

int main(int argc, char const *argv[]) {
  int num_pato=0,num_cor=0, i, maior =0, atual=0, mais_vezes=0, indice_maior=0,conta_cores=1,tipo_cor=0;
  while(scanf("%d",&num_pato)!=0&& num_pato!=0){
    int *vetor;
    vetor = malloc(num_pato*sizeof(int));
    for(i = 0; i < num_pato; i++){
      scanf("%d",&vetor[i]);
      if(vetor[i]>maior){
        maior=vetor[i];
      }

    }
    mergesort(0,num_pato,vetor);
    int *vetoraux = calloc(maior+1,sizeof(int));
    int *vetor_cores = malloc (sizeof(int));
    atual=vetor[0];
    for(i = 0; i < num_pato; i++){
      if(atual==vetor[i]){
        vetoraux[atual]++;
      }else{
        atual=vetor[i];
        vetoraux[atual]++;
        vetor_cores[tipo_cor] = vetor[i];
        tipo_cor++;
        conta_cores++;
        vetor_cores = realloc(vetor_cores , conta_cores*sizeof(int));
      }
    }

    for(i = 1 ; i <= maior; i++){
      if(vetoraux[i]>mais_vezes){
        mais_vezes=vetoraux[i];
        indice_maior=i;
      }
    }
    printf("%d\n",indice_maior );
    maior=0, mais_vezes =0;
    free(vetoraux);
    free(vetor);

  }

  return 0;
}
