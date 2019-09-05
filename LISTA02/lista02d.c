# include <stdio.h>
#include <stdlib.h>


int buscaBinaria(int *vetor,int tamanho, int chave) {
	int i = 0;
	int f = tamanho -1;
	int meio;
	while (i<=f) {
		meio = (i+f)/2;
		if (vetor[meio]==chave)
			return meio;
		else {
			if (chave>vetor[meio])
				i=meio+1;
			else
				f=meio-1;
		}
	}
	return -1;
}
int main(int argc, char const *argv[]) {
  int num_casas, num_casos,posicao_atual=0,soma=0;
  scanf("%d",&num_casas);
  int vetor_casas[num_casas];
  scanf("%d",&num_casos);
  int vetor_casos[num_casos];
  for(int i =0 ; i  < num_casas; i++){
    scanf("%d",&vetor_casas[i]);
  }
  for(int i =0 ; i  < num_casos; i++){
    scanf("%d",&vetor_casos[i]);
    if(posicao_atual<buscaBinaria(vetor_casas,num_casas,vetor_casos[i])){
      soma+=buscaBinaria(vetor_casas,num_casas,vetor_casos[i])-posicao_atual;
      posicao_atual=buscaBinaria(vetor_casas,num_casas,vetor_casos[i]);
    }else if(posicao_atual>buscaBinaria(vetor_casas,num_casas,vetor_casos[i])){
      soma+=posicao_atual-buscaBinaria(vetor_casas,num_casas,vetor_casos[i]);
      posicao_atual=buscaBinaria(vetor_casas,num_casas,vetor_casos[i]);

    }
  }
  printf("%d\n",soma );

  return 0;
}
