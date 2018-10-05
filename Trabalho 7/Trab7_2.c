#include <stdio.h>

/*A funcao recebe um numero e antes que ele fique igual a zero, ai ele pega as divisões a partir da ultima até chegar na primeira e sai printando na tela*/
int Dec2Bin(int num){

    int quociente, resto;

	if(num != 0){
		quociente = num / 2;
		resto = num-quociente * 2;
		Dec2Bin(quociente);
		printf("%d", resto);
	}
}

int main(){
    int num;

    printf("Digite um numero:\n");
    scanf("%d", &num);
    Dec2Bin(num);

    return 0;
}
