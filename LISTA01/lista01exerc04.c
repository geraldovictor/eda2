#include <stdio.h>

int main(){
/*
~~~~~~~~~~~
    |||
    |||
    ||| ---
  L |||
  L >||
~~~~~~~~~~~
~~~~~~~~~~~
 ---|||
    |||
    |||---
  L |||
  L |||
~~~~~~~~~~~
~~~~~~~~~~~
 ---|||
    |||
    |||---
  L |||
  L |||
~~~~~~~~~~~

*/

  int bases_arvore=0;
  int num_ga=0;
  char posi='\0';
  int linha=0;
  // primeiro vou ler a arvore e armazená-la como matriz
  scanf("%d", &bases_arvore);
  char matriz_arv[bases_arvore][11];
  for(int i=0; i < bases_arvore; i++){
    for(int j=0; j < 11 ; j++){
      matriz_arv[i][j]='\0';
      matriz_arv[i][j]=' ';
    }
  }
  scanf("%d",&num_ga);
  for(int i =0; i < num_ga; i++){
    scanf(" %c %d", &posi, &linha);
    if(posi=='D'){
      matriz_arv[linha][8]='-';
      matriz_arv[linha][9]='-';
      matriz_arv[linha][10]='-';
    }else if(posi=='E'){
      matriz_arv[linha][3]='-';
      matriz_arv[linha][2]='-';
      matriz_arv[linha][1]='-';
    }
  }
  scanf(" %c", &posi);
  if(posi=='D'){
    matriz_arv[bases_arvore-1][9]='L';
    matriz_arv[bases_arvore-2][9]='L';
  }else if(posi=='E'){
    matriz_arv[bases_arvore-1][3]='L';
    matriz_arv[bases_arvore-2][3]='L';
  }
  for(int i=0 ; i < bases_arvore; i++){ //colocando os troncos
    matriz_arv[i][4]= '|';
    matriz_arv[i][5]= '|';
    matriz_arv[i][6]= '|';
  }
  printf("~~~~~~~~~~~\n");
  for(int i= 0; i < bases_arvore; i++){
    for(int j= 0; j < 11 ; j++){
      printf("%c",matriz_arv[i][j]);
    }
    printf("\n");
  }
  printf("~~~~~~~~~~~\n");
  return 0;
}
