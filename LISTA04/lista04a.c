#include <stdio.h>
#include <stdlib.h>

void intercala2(int *v1, int tam1, int *v2, int tam2, int *vr_intercala2);
void intercala4(int *v1, int tam1, int *v2, int tam2, int *v3, int tam3, int *v4, int tam4, int *vr_intercala4);
void intercala8(int *v1, int tam1, int *v2, int tam2, int *v3, int tam3, int *v4, int tam4, int *v5, int tam5, int *v6, int tam6,int *v7, int tam7, int *v8, int tam8, int *vr_intercala8);
void armazena(int *v,int tam);


int main(){
  int tam[8],soma=0;

  scanf("%d",&tam[0]);
  v1[tam[0]+1];
  armazena(v1,tam[0]);
  scanf("%d",&tam[1]);
  int v2[tam[1]+1];
  armazena(v2,tam[1]);
  scanf("%d",&tam[2]);
  int v3[tam[2]+1];
  armazena(v3,tam[2]);
  scanf("%d",&tam[3]);
  int v4[tam[3]+1];
  armazena(v4,tam[3]);
  scanf("%d",&tam[4]);
  int v5[tam[4]+1];
  armazena(v5,tam[4]);
  scanf("%d",&tam[5]);
  int v6[tam[5]+1];
  armazena(v6,tam[5]);
  scanf("%d",&tam[6]);
  int v7[tam[6]+1];
  armazena(v7,tam[6]);
  scanf("%d",&tam[7]);
  int v8[tam[7]+1];
  armazena(v8,tam[7]);
  for (int i = 0; i < 8 ; i++) {
    soma+= tam[i];
  }
  int vetor_resultado[soma+1];
  intercala8(v1,tam[0],v2,tam[1],v3,tam[2],v4,tam[3],v5,tam[4],v6,tam[5],v7,tam[6],v8,tam[7], vetor_resultado);

  for (int i = 0; i < soma; i++) {
    if(i!=soma-1) printf("%d ", vetor_resultado[i]);
    else printf("%d\n",vetor_resultado[i]);
  }
  return 0;
}
void intercala2(int *v1, int tam1, int *v2, int tam2, int *vr_intercala2){
  int tam = tam1+tam2;
  int i=0, j=0, k=0;
  if(tam1!=0&&tam2!=0){
    int resul[tam];
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
void intercala4(int *v1, int tam1, int *v2, int tam2, int *v3, int tam3, int *v4, int tam4, int *vr_intercala4){
  int tam_sum2_1 = tam1+tam2;
  int vr1_4[tam_sum2_1+1];

  intercala2(v1,tam1,v2,tam2,vr1_4);

  int tam_sum2_2 = tam3+tam4;
  int vr2_4[tam_sum2_2+1];

  intercala2(v3,tam3,v4,tam4,vr2_4);

  int tam_sum4 = tam_sum2_2 + tam_sum2_1;
  int vr3_4[tam_sum4+1];

  intercala2 (vr1_4, tam_sum2_1, vr2_4, tam_sum2_2, vr3_4);

  for (int i = 0; i < tam_sum4 ; i++) {
    vr_intercala4[i]=vr3_4[i];
    /* code */
  }

}
void intercala8(int *v1, int tam1, int *v2, int tam2, int *v3, int tam3, int *v4, int tam4, int *v5, int tam5, int *v6, int tam6,int *v7, int tam7, int *v8, int tam8, int *vr_intercala8){
  int tam_sum4_1 = tam1+tam2+tam3+tam4;
  int vr1_8[tam_sum4_1+1];
  intercala4(v1, tam1,v2, tam2 , v3, tam3, v4, tam4,vr1_8);
  int tam_sum4_2=tam5+tam6+tam7+tam8;
  int vr2_8[tam_sum4_2+1];

  intercala4(v5, tam5,v6, tam6 , v7, tam7, v8, tam8,vr2_8);

  int tam_sum8 = tam_sum4_1 + tam_sum4_2;
  int vr3_8[tam_sum8+1];

  intercala2(vr1_8,tam_sum4_1, vr2_8,tam_sum4_2, vr3_8);

  for (int i = 0; i < tam_sum8; i++) {
    vr_intercala8[i]=vr3_8[i];
  }


}
void armazena(int *v,int tam){
  for(int i =0 ; i < tam ; i++){
    scanf("%d", &v[i]);
  }
}
