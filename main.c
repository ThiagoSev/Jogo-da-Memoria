#include "matriz.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void awaitFiveSeconds()
{
#ifdef _WIN32
    Sleep(5000);
#else
    sleep(5);
#endif
}

void cleanScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    setlocale(LC_ALL, "UTF-16");
    srand(time(NULL));

    int doubles[16], matrizValues[4][4], play = 1, matrizASCII[4][4];
    ;

    int choise[4], playerScore = 0, playerErrors = 0;

    while (play != 0)
    {
        generateArrayOfDoubles(doubles);
        generateMatriz(matrizValues, doubles);
        showMatriz(matrizValues);
        fillASCIIMatriz(matrizASCII);
        awaitFiveSeconds();
        while (playerErrors <= 10 || playerScore <= 8)
        {
            cleanScreen();
            showMatriz(matrizASCII);
            askForInput(choise, matrizValues, matrizASCII);
            if (checkMatch(choise, matrizValues, matrizASCII))
            {
                playerScore++;
            }
            else
            {
                playerErrors++;
            }

            printf("pontos: %i\n", playerScore);
        }

        printf("Deseja continuar jogando? \n\n");
        printf("Pressione qualquer numero para jogar novamente\n");
        printf("Pressione 0 para encerrar o jogo\n");
        scanf("%d", &play);
    }

    return 0;
}