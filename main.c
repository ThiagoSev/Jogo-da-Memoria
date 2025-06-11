#include "matriz.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

#define ASCII_COLOR_BOLD_RED "\e[1;31m"
#define ASCCI_COLOR_BOLD_GREEN "\e[1;32m"
#define ASCII_RESET_COLOR "\e[0m"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void awaitNSeconds(int x)
{
#ifdef _WIN32
    Sleep(x*1000);
#else
    sleep(x);
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
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "");
    srand(time(NULL));

    int doubles[16], matrizValues[4][4], matrizASCII[4][4], play = 1;
    
    int choise[4], playerScore = 0, playerErrors = 0;

    play = showMenu();
    printf("%i",play);

    while (play != 0)
    {
        cleanScreen();
        generateArrayOfDoubles(doubles);
        generateMatriz(matrizValues, doubles);
        showMatriz(matrizValues);
        fillASCIIMatriz(matrizASCII);
        awaitNSeconds(5);
        while (playerErrors < 10 && playerScore < 8)
        {
            cleanScreen();
            showMatriz(matrizASCII);
            printf(ASCCI_COLOR_BOLD_GREEN"acertos: %i   ", playerScore);
            printf(ASCII_COLOR_BOLD_RED"erros: %i\n" ASCII_RESET_COLOR,playerErrors);
            askForInput(choise, matrizValues, matrizASCII);
            if (checkMatch(choise, matrizValues, matrizASCII))
            {
                playerScore++;
            }
            else
            {
                playerErrors++;
            }

            
        }
        saveScore(playerScore, playerErrors);
        printf("Deseja continuar jogando? \n\n");
        printf("Pressione qualquer numero para jogar novamente\n");
        printf("Pressione 0 para encerrar o jogo\n");
        scanf("%d", &play);
    }
    printf("até a próxima \1");
    return 0;
}