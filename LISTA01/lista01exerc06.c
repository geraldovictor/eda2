#include <stdio.h>
#include <stdlib.h>

typedef int Item;
void exch(int *a, int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
int less(int *b, int *a){
  if(*b<*a) return 1;
  return 0;
}
void compexch(int v[], int j){
  if(less(&v[j],&v[j-1])) exch(&v[j-1],&v[j]);
}
 void insertionSortSimple(int v[], int l, int r){
   int i , j;
   for(i=l+1; i<r; i++){
     for(j=i; j>l ;j--){
       compexch(v, j);
       // if(less(&v[j],&v[j-1])) exch(&v[j-1],&v[j]);
     }
   }
 }
 void insertionSort(int v[], int l, int r){
   int i,j;
   for (i=r; i>=l; i--) compexch(v, j);
   for (i=l+1; i<r ; i++){
   Item menor = v[i], j=i;
     while(less(&menor, &v[j-1])){
       v[j]=v[j-1];
       j--;
     }
     v[j]=menor;
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
  n--;
  insertionSort(vetor,0, n);
  for(int j =0 ; j < n ; j++){
    if(j!=n-1) printf("%d ",vetor[j]);
    else printf("%d\n", vetor[j] );
  }
  free(vetor);
  return 0;
}
