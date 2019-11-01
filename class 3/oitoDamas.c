#include<stdio.h>

int validaNovaPeca(int tabuleiro[8][8], char posicaoNovaPeca[2]);
int aplicaPeca(int tabuleiro[8][8], char linha, char resultado[8]);

void main(){
    int tabuleiro[8][8] = {0};
    char resultado[8] = {0};
    
    aplicaPeca(tabuleiro, 0, resultado);
}

int aplicaPeca(int tabuleiro[8][8], char linha, char resultado[8]){
    if(linha == 8){
        for (int i = 0; i < 8; i++)
        {
            printf("%d%s", resultado[i], i!=7?" ":"");
        }
        printf("\n");
        return 0;
    }else{
        for(int i = 0; i < 8; i++){
            // printf("%d %d\n", linha, i);
            char posicao[2] = {linha,i};
            if(validaNovaPeca(tabuleiro,posicao)){
                resultado[linha] = posicao[1];
                tabuleiro[linha][i] = 1;
                if(aplicaPeca(tabuleiro, linha + 1,resultado)){
                    return 1;
                }else{
                    resultado[linha] = 0;
                    tabuleiro[linha][i] = 0;
                }
            }
        }
        return 0;
    }
}

//[x][y]
int validaNovaPeca(int tabuleiro[8][8], char posicaoNovaPeca[2]){
    int limitX = posicaoNovaPeca[0];
    int limitYPositivo = 7 - posicaoNovaPeca[1];
    int limitYNegativo = posicaoNovaPeca[1];
    int ret = 1;

    // printf("verificandoPosicao: (%d, %d) = %d\n", i, posicaoNovaPeca[2], tabuleiro[i][posicaoNovaPeca[2]]);
    for(int i = limitX; i>=0; i--){
        
        // printf("verificando1: (%d, %d) = %d\n", posicaoNovaPeca[0] - i, posicaoNovaPeca[1], tabuleiro[posicaoNovaPeca[0] - i][posicaoNovaPeca[1]]);
        if(tabuleiro[posicaoNovaPeca[0] - i][posicaoNovaPeca[1]] == 1){
            ret = 0;
            break;
        }
        // printf("verificando2: (%d, %d) = %d\n", posicaoNovaPeca[0] -i, posicaoNovaPeca[1] - i, tabuleiro[posicaoNovaPeca[0] -i][posicaoNovaPeca[1] - i]);
        if(i<=limitYNegativo && tabuleiro[posicaoNovaPeca[0] - i][posicaoNovaPeca[1] - i] == 1){
            ret = 0;
            break;
        }
        // printf("verificando3: (%d, %d) = %d\n", posicaoNovaPeca[0] - i, posicaoNovaPeca[1] +i, tabuleiro[posicaoNovaPeca[0] - i][posicaoNovaPeca[0] + i]);
        if(i<=limitYPositivo  && tabuleiro[posicaoNovaPeca[0] - i][posicaoNovaPeca[1] + i] == 1){
            // printf("Quebrou");
            ret = 0;
            break;
        }
    }

    return ret;
}