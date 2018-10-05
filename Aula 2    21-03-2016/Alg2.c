#include <stdio.h>
int main(){
	
	float a1,a2 = 0;
	float a3;
	int cont = 0;
	
	while( cont > -1){
		printf("Digite um numero:\n");
		scanf("%f",&a1);
		if( a1 == -99){
			break;
		}
		a2=a2+a1;
		cont=cont+1;
		
	}
	
	a3= (a2/cont);
	
	printf("Soma: %.2f \n", a2);
	printf("Media: %.2f \n", a3);
	


return 0;
}
