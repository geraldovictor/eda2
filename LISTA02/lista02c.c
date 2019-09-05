#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Item;
typedef char item;

static int separa(char **V, int l, int r){ //função static equilave a private em relação a OO
  char c[21];
  strcpy(c,V[r]); // 1,
  Item j=l ; // 0
  for(int i=l; i <r ; i++){
    if(strcmp(V[i],c)<0){
      item temp[21];
      strcpy(temp,V[i]);
      strcpy(V[i],V[j]);
      strcpy(V[j],temp);
      j++;
    }
  }
  item temp2[21];
  strcpy(temp2,V[r]);
  strcpy(V[r],V[j]);
  strcpy(V[j],temp2);
  return j;
}
void quicksort(char **V, int l, int r){ // complexidade nlog n de casos médio , para aumentar a probabilidade de de ser n log n vc pega r, l e r+l/2 e usa a madianacomo pivô
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
}
int main(int argc, char const *argv[]) {
  int num_casos, sorteado;
  scanf("%d", &num_casos );
  scanf("%d",&sorteado);
  char **vetor;
  vetor = malloc (num_casos*sizeof(char *));
  if(vetor == NULL) printf("Falha na alocação!!!\n");
  for (size_t i = 0; i < num_casos; i++) {
    vetor[i] = malloc (21*sizeof(char));
    if(vetor[i] == NULL) printf("Falha na alocação!!!\n");
  }

  for (size_t i = 0; i < num_casos; i++) {
    scanf("%s", vetor[i]);
  }
  quicksort(vetor,0,num_casos-1);

  printf("%s",vetor[sorteado-1] );
  for (size_t i = 0; i < num_casos; i++) {
    free(vetor[i]);
  }
  free(vetor);
  return 0;
}
