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
int main(int argc, char const *argv[]) {
  int n=1,i=0;
  int *vetor;
  vetor = malloc(sizeof(int));
  while(scanf("%d", &vetor[i])!=EOF){
    i++;
    n++;
    vetor= realloc(vetor , n*sizeof(int));
  }
  mergesort(0,i,vetor);
  
  for(int j =0 ; j < n-1 ; j++){
    if(j!=n-2) printf("%d ",vetor[j]);
    else printf("%d\n", vetor[j] );
  }
  free(vetor);
  return 0;
}
