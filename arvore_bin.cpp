#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux{
  TIPOCHAVE chave;
  /* Dados armazenados vão aqui */
  struct aux *esq, *dir;
} NO;
PONT inicializa(){
  return (NULL);
}
typedef NO *PONT;

PONT adiciona(PONT raiz, PONT no){
  if(raiz == NULL) return(no);
  if(no->chave < raiz->chave)
    raiz->esq= adiciona(raiz->, no);
  else
    raiz->dir= adiciona(raiz->dir, no);
  /*ignoro chave igual*/
  return(raiz);
}
PONT criaNovoNo(TIPOCHAVE ch){
  PONT novoNo = (PONT)malloc(sizeof(NO));
  novoNo->esq = NULL;
  novoNo->dir = NULL;
  novoNo->chave=ch;
  return(novoNo);
}
int main(){

  PONT r = inicializa();

  PONT no = criaNovoNo(23);
  r = adiciona(r, no);
}
