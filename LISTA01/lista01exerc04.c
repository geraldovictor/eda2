#include <stdio.h>
#include <string.h>

void atribui_inicial(char matriz_arv[][11], char posi, char lado_atual, int bases_arvore, int num_ga,int linha){
  for(int i=0; i < bases_arvore; i++){
    for(int j=0; j < 11 ; j++){
      matriz_arv[i][j]='\0';
      matriz_arv[i][j]=' ';
    }
  }
  if(posi=='D'){
    matriz_arv[linha][8]='-';
    matriz_arv[linha][9]='-';
    matriz_arv[linha][10]='-';
  }else if(posi=='E'){
    matriz_arv[linha][3]='-';
    matriz_arv[linha][2]='-';
    matriz_arv[linha][1]='-';
  }
  if(lado_atual=='D'){
    matriz_arv[bases_arvore-1][8]='L';
    matriz_arv[bases_arvore-2][8]='L';
  }else if(lado_atual=='E'){
    matriz_arv[bases_arvore-1][2]='L';
    matriz_arv[bases_arvore-2][2]='L';
  }
  for(int i=5 ; i < bases_arvore; i++){ //colocando os troncos
    matriz_arv[i][4]= '|';
    matriz_arv[i][5]= '|';
    matriz_arv[i][6]= '|';
  }

}

void imprime(char matriz_arv[][11],int linha_arv, int bases_arvore, int linha_atual){
  printf("~~~~~~~~~~~\n");
  for(int i= linha_arv; i < bases_arvore; i++){
    for(int j= 0; j < 11 ; j++){
      printf("%c",matriz_arv[i][j]);
    }
    printf("\n");
  }
    printf("~~~~~~~~~~~\n");
}
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
  int bases_arvore=0,num_ga=0,linha=0,linha_atual=0, linha_arv=0;
  char lado_atual='\0',posi='\0';
  char comandos[2000];
  // primeiro vou ler a arvore e armazená-la como matriz
  scanf("%d", &bases_arvore);
  bases_arvore+=5;
  char matriz_arv[bases_arvore][11];
  scanf("%d",&num_ga);
  for(int i =0; i < num_ga; i++){
    scanf(" %c %d", &posi, &linha);
  }
  scanf(" %c", &lado_atual);
  scanf("%s", comandos);
  atribui_inicial(matriz_arv,posi,lado_atual, bases_arvore, num_ga, linha);
  linha_arv = bases_arvore -5;
  linha_atual=bases_arvore-1;
  imprime(matriz_arv, linha_arv, bases_arvore, linha_atual);
  for(int i =0 ; i< strlen(comandos); i++){
    if(comandos[i]=='T'){
      if((lado_atual=='E')&&(matriz_arv[linha_atual][9]!='-'||matriz_arv[linha_atual-1][9]!='-')){
        matriz_arv[linha_atual][2]=' ';
        matriz_arv[linha_atual-1][2]=' ';
        matriz_arv[linha_atual][8]='L';
        matriz_arv[linha_atual-1][8]='L';
      }else if((lado_atual=='D')&& (matriz_arv[linha_atual][9]!='-'||matriz_arv[linha_atual-1][9]!='-')){
        matriz_arv[linha_atual][2]='L';
        matriz_arv[linha_atual-1][2]='L';
        matriz_arv[linha_atual][8]=' ';
        matriz_arv[linha_atual-1][8]=' ';
      }else{
        printf("**beep**\n");
        break;
      }
    }else if(comandos[i]=='B'){
      if(lado_atual=='E'&&matriz_arv[linha_atual][4]=='|'){
        matriz_arv[linha_atual][4]='>';
        imprime(matriz_arv, linha_arv, bases_arvore, linha_atual);
      }else if (lado_atual=='D'&&matriz_arv[linha_atual][6]=='|'){
        matriz_arv[linha_atual][6]='<';
        imprime(matriz_arv, linha_arv, bases_arvore, linha_atual);
      }else if (lado_atual=='E'&&matriz_arv[linha_atual][4]=='>'&&matriz_arv[linha_atual-2][3]==' '){
        matriz_arv[linha_atual-2][2]='L';
        imprime(matriz_arv, linha_arv-1, bases_arvore-1, linha_atual);
      }else if (lado_atual=='D'&&matriz_arv[linha_atual][6]=='>'&&matriz_arv[linha_atual-2][9]==' '){
        matriz_arv[linha_atual-2][2]='L';
        imprime(matriz_arv, linha_arv-1, bases_arvore-1, linha_atual);
      }
    }
  }
  return 0;
}
