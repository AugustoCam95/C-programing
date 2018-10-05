//O algoritmo funciona da seguinte forma: O usuario insere a opção de acordo com o menu, caso digite inserir dados de um aluno ele irá inserir todos os campos de matricula,nome,
//notas e faltas que ficarão armazenados no sistema até o mesmo ficar cheio que irá mandar uma menssagem de "Sistema cheio". Caso o usuario queira remover uma matricula, o sistema
//verifica se ela existe, se existir os dados da referida matricula serão apagados, mas se não existir o sistema envia uma menssagem alertando que não existe a matricula. As outras
// três opções são para printar os alunos com as devidas categorias Aprovados, Reprovados  por falta e reprovados por desempenho.

#include <stdio.h>
#include <string.h>
#define Aluno 20

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
                       media = ( notas[Linha][0] + notas[Linha][1] + notas[Linha][2] ) / 3.0;
                       if( (media > 6.9) && (faltas[Linha] < 11) ){
                            printf(" %s \n", nome[Linha]);
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
                       media = ( notas[Linha][0] + notas[Linha][1] + notas[Linha][2] ) / 3.0;
                       if( (media < 7) && (faltas[Linha] < 11) ){
                            printf(" %s \n", nome[Linha]);
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
