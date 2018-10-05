#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Estrutura a ser utilizada no nosso código*/
typedef struct {
        int matricula;
        char nome[50];
        float notas[3];
        int faltas;
}TStudent;
/*Funcao reloc ira retornar o um vetor com o novo tamanho de acordo com o tamanho que o usuario desejar, em questao ela vai dobrar o tamanho do vetor.
  Em seguida, copiar os elementos para um novo vetor, enviar de volta para o nosso vetor aluno e depois damos o free no vetor utilizado  */
TStudent *reloc(TStudent *vetor, int pasttam ,int novotamanho){

	int i,j;
    TStudent *p;

	p = (TStudent*) malloc(novotamanho*sizeof(TStudent));

    for(i = 0; i < novotamanho; i++){
        p[i].matricula = 0;
    }

	for( i = 0; i < pasttam; i++ ){
		p[i].matricula = vetor[i].matricula;
		strcpy(p[i].nome,vetor[i].nome);
		for( j = 0; j < 3; j++){
			p[i].notas[j] = vetor[i].notas[j];
		}
		p[i].faltas = vetor[i].faltas;
	}

	return p;
    free(p);
    p = NULL;
}
/*Imprime os elementos do nosso vetor passado na funcao principal*/
void imprimir(TStudent *vetor, int tam){

    int i;

    for( i = 0; i < tam; i++){
        if( vetor[i].matricula != 0){
            printf("Nome do aluno: %s - Matricula:%d\n",vetor[i].nome,vetor[i].matricula);
            printf("Notas: %.2f %.2f %.2f   - Media:%.2f \n",vetor[i].notas[0],vetor[i].notas[1],vetor[i].notas[2],(vetor[i].notas[0]+vetor[i].notas[1]+vetor[i].notas[2])/3);
            printf("Faltas:%d \n", vetor[i].faltas);
        }
    }

}
/*Gera um vetor contendo alunos com media maior que 7 e menos de 11 faltas, para isso criamos um vetor com o tamanho do numero de alunos aprovados, copiamos o conteudo
 desse alunos aprovados para o novo vetor, enviamos para funcao principal e depois damos o free*/
TStudent *vetorAprovados(TStudent *vetor,int totalAlunos, int *totalAprovados){

    TStudent *q;
    int i,j,k = 0,l = 0;
    float media;

    for( i = 0; i < totalAlunos; i++){
        media = (vetor[i].notas[0] + vetor[i].notas[1] + vetor[i].notas[2])/3;
        if( (media > 6.9) && (vetor[i].faltas < 11) ){
            k++;
        }
    }
    *totalAprovados = k;
    q = (TStudent*) malloc(k*sizeof(TStudent));

    while( l < k){
        for( i = 0; i < totalAlunos; i++){
            media = (vetor[i].notas[0] + vetor[i].notas[1] + vetor[i].notas[2])/3;
            if( (media > 6.9) && (vetor[i].faltas < 11) ){
                q[l].matricula = vetor[i].matricula;
                strcpy(q[l].nome,vetor[i].nome);
                for( j = 0; j < 3; j++){
                    q[l].notas[j] = vetor[i].notas[j];
                }
                q[l].faltas = vetor[i].faltas;
                l++;
            }
        }
    }

    return q;
    free(q);
    q = NULL;
}
/*Retorna um vetor com os alunos reprovados por desempenho, o procedimento é o mesmo para o vetor de aprovado. Aqui, o que muda é o critério de entrada para o novo vetor*/
TStudent *vetorReprovadosDesempenho(TStudent *vetor,int totalAlunos, int *totalReprovadosDesem){

    TStudent *r;
    int i,j,k = 0,l = 0;
    float media;

    for( i = 0; i < totalAlunos; i++){
        media = (vetor[i].notas[0] + vetor[i].notas[1] + vetor[i].notas[2])/3;
        if( ( media < 7 ) && (vetor[i].faltas < 11) && ( vetor[i].matricula > 0 ) ){
            k++;
        }
    }
    *totalReprovadosDesem = k;
    r = (TStudent*) malloc(k*sizeof(TStudent));

    while( l < k){
        for( i = 0; i < totalAlunos; i++){
            media = (vetor[i].notas[0] + vetor[i].notas[1] + vetor[i].notas[2])/3;
            if( (media < 7) && (vetor[i].faltas < 11) && ( vetor[i].matricula > 0) ){
                r[l].matricula = vetor[i].matricula;
                strcpy(r[l].nome,vetor[i].nome);
                for( j = 0; j < 3; j++){
                    r[l].notas[j] = vetor[i].notas[j];
                }
                r[l].faltas = vetor[i].faltas;
                l++;
            }
        }
    }

    return r;
    free(r);
    r = NULL;
}
/*Retorna um vetor com os alunos reprovados por falta, o procedimento é o mesmo para o vetor de aprovado. Aqui, o que muda é o critério de entrada para o novo vetor*/
TStudent *vetorReprovadosFaltas(TStudent *vetor,int totalAlunos, int *totalReprovadosFaltas){

    TStudent *s;
    int i,j,k = 0,l = 0;
    float media;

    for( i = 0; i < totalAlunos; i++){
        media = (vetor[i].notas[0] + vetor[i].notas[1] + vetor[i].notas[2])/3;
        if( (vetor[i].faltas > 10) && ( vetor[i].matricula > 0 ) ){
            k++;
        }
    }
    *totalReprovadosFaltas = k;
    s = (TStudent*) malloc(k*sizeof(TStudent));

    while( l < k ){
        for( i = 0; i < totalAlunos; i++){
            media = (vetor[i].notas[0] + vetor[i].notas[1] + vetor[i].notas[2])/3;
            if( (vetor[i].faltas > 10) && ( vetor[i].matricula > 0) ){
                s[l].matricula = vetor[i].matricula;
                strcpy(s[l].nome,vetor[i].nome);
                for( j = 0; j < 3; j++){
                    s[l].notas[j] = vetor[i].notas[j];
                }
                s[l].faltas = vetor[i].faltas;
                l++;
            }
        }

    }

    return s;
    free(s);
    s = NULL;
}
/*Confere se o elemento que se desejar inserir se encontra dentro do vetor, caso encontre retorna 1 se não encontrar retorna 0*/
int repetido(TStudent *aluno,int Nescolha,int tam){
    int i,repetir = 0;

    for( i = 0; i < tam; i++){
        if( Nescolha == aluno[i].matricula){
           repetir = 1;
           break;
        }
    }

    return repetir;
}

int main(){
    /*Variaveis usadas*/
    TStudent *aluno,*aprovados,*repFalta,*repDesem;
    int decisao = -1, Linha, RemoverMatricula, Coluna, contador = 0, verifica, achouMatricula = 0, media;
    int tamTurma, oldTurma;
    int temporario = -1;
    int aumentarTurma = 9999;
    int totalAprovados = 0;
    int totalRepFalta = 0;
    int totalRepDesem = 0;
    int descobrir = 0;
    int matriculatemp = 0;
    char nometemp[50];
    int v[3];
    int faltastemp;
    int j;

    printf("Algoritmo para organizar a particao dos alunos\n");
    printf("Digite o tamanho da turma:\n");
    scanf("%d", &tamTurma);

    aluno = (TStudent*) malloc(tamTurma*sizeof(TStudent));

    for(Linha = 0; Linha < tamTurma; Linha++){
        aluno[Linha].matricula = 0;
    }

        while( ( decisao < 0 ) || ( decisao > 6 ) ){

            printf("Digite a opcao desejada:\n");
            printf("0 - Sair do programa.\n");
            printf("1 - Inserir dados de um aluno.\n");
            printf("2 - Remover dados de um aluno a partir da matricula.\n");
            printf("3 - listar alunos.\n");
            printf("4 - listar alunos aprovados.\n");
            printf("5 - listar alunos reprovados por falta.\n");
            printf("6 - listar alunos reprovados por desempenho.\n");
            scanf("%d", &decisao);

            if( ( decisao < 0 )  || ( decisao > 6 ) ){
                printf("Erro !.Digite sua escolha novamente.\n");
                printf("\n");
            }


            switch(decisao){

                case 0:
                        printf("Encerrando programa !");
                        return 0;

                case 1:
                    /*Aqui iremos incluir os dados do aluno, a novidade está que dessa vez não se pode digitar uma matricula repetida, além disso podemos aumentar o tamanho do vetor
                    para podemos incluir mais alunos na turma*/
                    if( contador < tamTurma){
                        for( Linha = contador; Linha < contador+1; Linha++){
                                while( temporario != 0){
                                    printf("Digite a matricula do aluno %d:\n", contador+1);
                                    scanf("%d", &temporario);
                                    if(repetido(aluno,temporario,contador) == 0 ){
                                        aluno[Linha].matricula = temporario;
                                        temporario = 0;
                                    }
                                    if(repetido(aluno,temporario,contador) == 1){
                                        printf("Matricula repetida, digite uma outra matricula...\n");
                                    }
                                }
                                temporario = -1;
                                printf("Digite o nome do aluno %d:\n",contador+1);
                                scanf("%s",aluno[Linha].nome);
                                printf("Digite as notas do aluno %d:\n",contador+1);
                                for(Coluna = 0; Coluna < 3; Coluna++){
                                    scanf("%f", &aluno[Linha].notas[Coluna]);
                                }
                                printf("Digite as faltas do aluno %d:\n", contador+1);
                                scanf("%d", &aluno[Linha].faltas);
                        }
                        if(contador < tamTurma){
                            contador++;
                        }
                    }
                    if(contador == tamTurma){
                            printf("Sistema cheio\n");
                            while( aumentarTurma == 9999){
                            	printf("Deseja dobrar o tamanho da turma? ( 1 - Sim / Qualquer - Nao) \n");
                            	scanf("%d", &aumentarTurma);
                            }
                            if( aumentarTurma == 1){
                            	oldTurma = tamTurma;
                            	tamTurma = tamTurma * 2;
                            	aluno = reloc( aluno,oldTurma,tamTurma);
                            	aumentarTurma = 9999;
                            }
                            if( aumentarTurma != 1){
                                aumentarTurma = 9999;
                            }

                    }

                    break;

                case 2:
                    /*Aqui procuramos encontrar a matricula para ser apagada, se acharmos iremos fazer um swap com o ultimo elemento e então eliminamos esse ultimo, damos uma
                    decrementada no contador. Caso nao seja encontrada a matricula, o programa mandará uma mensagem relatando que a matricula nao foi encontrada*/
                    printf("Digite a matricula do aluno para remover seus dados:\n");
                    scanf("%d", &RemoverMatricula);

                    for( Linha = 0; Linha < tamTurma; Linha++){
                        if( aluno[Linha].matricula == RemoverMatricula){
                            achouMatricula = 1;
                            descobrir = Linha;
                        }
                    }
                    if( achouMatricula == 1 ){
                        matriculatemp  = aluno[tamTurma-1].matricula;
                        strcpy(nometemp, aluno[tamTurma-1].nome);
                        for(j = 0; j < 3; j++){
                            v[j] = aluno[tamTurma-1].notas[j];
                        }
                        faltastemp = aluno[tamTurma-1].faltas;
                        aluno[tamTurma-1].matricula = aluno[descobrir].matricula;
                        strcpy(aluno[tamTurma].nome, aluno[descobrir].nome);
                        for( j = 0 ; j < 3; j++){
                            aluno[tamTurma-1].notas[j] = aluno[descobrir].notas[j];
                        }
                        aluno[tamTurma-1].faltas = aluno[descobrir].faltas;

                        aluno[descobrir].matricula = matriculatemp;
                        strcpy(aluno[descobrir].nome,nometemp);
                        for( j = 0 ; j < 3; j++){
                            aluno[descobrir].notas[j] = v[j];
                        }
                        aluno[descobrir].faltas = faltastemp;

                        aluno[tamTurma-1].matricula = 0;
                        strcpy(aluno[tamTurma-1].nome,"");
                        for( j = 0; j < 3; j++){
                            aluno[tamTurma-1].notas[j] = 0;
                        }
                        aluno[tamTurma-1].faltas = 0;
                        contador--;
                    }
                    if(achouMatricula != 1 ){
                        printf("Nao existe essa matricula no sistema.\n");
                    }
                    else{
                        printf("Matricula eliminada...\n");
                    }



                    break;

                case 3:
                    imprimir(aluno,tamTurma);
                    break;

                case 4:

                    aprovados = (TStudent*) malloc(tamTurma*sizeof(TStudent));
                    aprovados = vetorAprovados(aluno,tamTurma,&totalAprovados);
                    printf("Lista de aprovados:\n");
                    imprimir(aprovados,totalAprovados);
                    break;


                case 5:
                    repFalta = (TStudent*) malloc(tamTurma*sizeof(TStudent));
                    repFalta = vetorReprovadosFaltas(aluno,tamTurma,&totalRepFalta);
                    printf("Lista de reprovados por falta:\n");
                    imprimir(repFalta,totalRepFalta);
                    break;

                case 6:
                    repDesem = (TStudent*) malloc(tamTurma*sizeof(TStudent));
                    repDesem = vetorReprovadosDesempenho(aluno,tamTurma,&totalRepDesem);
                    printf("Lista de reprovados por desempenho:\n");
                    imprimir(repDesem,totalRepDesem);
                    break;
            }

            printf("Deseja voltar ao menu: 0 - Sim / Qualquer outro valor - Nao\n");
            scanf("%d", &verifica);
            if( verifica == 0){
                decisao = -1;
            }

        }
    /*Dar o free nas variaveis alocadas e faze-las receber NULL*/
    free(aluno);
    aluno = NULL;

    free(aprovados);
    aprovados = NULL;

    free(repDesem);
    repDesem= NULL;

    free(repFalta);
    repFalta= NULL;

    return 0;
}



