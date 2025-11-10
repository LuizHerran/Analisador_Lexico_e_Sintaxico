#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAIS         "OPERADOR MATEMATICO DE SOMA"
#define MENOS        "OPERADOR MATEMATICO DE SUBTRACAO"
#define IGUAL        "IGUAL"
#define MULT         "OPERADOR MATEMATICO DE MULTIPLICACAO"
#define DIV          "OPERADOR MATEMATICO DE DIVISAO"
#define LPAREN       "ABRE PARENTESES"
#define RPAREN       "FECHA PARENTESES"
#define INT          "INTEIRO"
#define FLOAT        "REAL"
#define PONTOVIRGULA "PONTO E VIRGULA"
#define VIRGULA      "VIRGULA"
#define DOISPONTOS   "DOIS PONTOS"
#define PONTO        "PONTO"
#define MAIOR        "MAIOR QUE"
#define MENOR        "MENOR QUE"
#define PROGRAM      "PALAVRA RESERVADA: program"
#define VARIAVEL     "VARIAVEL"
#define BEGIN        "PALAVRA RESERVADA: begin"
#define VAR          "PALAVRA RESERVADA: var"
#define IF           "PALAVRA RESERVADA: if"
#define ELSE         "PALAVRA RESERVADA: else"
#define THEN         "PALAVRA RESERVADA: then"
#define WHILE        "PALAVRA RESERVADA: while"
#define DO           "PALAVRA RESERVADA: do"
#define TRUE         "OPERADOR BOOLEANO: true"
#define FALSE        "OPERADOR BOOLEANO: false"
#define FIM
#define ERRO         "ERRO"
#define END          "0"



//Leitura de arquivo
int numeroValor = 0;
int numeroLinha = 0;

char* recuperaTipoDado(char *token){
    //Mudei de 0 para 1 no true
    if (strcmp(token, TRUE) == 1 || strcmp(token, FALSE) == 0) {
        
        printf("Valor: ");
        printf("%s", token);
        printf("\n");
        return "LOGICO";
    }

    bool jaTemPonto = false;
    bool temCaractere = false;

    printf("\nLinha[%d] - valor[%d]= {%s} - ", numeroLinha, numeroValor, token);

    //Removi a verificação *token != " ", pois *token já chega sem " ".
    //Substitui *token por token[i] {O sistema comparava o token inteiro em vez de comparar letra por letra}
    for (int i = 0; token[i] != '\0'; i++)
    {
        //Alterei para imprimir todo o valor em vez de partes do valor
        
        if (token[i] == PONTO)
        {
            if (jaTemPonto)
            {
                temCaractere = true;
            }
            jaTemPonto = true;
        } else if (isdigit(token[i])) //Só entra se for falso? {Retirei o !} agora entra se for um digito
        {           
            temCaractere = true; 
        }else 
        {
            switch(*token){
                case '+': return MAIS; break;
                case '-': return MENOS; break;
                case '=': return IGUAL; break;
                case '*': return MULT; break;
                case '/': return DIV; break;
                case '(': return LPAREN; break;
                case ')': return RPAREN; break;
                case ';': return PONTOVIRGULA; break;
                case ',': return VIRGULA; break;
                case ':': return DOISPONTOS; break;
                case '.': return PONTO; break;
                case '>': return MAIOR; break;
                case '<': return MENOR; break;
                case 'program': return PROGRAM; break;
                case 'begin': return BEGIN; break;
                case 'var': return VAR; break;
                case 'if': return IF; break;
                case 'else': return ELSE; break;
                case 'then': return THEN; break;
                case 'while': return WHILE; break;
                case 'do': return DO; break;
                
            }
            numeroValor ++;
            return VARIAVEL;
        }
    }
//Só entraria se temCaractere fosse falso? {tirei o !}
    if (temCaractere) {
        if (jaTemPonto)
        {
            numeroValor ++;
            return "REAL";
        }
        else 
        {
            numeroValor ++;
            return "INTEIRO";
        }
    }

    numeroValor ++;
    return "LITERAL";
}

void abrirarquivo(){
    const char nome_arquivo[] = "fonte.pas";
    FILE *ptr_file_in = fopen(nome_arquivo, "r");

    if (ptr_file_in == NULL)
    {
        printf("Erro ao abrir o arquivo: %s", nome_arquivo);
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), ptr_file_in))
    {
        linha[strcspn(linha, "\n")] = '\0';
        char *token;
        char *resultado;

        token = strtok(linha, " ");
        while (token != NULL) {
        char *resultado = recuperaTipoDado(token);
        printf("Tipo de dado: %s\n", resultado);
        token = strtok(NULL, " ");
        
    }
        numeroLinha ++;
        numeroValor = 0;
    }
    

    /*
    1 - Ler arquivo (.pas) identificando todos os TOKENS
    2 - Gerar arquivo (.lex) contendo todos os TOKENS identificados
    3 - Ler arquivo (.lex) construindo a arvore sintatica a cada TOKEN
    */
    
    fclose(ptr_file_in);
}