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

void empilha(int y, int *pilha, int *topo){
  pilha[*topo] = y;
  *topo +=+1;
}

int desempilha(int *pilha, int *topo){
  *topo -= 1;
  return pilha[*topo];
}

int pilhavazia(int *topo){
  return *topo <= 0;
}

void enfileira(int aux, int *fila, int tam_fila){

}
int main(int argc, char const *argv[]) {
  int n=0, topo=0, j=0;
  while(scanf("%d",&n)==1&&n!=0){
    int *vetor;
    vetor = malloc(n*sizeof(int));
    int *aux;
    aux = malloc(n*sizeof(int));
    int *pilha;
    pilha = malloc(n*sizeof(int));
    for(int i =0; i < n; i++){
        scanf("%d",&vetor[i]);
        aux[i]=vetor[i];
    }
    insertionSortSimple(vetor,0, n);

    for(int i =0; i < n ; i++){
      while(vetor[i]!=aux[j]&&j<n){ // se o esperado for diferente
        if(i>0&&vetor[i]==pilha[topo-1]){ // se o esperado estiver no topo da pilha
          desempilha(pilha,&topo);
          j--;
          break;
        }
        empilha(aux[j],pilha,&topo);
        j++;
      }
      j++;
      if(j>=n){
        while(vetor[i]==pilha[topo-1]){
          desempilha(pilha,&topo);
        }
      }

    }
    if(pilhavazia(&topo)){
      printf("yes\n");
    }else{
      printf("no\n");
    }
    topo=0, j=0;
    free(vetor);
    free(pilha);
    free(aux);
  }


  return 0;
}
