#include <stdio.h>
#include <stdlib.h>

typedef int Item;

int lesseq(Item *b, Item *a){
  if(*b<=*a) return 1;
  return 0;
}
void mergeAB(Item *c, Item *A, int M, Item *B, int N){
  int k=0, i = 0, j =0;
  while(i<M&&j<N){
    if(lesseq(&A[i],&B[j])){
      c[k]=A[i]; i++ , k++;
    }else{
      c[k]=B[j]; j++, k++;
    }
  }
  while(i<M){
    c[k]=A[i];
    i++;
    k++;
  }
  while(i<N){
    c[k]=B[j];
    j++;
    k++;
  }
}
void merge(Item *v, int l, int meio , int r){
  Item *c = malloc(sizeof(Item)*(r-l+1));
  mergeAB(c,&v[l],(meio-l+1),&v[meio+1],(r-(meio+1)+1));
  Item k = 0;
  int i = l;
  while(i<r-l+1){
    v[l]= c[i];
    i++;
    l++;

  }
  free(c);
}
// é ou não é estável
void mergeSort(Item *v, int l, int r){ //custo nlog n

  for (size_t i = 0; i < 5; i++) {
    printf("%d ",v[i]);
  }
  printf("\n");
  if(l==r) return;
  int meio =(l+r)/2;
  mergeSort(v,l,meio);
  mergeSort(v,meio+1,r);
  merge(v,l,meio,r);
}

int main(int argc, char const *argv[]) {
  int num_proibidos,num;
  scanf("%d",&num_proibidos);
  Item *vetor;
  vetor = malloc(num_proibidos*sizeof(Item));
  if(vetor == NULL)printf("Falha na alocação\n");
  for(int i = 0 ; i < num_proibidos ; i++){
    scanf("%d",&vetor[i]);
  }

  mergeSort(vetor,0,num_proibidos);
  // while(scanf("%d",&num)!=EOF){
  //   if(buscaBinaria(vetor,num_proibidos,num)==-1){
  //     printf("nao\n");
  //   }else{
  //     printf("sim\n");
  //   }
  // }
  return 0;
}
