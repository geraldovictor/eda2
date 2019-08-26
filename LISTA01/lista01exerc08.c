#include <stdio.h>
#include <stdlib.h>

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
 int menor = v[i], j=i;
   while(less(&menor, &v[j-1])){
     v[j]=v[j-1];
     j--;
   }
   v[j]=menor;
 }
}
void desempilha(){

}
void empilha(int aux, int *pilha, int tam_pilha){
  pilha[tam_pilha-1]=aux;
}
void enfileira(int aux, int *fila, int tam_fila){

}
int main(int argc, char const *argv[]) {
  int n=0, zero =0, tam_pilha = 1, tam_fila=1;
  int *vetor;
  scanf("%d",&n );
  vetor = malloc(n*sizeof(int));
  int *aux;
  aux = malloc(n*sizeof(int));
  int *pilha;
  pilha = malloc(tam_pilha*sizeof(int));
  int *fila;
  fila = malloc(tam_fila*sizeof(int));
  for(int i =0; i < n+1; i++){
    if(i<n){
      scanf("%d",&vetor[i]);
      aux[i]=vetor[i];
    }else{
      scanf("%d",&zero);
    }
  }
  insertionSort(vetor,0, n);

  for(int i =0; i < n ; i++){
    while(aux[i]!=vetor[i]){ // se o esperado for diferente
      empilha(aux[i],pilha,tam_pilha);
      tam_pilha++;
      pilha = realloc (pilha,tam_pilha*sizeof(int)); // empilha os carros
    }

  }
  for(int i =0; i < n ; i++){
    while(aux[i]!=vetor[i]){ // se o esperado for diferente
      empilha(aux[i],pilha,tam_pilha);
      tam_pilha++;
      pilha = realloc (pilha,tam_pilha*sizeof(int));
    }
  }

  free(vetor);
  free(aux);
  free(pilha);
  return 0;
}
