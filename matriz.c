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
            matriz[i][j] = -1;
        }
    }
}

void showMatriz(int matriz[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf(matriz[i][j] == -1 ? "♣\t" : "%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

