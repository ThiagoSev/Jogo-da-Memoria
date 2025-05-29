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

void askForInput(int choise[3], int matrizValues[4][4],int matrizASCII[4][4]){
    printf("digite a primeira coordenada(x-y):\n");
    scanf("%i %i",&choise[0],&choise[1]);
    printf("digite a segunda coordenada(x-y):\n");
    scanf("%i %i",&choise[2],&choise[3]);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if((i==choise[0] &&j==choise[1]) || (i==choise[2] && j==choise[3])){
                
                printf("%d\t",matrizValues[i][j]);
            }else{
                printf("%c\t", matrizASCII[i][j]);
            }  
        }
        printf("\n");
    
    }
}

int checkMatch(int playerScore, int playerErrors, int choise[3], int matrizValues[4][4], int matrizASCII[4][4]){
    if(matrizValues[choise[0]][choise[1]] == matrizValues[choise[2]][choise[3]])
    {
        matrizASCII[choise[0]][choise[1]] = matrizValues[choise[0]][choise[1]];
        matrizASCII[choise[2]][choise[3]] = matrizValues[choise[2]][choise[3]];

        printf("\ncorreto! \7");
        return 1;
        
    }else{
        printf("\nerrou");
        return 0;
    }
}