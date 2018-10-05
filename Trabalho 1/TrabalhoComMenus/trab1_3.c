#include <stdio.h>

// Este código realiza operações sucessivas de divisão para encontrar a quantidade de celulas e moedas para compor o valor da variavel Numero e
// o valor da variavel NumeroParteDecimal, e em seguida faz subtração: Numero = Numero - MultiplicadorPorDivisao( Valor da nota ) /
// NumeroParteDecimal = NumeroParteDecimal - MultiplicadorPorDivisao( Valor da moeda )para seguir em diante para as outras notas e de menor valor.
//
// Variavel Numero do tipo float fica com o valor do numero de entrada.
//
// Variavel NumeroParteDecimal do tipo float fica apenas com a parte decimal do numero de entrada.
//
// Coloquei um adicional de 0.001 na variavel NumeroParteDecimal para entrar nos laços de if's que não interfere nas operações realizadas


void main(){

    float Numero,NumeroParteDecimal;
    int MultiplicadorPorDivisao;

    printf("Digite um valor:\n");
    scanf("%f", &Numero);
    system("cls");
    printf("O valor %.2f sera decomposto de forma monetaria em:\n",Numero);
    NumeroParteDecimal = Numero + 0.001 - (int) Numero;



    printf("Notas:\n");
    if( Numero/100 >= 0){
        MultiplicadorPorDivisao = Numero/100;
        Numero = Numero - MultiplicadorPorDivisao*100;
        if( MultiplicadorPorDivisao > 1){
            printf("%d Notas de R$ 100.00\n", MultiplicadorPorDivisao);
        }
        else{
            printf("%d Nota de R$ 100.00\n", MultiplicadorPorDivisao);
        }
    }
    if( Numero/50 >= 0){
        MultiplicadorPorDivisao = Numero/50;
        Numero = Numero - MultiplicadorPorDivisao*50;
        if( MultiplicadorPorDivisao > 1){
            printf("%d Notas de R$ 50.00\n", MultiplicadorPorDivisao);
        }
        else{
            printf("%d Nota de R$ 50.00\n", MultiplicadorPorDivisao);
        }
    }
    if( Numero/20 >= 0){
        MultiplicadorPorDivisao = Numero/20;
        Numero = Numero - MultiplicadorPorDivisao*20;
        if( MultiplicadorPorDivisao > 1){
            printf("%d Notas de R$ 20.00\n", MultiplicadorPorDivisao);
        }
        else{
            printf("%d Nota de R$ 20.00\n", MultiplicadorPorDivisao);
        }
    }
    if( Numero/10 >= 0){
        MultiplicadorPorDivisao = Numero/10;
        Numero = Numero - MultiplicadorPorDivisao*10;
        if( MultiplicadorPorDivisao > 1){
            printf("%d Notas de R$ 10.00\n", MultiplicadorPorDivisao);
        }
        else{
            printf("%d Nota de R$ 10.00\n", MultiplicadorPorDivisao);
        }
    }
    if( Numero/5 >= 0){
        MultiplicadorPorDivisao = Numero/5;
        Numero = Numero - MultiplicadorPorDivisao*5;
        if( MultiplicadorPorDivisao > 1){
            printf("%d Notas de R$ 5.00\n", MultiplicadorPorDivisao);
        }
        else{
            printf("%d Nota de R$ 5.00\n", MultiplicadorPorDivisao);
        }
    }
    if( Numero/2 >= 0){
        MultiplicadorPorDivisao = Numero/2;
        Numero = Numero - MultiplicadorPorDivisao*2;
        if( MultiplicadorPorDivisao > 1){
            printf("%d Notas de R$ 2.00\n", MultiplicadorPorDivisao);
        }
        else{
            printf("%d Nota de R$ 2.00\n", MultiplicadorPorDivisao);
        }
    }

    printf("Moedas\n");

    if( Numero/1 >= 0){
        MultiplicadorPorDivisao = Numero/1;
        Numero = Numero - MultiplicadorPorDivisao*1;
        if( MultiplicadorPorDivisao > 1){
            printf("%d Moedas de R$ 1.00\n", MultiplicadorPorDivisao);
        }
        else{
            printf("%d Moeda de R$ 1.00\n", MultiplicadorPorDivisao);
        }
    }
    if( NumeroParteDecimal/(0.50) > 0.00){
        MultiplicadorPorDivisao =  ( NumeroParteDecimal / (0.5) );
        NumeroParteDecimal = NumeroParteDecimal -  MultiplicadorPorDivisao*(0.5);
        if( MultiplicadorPorDivisao > 1){
            printf("%d Moedas de R$ 0.50\n", MultiplicadorPorDivisao);
        }
        else{
            printf("%d Moeda de R$ 0.50\n", MultiplicadorPorDivisao);
        }
    }
    if( NumeroParteDecimal/(0.25) > 0.00){
        MultiplicadorPorDivisao = ( NumeroParteDecimal / (0.25) ) ;
        NumeroParteDecimal = NumeroParteDecimal -  MultiplicadorPorDivisao*(0.25);
        if( MultiplicadorPorDivisao > 1){
            printf("%d Moedas de R$ 0.25\n", MultiplicadorPorDivisao);
        }
        else{
            printf("%d Moeda de R$ 0.25\n", MultiplicadorPorDivisao);
        }
    }
    if( NumeroParteDecimal/(0.10) > 0.00){
        MultiplicadorPorDivisao = ( NumeroParteDecimal / (0.10) );
        NumeroParteDecimal = NumeroParteDecimal -  MultiplicadorPorDivisao*(0.10);
        if( MultiplicadorPorDivisao > 1){
            printf("%d Moedas de R$ 0.10\n", MultiplicadorPorDivisao);
        }
        else{
            printf("%d Moeda de R$ 0.10\n", MultiplicadorPorDivisao);
        }
    }
    if( NumeroParteDecimal/(0.05) > 0.00){
        MultiplicadorPorDivisao =  ( NumeroParteDecimal / (0.05) );
        NumeroParteDecimal = NumeroParteDecimal -  MultiplicadorPorDivisao*(0.05);
        if( MultiplicadorPorDivisao > 1){
            printf("%d Moedas de R$ 0.05\n", MultiplicadorPorDivisao);
        }
        else{
            printf("%d Moeda de R$ 0.05\n", MultiplicadorPorDivisao);
        }
    }
    if( (NumeroParteDecimal)/(0.01) > 0.00){
        MultiplicadorPorDivisao =  ( NumeroParteDecimal / (0.01) );
        NumeroParteDecimal = NumeroParteDecimal -  MultiplicadorPorDivisao*(0.01);
        if( MultiplicadorPorDivisao > 1){
            printf("%d Moedas de R$ 0.01\n", MultiplicadorPorDivisao);
        }
        else{
            printf("%d Moeda de R$ 0.01\n", MultiplicadorPorDivisao);
        }
    }

}
