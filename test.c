#include "sintaxico.h"


void cocomando(leituraDeLinha tk[], int lugar){
// <atribuição> | <comando composto> | <comando condicional> | <comando repetitivo>
printf("\n\n - test - \n");
printf("variavel atual no teste -> %s\n", tk[lugarVariavel].variavel);


    if(strcmp(tk[lugar].palavraReservada, TOKEN_BEGIN) == 0){
        comandoComposto(tk, lugar);
        lugarVariavel++;

    } else if(strcmp(tk[lugar].palavraReservada, TOKEN_IF) == 0){
        // if <expressão> then <comando> [ else <comando> ] -- <Comando condicional>
        printf("palavra Reservada-[%s] - ", tk[lugar].palavraReservada);
        lugarVariavel++;
        
        expressao(tk, lugarVariavel);
        
        //Verifica se a proxima palavra é then:
        if(strcmp(tk[lugarVariavel].palavraReservada, TOKEN_THEN) == 0){
            printf("palavra Reservada-[%s] - ", tk[lugarVariavel].palavraReservada);
            lugarVariavel++;
            comando(tk, lugarVariavel);
            
            //Verifica se tem else (não é borigado a ter);
            if(strcmp(tk[lugarVariavel].palavraReservada, TOKEN_ELSE) == 0){
                printf("palavra Reservada-[%s] - ", tk[lugarVariavel].palavraReservada);
                lugarVariavel++;
                printf("\n");
                cocomando(tk, lugarVariavel);
            }
        } else {
            //Se não for then
            printf("Erro de Syntax: 'then' esperada no lugar de: \n\n");
            //Mostra oq foi escrito no lugar
            palavraNaoEsperada(tk, lugarVariavel);
        }
    } else if(strcmp(tk[lugar].palavraReservada, TOKEN_WHILE) == 0){
        // while <expressão> do <comando> -----> <Comando repetitivo>

        printf("palavra Reservada-[%s] - ", tk[lugar].palavraReservada);
        lugarVariavel++;
        expressao(tk, lugarVariavel);
        if(strcmp(tk[lugarVariavel].palavraReservada, TOKEN_DO) == 0){
            printf("palavra Reservada-[%s] - ", tk[lugarVariavel].palavraReservada);
            lugarVariavel++;
        } else {
        //Se não for do
        printf("Erro de Syntax: 'do' esperada no lugar de: \n\n");
        //Mostra oq foi escrito no lugar
        palavraNaoEsperada(tk, lugarVariavel);   
    }
        comando(tk, lugarVariavel);

    } else if(tk[lugar].variavel != NULL){
        // <variável> := <expressão> ----------> <atribuição>
        printf("Variavel-[%s] - ", tk[lugar].variavel);
        lugarVariavel++;

        //Verifica se a proxima palavra é :=
        if(strcmp(tk[lugarVariavel].simbolos, TOKEN_DOISPONTOIGUAL) == 0){
            printf("Variavel-[%s] - ", tk[lugarVariavel].simbolos);
            lugarVariavel++;
            expressao(tk, lugarVariavel);
        } else {
            //Se não for :=
                    printf("Erro de Syntax: ':=' esperada no lugar de: \n\n");
                    //Mostra oq foi escrito no lugar
                    palavraNaoEsperada(tk, lugar);
        }
    } else{
        //Se não for Beguin, if, while ou variavel
        printf("Erro de Syntax: 'atribuicao, comando composto, comando condicional ou comando repetitico' esperada no lugar de: \n\n");
        //Mostra oq foi escrito no lugar
        palavraNaoEsperada(tk, lugar);
    }
}


int main() {
    printf("\t\tAnalisador lexico:\n");
    abrirarquivo();
    printf("\n\n\n");
    printf("\t\tAnalisador sintatico:\n");
    lugarVariavel = 15;
    cocomando(tk, lugarVariavel);
    
}