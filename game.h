#include <stdbool.h>

#ifndef GAME_H
#define GAME_H

void askForInput(int choise[4], int matrizValues[4][4], int matrizASCII[4][4]);
bool checkMatch(int choise[4], int matrizValues[4][4], int matrizASCII[4][4]);
void saveScore(int playerScore, int playerErrors);
void awaitNSeconds(int x);
void cleanScreen();
int showMenu();



#endif