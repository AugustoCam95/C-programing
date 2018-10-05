#include <stdio.h>

//Este código é a primeira questão do Trabalho da cadeira de fundamentos
//aqui iremos imprimir na tela as figuras solicitadas na questão, o usuário
//seleciona de acordo com o menu a figura que quer imprimir na tela e
//em seguida entra com os valores necesários para formar a figura, como altura,base,numero ímpar e um numero qualquer.

//Fiz meu código usando mais de uma função para deixar mais organizado e fácil de trabalhar enquanto montava o mesmo.

void Retangulo( int Altura, int Base){

    int Linha,Coluna;

    for(Linha = 1; Linha <= Altura; Linha++){
        for(Coluna = 1; Coluna <= Base; Coluna++ ){
            printf("*");
        }
        printf("\n");
    }

}

void TrianguloRetangulo(int NumeroQualquer){

    int Linha,Coluna;

    for(Linha = 1; Linha <= NumeroQualquer; Linha++){
        for(Coluna = 1; Coluna <= Linha; Coluna++){
            printf("*");

        }
        printf("\n");
    }

}

void RetanguloVazio(int Altura, int Base){

    int Linha,Coluna;

     for(Linha = 1; Linha <= Altura; Linha++ ){
        for(Coluna = 1; Coluna <= Base; Coluna++){
            if((Linha == 1) || (Linha == Altura) ){
                printf("*");
            }
            else{
                if((Coluna == 1) || (Coluna == Base) ){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

}
void Piramide(int NumeroImpar){

    int Linha,Coluna,ParteInteira;

    ParteInteira = NumeroImpar/2;
    for(Linha = 1; Linha <= NumeroImpar; Linha=Linha+2){
        for(Coluna = 1; Coluna <= ParteInteira; Coluna++){
            printf(" ");
        }
        for( Coluna = 1; Coluna <= Linha; Coluna++){
            printf("*");
        }
        printf("\n");
        ParteInteira--;
    }

}

void Paralelograma(int NumeroQualquer){

    int Linha,Coluna;

    for( Linha = 1; Linha <= NumeroQualquer; Linha++){
        for( Coluna = 1; Coluna <= Linha; Coluna++){
            printf("*");
        }
        printf("\n");
    }
    for( Linha = 1; Linha <= NumeroQualquer; Linha++){
        for( Coluna = 1; Coluna <= Linha; Coluna++){
            printf(" ");
        }
        for( Coluna = NumeroQualquer-1; Coluna >= Linha; Coluna--){
            printf("*");
        }
        printf("\n");
    }


}

void main(){

    int Escolha,Altura,Base,NumeroImpar,NumeroQualquer,Verificador = 0;
    float RestoDaDivisao;

    printf("Algoritmo 1 - Imprimir figuras na tela.");
    printf("Digite sua escolha:\n");
    printf("0- Encerrar programa !\n");
    printf("1- Imprimir na tela um Retangulo !\n");
    printf("2- Imprimir na tela um Triangulo Retangulo !\n");
    printf("3- Imprimir na tela um Retangulo Vazio !\n");
    printf("4- Imprimir na tela um Piramide !\n");
    printf("5- Imprimir na tela um Paralelograma !\n");
    scanf("%d", &Escolha);


    switch (Escolha){

    case 0:
            printf("Encerrando programa !");
            return;

    case 1:
            system("cls");
            printf("Entre com o valor da altura:\n");
            scanf("%d", &Altura);
            printf("Entre com o valor da base:\n");
            scanf("%d", &Base);
            system("cls");
            printf("Seu Retangulo ficou assim:\n");
            Retangulo(Altura,Base);
            system("pause");
            system("cls");
            break;

    case 2:
            printf("Entre com um numero para o Triangulo Retangulo:\n");
            scanf("%d", &NumeroQualquer);
            system("cls");
            printf("Seu Triangulo retangulo ficou assim:\n");
            TrianguloRetangulo(NumeroQualquer);
            system("pause");
            system("cls");
            break;

    case 3:
            printf("Entre com o valor da altura:\n");
            scanf("%d", &Altura);
            printf("Entre com o valor da base:\n");
            scanf("%d", &Base);
            system("cls");
            printf("Seu Retangulo vazio ficou assim:\n");
            RetanguloVazio(Altura,Base);
            system("pause");
            system("cls");
            break;

    case 4:
            while(Verificador == 0){
                printf("Entre com o valor do numero impar:\n");
                scanf("%d", &NumeroImpar);
                RestoDaDivisao = NumeroImpar%2;
                if( RestoDaDivisao != 0 ){
                    Verificador=1;
                }
            }
            system("cls");
            printf("Sua Piramide ficou assim:\n");
            Piramide(NumeroImpar);
            system("pause");
            system("cls");
            break;

    case 5:
            printf("Entre com um numero para o Paralelograma:\n");
            scanf("%d", &NumeroQualquer);
            system("cls");
            printf("Seu Paralelograma ficou assim:\n");
            Paralelograma(NumeroQualquer);
            system("pause");
            system("cls");
            break;

    default:
            printf("Erro!\n");
            printf("Por favor digite uma das opcoes exibidas na tela ! \n");
            system("pause");
            system("cls");
            break;

    }

return main();
}
