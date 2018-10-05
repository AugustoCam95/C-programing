#include <stdio.h>
#define MAX 10

int main(){
	
	float i,soma = 0, conjunto[MAX], media,MaiorTemperatura = -1000 ,MenorTemperatura = 1000;
	int cont =0;
	
	for(; cont < MAX; cont++){
	
		printf("Digite a temperatura do dia %d :\n", cont);
		scanf("%f", &conjunto[cont]);

		
		soma = soma + conjunto[cont];
		
	}	
	
	media = soma / MAX;
	
	for (cont = 0; cont < MAX; cont++)
	{
		if( conjunto[cont] > MaiorTemperatura ){
			MaiorTemperatura = conjunto[cont];
		}
	
		if( conjunto[cont] < MenorTemperatura){
			MenorTemperatura = conjunto[cont];
		}
	
	}


	printf("Temperaturas:\n");
	printf("Maior: %.2f \n", MaiorTemperatura);
	printf("Media: %.2f \n", media);
	printf("Menor: %.2f \n", MenorTemperatura);
	
	printf("Temperaturas acima da media\n");
	for(cont = 0; cont < MAX; cont++){
		if( conjunto[cont] > media){
			printf("%.2f\n", conjunto[cont]);
		}
	}

	printf("\n");

	printf("Temperaturas abaixo da media\n");
	for(cont = 0; cont < MAX; cont++){
		if( conjunto[cont] < media){
			printf("%.2f\n", conjunto[cont]);
		}
	}

	

return 0;
}

