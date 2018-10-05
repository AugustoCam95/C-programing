#include <stdio.h>

// Este código imprime uma piramide ou um triangulo retangulo formado por numeros, em que na primeira coluna
// temos o tamanho da altura e nas suas sucessivas linhas temos os multiplos do numero inicial da linha.
// O usuario escolhe o uma das opções, caso selecione uma das opções de imprimir na tela, ele entra com a
// altura, em seguida é imprimida como fica sua figura e depois ele volta ao menu.

// por exemplo, o usuario digita 5, logo sua piramide é:
//      1
//     2 4
//    3 6 9
//   4 8 12 16
//  5 10 15 20 25
// ou, assim :
//
// 1
// 2 4
// 3 6 9
// 4 8 12 16
// 5 10 15 20 25


void main(){

    int altura,linha,coluna,decisao,produto, ValorDecrementado;

    system("cls");

    printf("Algoritmo 2 - Piramide de numeros\n");
    printf("Digite sua escolha:\n");
    printf("0- Imprimir na tela uma Piramide !\n");
    printf("1- Imprimir na tela um Triangulo Retangulo !\n");
    printf("2- Encerrar programa !\n");
    scanf("%d", &decisao);

    system("cls");



    switch(decisao){
    case 0:

        printf("Digite a altura da Piramide (Por favor, digite valores nos naturais !):\n");
        scanf("%d", &altura);
        ValorDecrementado = altura;

        system("cls");

        printf("A Piramide eh a seguinte:\n");
        for(linha = 1; linha <= altura; linha++){
            for(coluna = 1; coluna <= ValorDecrementado; coluna++){
                printf(" ");
            }
            for(coluna = 1; coluna <= linha; coluna++){
                produto = linha*coluna;
                printf("%d ", produto);
            }
            printf("\n");
            ValorDecrementado--;
        }
        system("Pause");
        break;

    case 1:

        printf("Digite a altura do Triangulo Retangulo (Por favor, digite valores nos naturais !):\n");
        scanf("%d", &altura);

        system("cls");

        printf("O Triangulo Retangulo eh o seguinte:\n");
        for(linha = 1; linha <= altura; linha++){
            for(coluna = 1; coluna <= linha; coluna++){
                produto = linha*coluna;
                printf("%d ", produto);
            }
            printf("\n");
        }
        system("Pause");
        break;

    case 2:

        printf("Encerrando programa !");
        return;

    default:
        printf("Erro!\n");
        printf("Por favor digite uma das opcoes exibidas na tela ! \n");
        system("pause");
        system("cls");
        break;

    }

return main();
}
