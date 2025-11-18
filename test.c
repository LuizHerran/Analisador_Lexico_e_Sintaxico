#include "sintaxico.h"





int main() {

    abrirarquivo();
    printf("\n\n\n");
    for(int k = 24; k < (30); k++){
        if (tk[k].palavraReservada != NULL){
            printf("Leitura {%d} palavra Reservada-[%s]\n", k, tk[k].palavraReservada);
            } else if (tk[k].variavel != NULL){
                printf("Leitura {%d} Variavel-[%s]\n", k, tk[k].variavel);
            } else if (tk[k].simbolos != NULL){
                printf("Leitura {%d} Simbolo Duplo-[%s]\n", k, tk[k].simbolos);
            } else if (tk[k].simbolo != '\0'){
                printf("Leitura {%d} Simbolo simples-[%c]\n", k, tk[k].simbolo);
            } else if (tk[k].real != 0.0f){
                printf("Leitura {%d} Numero Real[%.2f]\n", k, tk[k].real);
            } else {printf("Leitura {%d} Numero inteiro-[%d]\n", k, tk[k].num);}
    }
    
}