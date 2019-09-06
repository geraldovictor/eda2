#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]) {
  int num_lim=0, num_col=0,conta_t=0;
  scanf("%d",&num_lim );
  scanf("%d",&num_col );
  char vetor[num_lim][num_col];
  char linha[num_col+1];
  for(int i = 0 ; i < num_lim ; i++){
    scanf("%s", linha);
    for(int j = 0 ; j < strlen(linha); j++){
      if(linha[j]=='t') {
        conta_t++;
      }
      vetor[i][j]=linha[j];
    }
  }
  int altura[conta_t];
  for (int i = 0; i < conta_t; i++) {
    scanf("%d",&altura[i]);
  }
  conta_t=0;
  int linha_ini=0,col_ini=0,linha_final=0,col_final=0, conta_visao=0;
  for(int i = 0 ; i < num_lim ; i++){
    for(int j =0 ; j< num_col ; j++){
      if(vetor[i][j]=='t'){
        if(i-altura[conta_t]<0) linha_ini=0;
        if(i-altura[conta_t]>=0) linha_ini=i-altura[conta_t];
        if(i+altura[conta_t]>num_lim-1) linha_final=num_lim-1;
        if(i+altura[conta_t]<=num_lim-1) linha_final=i+altura[conta_t];

        if(j-altura[conta_t]<0) col_ini=0;
        if(j-altura[conta_t]>=0) col_ini=j-altura[conta_t];
        if(j+altura[conta_t]>num_col-1) col_final=num_col-1;
        if(j+altura[conta_t]<=num_col-1) col_final=j+altura[conta_t];

        for (int k = linha_ini; k <= linha_final; k++) {
          for (int l = col_ini; l <= col_final; l++) {
            if(vetor[k][l]!='t'&&vetor[k][l]!='.'){
              vetor[k][l]='.';
              conta_visao++;

            }
          }
        }
        conta_t++;
      }
    }
  }
  printf("%d\n",conta_visao );
  for(int i = 0 ; i < num_lim ; i++){
    for(int j =0 ; j< num_col ; j++){
      printf("%c", vetor[i][j]);
    }
    printf("\n");
  }

  return 0;
}
