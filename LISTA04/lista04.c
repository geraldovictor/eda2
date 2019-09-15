#include <stdio.h>

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
  int vr1[tam_sum2_1+1];

  intercala2(v1,tam1,v2,tam2,vr1);

  int tam_sum2_2 = tam3+tam4;
  int vr2[tam_sum2_2+1];

  intercala2(v3,tam3,v4,tam4,vr2);

  int tam_sum4 = tam_sum2_2 + tam_sum2_1;
  int vr3[tam_sum4+1];

  intercala2 (vr1, tam_sum2_1, vr2, tam_sum2_2, vr3);

  for (int i = 0; i < tam_sum4 ; i++) {
    vr_intercala4[i]=vr3[i];
    /* code */
  }

}
void intercala8(int *v1, int tam1, int *v2, int tam2, int *v3, int tam3, int *v4, int tam4, int *v5, int tam5, int *v6, int tam6,int *v7, int tam7, int *v8, int tam8, int *vr_intercala8){
  int tam_sum4_1 = tam1+tam2+tam3+tam4;
  int vr1[tam_sum4_1+1];
  intercala4(v1, tam1,v2, tam2 , v3, tam3, v4, tam4,vr1);
  int tam_sum4_2=tam5+tam6+tam7+tam8;
  int vr2[tam_sum4_2+1];

  intercala4(v5, tam5,v6, tam6 , v7, tam7, v8, tam8,vr2);

  int tam_sum8 = tam_sum4_1 + tam_sum4_2;
  int vr3[tam_sum8+1];

  intercala2(vr1,tam_sum4_1, vr2,tam_sum4_2, vr3);

  for (int i = 0; i < tam_sum8; i++) {
    vr_intercala8[i]=vr3[i];
  }


}
void armazena(int *v,int tam){
  for(int i =0 ; i < tam ; i++){
    scanf("%d", &v[i]);
  }
}


int main(int argc, char const *argv[]) {

  return 0;
}
