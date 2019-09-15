#include <stdio.h>
#include <stdlib.h>

typedef struct Candidato{
  int qtd_votos;
  int codigo;
}candidato;
typedef struct descritor Lista;
struct elemento{
  candidato dados;
  struct elemento *prox;
};

struct descritor{
  struct elemento *inicio;
  struct elemento *fim;
  int qtd;
};
typedef struct elemento Elem;


Lista* cria_lista(){
  Lista *li = malloc (sizeof(Lista));
  if(li != NULL){
    li->inicio = NULL;
    li->fim = NULL;
    li->qtd = 0;
  }
  return li;
}

void libera_lista(Lista *li){
  if(li!=NULL){
    Elem* no = malloc(sizeof(Elem));
    while(li->inicio!=NULL){
      no = li->inicio;
      li->inicio= li->inicio->prox;
      free(no);
    }
  }
  free(li);
}
int insere_inicio(Lista *li,int voto){
  if(li == NULL) return 0;
  Elem *no = malloc (sizeof(Elem));
  if(no == NULL) return 0;
  no->dados.codigo = voto;
  no->dados.qtd_votos++;
  no->prox = li->inicio;
  if(li->inicio==NULL)
    li->fim = no;
  li->inicio = no;
  li->qtd++;

}
int main(int argc, char const *argv[]) {
  int senador, dep_est, dep_fed;
  int voto;
  Lista *cand = malloc(sizeof(Lista));
  cand = cria_lista();
  scanf("%d",&senador );
  scanf("%d",&dep_fed );
  scanf("%d",&dep_est );
  while(scanf("%d",&voto)!=EOF){
    insere_inicio(cand, voto);
  }

  Lista *aux = malloc(sizeof(Lista));
  aux->inicio= cand->inicio;
  while(aux->inicio!=NULL){
    printf("%d",aux->inicio->dados.codigo);
    aux->inicio = aux->inicio->prox;
  }
  // if(voto<0){
    //
    // }else if(voto<100){
      //   if(insere_inicio(cand,voto)) printf("ok\n");
      //   Elem* no = malloc(sizeof(Elem));
      //   no = cand->inicio->prox;
      //   while(no->inicio->prox!=NULL){
        //     printf("%d",cand->inicio->dados.codigo );
        //     no = cand->inicio->prox;
        //   }
        // }else if(voto<1000){
          //
          // }else if(voto<10000){
            //
            // }else if(voto<100000){
              // }
  return 0;
}
