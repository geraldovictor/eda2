#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  int num_proibidos,num;
  scanf("%d",&num_proibidos);
  int *vetor;
  vetor = malloc(num_proibidos*sizeof(int));
  for(int i = 0 ; i < num_proibidos ; i++){
    scanf("%d",&vetor[i]);
  }
  while(scanf("%d",&num)!=EOF){
    for(int i =0; i < num_proibidos; i++){
      if(num==vetor[i]){
        printf("sim\n");
        break;
      }else if(i == num_proibidos -1&& vetor[i]!=num){
        printf("nao\n");
      }
    }
  }
  return 0;
}
