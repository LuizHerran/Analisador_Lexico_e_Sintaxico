#include <stdio.h>
#include <ctype.h>

int main(){
    printf("\n\tPROGRAMA DE TESTES\n\n");
    char buffer[100];


    char *numero  = (char *)malloc(100 * sizeof(char));
    char *numero2 = (char *)malloc(100 * sizeof(char));
    if(numero == NULL || numero2 == NULL){
        printf("Erro na alocacao de memorias.\n");
    }
    printf("Digite um numero inteiro: ");
    fgets(numero, sizeof(buffer), stdin);

    printf("\n\rDigite um numero real: ");
    fgets(numero2, sizeof(buffer), stdin);

    int n = 0;

    for(int i = 0; sizeof(buffer); i++){
        if(!isdigit(numero[i])){
            n = 1;
        }
        if(!isdigit(numero2[i])){
            n = 1;
        }
    }
    if(n == 1){
        printf("Um dos numeros nao e um numero!");
    }else{
        printf("as variaveis nao sao numeros: %s / %s", numero, numero2);
    }

}