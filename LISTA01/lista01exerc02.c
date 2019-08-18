#include <stdio.h>

int main(){
  int tam,num,soma=0;
  scanf("%d",&tam );
  for(int i =0; i < tam; i++){
    scanf("%d", &num );
    soma+=num;
  }
  printf("%d\n",soma );
  return 0;
}
