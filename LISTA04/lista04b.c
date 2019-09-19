#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct{
  int codigo;
  int qualidade;
}semente;

int less(Item *a, Item *b){
  if(*a<*b) return 1;
  else return 0;
}

int lesseq(Item *a, Item *b){
  if(*a<=*b) return 1;
  else return 0;
}

void exch(Item *a, Item *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void compexch(Item *a, Item *b){
  if(less(a,b)) exch(a,b);
}
static int separa(semente *v, int l, int r){ //função static equilave a private em relação a OO
  Item c = v[r].qualidade; // 1,
  Item j=l ; // 0
  for(int i=l; i <r ; i++){
  if(lesseq(&v[i].qualidade,&c)){
    exch(&v[i].qualidade,&v[j].qualidade);
    exch(&v[i].codigo,&v[j].codigo);
    j++;
  }
  /*se o valor da minha posição atual for menor ou igual a esse meu pivô
  soma 1 no contador
  senão joga esse elemento pra ultima se não
  */
  }
  exch(&v[r].qualidade, &v[j].qualidade);
  exch(&v[r].codigo, &v[j].codigo);
  return j;
}
// static int separa_codigo(semente *v, int l, int r){ //função static equilave a private em relação a OO
//   Item c = v[r].codigo; // 1,
//   Item j=l ; // 0
//   for(int i=l; i <r ; i++){
//   if(lesseq(&v[i].codigo,&c)){
//     exch(&v[i].qualidade,&v[j].qualidade);
//     exch(&v[i].codigo,&v[j].codigo);
//     j++;
//   }
//   /*se o valor da minha posição atual for menor ou igual a esse meu pivô
//   soma 1 no contador
//   senão joga esse elemento pra ultima se não
//   */
//   }
//   exch(&v[r].qualidade, &v[j].qualidade);
//   exch(&v[r].codigo, &v[j].codigo);
//   return j;
// }
void eec(int i, semente *v, int l, int r){
  compexch(&v[l].qualidade,&v[r].qualidade);//mediana
  compexch(&v[l].codigo,&v[r].codigo);//mediana
  compexch(&v[(r+l/2)].qualidade,&v[l].qualidade);
  compexch(&v[(r+l/2)].codigo,&v[l].codigo);
  compexch(&v[r].qualidade,&v[l].qualidade);
  compexch(&v[r].codigo,&v[l].codigo);
  Item j = separa(v,l,r);
  if(j==i) return;
  if(j==i) return;
  if(j<i) {
    eec(i,v,j+1,r);
  }else{
    eec(i,v,l,j-1);
  }
}
static void mergeAB(int p, int q, int r, semente *v){
  semente *w;
  w = malloc ((r-p) * sizeof (semente));
  int i = p, j = q;
  int k = 0;

  while (i < q && j < r) {
    if (v[i].codigo <= v[j].codigo)  {
      w[k++].codigo = v[i++].codigo;
      w[k++].qualidade = v[i++].qualidade;
    }else  {
      w[k++].codigo = v[j++].codigo;
      w[k++].qualidade = v[j++].qualidade;
    }
  }
  while (i < q)  {
    w[k++].codigo = v[i++].codigo;
    w[k++].qualidade = v[i++].qualidade;

  }
  while (j < r)  {
    w[k++].codigo = v[j++].codigo;
    w[k++].qualidade = v[j++].qualidade;

  }
  for (i = p; i < r; ++i)  {
    v[i].codigo = w[i-p].codigo;
    v[i].qualidade = w[i-p].qualidade;
  }
  // free (w);
}
void mergesort (int p, int r, semente *v){
   if (p < r-1) {                 // 1
      int q = (p + r)/2;          // 2
      mergesort (p, q, v);        // 3
      mergesort (q, r, v);        // 4
      mergeAB (p, q, r, v);     // 5
   }
}
int main(int argc, char const *argv[]) {
  semente *s = malloc(sizeof(semente));
  int qtd, i = 0;
  scanf("%d",&qtd );
  // do{
  //   scanf("%d%d",&s[i].codigo, &s[i].qualidade);
  //   i++;
  //   n++;
  // }while (s[i].codigo!=EOF&&s[i].qualidade!=EOF);
  while(scanf("%d%d",&s[i].codigo, &s[i].qualidade)==2){
    i++;
    s = realloc (s, (i+1)*sizeof(semente) );
  }

  // eec(qtd, s, 0 , i-1);
  mergesort(0,qtd,s);
  for(int j =0 ; j< qtd ; j++){
    printf("%d %d\n",s[j].codigo,s[j].qualidade);
  }
  return 0;
}
