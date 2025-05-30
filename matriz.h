#ifndef MATRIZ_UTILS_H
#define MATRIZ_UTILS_H

void generateArrayOfDoubles(int doubles[16]);
void generateMatriz(int matriz[4][4], int doubles[16]);
void fillASCIIMatriz(int matriz[4][4]);
void showMatriz(int matriz[4][4], char matrizType);
void askForInput(int choise[3], int matrizValues[4][4], int matrizASCII[4][4]);
int checkMatch(int playerScore, int playerErrors, int choise[3], int matrizValues[4][4], int matrizASCII[4][4]);

#endif