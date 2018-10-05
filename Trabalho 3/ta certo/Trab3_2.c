#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tamString 30

/*Esta função recebe o numero da variavel hora e o numero da variável modo ambas da funcao principal e retorna a versao por extenso do respectivo numero de acordo com o valor
inserido em modo para o formato 12 horas ou 24 horas*/
char * horaExtenso(int hora, int modo){

    if(modo == 1){

        if( hora == 0){
            return "Zero";
        }

        if( hora == 1 ){
            return "Uma";
        }

        if( hora == 2 ){
            return "Duas";
        }

        if( hora == 3 ){
            return "Três";
        }

        if( hora == 4 ){
            return "Quatro";
        }

        if( hora == 5 ){
            return "Cinco";
        }

        if( hora == 6  ){
            return "Seis";
        }

        if( hora == 7 ){
            return "Sete";
        }

        if( hora == 8 ){
            return "Oito";
        }

        if( hora == 9 ){
            return "Nove";
        }

        if( hora == 10 ){
            return "Dez";
        }

        if( hora == 11 ){
            return "Onze";
        }

        if( hora == 12 ){
            return "Doze";
        }

         if( hora == 13 ){
            return "Treze";
        }

        if( hora == 14 ){
            return "Quatorze";
        }

        if( hora == 15 ){
            return "Quinze";
        }

        if( hora == 16 ){
            return "Dezesseis";
        }

        if( hora == 17 ){
            return "Dezessete";
        }

        if( hora == 18 ){
            return "Dezoito";
        }

        if( hora == 19 ){
            return "Dezenove";
        }

        if( hora == 20 ){
            return " Vinte";
        }

        if( hora == 21 ){
            return " Vinte e um";
        }

        if( hora == 22 ){
            return "Vinte e dois";
        }

        if( hora == 23 ){
            return "Vinte e três";
        }
    }

    if(modo == 2){
        if(hora == 1 || hora == 13){
            return "Uma";
        }
        if((hora == 2) || (hora == 14)){
            return "Duas";
        }
        if((hora == 3) || (hora == 15)){
            return "Três";
        }
        if( (hora == 4) || (hora == 16) ){
            return "Quatro";
        }
        if(hora == 5 || hora == 17){
            return "Cinco";
        }
        if(hora == 6 || hora == 18){
            return "Seis";
        }
        if(hora == 7 || hora == 19){
            return "Sete";
        }
        if((hora == 8) || (hora == 20)){
            return "Oito";
        }
        if((hora == 9) || (hora == 21)){
            return "Nove";
        }
        if((hora == 10) || (hora == 22)){
            return "Dez";
        }
        if((hora == 11) || (hora == 23)){
            return "Onze";
        }
        if((hora == 12) || (hora == 00)){
            return "Doze";
        }
    }
}
    /*Esta função recebe o numero da variavel minuto da funcao principal e retorna a versao por extenso do respectivo numero*/
char * minutoExtenso(int minuto){

    if(minuto == 1){
        return "um";
    }

    if(minuto == 2){
        return "dois";
    }
    if(minuto == 3){
        return "três";
    }

    if(minuto == 4){
        return "quatro";
    }

    if(minuto == 5){
        return "cinco";
    }

    if(minuto == 6){
        return "seis";
    }

    if(minuto == 7){
        return "sete";
    }

    if(minuto == 8){
        return "oito";
    }

    if(minuto == 9){
        return "nove";
    }

    if(minuto == 10){
        return "dez";
    }

    if(minuto == 11){
        return "onze";
    }

    if(minuto == 12){
        return "doze";
    }

    if(minuto == 13){
        return "treze";
    }

    if(minuto == 14){
        return "quatorze";
    }

    if(minuto == 15){
        return "quinze";
    }

    if(minuto == 16){
        return "dezeseis";
    }

    if(minuto == 17){
        return "dezesete";
    }

    if(minuto == 18){
        return "dezoito";
    }

    if(minuto == 19){
        return "dezenove";
    }

    if(minuto == 20){
        return "vinte";
    }

    if(minuto == 21){
        return "vinte e um";
    }

    if(minuto == 22){
        return "vinte e dois";
    }

    if(minuto == 23){
        return "vinte e três";
    }

    if(minuto == 24){
        return "vinte e quatro";
    }

    if(minuto == 25){
        return "vinte e cinco";
    }

    if(minuto == 26){
        return "vinte e seis";
    }

    if(minuto == 27){
        return "vinte e sete";
    }

    if(minuto == 28){
        return "vinte e oito";
    }

    if(minuto == 29){
        return "vinte e nove";
    }

    if(minuto == 30){
        return "trinta";
    }

    if(minuto == 31){
        return "trinta e um";
    }

    if(minuto == 32){
        return "trinta e dois";
    }

    if(minuto == 33){
        return "trinta e três";
    }

    if(minuto == 34){
        return "trinta e quatro";
    }

    if(minuto == 35){
        return "trinta e cinco";
    }

    if(minuto == 36){
        return "trinta e seis";
    }

    if(minuto == 37){
        return "trinta e sete";
    }

    if(minuto == 38){
        return "trinta e oito";
    }

    if(minuto == 39){
        return "trinta e nove";
    }

    if(minuto == 40){
        return "quarenta";
    }

    if(minuto == 41){
        return "quarenta e um";
    }

    if(minuto == 42){
        return "quarenta e dois";
    }

    if(minuto == 43){
        return "quarenta e três";
    }

    if(minuto == 44){
        return "quarenta e quatro";
    }

    if(minuto == 45){
        return "quarenta e cinco";
    }

    if(minuto == 46){
        return "quarenta e seis";
    }

    if(minuto == 47){
        return "quarenta e sete";
    }

    if(minuto == 48){
        return "quarenta e oito";
    }

    if(minuto == 49){
        return "quarenta e nove";
    }

    if(minuto == 50){
        return "cinquenta";
    }

    if(minuto == 51){
        return "cinquenta e um";
    }

    if(minuto == 52){
        return "cinquenta e dois";
    }

    if(minuto == 53){
        return "cinquenta e três";
    }

    if(minuto == 54){
        return "cinquenta e quatro";
    }

    if(minuto == 55){
        return "cinquenta e cinco";
    }

    if(minuto == 56){
        return "cinquenta e seis";
    }

    if(minuto == 57){
        return "cinquenta e sete";
    }

    if(minuto == 58){
        return "cinquenta e oito";
    }

    if(minuto == 59){
        return "cinquenta e nove";
    }

}


int main(){

    /*Declaração de variaveis*/
    int modo = 3;
    int hora,minuto;
    char stringHora[tamString];
    char stringMinuto[tamString];
    char stringManha[tamString];
    char stringTarde[tamString];
    char stringNoite[tamString];
    char stringMadrugada[tamString];

    printf("Algoritmo conversao\n");

    printf("Digite a hora:\n");
    scanf("%d", &hora);
    printf("Digite os minutos:\n");
    scanf("%d", &minuto);

    /*Laço para fazer com que modo só possa receber apenas 1 e 2*/
    while( modo == 3){
        printf("Escolha o modo de exibicao: 24 - 1 / 12 - 2 \n");
        scanf("%d", &modo);
        if( modo != 1 && modo != 2){
            modo = 3;
        }
    }

    /*Verificadores para detectar horas inválidas*/
    if( hora > 23){
        printf("Hora Invalida\n");
        return 0;
    }
    if( minuto > 59){
        printf("Hora Invalida\n");
        return 0;
    }

    /*Nesse bloco iremos "dar valor" as strings atraves do comando "strcpy"  */
    strcpy(stringHora, horaExtenso(hora,modo));
    strcpy(stringMinuto, minutoExtenso(minuto));
    strcpy(stringManha, "da manha");
    strcpy(stringTarde, "da tarde");
    strcpy(stringNoite, "da noite");
    strcpy(stringMadrugada, "da madrugada");

    /*Aqui iremos printar a hora para quando o usuário digitar modo = 2, dessa forma irá imprimir a hora no formato 12 horas acrescida do respectivo complemento.*/
    if(modo == 2){

        if( (0 <= hora) && (hora < 5)){

            if(hora ==1){
                printf(" %s hora e %s minutos %s \n", stringHora, stringMinuto, stringMadrugada);
            }
            else{
                printf(" %s horas e %s minutos %s \n", stringHora, stringMinuto, stringMadrugada);
            }
        }

        if( (5 <= hora) && (hora < 12)){
            printf(" %s horas e %s minutos %s \n", stringHora, stringMinuto, stringManha);
        }

        if( (12<= hora) && (hora < 18)){
             if(hora ==13){
                printf(" %s hora e %s minutos %s \n", stringHora, stringMinuto, stringTarde);
            }
            else{
                printf(" %s horas e %s minutos %s \n", stringHora, stringMinuto, stringTarde);
            }
        }

        if( (18<= hora) && (hora < 24)){
            printf(" %s horas e %s minutos %s \n", stringHora, stringMinuto, stringNoite);
        }

    }
    /*Aqui iremos printar a hora para quando o usuário digitar modo = 1, dessa forma irá imprimir a hora no formato 24 horas.*/
    if(modo == 1){

        if( (0 <= hora) && (hora < 5)){

            if(hora ==1){
                printf(" %s hora e %s minutos \n", stringHora, stringMinuto);
            }
            else{
                printf(" %s horas e %s minutos  \n", stringHora, stringMinuto);
            }

        }

        if( (5 <= hora) && (hora < 12)){
            printf(" %s horas e %s minutos  \n", stringHora, stringMinuto);
        }

        if( (12<= hora) && (hora < 18)){
            printf(" %s horas e %s minutos  \n", stringHora, stringMinuto);
        }

        if( (18<= hora) && ( hora < 24)){
            printf(" %s horas e %s minutoss  \n", stringHora, stringMinuto);
        }

    }


    return 0;
}
