#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArrayOfDoubles(int doubles[16])
{
    int counts[10] = {0};
    int i = 0;

    while (i < 16)
    {
        int value = rand() % 10;
        if (counts[value] < 2)
        {
            doubles[i] = value;
            doubles[i + 1] = value;
            counts[value] += 2;
            i += 2;
        }
    }

    for (int j = 0; j < 16; j++)
    {
        int value = rand() % 16;
        int doubleValue = doubles[j];
        doubles[j] = doubles[value];
        doubles[value] = doubleValue;
    }
}

void generateMatriz(int matriz[4][4], int doubles[16])
{
    int d = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = doubles[d];
            d++;
        }
    }
}

void fillASCIIMatriz(int matriz[4][4])
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = 5;
        }
    }
}

void showMatriz(int matriz[4][4], char matrizType)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (matrizType == 'd')
            {
                printf("%d\t", matriz[i][j]);
            }

            if (matrizType == 'c')
            {
                printf("%c\t", matriz[i][j]);
            }
        }
        printf("\n");
    }
}

void askForInput(int choise[4], int matrizValues[4][4], int matrizASCII[4][4])
{
    printf("digite a primeira coordenada(x-y):\n");
    scanf("%i %i", &choise[0], &choise[1]);
    printf("digite a segunda coordenada(x-y):\n");
    scanf("%i %i", &choise[2], &choise[3]);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((i == choise[0] && j == choise[1]) || (i == choise[2] && j == choise[3]))
            {

                printf("%d\t", matrizValues[i][j]);
            }
            else
            {
                printf("%c\t", matrizASCII[i][j]);
            }
        }
        printf("\n");
    }
}

int indexMapper[16];
int i = 0;

int replaceIndex(int indexMapper[16], int choise[4])
{

    if (i >= 16)
    {
        return printf("Erro, index inválido");
    }

    int control = 0;
    int c = 0;

    while (control < 4)
    {
        if (c < 4)
        {
            indexMapper[i] = choise[c];
            c++;
            i++;
        }

        control++;
    }

    return 0;
}

int showIndexMapper(int indexMapper[16])
{
    int i = 0;
    printf("I'm here");

    while (i < 16)
    {
        printf("%d\t", indexMapper[i]);
    }
}

int checkMatch(int playerScore, int playerErrors, int choise[4], int matrizValues[4][4], int matrizASCII[4][4])
{
    if (matrizValues[choise[0]][choise[1]] == matrizValues[choise[2]][choise[3]])
    {
        printf("trocou");
        matrizASCII[choise[0]][choise[1]] = matrizValues[choise[0]][choise[1]];
        matrizASCII[choise[2]][choise[3]] = matrizValues[choise[2]][choise[3]];

        replaceIndex(indexMapper, choise);
        showIndexMapper(indexMapper);

        // Verificar o vazamento de memória

        printf("\ncorreto! \7");
        return 1;
    }
    else
    {
        printf("\nerrou");
        return 0;
    }
}