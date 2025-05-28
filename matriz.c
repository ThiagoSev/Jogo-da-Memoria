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

void generateAndShowACIIMatriz(int matriz[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = 5;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%c\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void showMatriz(int matriz[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void askForInput(int matrizValues[4][4],int matrizASCII[4][4]){
    int column1, column2, row1, row2;
    
        printf("digite a primeira coordenada(x-y):\n");
        scanf("%i %i",&row1,&column1);
        printf("digite a segunda coordenada(x-y):\n");
        scanf("%i %i",&row2,&column2);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if((i==row1 &&j==column1) || (i==row2 &&j==column2)){
                    printf("%d\t",matrizValues[i][j]);
                }else{
                    printf("%c\t", matrizASCII[i][j]);
                }  
            }
            printf("\n");
        }
    
}