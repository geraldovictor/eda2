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
*/

  int bases_arvore;
  int num_ga;
  char posi;
  int linha;
  // primeiro vou ler a arvore e armazená-la como matriz
  scanf("%d", &bases_arvore);
  char matriz_arv[bases_arvore][12];
  for(int i=0; i < bases_arvore; i++){
    for(int j=0; j < 12 ; j++){
      matriz_arv[i][j]='\0';
      matriz_arv[i][j]=' ';
    }
  }
  scanf("%d",&num_ga);
  for(int i=0 ; i < bases_arvore; i++){ //colocando os troncos
    matriz_arv[i][5]= '|';
    matriz_arv[i][6]= '|';
    matriz_arv[i][7]= '|';
    matriz_arv[i][12]='\n';
  }
  for(int i =0; i < num_ga; i++){
    scanf(" %c %d", &posi, &linha);
    if(posi=='D'){
      matriz_arv[linha][9]='-';
      matriz_arv[linha][10]='-';
      matriz_arv[linha][11]='-';
    }else if(posi=='E'){
      matriz_arv[linha][4]='-';
      matriz_arv[linha][3]='-';
      matriz_arv[linha][2]='-';
    }
  }
  scanf(" %c",&posi);
  printf("\n");
  for(int i=0; i < bases_arvore; i++){
    for(int j=0; j < 12 ; j++){
      printf("%c",matriz_arv[i][j]);
    }
  }
  // printf("~~~~~~~~~~~
  return 0;
}
