#include <stdio.h>

typedef struct{
  int codigo;
  int qualidade;
}semente;
int main(int argc, char const *argv[]) {
  semente *s = malloc(sizeof(semente));
  int qtd, i = 0;

  scanf("%d",&qtd);

  while(scanf("%d %d",&s[i++].codigo, &s[i++].qualidade)==2){
    s = realloc (s, (i+1)*sizeof(semente) );
  }
  for(int j =0 ; j < i ; j++){
    printf("  %d  %d  \n",s[j].codigo, s[j].qualide );

  }
  return 0;
}
