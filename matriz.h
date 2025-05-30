#ifndef MATRIZ_UTILS_H
#define MATRIZ_UTILS_H

void generateArrayOfDoubles(int doubles[16]);
void generateMatriz(int matriz[4][4], int doubles[16]);
void fillASCIIMatriz(int matriz[4][4]);
void showMatriz(int matriz[4][4], char matrizType);
int replaceIndex(int indexMapper[16], int choise[4]);
int showIndexMapper(int indexMapper[16]);
void askForInput(int choise[4], int matrizValues[4][4], int matrizASCII[4][4]);
int checkMatch(int playerScore, int playerErrors, int choise[4], int matrizValues[4][4], int matrizASCII[4][4]);

#endif