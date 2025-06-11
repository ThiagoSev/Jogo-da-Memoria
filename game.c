#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ASCII_COLOR_RED "\e[0;31m"
#define ASCII_COLOR_BOLD_RED "\e[1;31m"
#define ASCII_COLOR_GREEN "\e[0;32m"
#define ASCII_COLOR_YELLOW "\e[0;33m"
#define ASCII_COLOR_BLUE "\e[0;34m"
#define ASCII_COLOR_BOLD_BLUE "\e[1;94m"
#define ASCII_RESET_COLOR "\e[0m"

int showMenu(){
    printf(ASCII_COLOR_BOLD_RED"            ▄█  ▄██████▄     ▄██████▄   ▄██████▄       ████████▄     ▄████████\n");
    printf(ASCII_COLOR_BOLD_RED"           ███ ███    ███   ███    ███ ███    ███      ███   ▀███   ███    ███\n");
    printf(ASCII_COLOR_BOLD_RED"           ███ ███    ███   ███    █▀  ███    ███      ███    ███   ███    ███\n");
    printf(ASCII_COLOR_BOLD_RED"           ███ ███    ███  ▄███        ███    ███      ███    ███   ███    ███\n");
    printf(ASCII_COLOR_BOLD_RED"           ███ ███    ███ ▀▀███ ████▄  ███    ███      ███    ███ ▀███████████\n");
    printf(ASCII_COLOR_BOLD_RED"           ███ ███    ███   ███    ███ ███    ███      ███    ███   ███    ███\n");
    printf(ASCII_COLOR_BOLD_RED"           ███ ███    ███   ███    ███ ███    ███      ███   ▄███   ███    ███\n");
    printf(ASCII_COLOR_BOLD_RED"       █▄ ▄███  ▀██████▀    ████████▀   ▀██████▀       ████████▀    ███    █▀ \n");
    printf(ASCII_COLOR_BOLD_RED"       ▀▀▀▀▀▀                                                                 \n");

    printf("\n");

    printf(ASCII_COLOR_BLUE"  ▄▄▄▄███▄▄▄▄      ▄████████   ▄▄▄▄███▄▄▄▄    ▄██████▄     ▄████████  ▄█     ▄████████ \n");
    printf(ASCII_COLOR_BLUE"▄██▀▀▀███▀▀▀██▄   ███    ███ ▄██▀▀▀███▀▀▀██▄ ███    ███   ███    ███ ███    ███    ███ \n");
    printf(ASCII_COLOR_BLUE"███   ███   ███   ███    █▀  ███   ███   ███ ███    ███   ███    ███ ███▌   ███    ███ \n");
    printf(ASCII_COLOR_BLUE"███   ███   ███  ▄███▄▄▄     ███   ███   ███ ███    ███  ▄███▄▄▄▄██▀ ███▌   ███    ███ \n");
    printf(ASCII_COLOR_BLUE"███   ███   ███ ▀▀███▀▀▀     ███   ███   ███ ███    ███ ▀▀███▀▀▀▀▀   ███▌ ▀███████████ \n");
    printf(ASCII_COLOR_BLUE"███   ███   ███   ███    █▄  ███   ███   ███ ███    ███ ▀███████████ ███    ███    ███ \n");
    printf(ASCII_COLOR_BLUE"███   ███   ███   ███    ███ ███   ███   ███ ███    ███   ███    ███ ███    ███    ███ \n");
    printf(ASCII_COLOR_BLUE" ▀█   ███   █▀    ██████████  ▀█   ███   █▀   ▀██████▀    ███    ███ █▀     ███    █▀  \n");
    printf(ASCII_COLOR_BLUE"                                                          ███    ███                   \n" ASCII_RESET_COLOR);
    awaitNSeconds(3);
    printf("\n---OPÇÕES---\n");
    printf(ASCII_COLOR_GREEN"\n1- Jogar");
    printf(ASCII_COLOR_RED"\n2- Sair\n" ASCII_RESET_COLOR);

    int option;
    do{
        scanf("%i",&option);
        switch(option){
            case 1:
                return 1;
                break;
            case 2:
                return 0;
                break;
            default:
                printf("opção inválida. Escolha de 1 a 2");
                break;
        }
    }while(option >=1 && option<=2);
}

void askForInput(int choise[4], int matrizValues[4][4], int matrizASCII[4][4])
{
    int isRepeated=0, isEqual=0;
    do{

        printf("digite a primeira coordenada(x-y):\n");
        scanf("%i %i", &choise[0], &choise[1]);
        printf("digite a segunda coordenada(x-y):\n");
        scanf("%i %i", &choise[2], &choise[3]);

        if((choise[0] == choise[2]) && (choise[1] == choise[3])){
            printf("\nVoce escolheu as mesmas cartas! escolha cartas diferentes.\n");
            isEqual = 1;
        }else{
            isEqual = 0;
        }

        if(matrizASCII[choise[0]][choise[1]] != -1 || matrizASCII[choise[2]][choise[3]] != -1){
            printf("\nvoce ja digitou estas coordenadas!\nDigite novamente.\n");
            isRepeated = 1;
        }else{
            isRepeated = 0;
        }

    }while(isRepeated || isEqual);

    matrizASCII[choise[0]][choise[1]] = matrizValues[choise[0]][choise[1]];
    matrizASCII[choise[2]][choise[3]] = matrizValues[choise[2]][choise[3]];
}

bool checkMatch(int choise[4], int matrizValues[4][4], int matrizASCII[4][4])
{
    if ((matrizValues[choise[0]][choise[1]] == matrizValues[choise[2]][choise[3]]))
    {
        printf("trocou");
        matrizASCII[choise[0]][choise[1]] = matrizValues[choise[0]][choise[1]];
        matrizASCII[choise[2]][choise[3]] = matrizValues[choise[2]][choise[3]];

        printf("\ncorreto! \7");
        return true;
    }
    else
    {
        cleanScreen();
        matrizASCII[choise[0]][choise[1]] = matrizValues[choise[0]][choise[1]];
        matrizASCII[choise[2]][choise[3]] = matrizValues[choise[2]][choise[3]];
        
        printf(ASCII_COLOR_BOLD_BLUE"\t0\t1\t2\t3\n");
        for (int i = 0; i < 4; i++)
        {
            printf(ASCII_COLOR_BOLD_BLUE"%i\t"ASCII_RESET_COLOR,i);
            for (int j = 0; j < 4; j++)
            {
                if(choise[0] == i && choise[1] == j || choise[2] == i && choise[3] == j){
                    printf(matrizASCII[i][j] == -1 ? "♣\t" : ASCII_COLOR_BOLD_RED"%d\t"ASCII_RESET_COLOR, matrizASCII[i][j]);
                }else{
                    printf(matrizASCII[i][j] == -1 ? "♣\t" : "%d\t", matrizASCII[i][j]);
                } 
            }
            printf("\n");
        }
        printf("errou!");
        Sleep(2000);

        matrizASCII[choise[0]][choise[1]] = -1;
        matrizASCII[choise[2]][choise[3]] = -1;
        return false;
    }
}