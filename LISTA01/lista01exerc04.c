#include <stdio.h>
#include <string.h>

void atribui_inicial(char matriz_arv[][11], int bases_arvore){
  for(int i=0; i < bases_arvore; i++){ // vai do numero de bases até 1
    for(int j=0; j < 11 ; j++){
      matriz_arv[i][j]='\0';
      matriz_arv[i][j]=' ';
    }
  }
  for(int i = 5 ; i < bases_arvore; i++){ //colocando os troncos com 5 espaços vazios
    matriz_arv[i][4]= '|';
    matriz_arv[i][5]= '|';
    matriz_arv[i][6]= '|';
  }

}
void atribui_lenhador(char matriz_arv[][11],char lado_atual, int bases_arvore, int linha_atual){
  if(lado_atual=='D'){
    matriz_arv[linha_atual][8]='L';
    matriz_arv[linha_atual-1][8]='L';
  }else if(lado_atual=='E'){
    matriz_arv[linha_atual][2]='L';
    matriz_arv[linha_atual-1][2]='L';
  }
}
void atribui_galho(char posi, int linha, char matriz_arv[][11]){
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

void imprime(char matriz_arv[][11], int linha_atual){
  // quero que a minha impressão vá de da minha linha atual até minha
  //  linha atual - 5
  printf("~~~~~~~~~~~\n");
  for(int i = linha_atual-4; i <= linha_atual; i++){
    for(int j = 0; j < 11 ; j++){
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
  char comandos[2001];
  // primeiro vou ler a arvore e armazená-la como matriz
  scanf("%d", &bases_arvore);
  bases_arvore+=5; // adicionando os espaços vazios
  char matriz_arv[bases_arvore][11];
  atribui_inicial(matriz_arv, bases_arvore);
  scanf("%d",&num_ga);
  for(int i =0; i < num_ga; i++){
    scanf(" %c %d", &posi, &linha);
    // por exemplo 9 é a primeira linha numa matriz de 10 linha, como eu faço para converter para 9 ser a primeira linha ?
    // quando digitar 1 ele vá pra linha 9
    linha = bases_arvore - linha ; // por exemplo digitou 1 , 10 bases vai pra linha 9 da minha matriz que é a primeira da impressão
    atribui_galho(posi,linha,matriz_arv);
  }
  scanf(" %c", &lado_atual);
  linha_atual=bases_arvore-1; // linha atual é na verdade a ultima linha da matriz, mas a primeira da da impressão
  atribui_lenhador(matriz_arv,lado_atual,bases_arvore, linha_atual);
  scanf("%s", comandos);

  // preciso de passar para minha impressão da minha linha atual até minha linha atual+5
  imprime(matriz_arv, linha_atual);

  for(int i =0 ; i< strlen(comandos); i++){
    if(comandos[i]=='T'){
      if(((matriz_arv[linha_atual-1][8]!='-'&&matriz_arv[linha_atual][8]!='-')) && lado_atual=='E'){
        matriz_arv[linha_atual][2]=' ';
        matriz_arv[linha_atual-1][2]=' ';
        matriz_arv[linha_atual][8]='L';
        matriz_arv[linha_atual-1][8]='L';
        lado_atual='D';
        imprime(matriz_arv,linha_atual);
      }else if(((matriz_arv[linha_atual-1][2]!='-'&&matriz_arv[linha_atual][2]!='-')) && lado_atual=='D'){
        matriz_arv[linha_atual][2]='L';
        matriz_arv[linha_atual-1][2]='L';
        matriz_arv[linha_atual][8]=' ';
        matriz_arv[linha_atual-1][8]=' ';
        lado_atual='E';
        imprime(matriz_arv,linha_atual);
      }else{
        printf("**beep**\n");
      }
    }else if(comandos[i]=='B'){
      if(lado_atual=='E'&&matriz_arv[linha_atual][4]=='|'){
        matriz_arv[linha_atual][4]='>';
        imprime(matriz_arv, linha_atual);
      }else if (lado_atual=='D'&&matriz_arv[linha_atual][6]=='|'){
        matriz_arv[linha_atual][6]='<';
        imprime(matriz_arv, linha_atual);
      }else if (lado_atual=='E'&&matriz_arv[linha_atual][4]=='>'&&matriz_arv[linha_atual-2][3]==' '){
        matriz_arv[linha_atual-2][2]='L';
        linha_atual--;
        imprime(matriz_arv, linha_atual);
      }else if (lado_atual=='D'&&matriz_arv[linha_atual][6]=='<'&&matriz_arv[linha_atual-2][9]==' '){
        matriz_arv[linha_atual-2][8]='L';
        linha_atual--;
        imprime(matriz_arv, linha_atual);
      }else {
        printf("**morreu**\n");
        break;
      }
    }
  }
  return 0;
}
