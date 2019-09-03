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

  for (size_t i = 0; i < 7; i++) {
    printf("%d ",v[i]);
  }
  printf("\n");
  if(l==r) return;
  int meio =(l+r)/2;
  mergeSort(v,l,meio);
  mergeSort(v,meio+1,r);
  merge(v,l,meio,r);
}
void exch(Item *a, Item *b){
  Item temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
// int lesseq(Item *b, Item *a){
//   if(*b<=*a) return 1;
//   return 0;
// }
int less(Item *b, Item *a){
  if(*b<*a) return 1;
  return 0;
}

void compexch(Item *V, Item j){
  if(less(&V[j],&V[j-1])) exch(&V[j-1],&V[j]);
}
static int separa(Item *V, int l, int r){ //função static equilave a private em relação a OO
  Item c = V[r]; // 1,
  Item j=l ; // 0
  for(int i=l; i <r ; i++){
  if(lesseq(&V[i],&c)){
    exch (&V[i],&V[j]);
    j++;
  }
  /*se o valor da minha posição atual for menor ou igual a esse meu pivô
  soma 1 no contador
  senão joga esse elemento pra ultima se não
  */
  }
  exch(&V[r], &V[j]);
  return j;
}
void quicksort(Item *V, int l, int r){ // complexidade nlog n de casos médio , para aumentar a probabilidade de de ser n log n vc pega r, l e r+l/2 e usa a madianacomo pivô
  // compexch(V[l],V[r]);//mediana
  // compexch(V[(r+l/2)],V[l]);
  // compexch(V[r],V[l]);
  //if (ps> 2*lg(r)) return; // quando o elemento está demorando muito
  // if(r-l>M){
    if(l<r){
      Item j =separa(V,l,r);

      if(j-1-l> r-j+1){//qual caso tem menos elemento
        quicksort(V,l,j-1);
        quicksort(V,j+1,r);
      }else{
        quicksort(V,j+1,r);
        quicksort(V,l,j-1);
      }
    }
  // }//else{
    //insertion(v,l,r);
  //}
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
  while(scanf("%d",&num)!=EOF){
    if(buscaBinaria(vetor,num_proibidos,num)==-1){
      printf("nao\n");
    }else{
      printf("sim\n");
    }
  }
  return 0;
}
