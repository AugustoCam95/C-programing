#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
    int matricula;
    char nome[50];
    float notas[3];
    int faltas;
    int flag;
}TStudent;

/*Inseri um novo aluno no final do arquivo ou se não existir arquivo ele cria e começa a inserir*/
void inserirAluno(char nomeArquivo[50]){

    int existeArquivo = 1;
    int decisao = 1;

    int i,j;

    FILE *aptr;
    TStudent aluno;


    aptr = fopen(nomeArquivo,"rb");
    if(aptr == NULL){
        printf("Documento nao encontrado...\n");
        existeArquivo = 0;
    }
    if( aptr != NULL){
        existeArquivo = 1;
    }
    fclose(aptr);


    if( existeArquivo == 0){
        printf("O arquivo nao foi encontrado, logo iniciaremos um novo!\n");
        aptr = fopen(nomeArquivo,"a+b");
        do{
            printf("digite a matricula do aluno:\n");
            scanf("%d",&aluno.matricula );
            printf("digite o nome do aluno:\n");
            setbuf(stdin , NULL);
            scanf(" %[^\n]s", aluno.nome);
            printf("digite a nota 1:\n");
            scanf("%f", &aluno.notas[0]);
            printf("digite a nota 2:\n");
            scanf("%f", &aluno.notas[1]);
            printf("digite a nota 3:\n");
            scanf("%f", &aluno.notas[2]);
            printf("Digite as faltas do aluno:\n");
            scanf("%d", &aluno.faltas);
            aluno.flag = 1;

            fwrite(&aluno,sizeof(TStudent),1,aptr);

            printf("Deseja continuar inserindo? (1 - S / Qualquer num - N)\n");
            scanf("%d", &decisao);
        }while( decisao == 1);

        fclose(aptr);
    }

    if( existeArquivo == 1){
        printf("O arquivo foi encontrado, iremos inserir ao final do mesmo\n");
        aptr = fopen(nomeArquivo,"a+b");
        do{
            printf("digite a matricula do aluno:\n");
            scanf("%d",&aluno.matricula );
            printf("digite o nome do aluno:\n");
            setbuf(stdin , NULL);
            scanf(" %[^\n]s", aluno.nome);
            printf("digite a nota 1:\n");
            scanf("%f", &aluno.notas[0]);
            printf("digite a nota 2:\n");
            scanf("%f", &aluno.notas[1]);
            printf("digite a nota 3:\n");
            scanf("%f", &aluno.notas[2]);
            printf("Digite as faltas do aluno:\n");
            scanf("%d", &aluno.faltas);
            aluno.flag = 1;

            fwrite(&aluno,sizeof(TStudent),1,aptr);

            printf("Deseja continuar inserindo? (1 - S / Qualquer num - N)\n");
            scanf("%d", &decisao);
        }while( decisao == 1);

        fclose(aptr);
    }

}
/*Printa na tela todos os elementos ja cadastrados no arquivo*/
void listar(char nomeArquivo[50]){
    FILE *aptr;
    TStudent aluno;
    int i = 1;


    aptr = fopen(nomeArquivo,"r+b");

    if(aptr == NULL){
        printf("Documento nao encontrado...\n");
    }
    if( aptr != NULL){
        while( fread(&aluno,sizeof(TStudent),1,aptr) == 1){
            if( aluno.matricula != 0){
                printf("Aluno %d\n",i);
                printf("Matricula: %d\n",aluno.matricula);
                printf("Nome: %s\n",aluno.nome);
                printf("Nota 1: %.2f \n",aluno.notas[0]);
                printf("Nota 2: %.2f \n",aluno.notas[1]);
                printf("Nota 3: %.2f \n",aluno.notas[2]);
                printf("Faltas: %d \n",aluno.faltas);
                printf("-------------------------------\n");
            }
            i = i+1;
        }

    }
    fclose(aptr);
}
/*pesquisa o aluno de acordo com seu nome ou parte do nome*/
void pesquisarNome(char nomeArquivo[50]){
    FILE *aptr;
    TStudent aluno;
    char nomeComparar[30];



    aptr = fopen(nomeArquivo,"r+b");

    if(aptr == NULL){
        printf("Documento nao encontrado...\n");
    }
    if( aptr != NULL){
        printf("Digete o nome para consultar no sistema:\n");
        scanf("%s", nomeComparar);
        while( fread(&aluno,sizeof(TStudent),1,aptr) == 1){
            if(strstr(aluno.nome,nomeComparar) != NULL && aluno.flag == 1){
                printf("Matricula: %d\n",aluno.matricula);
                printf("Nome: %s\n",aluno.nome);
                printf("Nota 1: %.2f\n",aluno.notas[0]);
                printf("Nota 2: %.2f\n",aluno.notas[1]);
                printf("Nota 3: %.2f\n",aluno.notas[2]);
                printf("Faltas: %d\n",aluno.faltas);
                printf("-------------------------------\n");
            }
        }
    }
    fclose(aptr);
}
/*Altera o conjunto de dados de um aluno de acorodo com a posicao no arquivo*/
void alterarDados(char nomeArquivo[50]){

    FILE *aptr,*ptr;
    TStudent aluno;
    int i = 1;
    int posicao;
    int decisaoAlterar = -1;

    aptr = fopen(nomeArquivo,"r+b");

    if(aptr == NULL){
        printf("Documento nao encontrado...\n");
    }
    if( aptr != NULL){

        while( fread(&aluno,sizeof(TStudent),1,aptr) == 1){
                if(aluno.flag == 1){
                    printf("-----------------------------\n");
                    printf("Aluno %d\n",i);
                    printf("Matricula: %d\n",aluno.matricula);
                    printf("Nome: %s\n",aluno.nome);
                    printf("Nota 1: %.2f\n",aluno.notas[0]);
                    printf("Nota 2: %.2f\n",aluno.notas[1]);
                    printf("Nota 3: %.2f\n",aluno.notas[2]);
                    printf("Faltas: %d\n",aluno.faltas);
                    printf("-----------------------------\n");
                }
            i++;
        }
        printf("Dentre os alunos presente escolha aquele que deseja alterar  os dados de acordo com sua posicao\n");
        scanf("%d", &posicao);
        fseek(aptr,sizeof(TStudent)*(posicao - 1),SEEK_SET);
        printf("Digite o novo nome:\n");
        setbuf(stdin , NULL);
        scanf(" %[^\n]s", aluno.nome);
        printf("Digite as novas notas:\n");
        scanf("%f %f %f",&aluno.notas[0],&aluno.notas[1],&aluno.notas[2]);
        printf("Digite a nova quantidade de faltas\n");
        scanf("%d", &aluno.faltas);
        fseek(aptr,sizeof(TStudent)*(posicao - 1),SEEK_SET);
        fwrite(&aluno,sizeof(TStudent),1,aptr);
        fclose(aptr);
    }
}
/*Pesquisa o aluno pela matricula dele*/
void pesquisarMatricula(char nomeArquivo[50]){
    FILE *aptr;
    TStudent aluno;
    int matriculaConsulta;



    aptr = fopen(nomeArquivo,"rb");

    if(aptr == NULL){
        printf("Documento nao encontrado...\n");
    }
    if( aptr != NULL){
        printf("Digete a matricula para consultar no sistema:\n");
        scanf("%d", &matriculaConsulta);
        while( fread(&aluno,sizeof(TStudent),1,aptr) == 1){
            if( matriculaConsulta == aluno.matricula && aluno.flag == 1){
                printf("Matricula: %d\n",aluno.matricula);
                printf("Nome: %s\n",aluno.nome);
                printf("Nota 1: %f\n",aluno.notas[0]);
                printf("Nota 2: %f\n",aluno.notas[1]);
                printf("Nota 3: %ff\n",aluno.notas[2]);
                printf("Faltas: %d\n",aluno.faltas);
                printf("-------------------------------\n");
            }
        }
    }
    fclose(aptr);
}
/*A funcao excluir arquivo muda a flag do aluno para o valor 0 e nao ser mostrado na consulta*/
void excluirAluno(char nomeArquivo[50]){
    FILE *aptr;
    TStudent aluno;
    int i = 1;
    int posicao;
    int decisaoAlterar = -1;

    aptr = fopen(nomeArquivo,"r+b");

    if(aptr == NULL){
        printf("Documento nao encontrado...\n");
    }
    if( aptr != NULL){
        while( fread(&aluno,sizeof(TStudent),1,aptr) == 1){
                if(aluno.flag == 1){
                    printf("-----------------------------\n");
                    printf("Aluno %d\n",i);
                    printf("Matricula: %d\n",aluno.matricula);
                    printf("Nome: %s\n",aluno.nome);
                    printf("Nota 1: %.2f\n",aluno.notas[0]);
                    printf("Nota 2: %.2f\n",aluno.notas[1]);
                    printf("Nota 3: %.2f\n",aluno.notas[2]);
                    printf("Faltas: %d\n",aluno.faltas);
                    printf("-----------------------------\n");
                }
            i++;
        }
        printf("Dentre os alunos presente escolha aquele que deseja alterar  os dados de acordo com sua posicao\n");
        scanf("%d", &posicao);
        fseek(aptr,sizeof(TStudent)*(posicao - 1),SEEK_SET);
        aluno.flag = 0;
        fseek(aptr,sizeof(TStudent)*(posicao - 1),SEEK_SET);
        fwrite(&aluno,sizeof(TStudent),1,aptr);
        fclose(aptr);
    }
}

void BubbleSortMatricula(TStudent *vetor, int tamanho)
{
	int i, j;
    TStudent aux;

	for(j=tamanho-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(vetor[i].matricula > vetor[i+1].matricula){
				aux=vetor[i];
                vetor[i]=vetor[i+1];
                vetor[i+1]=aux;
            }
        }
    }
}


/*A funcao ordenarMatricula o arquivo de acordo com matricula do aluno, usamos o bubble sort para fazer a ordenacao*/
void ordenarMatricula(char nomeArquivo[50]){
    FILE *aptr;
    TStudent aluno, *alunotemp, aluno2;
    int i;
    int tamTurma;
    int j = 0;
    int troca;

    aptr = fopen(nomeArquivo,"r+b");

    if(aptr == NULL){
        printf("Documento nao encontrado...\n");
    }
    if( aptr != NULL){

        i = 0;
        while( fread(&aluno,sizeof(TStudent),1,aptr) == 1){
            i++;
        }

        alunotemp = (TStudent*) malloc(i*sizeof(TStudent));
        tamTurma = i;

        i = 0;

        rewind(aptr);

        while( fread(&aluno,sizeof(TStudent),1,aptr) == 1){
            alunotemp[i] = aluno;
            i++;
        }

        BubbleSortMatricula(alunotemp,tamTurma);

        rewind(aptr);


        i = 0;
        while(i< tamTurma){
            fseek(aptr, sizeof(TStudent)*i,SEEK_SET);
            aluno = alunotemp[i];
            fwrite(&aluno,sizeof(aluno),1,aptr);
            i++;
        }

    }
    fclose(aptr);
}

void BubbleSortNome(TStudent *vetor, int tamanho)
{
	int i, j;
    TStudent aux;

	for(j=tamanho-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(vetor[i].nome[0] > vetor[i+1].nome[0] ){
				aux=vetor[i];
                vetor[i]=vetor[i+1];
                vetor[i+1]=aux;
            }
        }
    }
}



/*A funcao ordenarNome o arquivo de acordo com a primeira letra do nome, usamos o bubble sort para fazer a ordenacao*/
void ordenarNome(char nomeArquivo[50]){
    FILE *aptr;
    TStudent aluno, *alunotemp, aluno2;
    int i = 0;
    int tamTurma;
    int j = 0;
    int troca;

    aptr = fopen(nomeArquivo,"r+b");

    if(aptr == NULL){
        printf("Documento nao encontrado...\n");
    }
    if( aptr != NULL){

        while( fread(&aluno,sizeof(TStudent),1,aptr) == 1){
            i++;
        }

        alunotemp = (TStudent*) malloc(i*sizeof(TStudent));
        tamTurma = i;

        i = 0;
        rewind(aptr);
        while( fread(&aluno,sizeof(TStudent),1,aptr) == 1){
            alunotemp[i] = aluno;
            i++;
        }


        BubbleSortNome(alunotemp,tamTurma);

        rewind(aptr);

        i = 0;
        while(i< tamTurma){
            fseek(aptr, sizeof(TStudent)*i,SEEK_SET);
            aluno = alunotemp[i];
            fwrite(&aluno,sizeof(aluno),1,aptr);
            i++;
        }
    }

    fclose(aptr);
}

/*Aqui na main iremos lançar as funcionalidades para as suas respctivas funções junto com o nome do arquivo, para o usuario nao precisar ficar acessando*/
int main(){
    /*Declaracao*/
    FILE *aptr, *ptr;
    TStudent aluno;
    char nomeArquivo[50];
    char relatorioNotas[50];
    int i;
    int marcador;
    int matriculatemp;
    int decisao = -1;
    int decisaoConsulta = -1;
    int decisaoReordenar = -1;
    int verifica;
    float mediaFinal;

    /*Apresentacao do codigo*/
    printf("Algoritmo para organizar a particao dos alunos em um arquivo binario\n");
    printf("Digite o nome do arquivo:(por favor colocar .txt)\n");
    scanf("%s", nomeArquivo);


    while( ( decisao < 0 ) || ( decisao > 7 ) ){
            printf("Digite a opcao desejada:\n");
            printf("0 - Sair do programa.\n");
            printf("1 - Inserir dados de um aluno.\n");
            printf("2 - Remover dados de um aluno a partir da matricula.\n");
            printf("3 - Alterar dados de um aluno.\n");
            printf("4 - Consultar dados de um aluno.\n");
            printf("5 - Reordenar arquivos de alunos.\n");
            printf("6 - Listar alunos.\n");
            printf("7 - Imprimir relatorio.\n");

            scanf("%d", &decisao);

            if( ( decisao < 0 )  || ( decisao > 7 ) ){
                printf("Erro !.Digite sua escolha novamente.\n");
                printf("\n");
            }


            switch(decisao){

                case 0:
                    printf("Encerrando programa !");
                    return 0;

                case 1:
                    inserirAluno(nomeArquivo);
                    break;

                case 2:
                    excluirAluno(nomeArquivo);
                    break;

                case 3:
                    alterarDados(nomeArquivo);
                    break;

                case 4:
                    while((decisaoConsulta < 1) || ( decisaoConsulta > 2)){
                        printf("Deseja consultar os dados por:\n");
                        printf("1 - Pelo numero de matricula.\n");
                        printf("2 - Pelo nome do aluno.\n");
                        scanf("%d",&decisaoConsulta);
                    }
                    switch(decisaoConsulta){

                        case 1:
                            pesquisarMatricula(nomeArquivo);
                        break;

                        case 2:
                            pesquisarNome(nomeArquivo);
                        break;
                    }

                    break;

                case 5:
                    while((decisaoReordenar < 1)||( decisaoReordenar > 2)){
                        printf("Como deseja ordenar o arquivo ?\n");
                        printf("1 - Pela matricula.\n");
                        printf("2 - Pelo nome.\n");
                        scanf("%d", &decisaoReordenar);
                    }
                    switch(decisaoReordenar){

                    case 1:
                        ordenarMatricula(nomeArquivo);

                    break;

                    case 2:
                        ordenarNome(nomeArquivo);
                    break;

                    }

                    break;

                case 6:
                    listar(nomeArquivo);
                    break;

                case 7:

                        aptr = fopen(nomeArquivo,"r+b");

                        if( aptr == NULL){
                            printf("Arquivo nao encontrado...\n");
                        }
                        else{
                            printf("Digite o nome para o arquivo final:\n");
                            scanf("%s", relatorioNotas);
                            ptr = fopen(relatorioNotas,"w");
                            fprintf(ptr,"%s %s %s %s\n","Universidade", "Federal", "do", "Ceara");
                            fprintf(ptr,"%s %s %s\n","Disciplina","de","Programacao");
                            fprintf(ptr,"%s %s %s\n","Professor:","Fernando","Trinta");
                            fprintf(ptr,"%s\n","---------------------------------------------------------");
                            fprintf(ptr,"%s   %s     %s    %s    %s        %s  \n","Matricula","Aluno","Nota1","Nota 2","Nota3","Media");
                            fprintf(ptr,"%s\n","---------------------------------------------------------");
                            i = 0;
                            while( fread(&aluno,sizeof(TStudent),1,aptr) == 1 ){
                                i++;
                            }
                            int tamTurma = i;
                            float *media;
                            media =  (float*) malloc(tamTurma*sizeof(float));
                            mediaFinal = 0;
                            i = 0;
                            rewind(aptr);
                            while( fread(&aluno,sizeof(TStudent),1,aptr) == 1 ){
                                media[i] = (float) (aluno.notas[0]+aluno.notas[1]+aluno.notas[2])/3;
                                fprintf(ptr,"%d         %s          %.2f    %.2f    %.2f         %.2f     \n",aluno.matricula,aluno.nome,aluno.notas[0],aluno.notas[1],aluno.notas[2],media[i]);
                                i++;
                            }
                            fprintf(ptr,"%s\n","---------------------------------------------------------");
                            fprintf(ptr,"%s %d\n","Total de alunos",tamTurma);
                            i = 0;
                            while( i < tamTurma){
                                mediaFinal =  mediaFinal + media[i];
                                i++;
                            }
                            mediaFinal = (mediaFinal/tamTurma);
                            fprintf(ptr,"%s %.2f\n","Media da turma:", mediaFinal);

                            fclose(ptr);
                        }

                    fclose(aptr);
                    break;

            }


        printf("Deseja voltar ao menu: 0 - Sim / Qualquer outro valor - Nao\n");
        scanf("%d", &verifica);
        if( verifica == 0){
            decisao = -1;
            decisaoConsulta = -1;
            decisaoReordenar = -1;
        }

    }


    return 0;
}
