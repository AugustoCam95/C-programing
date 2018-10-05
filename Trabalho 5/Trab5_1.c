#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define minAposta 1
#define maxAposta 20
#define minNum 1
#define maxNum 100

/*Confere se o elemento que se desejar inserir se encontra dentro do vetor, caso encontre retorna 1 se não encontrar retorna 0*/
int repetido(int *aposta,int Nescolha,int tam){
    int i,repetir = 0;

    for( i = 0; i < tam; i++){
        if( Nescolha == aposta[i]){
           repetir = 1;
           break;
        }
    }

    return repetir;
}
/*De acordo com o tamanho da aposta inserida pelo usuario, o usuario irar digitar os numeros entre 1 - 100 , sem ultrapassar esse limite e sem poder colocar numero repetido
caso faça isso o programa rejeita o numero e pede para inserir outro
*/
void ler_aposta(int *aposta, int Naposta){

    int i = 0;
    int Nescolha;

    printf("Digite seus numeros: \n");
    while(i < Naposta){
        scanf("%d", &Nescolha);
        if((Nescolha > minNum - 1)&&(Nescolha < maxNum + 1)){
            if(repetido(aposta, Nescolha, i) == 0){
                aposta[i] = Nescolha;
                i++;
            }
            else{
                printf("Numero repetido. Escolha outro numero...\n");
            }
        }
        else{
            printf("Numero incorreto. Entre outro numero...\n");
        }
    }
}
/*Gera os numeros aleatorios para o bilhete premiado no intervalo entre 1 - 100 e sem repetição*/
void sorteia_valores(int *sorteio, int n){
    int i = 0,x;

     /*Gerar bilhete premiado aleatorio*/
    while( i < n){
        x = 1 + rand() % 100;
        if( repetido(sorteio,x,n) == 0){
            sorteio[i] = x;
            i++;
        }

    }


}
/*Compara o vetor aposta e o sorteio, conta os elementos repetidos, armazena os elementos repetidos em um novo vetor alocado dinamicamente e retorna para funcao principal*/
int *compara_aposta( int *aposta, int *sorteio, int *qtacertos, int na, int ns){
    int i,j = 0, k = 0;
    int *p,*q;

    for( i = 0; i < na; i++){
        for(j = 0; j < ns; j++){
            if( aposta[i] == sorteio[j]){
                k++;
            }
        }
    }

    *qtacertos = k;

    if( k > 0 ){
        p = (int*) malloc(na*sizeof(int));

        for( i = 0; i < na; i++){
            p[i] = 0;
        }

        for( i = 0; i < na; i++){
            for(j = 0; j < ns; j++){
                if( aposta[i] == sorteio[j]){
                    p[i] = aposta[i];
                }
            }
        }

        q = (int*) malloc(k*sizeof(int));

        for( i = 0; i < k; i++){
            q[i] = 0;
        }

        i = 0;

        while( i < k){
            for( j = 0; j < na; j++){
                if( p[j] != 0){
                    q[i] = p[j];
                    i++;
                }
            }
        }

        return q;
        free(q);
        q = NULL;
        free(p);
        p = NULL;
    }
    if( k == 0){
        return NULL;
        free(q);
        q = NULL;
        free(p);
        p = NULL;
    }
}

int main(){
    int Naposta = 0, Nescolha = 0;
    int *aposta, *sorteio, *acertou;
    int qtacertos = 0;
    int i,j;
    srand(time(NULL));

    printf("\n\n### Bem vindo ao Bingo de programacao ! ###\n");
    while( (Naposta < minAposta ) || (Naposta > maxAposta) ){
        printf("Quantos numeros deseja apostar? (Entre 1 e 20)\n");
        scanf("%d", &Naposta);
    }

    aposta =  (int*) malloc(Naposta*sizeof(int));
    sorteio = (int*) malloc(20*sizeof(int));
    acertou = (int*) malloc(Naposta*sizeof(int));
    printf("###AVISOS###\n");
    printf("Para inserir os numeros da sua aposta, digite o numero e aperte enter para continuar inserindo...\n");
    printf("Digite numeros entre 1 e 100, caso contrario o programa rejeita, manda mensagem e pede para colocar outro numero...\n");
    printf("Caso digite um numero ja inserido, o programa reijeita, manda mensagem e pede para colocar outro numero...\n");
    printf("############\n");
    ler_aposta(aposta,Naposta);
    printf("Sua aposta:\n");
    for( i = 0; i < Naposta; i++){
        printf("%d\t",aposta[i]);
        if( (i+1)%5 == 0){
            printf("\n");
        }
    }
    printf("\n");

    sorteia_valores(sorteio, 20);

    printf("Bilhete premiado:\n");
    for( i = 0; i < 20; i++){
        printf("%d\t",sorteio[i]);
        if( (i+1)%5 == 0){
            printf("\n");
        }
    }
    printf("\n");

    acertou = compara_aposta(aposta,sorteio,&qtacertos,Naposta,20);

    printf("A quantidade de acertos foi: %d \n",qtacertos);
    if( qtacertos > 0){
        printf("Seus acertos foram com os numeros: \n");
        for( i = 0; i < qtacertos; i++){
            printf("%d\t", acertou[i]);
            if( (i+1)%5 == 0){
                printf("\n");
            }
        }
    }
    printf("\n");

    free(aposta);
    aposta = NULL;

    free(sorteio);
    sorteio = NULL;

    free(acertou);
    acertou = NULL;


    return 0;

}
