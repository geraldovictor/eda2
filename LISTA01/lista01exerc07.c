// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//
// typedef struct reg  {
//   char nome[26];
//   struct reg *prox;
// } celula;
//
// celula *primeiro;
// celula *ultimo;
//
// void cria_primeiro() {
//  primeiro = malloc(sizeof(celula));
//  if(primeiro == NULL)
//   printf("Falha na alocação\n");
//  primeiro-> prox = primeiro;
// }
// void cria_ultimo() {
//   ultimo = malloc(sizeof(celula));
//   if(ultimo == NULL)
//   printf("Falha na alocação\n");
//   ultimo-> prox = ultimo;
// }
// void enfileira_primeiro(char *nome) {
//   celula *nova;
//   nova = malloc(sizeof(celula));
//   if(nova == NULL) {
//     printf("Falha na alocação\n");
//   }
//   nova->prox = primeiro-> prox;
//   primeiro->prox = nova;
//   strcpy(primeiro->nome, nome);
//   primeiro = nova;
// }
// void enfileira_ultimo(char *nome) {
//   celula *nova;
//   nova = malloc(sizeof(celula));
//   if(nova == NULL) {
//     printf("Falha na alocação\n");
//   }
//   nova->prox = ultimo-> prox;
//   ultimo->prox = nova;
//   strcpy(ultimo->nome, nome);
//   ultimo = nova;
// }
// // void cria_cidades() {
// //   cidades = malloc(sizeof(celula));
// //   if(cidades == NULL)
// //   printf("Falha na alocação\n");
// //   cidades-> prox = cidades;
// // }
// void cria_celula(celula *p) {
//  celula *aux3;
//  aux3 = malloc(sizeof(celula));
//  if(p == NULL)
//   printf("Falha na alocação\n");
//  aux3 = p->prox;
// }
// // void enfileira_celula(char *nome, celula *p) {
// //  celula *nova;
// //  nova = malloc(sizeof(celula));
// //  if(nova == NULL) {
// //    printf("Falha na alocação\n");
// //  }
// //  nova-> prox = p->prox;
// //  p-> prox = nova;
// //  strcpy(p->nome, nome);
// //  p = nova;
// // }
//
// //  nova-> prox = ultimo->prox;
// //  ultimo-> prox = nova;
// //  strcpy(ultimo->nome, nome);
// //  ultimo = nova;
// // }
// // void enfileira_cidades(char *nome) {
// //  celula *nova;
// //  nova = malloc(sizeof(celula));
// //  if(nova == NULL) {
// //    printf("Falha na alocação\n");
// //  }
// //  nova-> prox = cidades->prox;
// //  cidades-> prox = nova;
// //  strcpy(cidades->nome, nome);
// //  cidades = nova;
// // }
// void imprime(celula *p){
//   celula *aux2;
//   aux2 = malloc(sizeof(celula));
//   aux2 = p->prox;
//   while(aux2!=p){
//     printf("%s\n",aux2->nome);
//     aux2=aux2->prox;
//   }
// }
// int main(int argc, char const *argv[]) {
//
//   int i=0,j;
//   char primeira = '\0';
//   char ultima = '\0';
//   // cria_cidades();
//   cria_primeiro();
//   cria_ultimo();
//   // cria_celula(primeiro);
//   char cidade[26];
//   while(scanf("%s",cidade )!=EOF){
//     if(i==0){
//       enfileira_primeiro(cidade);
//       ultima=cidade[strlen(cidade)-1];
//       i++;
//     }else{
//       primeira=cidade[0];
//       while (primeira==ultima-32) {
//         /* code */
//       }
//       // primeira=cidade[0];
//       // if(primeira==ultima-32){
//       //   enfileira_ultimo(cidade);
//       //
//       // }else{
//       //   enfileira_primeiro(cidade);
//       //   ultima=cidade[strlen(cidade)-1];
//       // }
//     }
//   }
//   imprime(primeiro);
//   imprime(ultimo);
// ------------------------------
//   enfileira_celula(cidade,primeiro);
//     enfileira_cidades(cidade);
//     contador++;
//   }
//   char primeiro_est[contador][26];
//   char ultimo_est[contador][26];
//   celula *aux1;
//   aux1 = malloc(sizeof(celula));
//   aux1 = cidades->prox;
//   for(int i = 0; i < contador ; i++){
//       if(i==0){
//           strcpy(primeiro_est[i], aux1->nome);
//           ultima= primeiro_est[i][strlen(primeiro_est[i])-1];
//           aux1=aux1->prox;
//         }else{
//             primeira=aux1->nome[0];
//             if(primeira==ultima-32){
//                 aux1=aux1->prox;
//               }
//
//             }
//           }
//           printf("%s\n",primeiro_est[0] );
//           imprime(cidades);
//
//   //-----------------------------------------
//   int c=1,f=1,n=0,k=0;
//   char cidade[26],aux[26];
//   char ultima='\0';
//   char primeira='\0';
//   // char *cidade;
//   // cidade = malloc(26*sizeof(char*));
//   // cidade[0] = malloc(26*sizeof(char));
//   char **comeco;
//   comeco =  malloc(c*sizeof(char *));
//   if(comeco == NULL) printf("Falha na alocação\n");
//   comeco[0] =  malloc(26*sizeof(char));
//   if(comeco[0] == NULL) printf("Falha na alocação\n");
//   char **final;
//   final =  malloc(c*sizeof(char *));
//   if(final == NULL) printf("Falha na alocação\n");
//   final[0] =  malloc(26*sizeof(char));
//   if(final[0] == NULL) printf("Falha na alocação\n");
//
//   while (scanf("%s",cidade)!=EOF) {
//     // ultima=cidade[strlen(cidade)-1];
//     if(c==1){
//       // printf("ok\n");
//       strcpy(comeco[c-1],cidade);
//       ultima=cidade[strlen(comeco[c-1])-1];
//       c++;
//     }else{
//       primeira=cidade[0];
//       if(ultima==primeira+32){
//         // printf("ok\n" );
//         strcpy(final[f-1],cidade);
//         f++;
//         final = realloc(final,f*sizeof(char *));
//         if(final == NULL) printf("Falha na alocação\n");
//         final[f-1] = malloc(26*sizeof(char));
//         if(final[f-1] == NULL) printf("Falha na alocação\n");
//         ultima='\0';
//       }else{
//         comeco = realloc(comeco,c*sizeof(char *));
//         if(comeco == NULL) printf("Falha na alocação\n");
//         comeco[c-1] = malloc(26*sizeof(char));
//         if(comeco[c-1] == NULL) printf("Falha na alocação\n");
//         strcpy(comeco[c-1],cidade);
//         ultima=cidade[strlen(comeco[c-1])-1];
//         c++;
//       }
//       // c++;
//       // comeco = realloc(comeco,c*sizeof(char *));
//       // comeco[c-1] = malloc(26*sizeof(char));
//     }
//     // free(cidade);
//   }
//   // printf("**%d**\n",c );
//   // printf("**%d**\n",f );
//   c--;
//   f--;
//   if(f>1){
//     primeira=final[0][0];
//     ultima=final[1][strlen(final[1])-1];
//     while(ultima==primeira+32&&n<f){
//       n++;
//       if(n==f-1) n = 0;
//       if(ultima==primeira+32){
//         k = f-1;
//         strcpy(aux,final[n]);
//         while(k>n){
//           strcpy(final[k-1],final[k]);
//           k--;
//         }
//         strcpy(final[f-1], aux);
//       }
//       primeira=final[n][0];
//       ultima=final[n+1][strlen(final[n])-1];
//
//     }
//
//   }
//   for(int i=0 ; i < c ; i++){
//     printf("%s\n",comeco[i]);
//   }
//   for(int i=0 ; i < f ; i++){
//     printf("%s\n",final[i]);
//   }
//
//   // free(cidade);
//   // free(comeco);
//   // free(final);
//   return 0;
// }
