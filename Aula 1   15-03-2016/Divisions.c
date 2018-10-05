#include<stdio.h>
int main(){
	int numero,p1,p2,soma;
	while( numero < 10000 ){
		p1= numero/100;
		p2= numero%100;
		soma= p1+p2;
		soma= soma*soma;
		if( soma == numero ){
			printf("%d\n",numero);
		}
		numero++;
	}
return 0;
}
