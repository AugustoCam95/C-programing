#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    /*Declaração de variaveis*/
	char nome[50],tamanhoString,tabelaAsc;
	int numero,distancia,contador, inicioPalavra = 0,memorizarPosicao = 0;

	printf("Algortimo de padronizacao de nomes\n");
    /*Obtendo a string inserida pelo usuario atraves do comando "gets" */
	printf("Digite o nome desejado:\n");
	gets(nome);
	/*Obtendo o tamanho da string inserida*/
	tamanhoString = strlen(nome);
    /*Neste laço iremos varrer a string para deixar todos os caracteres de acordo com os elementos de 65 até 90 da tabela ascII*/
	for( contador = 0; contador < tamanhoString; contador++){
		tabelaAsc = nome[contador];
		if( (64 < tabelaAsc) && (tabelaAsc < 91)){
			numero= (int) tabelaAsc;
			distancia = numero - 65;
			tabelaAsc = 97 + distancia;
		}
		nome[contador]= tabelaAsc;
	}

	/*Neste laço iremos trocar as letras do começo das palavras das cadeias com tamanho maior que 2 para de acordo com os elementos 97 até 122 da tabela ascII*/
	for( contador = 0; contador < tamanhoString; contador++){
        /*Como todo nome começa com letra maiúscula aqui já iniciamos fazendo a mudança*/
		if( contador == 0){
			tabelaAsc = nome[contador];
			if( (96 < tabelaAsc) && (tabelaAsc < 123)){
				numero= (int) tabelaAsc;
				distancia = numero - 97;
				tabelaAsc = 65 + distancia;
			}
			nome[contador]= tabelaAsc;
		}
        /*Neste condicional iremos verificar o tamanho da palavra para mudar sua letra inicial e não mudar de palavras como "de" ou "da"*/
		if( ((int)nome[contador-1] == (int)' ') && ((int) nome[contador] != (int) ' ' ) && ((int)nome[contador+1] != (int)' ') && ((int)nome[contador+2] != (int) ' ') && ((int)nome[contador+3]) != (int)' '){
			tabelaAsc = nome[contador];
			if( (96 < tabelaAsc) && (tabelaAsc < 123)){
				numero= (int) tabelaAsc;
				distancia = numero - 97;
				tabelaAsc = 65 + distancia;
			}
			nome[contador]= tabelaAsc;
		}

	}

    /*Imprimimos o resultado final*/
	printf("%s\n",nome);

	return 0;
}



