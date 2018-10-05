#include<stdio.h>
#include<string.h>

/*Aqui fazemos nossa funcao recursiva para em cada chamada verifica o vetor char de acordo com o tamanho e a posicao, caso ele falhe logo a palavra
não é palindroma, mas se chegou a verrar todas as posicoes entao a palavra é um palindromo*/
int eh_palindromo(char palavra[50], int tamanho, int posicao){
    if( posicao >= tamanho){
        return 1;
    }else{
        if ( palavra[posicao] == palavra[tamanho]){
                eh_palindromo(palavra,tamanho-1,posicao+1);
        }
        else{
            return 0;
        }
    }
}

int main(){
    char palavra[50];
    char palavraSemEspaco[50];
    int j = 0;
    int i;
    int tam;

    printf("Digite a palavra:\n");
    setbuf(stdin , NULL);
    scanf(" %[^\n]s", palavra);

    /*Funcao para tirar os espaços vazios do vetor char*/
    for(i = 0; i < strlen(palavra); i++) {
        if(palavra[i] != ' ') {
            palavraSemEspaco[j] = palavra[i];
            j++;
        }
    }
    palavraSemEspaco[j] = '\0';

    tam = strlen(palavraSemEspaco);

    if(eh_palindromo(palavraSemEspaco,tam-1,0)){
        printf("Temos uma palavra palindroma !\n");
    }
    else{
        printf("Nao eh palindroma\n");
    }

    return 0;
}
