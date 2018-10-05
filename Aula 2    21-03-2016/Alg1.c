#include <stdio.h>
#define MAX 30

int main(){
	
	float i,soma = 0, t1 = -1000, t2 = 1000, media;
	int cont=0;
	
	while ( cont != MAX){
	
		printf("Digite a temperatura do dia %d :\n", cont);
		scanf("%f", &i);

		if( i > t1 ){
			t1=i;
		}
	
		if( i< t2 ){
			t2=i;
		}
	
		soma = soma + i;
		cont = cont + 1;
		
		}
	
	media = soma / MAX;
	
	printf("Temperaturas:\n");
	printf("Maior: %.2f \n", t1);
	printf("Media: %.2f \n", media);
	printf("Menor: %.2f \n", t2);
	
return 0;
}

