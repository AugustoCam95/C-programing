#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Aluno 20
/*Essa função auxiliar recebe os valores do vetor notas e o valor variavel linha, em que ambos da funcao principal*/
float novaMedia( float notas[Aluno][3], int linha){

    /*Declaração de variaveis para função auxiliar*/
    int indiceMaior = -1;
    float media;
    float maior = 0,maior2 = 0;

    /*Tesete para encontrar o maior de todos ou simplesmente um numero que se repita e seja maior que os outros, logo em seguida armazena na variavel "maior" e salva o
    indice do vetor notas na variavel "indiceMaior" */
    if( ( notas[linha][0] >= notas[linha][1] ) && ( notas[linha][0] >= notas[linha][2] ) ){
        maior = notas[linha][0];
        indiceMaior = 0;
    }

    if( ( notas[linha][1] >= notas[linha][0] ) && ( notas[linha][1] >= notas[linha][2] ) ){
        maior = notas[linha][1];
        indiceMaior = 1;
    }

    if( ( notas[linha][2] >= notas[linha][0] ) && ( notas[linha][2] >= notas[linha][1] ) ){
        maior = notas[linha][2];
        indiceMaior = 2;
    }

    /*Neste outro bloco de condicionais, iremos através da variavel "indiceMaior" encontrar o segundo maior através da comparação com as outras duas notas, observe que a
    a decisão de quem vai pra variavel "maior2" é feita pela segunda parte da condição onde fica o operador "||"  e em seguida maior2 = notas[linha][indice do segundo maior]*/
    if( ( indiceMaior != 0 ) && ( maior >= notas[linha][0] ) && ( (notas[linha][0] >= notas[linha][2])  ||  (notas[linha][0] >= notas[linha][1]) )){
        maior2 = notas[linha][0];
    }

    if( ( indiceMaior != 1 ) && ( maior >=  notas[linha][1] ) && ( ( notas[linha][1] >= notas[linha][2])  ||  (notas[linha][1] >= notas[linha][0] ) )){
        maior2 = notas[linha][1];
    }

    if( ( indiceMaior != 2 ) && ( maior >= notas[linha][2] ) && ( (notas[linha][2] >= notas[linha][0])  ||  (notas[linha][2] >= notas[linha][1]) )){
        maior2 = notas[linha][2];
    }

    /*Soma maior com maior2, divide por 2 e retorna o resultado para a função principal*/
    media = (maior+maior2)/2;
    return media;
}



int main(){

	int matricula[Aluno];
	char nome[Aluno][500];
	float notas[Aluno][3], media;
	int faltas[Aluno];
    int decisao = -1, Linha, RemoverMatricula, Coluna, contador = 0, verifica, achouMatricula = 0;

    for(Linha = 0; Linha < Aluno; Linha++){
        matricula[Linha] = 0;
    }

    printf("Algoritmo para organizar a particao dos alunos\n");


        while( ( decisao < 0 ) || ( decisao > 5 ) ){

            printf("Digite a opcao desejada:\n");
            printf("0 - Sair do programa.\n");
            printf("1 - Inserir dados de um aluno.\n");
            printf("2 - Remover dados de um aluno a partir da matricula.\n");
            printf("3 - listar alunos aprovados.\n");
            printf("4 - listar alunos reprovados por falta.\n");
            printf("5 - listar alunos reprovados por desempenho.\n");
            scanf("%d", &decisao);

            if( ( decisao < 0 )  || ( decisao > 5 ) ){
                printf("Erro !.Digite sua escolha novamente.\n");
                printf("\n");
            }


            switch(decisao){

                case 0:
                        printf("Encerrando programa !");
                        return 0;

                case 1:

                    for( Linha = contador; Linha < contador+1; Linha++){
                        if( matricula[Linha] == 0){
                            printf("Digite a matricula do aluno %d:\n",contador+1);
                            scanf("%d", &matricula[Linha]);
                            printf("Digite o nome do aluno %d:\n",contador+1);
                            scanf("%s", nome[Linha]);
                            printf("Digite as notas do aluno %d:\n",contador+1);
                            for(Coluna = 0; Coluna < 3; Coluna++){
                                scanf("%f", &notas[Linha][Coluna]);
                            }
                            printf("Digite as faltas do aluno %d:\n", contador+1);
                            scanf("%d", &faltas[Linha]);

                        }
                        if(contador == Aluno){
                            printf("Sistema cheio\n");
                        }
                    }
                    contador++;
                    break;

                case 2:

                    printf("Digite a matricula do aluno para remover seus dados:\n");
                    scanf("%d", &RemoverMatricula);

                    for( Linha = 0; Linha < Aluno; Linha++){
                        if( matricula[Linha] == RemoverMatricula){
                            matricula[Linha] = 0;
                            strcpy( nome[Linha], "" );
                            for(Coluna = 0; Coluna < 3; Coluna++){
                                notas[Linha][0] = 0;
                                notas[Linha][1] = 0;
                                notas[Linha][2] = 0;
                            }
                            faltas[Linha]=0;
                            contador--;
                            achouMatricula = 1;
                        }
                    }
                    if(achouMatricula != 1 ){
                        printf("Nao existe essa matricula no sistema.\n");
                    }
                    else{
                        printf("Matricula eliminada...\n");
                    }
                    break;

                case 3:

                    printf("Alunos aprovados:\n");
                    for( Linha = 0; Linha < Aluno; Linha++){
                        /*Aqui fazemos a chamada da funcao novaMedia para calcular nossa nova media e armazenar na variavel media da funcao principal*/
                        media = novaMedia(notas,Linha);
                        if( (media > 6.9) && (faltas[Linha] < 11) ){
                            printf(" %s  com media %.2f \n", nome[Linha], media);
                        }
                    }
                    break;

                case 4:

                    printf("Alunos reprovados por falta:\n");
                    for( Linha = 0; Linha < Aluno; Linha++){
                        if( (faltas[Linha] > 10) && (matricula[Linha] > 0) ){
                            printf(" %s \n ", nome[Linha]);
                        }
                    }

                    break;


                case 5:
                    printf("Alunos reprovados por baixo rendimento:\n");
                    for( Linha = 0; Linha < Aluno; Linha++){
                        /*Aqui fazemos a chamada da funcao novaMedia para calcular nossa nova media e armazenar na variavel media da funcao principal*/
                        media = novaMedia(notas,Linha);
                        if( (media < 7) && (faltas[Linha] < 11) && (matricula[Linha] > 0) ){
                            printf(" %s  com media %.2f \n", nome[Linha], media);
                        }
                    }
                    break;
            }

            printf("Deseja voltar ao menu: 0 - Sim / Qualquer outro valor - Nao\n");
            scanf("%d", &verifica);
            if( verifica == 0){
                decisao = -1;
            }

        }

    return 0;
}
