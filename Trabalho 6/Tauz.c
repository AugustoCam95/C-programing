#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
        int matricula;
        char nome[50];
        float notas[3];
        int faltas;
}TStudent;

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
    /*Declaracao*/
    char nomeArquivo[50];
    int tamTurma, oldTurma;
    int temporario = -1;
    FILE *aptr;
    TStudent *aluno,*temp;
    int descobrir;
    int i,j;
    int existeAr = 1;
    int aumentarTurma = 9999;
    int decisao = -1, Linha, RemoverMatricula, Coluna, contador = 0, verifica, achouMatricula = 0, media;
    int matriculatemp;
    char nometemp[50];
    int v[3],faltastemp;
    int marcador = 0;
    int decisaoConsulta = -1;
    int decisaoMudar = -1;
    int notaMudar;
    int faltaMudar;
    char stringMudar[50];
    int decisaoReordenar = -1;

    /*Apresentacao do codigo*/
    printf("Algoritmo para organizar a particao dos alunos em um arquivo binario\n");
    printf("Digite o nome do arquivo:(por favor colocar .bin)\n");
    scanf("%s", nomeArquivo);

    while( ( decisao < 0 ) || ( decisao > 6 ) ){

            aptr = fopen(nomeArquivo,"rb");

            /*Verificar existencia do arquivo*/
            if( aptr == NULL){
                printf("Nao existe arquivo pre-existente\n");
                existeAr = 0;
            }
            else{
                existeAr = 1;
            }
            fclose(aptr);
            fflush(aptr);

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

            if( ( decisao < 0 )  || ( decisao > 6 ) ){
                printf("Erro !.Digite sua escolha novamente.\n");
                printf("\n");
            }


            switch(decisao){

                case 0:
                        printf("Encerrando programa !");
                        return 0;

                case 1:
                    if( existeAr == 0 ){
                        aptr = fopen(nomeArquivo,"wb");
                        printf("Nao existe um arquivo com esse nome, iremos iniciar um arquivo com esse nome!\n");
                        printf("Digite o tamanho da turma:\n");
                        scanf("%d",&tamTurma);
                        aluno = (TStudent*) malloc(tamTurma*sizeof(TStudent));
                        for(Linha = 0; Linha < tamTurma; Linha++){
                            aluno[Linha].matricula = 0;
                        }
                    }

                    if( existeAr == 1){
                        aptr = fopen(nomeArquivo,"ab");
                        fseek(aptr,sizeof(TStudent),SEEK_END);
                        fread(&tamTurma,sizeof(int),1,aptr);
                        fread(&aluno,sizeof(TStudent),tamTurma,aptr);

                    }

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
                    fwrite(&tamTurma,sizeof(int),1,aptr);
                    fwrite(&aluno,sizeof(TStudent),1,aptr);
                    fclose(aptr);
                    fflush(aptr);
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
                    printf("Digite a matricula do aluno que deseja alterar os dados\n");
                    scanf("%d", &matriculatemp);
                    for( i = 0; i < tamTurma; i++){
                        if( matriculatemp == aluno[i].matricula){
                            marcador = i;
                        }
                    }
                    if(marcador != 0){
                        while((decisaoConsulta > 0)&&(decisaoConsulta < 3 )){
                            printf("O que deseja mudar?\n");
                            printf("1. O nome do aluno.");
                            printf("2. A nota  aluno.");
                            printf("3. O numero de faltas do aluno.");
                        }
                    }
                    else{
                        printf("Matricula nao encontrada...\n");
                    }

                    marcador = 0;
                    break;
                case 4:
                    while((decisaoConsulta > 0) && ( decisaoConsulta < 2)){
                        printf("Deseja consultar os dados por:\n");
                        printf("1 - Pelo numero de matricula:\n");
                        printf("2 - Pelo nome do aluno \n");
                    }
                    switch(decisaoConsulta){
                        case 1:
                            printf("Digite a matricula do aluno que deseja consultar:\n");
                            scanf("%d", &matriculatemp);
                            for( i = 0; i < tamTurma; i++){
                                if( matriculatemp == aluno[i].matricula){
                                    marcador = i;
                                }
                            }
                            if(marcador != 0){
                                while((decisaoMudar > 0)&&(decisaoMudar < 3 )){
                                    printf("O que deseja mudar?\n");
                                    printf("1-mudar o nome.\n");
                                    printf("2-mudar uma nota.\n");
                                    printf("3-mudar a quantidade de faltas\n");
                                    scanf("%d", &decisaoMudar);
                                }
                                switch(decisaoMudar){
                                    case 1:
                                    printf("Digite o novo nome:\n");
                                    scanf("%s", stringMudar);
                                    strcpy(aluno[marcador].nome,stringMudar);
                                    break;

                                    case 2:
                                    printf("Qual nota deseja mudar:(escolha de 1 a 3)\n");
                                    scanf("%d",&notaMudar);
                                    notaMudar= notaMudar - 1;
                                    printf("Qual nota deseja colocar:\n");
                                    scanf("%d",aluno[marcador].notas[notaMudar]);

                                    break;

                                    case 3:
                                    printf("Digite a nova quantidade de faltas do aluno:\n");
                                    scanf("%d",aluno[marcador].faltas);
                                    break;
                                }
                            }
                            else{
                                printf("Matricula nao encontrada...\n");
                            }

                        break;

                        case 2:
                        /*Aqui lascou =(*/
                        break;
                    }

                    break;

                case 5:



                    break;

                case 6:
                    fopen(nomeArquivo,"rb");
                    fread(&tamTurma,sizeof(int),1,aptr);

                    printf("tamTurma valor: %d\n",tamTurma);
                    printf("Listagem de alunos no sistema:\n");
                    for(i = 0;i < tamTurma;i++){
                        fread(&aluno,sizeof(TStudent),i+1,aptr);
                        if(aluno[i].matricula != 0){
                            printf("Matricula: %d\n",aluno[i].matricula);
                            printf("Nome: %s\n",aluno[i].nome);
                            printf("Nota 1: %.2f\n",aluno[i].notas[0]);
                            printf("Nota 2: %.2f\n",aluno[i].notas[1]);
                            printf("Nota 3: %.2f\n",aluno[i].notas[2]);
                            printf("Faltas: %d\n",aluno[i].faltas);
                        }
                    }
                    fclose(aptr);
                    fflush(aptr);
                    break;

                case 7:
                    printf("Universidade Federal do Ceara\n");
                    printf("Disciplina de Programaçao\n");
                    printf("Professor: Fernando Trinta\n");
                    printf("-----------------------------------------------------\n");
                    printf("Matricula   Aluno       Nota1 Nota2 Nota3     Media  \n");
                    printf("-----------------------------------------------------\n");
                    for( i = 0; i < tamTurma; i++){
                        printf("%d  %s                  %f      %f      %f    %f     \n",aluno[i].matricula,aluno[i]);
                    }
                    printf("-----------------------------------------------------\n");
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



    return 0;
}
