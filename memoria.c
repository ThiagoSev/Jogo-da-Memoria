#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gerarMatriz(){
    int matriz[4][4];
    int rand9[16];
    
    srand(time(NULL));
    
    for(int i=0;i<16;i++){
        rand9[i]=rand()%10;
        for(int j=0;j<i;j++){
            while(rand9[i]==rand9[j]){
                rand9[i]=rand()%10;
            };
        }
    }
    //cria a matriz

    int contador=0;
    for(int i=0;i<4;i++){
        for(int j=0; j<4;j+=2){
            int isRandEqual=1;
            
            //atribuir um valor aleatório que já não tenha sido atribuído antes
            /*do{
                isRandEqual=0;
                rand9[i+j]=rand()%9;
                for(int r=0;r<(i+j);r++){
                    if(rand9[i+j]==rand9[r]){
                        isRandEqual=1;
                        break;
                    }
                }
            }while(isRandEqual==1);*/
            
            matriz[i][j]=rand9[contador];
            matriz[i][j+1]=matriz[i][j];
            contador++;
        }
    }
    
    //mostra a matriz normal (temporário)
    printf("----matriz normal-------\n");
    for(int i=0;i<4;i++){
        for(int j=0; j<4;j++){
            printf("%i",matriz[i][j]);
        }
        printf("\n");
    }
    
    //embaralhar a matriz
    
    for(int i=0;i<4;i++){
        for(int j=0; j<4;j++){
            int temp=0;
            int mAleatorio=matriz[rand()%4][rand()%4];
            temp=matriz[i][j];
            matriz[i][j]=mAleatorio;
            mAleatorio=temp;
        }
    }
    
    //mostra a matriz embaralhada
    printf("\n------matriz embaralhada-------\n");
    for(int i=0;i<4;i++){
        for(int j=0; j<4;j++){
            printf("%i",matriz[i][j]);
        }
        printf("\n");
    }  
}
int main()
{
    gerarMatriz();

    return 0;
}