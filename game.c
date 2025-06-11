#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void askForInput(int choise[4], int matrizValues[4][4], int matrizASCII[4][4])
{
    int isRepeated=0;
    do{

        printf("digite a primeira coordenada(x-y):\n");
        scanf("%i %i", &choise[0], &choise[1]);
        printf("digite a segunda coordenada(x-y):\n");
        scanf("%i %i", &choise[2], &choise[3]);

        if(matrizASCII[choise[0]][choise[1]] != -1 || matrizASCII[choise[2]][choise[3]] != -1){
            printf("\nvoce ja digitou estas coordenadas!\nDigite novamente\n");
            isRepeated = 1;
        }else{
            isRepeated = 0;
        }

    }while(isRepeated);

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
        
        printf("\nerrou\n");
        matrizASCII[choise[0]][choise[1]] = matrizValues[choise[0]][choise[1]];
        matrizASCII[choise[2]][choise[3]] = matrizValues[choise[2]][choise[3]];
        
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf(matrizASCII[i][j] == -1 ? "♣\t" : "%d\t", matrizASCII[i][j]);
            }
            printf("\n");
        }
        Sleep(2000);

        matrizASCII[choise[0]][choise[1]] = -1;
        matrizASCII[choise[2]][choise[3]] = -1;
        return false;
    }
}