#include <stdio.h>

// Este código imprime uma piramide  formada por numeros, em que na primeira coluna
// temos o tamanho da altura e nas suas sucessivas linhas temos os multiplos do numero inicial da linha.
//
// por exemplo, o usuario digita 5, logo sua piramide é:
//
// 1
// 2 4
// 3 6 9
// 4 8 12 16
// 5 10 15 20 25


void main(){

    int altura,linha,coluna,decisao,produto, ValorDecrementado;

    printf("Algoritmo 2 - Piramide de numeros\n");
    printf("Digite a altura da Piramide (Por favor, digite valores nos naturais !):\n");
    scanf("%d", &altura);

    system("cls");

    printf("A Piramide eh a seguinte:\n");
    for(linha = 1; linha <= altura; linha++){
        for(coluna = 1; coluna <= linha; coluna++){
            produto = linha*coluna;
            printf("%d ", produto);
        }
        printf("\n");
    }

}
