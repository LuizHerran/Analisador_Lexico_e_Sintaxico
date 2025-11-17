#include "sintaxico.h"

int main(void)
{
    //Real esta caindo como variavel e primeira leitura esta separada
    printf("\t\tAnalisador lexico:\n");
    abrirarquivo();
    printf("\n\n\n");
    printf("\t\tAnalisador sintatico:\n");
    programaEBloco(tk);

    return 0;
}
