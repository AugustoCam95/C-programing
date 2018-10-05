#include<stdio.h>

/*Aqui a funcao recebe dois numeros, compara eles se forem iguais temos o MDC, caso seja Y>X trocamos os valores e rodamos de novo. Mas se caso X > Y, fazemos X=X-Y e chamamos a
funcao novamente em cima do novo X e de Y*/
int mdc(int x, int y){
    int z;

    if( x == y){
        return x;
    }
    if( y > x){
        z = x;
        x = y;
        y = z;
        return mdc(x,y);
    }
    if( x > y){
        return mdc( x-y,y);
    }

}
int main(){

    int x,y,z;

    printf("Digite o numero para X:\n");
    scanf("%d",&x);
    printf("Digite o numero para Y:\n");
    scanf("%d",&y);
    z = mdc(x,y);
    printf("MDC: %d",z);

}
