#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

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
        showMatriz(matrizValues, 'd');
        fillASCIIMatriz(matrizASCII);
        while (playerErrors <= 10 || playerScore <= 8)
        {
            awaitFiveSeconds();
            cleanScreen();
            showMatriz(matrizASCII, 'c');
            askForInput(choise, matrizValues, matrizASCII);
            if (checkMatch(playerScore, playerErrors, choise, matrizValues, matrizASCII))
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