#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// static void mergeAB(int p, int q, int r, int *v)
// {
//     int *w;
//     w = malloc((r - p) * sizeof(int));
//     int i = p, j = q;
//     int k = 0;

//     while (i < q && j < r)
//     {
//         if (v[i] <= v[j])
//             w[k++] = v[i++];
//         else
//             w[k++] = v[j++];
//     }
//     while (i < q)
//         w[k++] = v[i++];
//     while (j < r)
//         w[k++] = v[j++];
//     for (i = p; i < r; ++i)
//         v[i] = w[i - p];
//     free(w);
// }
// void mergesort(int p, int r, int v[])
// {
//     if (p < r - 1)
//     {                        // 1
//         int q = (p + r) / 2; // 2
//         mergesort(p, q, v);  // 3
//         mergesort(q, r, v);  // 4
//         mergeAB(p, q, r, v); // 5
//     }
// }
// int buscaBinaria(int *vetor, int tamanho, int chave)
// {
//     int i = 0;
//     int f = tamanho - 1;
//     int meio;
//     while (i <= f)
//     {
//         meio = (i + f) / 2;
//         if (vetor[meio] == chave)
//             return meio;
//         else
//         {
//             if (chave > vetor[meio])
//                 i = meio + 1;
//             else
//                 f = meio - 1;
//         }
//     }
//     return -1;
// }
// int main(int argc, char const *argv[])
// {
//     int n, m, j, posi, lugares;
//     scanf("%d", &n); //vizinhanças
//     int *num = malloc(n * sizeof(int));
//     scanf("%d", &m); //lugares que ele ja esteve
//     scanf("%d", &j); //lugar que ele vai visitar
//     int *vetor_m = malloc(m * sizeof(int));
//     int **vetor_n = malloc(n * sizeof(int *));

//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &num[i]);
//         for (int k = 0; k < num[i]; k++)
//         {
//             vetor_n[i] = malloc(num[i] * sizeof(int));
//         }
//         for (int k = 0; k < num[i]; k++)
//         {
//             scanf("%d", &vetor_n[i][k]);
//         }
//     }
//     for (int i = 0; i < m; i++)
//     {
//         scanf("%d", &vetor_m[i]);
//     }
//     mergesort(0, m, vetor_m);
//     for (int i = 0; i < j; i++)
//     {
//         scanf("%d", &lugares);
//         posi = buscaBinaria(vetor_m, m, lugares);
//         if (posi != -1)
//         {
//             printf("Eu vou estar la\n");
//         }
//         else
//         {
//             for (int k = 0; k < m; k++)
//             {
//                 //para cada posição lugar que julius esteve veja quais são visinhos
//                 //se algum desses lugares for visinho "eu vou estar la"
//                 posi = buscaBinaria(vetor_n[vetor_m[k]], num[vetor_m[k]], lugares);
//                 if (posi != -1)
//                 {
//                     printf("Eu vou estar la\n");
//                     break;
//                 }
//             }
//             if (posi == -1)
//             {
//                 printf("Nao vou estar la\n");
//             }
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         free(vetor_n[i]);
//     }
//     free(vetor_n);
//     free(vetor_m);
//     free(num);

//     return 0;
// // }
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// static void mergeAB(int p, int q, int r, int *v)
// {
//     int *w;
//     w = malloc((r - p) * sizeof(int));
//     int i = p, j = q;
//     int k = 0;

//     while (i < q && j < r)
//     {
//         if (v[i] <= v[j])
//             w[k++] = v[i++];
//         else
//             w[k++] = v[j++];
//     }
//     while (i < q)
//         w[k++] = v[i++];
//     while (j < r)
//         w[k++] = v[j++];
//     for (i = p; i < r; ++i)
//         v[i] = w[i - p];
//     free(w);
// }
// void mergesort(int p, int r, int v[])
// {
//     if (p < r - 1)
//     {                        // 1
//         int q = (p + r) / 2; // 2
//         mergesort(p, q, v);  // 3
//         mergesort(q, r, v);  // 4
//         mergeAB(p, q, r, v); // 5
//     }
// }
// int buscaBinaria(int *vetor, int tamanho, int chave)
// {
//     int i = 0;
//     int f = tamanho - 1;
//     int meio;
//     while (i <= f)
//     {
//         meio = (i + f) / 2;
//         if (vetor[meio] == chave)
//             return meio;
//         else
//         {
//             if (chave > vetor[meio])
//                 i = meio + 1;
//             else
//                 f = meio - 1;
//         }
//     }
//     return -1;
// }
// int main(int argc, char const *argv[])
// {
//     int n, m, j, posi, lugares;
//     scanf("%d", &n); //vizinhanças
//     int *num = malloc(n * sizeof(int));
//     scanf("%d", &m); //lugares que ele ja esteve
//     scanf("%d", &j); //lugar que ele vai visitar
//     int *vetor_m = malloc(m * sizeof(int));
//     int **vetor_n = malloc(n * sizeof(int *));

//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &num[i]);
//         for (int k = 0; k < num[i]; k++)
//         {
//             vetor_n[i] = malloc(num[i] * sizeof(int));
//         }
//         for (int k = 0; k < num[i]; k++)
//         {
//             scanf("%d", &vetor_n[i][k]);
//         }
//     }
//     for (int i = 0; i < m; i++)
//     {
//         scanf("%d", &vetor_m[i]);
//     }
//     mergesort(0, m, vetor_m);
//     // for (size_t i = 0; i < m; i++)
//     // {
//     //     printf("%d ",vetor_m[i]);
//     // }
//     // printf("\n");

//     // printf("%d\n", buscaBinaria(vetor_m,m,8));

//     for (int i = 0; i < j; i++)
//     {
//         scanf("%d", &lugares);
//         posi = buscaBinaria(vetor_m, m, lugares);
//         if (posi != -1)
//         {
//             printf("Eu vou estar la\n");
//         }
//         else
//         {
//             for (int k = 0; k < m; k++)
//             {
//                 //para cada posição lugar que julius esteve veja quais são visinhos
//                 //se algum desses lugares for visinho "eu vou estar la"
//                 if (vetor_m[k] < n)
//                 {
//                     for (int l = 0; l < num[vetor_m[k]]; l++)
//                     {
//                         if (lugares == vetor_n[vetor_m[k]][l])
//                         {
//                             printf("Eu vou estar la\n");
//                             posi = 1;
//                             break;
//                         }
//                     }
//                 }
//             }
//             if (posi == -1)
//                 printf("Nao vou estar la\n");
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         free(vetor_n[i]);
//     }
//     free(vetor_n);
//     free(vetor_m);
//     free(num);

//     return 0;
// }
int main(int argc, char const *argv[])
{
    int n, m, j, posi, lugares, num, num_aux;
    scanf("%d", &n); //vizinhanças
    scanf("%d", &m); //lugares que ele ja esteve
    int num_m[m];
    scanf("%d", &j); //lugar que ele vai visitar
    int *vetor_m = malloc(2000 * sizeof(int));
    for (int i = 0; i < 2000; i++)
    {
        vetor_m[i] = -1;
    }
    int **vetor_n = malloc(2000 * sizeof(int *));
    for (int i = 0; i < 2000; i++)
    {
        vetor_n[i] = malloc(1000000 * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &num_aux);
            vetor_n[i][num_aux] = num_aux;
        }
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num_m[i]);
        vetor_m[num_m[i]] = num_m[i];
    }
    for (int i = 0; i < j; i++)
    {
        posi = -1;
        scanf("%d", &lugares);
        if (vetor_m[lugares] == lugares && vetor_m[lugares]!= -1)
        {
            printf("Eu vou estar la\n");
        }
        else
        {
            for (int k = 0; k < m; k++)
            {
                //para cada posição lugar que julius esteve veja quais são visinhos
                //se algum desses lugares for visinho "eu vou estar la"
                if (num_m[k] < n)
                {
                    if (lugares == vetor_n[num_m[k]][lugares])
                    {
                        printf("Eu vou estar la\n");
                        posi = 1;
                        break;
                    }
                }
            }
            if (posi == -1)
                printf("Nao vou estar la\n");
        }
    }
    for (int i = 0; i < 2000; i++)
    {
        free(vetor_n[i]);
    }
    free(vetor_n);
    free(vetor_m);

    return 0;
}
