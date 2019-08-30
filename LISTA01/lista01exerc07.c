#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
  char cidade[26];
  struct Node *prox;
};
typedef struct Node node;

void inicia(node *LISTA){
  LISTA->prox = NULL;
}
int vazia(node *LISTA){
  if(LISTA->prox==NULL) return 1;
  else return 0;
}
void insere_final(char *cidade, node *LISTA){
  node *novo = malloc(sizeof(node));
  if(novo == NULL) printf("Falha na alocação!!!\n");
  if(vazia(LISTA)){
    LISTA->prox= novo;
    strcpy(novo->cidade, cidade);
    novo->prox = NULL;
  }else{
    node *temp;
    temp = LISTA->prox;
    while(temp->prox!=NULL){
      temp=temp->prox;
    }
    temp->prox=novo;
    strcpy(novo->cidade, cidade);
    novo->prox=NULL;
  }
}
void remove(node *LISTA){
  node *newHead = malloc(sizeof(node));
  if(novo == NULL) printf("Falha na alocação!!!\n");
  newHead
}
int main(int argc, char const *argv[]) {
  int i =0;
  char cidade[26], ultima= '\0',primeira ='\0';
  node *LISTA = malloc (sizeof(node));
  if (LISTA == NULL) printf("Falha na alocação!!!\n");
  inicia(LISTA);
  while(scanf("%s",cidade )!=EOF){
    insere_final(cidade,LISTA);
  }
  // node *teste = malloc(sizeof(node));
  // if(teste == NULL) printf("Falha na alocação!!!\n");
  // teste = LISTA->prox;
  // while(teste!=NULL){
  //     printf("%s\n", teste->cidade);
  //     teste= teste->prox;
  // }

  node *atual= malloc (sizeof(node));
  if(atual == NULL) printf("Falha na alocação!!!\n");
  atual = LISTA->prox;
  while(atual!=NULL){
    if(i==0){
      printf("%s\n",atual->cidade);
      i++;
      ultima=atual->cidade[strlen(atual->cidade)-1];
      atual = atual->prox;
    }else{
      primeira=atual->cidade[0];
      if(primeira==toupper(ultima)){
        insere_final(atual->cidade,atual);
        atual = atual->prox;
        printf("%s\n",atual->cidade);
        ultima=atual->cidade[strlen(atual->cidade)-1];
        atual = atual->prox;

      }else{
        printf("%s\n",atual->cidade );
        ultima=atual->cidade[strlen(atual->cidade)-1];
        atual = atual->prox;
      }
    }
  }
  return 0;
}
