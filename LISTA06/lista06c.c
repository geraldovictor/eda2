#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int i = 0, j = 0, fim = 0, inicio = 0, repete = 0;
    char letra;
    int *vetor_intervalo = malloc(100000 * sizeof(int));
    char *vetor_letras = malloc(4294305 * sizeof(char));
    while (scanf("%c", &vetor_letras[i]) != EOF)
    {
        if (vetor_letras[i] == '\n')
        {
            vetor_letras[i] = '\0';
            fim = i;
            vetor_intervalo[j] = inicio;
            inicio = fim + 1;
            j++;
        }
        i++;
    }
    char *confere = &vetor_letras[vetor_intervalo[j-1]];
    for (i = 0; i < j - 1; i++)
    {
        char *ptr = strstr(&vetor_letras[vetor_intervalo[i]], confere);
        while (ptr != NULL)
        {
            repete++;
            ptr = strstr(ptr + 1, confere);
        }
        printf("%d\n", repete);
        repete = 0;
    }
    return 0;
}
