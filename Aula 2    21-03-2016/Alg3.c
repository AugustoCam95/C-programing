#include <stdio.h>

int main(){

	int numero,time1 = 0,time2 = 0,time3 = 0,time4 = 0,time5 = 0,contador=1;
	float porcetagem1,porcetagem2,porcetagem3,porcetagem4,porcetagem5;

	while( contador< 11 ){
		printf("Candidato %d, qual seu time 1-Ceara 2-Ferroviario 3-Fortaleza 4-Tiradentes 5-Nenhum: \n", contador);

		scanf("%d", &numero);
		contador = contador + 1;

		switch (numero){
			case 1: time1++;
					break;

			case 2: time2++;
					break;

			case 3: time3++;
					break;

			case 4: time4++;
					break;

			case 5: time5++;
					break;


		}
	}

	porcetagem1 = (float) time1/11;
	porcetagem2 = (float) time2/11;
	porcetagem3 = (float) time3/11;
	porcetagem4 = (float) time4/11;
	porcetagem5 = (float) time5/11;


	printf("Porcetagem Ceara: %.2f\n",porcetagem1);
	printf("Porcetagem Ferroviario: %.2f\n",porcetagem2);
	printf("Porcetagem Fortaleza: %.2f\n",porcetagem3);
	printf("Porcetagem Tiradentes: %.2f\n",porcetagem4);
	printf("Porcetagem Nenhum: %.2f\n",porcetagem5);

return 0;
}
