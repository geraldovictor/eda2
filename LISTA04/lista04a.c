#include <stdio.h>
#include <stdlib.h>

typedef int Item;
void intercala2(Item *v1, Item tam1, Item *v2, Item tam2, Item *vr_intercala2);
void intercala4(Item *v1, Item tam1, Item *v2, Item tam2, Item *v3, Item tam3, Item *v4, Item tam4, Item *vr_intercala4);
void intercala8(Item *v1, Item tam1, Item *v2, Item tam2, Item *v3, Item tam3, Item *v4, Item tam4, Item *v5, Item tam5, Item *v6, Item tam6,Item *v7, Item tam7, Item *v8, Item tam8, Item *vr_intercala8);
void armazena(Item *v,Item tam);


int main(){
  int tam[8],soma=0;

  scanf("%d",&tam[0]);
  Item *v1 = malloc((tam[0]+1)*sizeof(Item));
  armazena(v1,tam[0]);
  scanf("%d",&tam[1]);
  Item *v2 = malloc((tam[1]+1)*sizeof(Item));
  armazena(v2,tam[1]);
  scanf("%d",&tam[2]);
  Item *v3 = malloc((tam[2]+1)*sizeof(Item));
  armazena(v3,tam[2]);
  scanf("%d",&tam[3]);
  Item *v4 = malloc((tam[3]+1)*sizeof(Item));
  armazena(v4,tam[3]);
  scanf("%d",&tam[4]);
  Item *v5 = malloc((tam[4]+1)*sizeof(Item));
  armazena(v5,tam[4]);
  scanf("%d",&tam[5]);
  Item *v6 = malloc((tam[5]+1)*sizeof(Item));
  armazena(v6,tam[5]);
  scanf("%d",&tam[6]);
  Item *v7 = malloc((tam[6]+1)*sizeof(Item));
  armazena(v7,tam[6]);
  scanf("%d",&tam[7]);
  Item *v8 = malloc((tam[7]+1)*sizeof(Item));
  armazena(v8,tam[7]);
  for(int i = 0; i < 8 ; i++) {
    soma+= tam[i];
  }
  Item *vetor_resultado = malloc(soma*sizeof(Item));
  intercala8(v1,tam[0],v2,tam[1],v3,tam[2],v4,tam[3],v5,tam[4],v6,tam[5],v7,tam[6],v8,tam[7], vetor_resultado);

  for(int i = 0; i < soma; i++) {
    if(i!=soma-1) printf("%d ", vetor_resultado[i]);
    else printf("%d\n",vetor_resultado[i]);
  }
  free(v1);
  free(v2);
  free(v3);
  free(v4);
  free(v5);
  free(v6);
  free(v7);
  free(v8);
  free(vetor_resultado);


  return 0;
}
void intercala2(Item *v1, Item tam1, Item *v2, Item tam2, Item *vr_intercala2){
  Item tam = tam1+tam2;
  Item i=0, j=0, k=0;
  if(tam1!=0&&tam2!=0){
    Item *resul = malloc(tam*sizeof(Item));
    while(j<tam1&&k<tam2){
      if(v1[j]<=v2[k]){
        resul[i]=v1[j];
        i++; j++;
      }else{
        resul[i] = v2[k];
        i++; k++;
      }
    }
    while(j<tam1){
      resul[i]=v1[j]; i++; j++;
    }
    while (k<tam2){
      resul[i]=v2[k]; i++; k++;
    }
    for(i = 0 ; i < tam ; i++){
      vr_intercala2[i]=resul[i];
    }
  }else{
    if(tam1>0){
      for(i = 0 ; i < tam1 ; i++){
        vr_intercala2[i]=v1[i];
      }
    }
    if(tam2>0){
      for(i = 0 ; i < tam2 ; i++){
        vr_intercala2[i]=v2[i];
      }
    }
  }
}
void intercala4(Item *v1, Item tam1, Item *v2, Item tam2, Item *v3, Item tam3, Item *v4, Item tam4, Item *vr_intercala4){
  Item tam_sum2_1 = tam1+tam2;
  Item *vr1_4 = malloc ((tam_sum2_1+1)*sizeof(Item));

  intercala2(v1,tam1,v2,tam2,vr1_4);

  Item tam_sum2_2 = tam3+tam4;
  Item *vr2_4 = malloc ((tam_sum2_2+1)*sizeof(Item));

  intercala2(v3,tam3,v4,tam4,vr2_4);

  Item tam_sum4 = tam_sum2_2 + tam_sum2_1;
  Item *vr3_4 = malloc ((tam_sum4+1)*sizeof(Item));

  intercala2 (vr1_4, tam_sum2_1, vr2_4, tam_sum2_2, vr3_4);

  for (int i = 0; i < tam_sum4 ; i++) {
    vr_intercala4[i]=vr3_4[i];
    /* code */
  }

}
void intercala8(Item *v1, Item tam1, Item *v2, Item tam2, Item *v3, Item tam3, Item *v4, Item tam4, Item *v5, Item tam5, Item *v6, Item tam6,Item *v7, Item tam7, Item *v8, Item tam8, Item *vr_intercala8){
  Item tam_sum4_1 = tam1+tam2+tam3+tam4;
  Item *vr1_8 = malloc((tam_sum4_1+1)*sizeof(Item));

  intercala4(v1, tam1,v2, tam2 , v3, tam3, v4, tam4,vr1_8);

  Item tam_sum4_2=tam5+tam6+tam7+tam8;
  Item *vr2_8 = malloc((tam_sum4_2+1)*sizeof(Item));
  intercala4(v5, tam5,v6, tam6 , v7, tam7, v8, tam8,vr2_8);

  Item tam_sum8 = tam_sum4_1 + tam_sum4_2;
  Item *vr3_8 = malloc((tam_sum8+1)*sizeof(Item));

  intercala2(vr1_8,tam_sum4_1, vr2_8,tam_sum4_2, vr3_8);

  for (int i = 0; i < tam_sum8; i++) {
    vr_intercala8[i]=vr3_8[i];
  }


}
void armazena(Item *v,Item tam){
  for(int i =0 ; i < tam ; i++){
    scanf("%d", &v[i]);
  }
}
