#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int num_senador, num_dep_est, num_dep_fed, i =0, j=0,voto,soma=0, validos, invalidos;
  int *vetor = calloc(1000000,sizeof(int));
  if(vetor==NULL) printf("Falha na alocação\n");

  scanf("%d",&num_senador );
  scanf("%d",&num_dep_fed );
  scanf("%d",&num_dep_est );

  while(scanf("%d",&voto)!=EOF){
    if(voto>0){
      validos++;
      vetor[voto]++;
    }else{
      invalidos++;
    }
  }
  int vetor_aux[1000000];
  for(i =0; i < 1000000; i++){
    if(vetor[i]!=0){
      if(i<100) soma+=vetor[i];
      vetor_aux[j]=i;
      j++;
    }
  }
  int pre_ele, maior=0;
  i=0;
  while(i < j){
    if(vetor_aux[i]>99) break;
    if(vetor[vetor_aux[i]]>maior){
      pre_ele = vetor_aux[i];
      maior = vetor[vetor_aux[i]];
    }
    i++;
  }
  maior = 0;
  i =0;
  int sen_ele[num_senador];
  int cod_maior=0;
  for (size_t k = 0; k < num_senador; k++) {
    while(i < j){
      if(vetor_aux[i]>999) break;
      if(vetor_aux[i]>99){
        if(vetor[vetor_aux[i]]>=maior&&vetor_aux[i]>cod_maior){
          sen_ele[k] = vetor_aux[i];
          maior = vetor[vetor_aux[i]];
          cod_maior = vetor_aux[i];
        }
      }
        i++;
      }
      vetor[sen_ele[k]] = 0;
      maior = 0;
      cod_maior = 0;
      i =0;
  }
  int fed_ele[num_dep_fed];
  cod_maior=0;
  for (size_t k = 0; k < num_dep_fed; k++) {
    while(i < j){
      if(vetor_aux[i]>9999) break;
      if(vetor_aux[i]>999){
        if(vetor[vetor_aux[i]]>=maior&&vetor_aux[i]>cod_maior){
          fed_ele[k] = vetor_aux[i];
          maior = vetor[vetor_aux[i]];
          cod_maior = vetor_aux[i];
        }
      }
      i++;
    }
    vetor[fed_ele[k]] = 0;
    maior = 0;
    cod_maior = 0;
    i =0;
  }
  int est_ele[num_dep_est];
  for (size_t k = 0; k < num_dep_est; k++) {
    while(i < j){
      if(vetor_aux[i]>9999){
        if(vetor[vetor_aux[i]]>=maior&&vetor_aux[i]>cod_maior){
          est_ele[k] = vetor_aux[i];
          maior = vetor[vetor_aux[i]];
          cod_maior = vetor_aux[i];
        }
      }
      i++;
    }
    vetor[est_ele[k]] = 0;
    maior = 0;
    cod_maior = 0;
    i =0;
  }
  printf("%d %d\n",validos, invalidos);
  // printf("%d\n",soma );
  // printf("%d\n",vetor[pre_ele] );
  if(vetor[pre_ele]<=(soma/2)) {
    printf("Segundo turno\n");
  }else{
      printf("%d\n", pre_ele);
  }
  for( i=0; i<num_senador; i++){
    if(i!=num_senador-1){
      printf("%d ", sen_ele[i]);
    }else{
      printf("%d\n", sen_ele[i]);

    }
      // printf("%d ", sen_ele[i]);
  }
  // printf("\n");
  for( i=0; i<num_dep_fed; i++){
    if(i!=num_dep_fed-1){
      printf("%d ", fed_ele[i]);
    }else{
      printf("%d\n", fed_ele[i]);
    }
      // printf("%d ", fed_ele[i]);
  }
  // printf("\n");
  for( i=0; i<num_dep_est; i++){
    if(i!=num_dep_est-1){
      printf("%d ", est_ele[i]);
    }else{
      printf("%d\n", est_ele[i]);
    }
      // printf("%d ", est_ele[i]);
  }
  // printf("\n");
  free(vetor);

  return 0;
}
