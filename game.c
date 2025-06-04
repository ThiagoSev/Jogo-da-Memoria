#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void askForInput(int choise[4], int matrizValues[4][4], int matrizASCII[4][4])
{
    printf("digite a primeira coordenada(x-y):\n");
    scanf("%i %i", &choise[0], &choise[1]);
    printf("digite a segunda coordenada(x-y):\n");
    scanf("%i %i", &choise[2], &choise[3]);

    matrizASCII[choise[0]][choise[1]] = matrizValues[choise[0]][choise[1]];
    matrizASCII[choise[2]][choise[3]] = matrizValues[choise[2]][choise[3]];
}

bool checkMatch(int choise[4], int matrizValues[4][4], int matrizASCII[4][4])
{
    if (matrizValues[choise[0]][choise[1]] == matrizValues[choise[2]][choise[3]])
    {
        printf("trocou");
        matrizASCII[choise[0]][choise[1]] = matrizValues[choise[0]][choise[1]];
        matrizASCII[choise[2]][choise[3]] = matrizValues[choise[2]][choise[3]];

        printf("\ncorreto! \7");
        return true;
    }
    else
    {
        printf("\nerrou");
        matrizASCII[choise[0]][choise[1]] = -1;
        matrizASCII[choise[2]][choise[3]] = -1;
        return false;
    }
}