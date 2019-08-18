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
  */
  int bases_arvore;
  int num_ga;
  char posi;
  // primeiro vou ler a arvore e armazená-la como matriz
  scanf("%d", bases_arvore);
  int matriz_arv[bases_arvore][11];
  scanf("%d",num_ga);
  for(int i =0; i < num_ga; i++){
    scanf(" %c", &posi );
  }
  scanf(" %c",&posi);
  return 0;
}
