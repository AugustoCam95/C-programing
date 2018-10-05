#include <stdio.h>

int main(){
	int tamanho = 0, matriz[10][10],ContadorLinha,ContadorColuna,Diagonal = 0;
	
	while( (tamanho < 3) || (tamanho >10)){
		printf("Digite o tamanho da matriz ( Entre 3 e 10 )\n");
		scanf("%d", &tamanho);
		if ((tamanho < 3)||( tamanho >)){
			printf("Valor invalido. Digite novamente\n");
		}
	}

	printf("Digite os valores da matriz: \n");
	for(ContadorColuna = 0; ContadorColuna < tamanho; ContadorColuna++){
		for (ContadorLinha = 0; ContadorLinha < tamanho; ContadorLinha++)
		{
			scanf("%d", &matriz[ContadorColuna][ContadorLinha]);
			if( matriz[ContadorColuna][ContadorLinha] < 0 ){
				matriz[ContadorColuna][ContadorLinha] = 0;
			} 
		}
	}

	for(ContadorColuna = 0; ContadorColuna < tamanho; ContadorColuna++){
		for (ContadorLinha = 0; ContadorLinha < tamanho; ContadorLinha++)
		{
			if( ContadorColuna == ContadorLinha ){
				Diagonal = Diagonal + matriz[ContadorColuna][ContadorLinha];			}
			 
		}
	}

	printf("O valor da Diagonal eh: %d\n",Diagonal );
	for(ContadorColuna = 0; ContadorColuna < tamanho; ContadorColuna++){
		for (ContadorLinha = 0; ContadorLinha < tamanho; ContadorLinha++)
		{
			printf("%d\t",matriz[ContadorColuna][ContadorLinha]); 
		}
		printf("\n");
	}



return 0;
}