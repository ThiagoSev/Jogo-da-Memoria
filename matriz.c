#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ASCII_COLOR_RED "\e[0;31m"
#define ASCII_COLOR_GREEN "\e[0;32m"
#define ASCII_COLOR_BLUE "\e[0;34m"
#define ASCII_COLOR_BOLD_BLUE "\e[1;94m"
#define ASCII_RESET_COLOR "\e[0m"

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
int counter=0;
void showMatriz(int matriz[4][4])
{
    printf(ASCII_COLOR_BOLD_BLUE"\t0\t1\t2\t3\n");
    for (int i = 0; i < 4; i++)
    {
        printf(ASCII_COLOR_BOLD_BLUE"%i\t"ASCII_RESET_COLOR,i);
        for (int j = 0; j < 4; j++)
        {
            if(counter > 0){
                printf(matriz[i][j] == -1 ? "♣\t" : ASCII_COLOR_GREEN"%d\t"ASCII_RESET_COLOR, matriz[i][j]);
            }else{
                printf(matriz[i][j] == -1 ? "♣\t" : "%d\t", matriz[i][j]);
            }
        }
        printf("\n");
    }
    counter++;
}

