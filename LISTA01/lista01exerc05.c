#include <stdio.h>
#include <stdlib.h>

void ultrapassa(int *v, int i, int limite,  int soma){ //qual o caso base?

  soma+= v[i];
  //enquanto a soma não passa o limite
  if(soma>limite){
    ultrapassa(v,i+1,limite,soma);
    printf("%d",v[i]);
  }else{
    ultrapassa(v,i+1,limite,soma);
  }
  // if(v[i]){ //se ultrapassar chama a função novamente
  //   printf("%s\n", );
  // }
  // ultrapassa(v[i+1]);

}
int main(int argc, char const *argv[]) {
  int i = 0, n=2, limite=0,soma=0;
  int *v;
  v = malloc (n*sizeof(int));
  scanf("%d", &v[i]);
  while (v[i]!=0) {
      i++;
      n++;
      v = realloc(v,n*sizeof(int));
      scanf("%d", &v[i]);
    }
  scanf("%d",&limite);
  ultrapassa(v,0,limite,soma);
  return 0;
}
