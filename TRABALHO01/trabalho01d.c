#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char email_cadastrado[101];
} email;
static void mergeAB(int p, int q, int r, email *v)
{
    email *w;
    w = malloc((r - p) * sizeof(email));
    int i = p, j = q;
    int k = 0;

    while (i < q && j < r)
    {
        if (strcmp(v[i].email_cadastrado,v[j].email_cadastrado) <= 0) 
        {
            w[k] = v[i];
            i++;
            k++;
        }
        else
        {
            w[k] = v[j];
            j++;
            k++;
        }
    }
    while (i < q)
    {
        w[k] = v[i];
        i++;
        k++;
    }
    while (j < r)
    {
        w[k] = v[j];
        j++;
        k++;
    }
    for (i = p; i < r; ++i)
    {
        v[i] = w[i - p];
    }
    free(w);
}
void mergesort(int p, int r, email *v)
{
    if (p < r - 1)
    {                        // 1
        int q = (p + r) / 2; // 2
        mergesort(p, q, v);  // 3
        mergesort(q, r, v);  // 4
        mergeAB(p, q, r, v); // 5
    }
}

int main(int argc, char const *argv[])
{
    int num_lines, i = 0, j = 0, k = 0;
    scanf("%d", &num_lines);
    email *v = malloc(num_lines * sizeof(email));
    email *v2 = malloc(num_lines * sizeof(email));
    for (i = 0; i < num_lines; i++)
    {
        scanf("%s", v[i].email_cadastrado);
    }
    for (i = 0; i < num_lines; i++)
    {
        for (j = 0; j < strlen(v[i].email_cadastrado); j++)
        {
            if (v[i].email_cadastrado[j] != '.')
            {

                if (v[i].email_cadastrado[j] == '+')
                {
                    while (v[i].email_cadastrado[j] != '@')
                        j++;

                    if (v[i].email_cadastrado[j] == '@')
                    {

                        for (j; j < strlen(v[i].email_cadastrado); j++)
                        {
                            v2[i].email_cadastrado[k++] = v[i].email_cadastrado[j];
                        }
                        break;
                    }
                }
                if (v[i].email_cadastrado[j] == '@')
                {
                    for (j; j < strlen(v[i].email_cadastrado); j++)
                    {
                        v2[i].email_cadastrado[k++] = v[i].email_cadastrado[j];
                    }
                    break;
                }
                v2[i].email_cadastrado[k++] = v[i].email_cadastrado[j];
            }
        }
        v2[i].email_cadastrado[k] = '\0';
        k = 0;
    }
    mergesort(0,num_lines,v2);
    int contador=1;
    for (int i = 0; i < num_lines-1; i++)
    {
        if(strcmp(v2[i+1].email_cadastrado,v2[i].email_cadastrado)!=0) contador++;
    }
    printf("%d\n",contador);
    
    return 0;
}
