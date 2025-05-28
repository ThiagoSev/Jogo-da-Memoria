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
    setlocale(LC_ALL, "UTF-8");
    srand(time(NULL));

    int doubles[16], matrizValues[4][4], play = 1;

    int matrizASCII[4][4];

    while (play != 0)
    {
        generateArrayOfDoubles(doubles);
        generateMatriz(matrizValues, doubles);
        showMatriz(matrizValues);
        awaitFiveSeconds();
        cleanScreen();
        generateAndShowACIIMatriz(matrizASCII);
        askForInput(matrizValues,matrizASCII);

        printf("Deseja continuar jogando? \n\n");
        printf("Pressione qualquer numero para jogar novamente\n");
        printf("Pressione 0 para encerrar o jogo\n");
        scanf("%d", &play);
    }

    

    return 0;
}