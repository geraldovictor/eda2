#include <stdio.h>
#include <stdlib.h>

typedef int Item;
void exch(Item *a, Item *b){
  Item temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
int lesseq(Item *b, Item *a){
  if(*b<=*a) return 1;
  return 0;
}
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
int main(int argc, char const *argv[]) {
  int n=1,i=0;
  Item *vetor;
  vetor = malloc(sizeof(Item));
  while(scanf("%d", &vetor[i])!=EOF){
    i++;
    n++;
    vetor= realloc(vetor , n*sizeof(int));
  }
  i--;
  quicksort(vetor,0,i);
  for(int j =0 ; j < n-1 ; j++){
    if(j!=n-2) printf("%d ",vetor[j]);
    else printf("%d\n", vetor[j] );
  }
  free(vetor);

  return 0;
}
