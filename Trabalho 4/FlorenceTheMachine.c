#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Declaração de todas as estruturas usadas neste código relativos ao Partido, Estado e Congressista.*/
typedef struct TPartido_{
    char sigla[5];
    char nome[30];
}TPartido;

typedef struct TEstado_{
    char sigla[2];
    char nome[20];
}TEstado;

typedef struct TCongressista_{
    char nome[60];
    int matricula;
    int voto;
    TPartido partido;
    TEstado estado;
    int bancada;
}TCongressista;

/*Cada vez que essa funcao é chamada inserimos a sigla e o nome de um partido, quando chega a 10 o código não entra mais aqui.*/
/*void preencherPartido(TPartido partido.sigla , TPartido partido.nome){

    TPartido partido;
    printf("Sigla do partido: \n");
    scanf( "%s", partido.sigla);
    printf("Nome do partido: \n");
    scanf( "%s", partido.nome);
}*/

/*Aqui prenchemos de uma vez só, todos os estados com a sua sigla e nome*/
/*
void preencherEstado( TEstado estado.sigla, TEstado estado.nome){

    TEstado estado[27];

    strcpy(estado[0].sigla,"AC");
    strcpy(estado[1].sigla,"AL");
    strcpy(estado[2].sigla,"AM");
    strcpy(estado[3].sigla,"AP");
    strcpy(estado[4].sigla,"BA");
    strcpy(estado[5].sigla,"CE");
    strcpy(estado[6].sigla,"DF");
    strcpy(estado[7].sigla,"ES");
    strcpy(estado[8].sigla,"GO");
    strcpy(estado[9].sigla,"MA");
    strcpy(estado[10].sigla,"MG");
    strcpy(estado[11].sigla,"MS");
    strcpy(estado[12].sigla,"MT");
    strcpy(estado[13].sigla,"PA");
    strcpy(estado[14].sigla,"PB");
    strcpy(estado[15].sigla,"PE");
    strcpy(estado[16].sigla,"PI");
    strcpy(estado[17].sigla,"PR");
    strcpy(estado[18].sigla,"RJ");
    strcpy(estado[19].sigla,"RN");
    strcpy(estado[20].sigla,"RO");
    strcpy(estado[21].sigla,"RR");
    strcpy(estado[22].sigla,"RS");
    strcpy(estado[23].sigla,"SC");
    strcpy(estado[24].sigla,"SE");
    strcpy(estado[25].sigla,"SP");
    strcpy(estado[26].sigla,"TO");
    strcpy(estado[0].nome,"Acre");
    strcpy(estado[1].nome,"Alagoas");
    strcpy(estado[2].nome,"Amazonas");
    strcpy(estado[3].nome,"Amapa");
    strcpy(estado[4].nome,"Bahia");
    strcpy(estado[5].nome,"Ceara");
    strcpy(estado[6].nome,"Distrito Federal");
    strcpy(estado[7].nome,"Espirito Santo");
    strcpy(estado[8].nome,"Goiais");
    strcpy(estado[9].nome,"Maranhao");
    strcpy(estado[10].nome,"Minas Gerais");
    strcpy(estado[11].nome,"Mato Grosso do sul");
    strcpy(estado[12].nome,"Mato Grosso");
    strcpy(estado[13].nome,"Para");
    strcpy(estado[14].nome,"Parnaiba");
    strcpy(estado[15].nome,"Parana");
    strcpy(estado[16].nome,"Pernanbuco");
    strcpy(estado[17].nome,"Piaui");
    strcpy(estado[18].nome,"Rio de Janeiro");
    strcpy(estado[19].nome,"Rio Grande do Norte");
    strcpy(estado[20].nome,"Rio Grande do Sul");
    strcpy(estado[21].nome,"Rondonia");
    strcpy(estado[22].nome,"Roraima");
    strcpy(estado[23].nome,"Santa Catarina");
    strcpy(estado[24].nome,"Sergipe");
    strcpy(estado[25].nome,"Sao Paulo");
    strcpy(estado[26].nome,"Tocatins");
}*/

/*Aqui é computado o voto do deputado, respeitando as opções na tela.*/
/*
void votaDeputado(TCongressista deputado.voto){
     while( ( deputado.voto < 0 )  || ( deputado.voto > 2 ) ){
        printf("Digite o voto do congressista: (0 - A favor / 1 - Contra / 2 - Abstenção) \n");
    }
    scanf("%d",&deputado.voto);
}*/

void imprimirContabilizacaoDeVoto( int votos[513] ){

    int afavor = 0, contra = 0, abstencia = 0,i, modoApuracao = 0;
    int somaVotos;

    for( i = 0; i < 513; i++){
        if( votos[i] == 0){
            afavor++;
        }
        if( votos[i] == 1){
            contra++;
        }
        if( votos[i] == 2){
            abstencia++;
        }
    }

    printf("Qual a forma da apuracao ? \n");
    printf("1 - Metade dos votos + 1 \n");
    printf("2 - Dois tercos dos votos validos \n");
    scanf("%d", &modoApuracao);

    if( modoApuracao != 1 && modoApuracao != 2){
        printf("MODO INDEFINIDO DE APURACAO \n");
    }

    somaVotos = afavor + contra;

    switch(modoApuracao){

    case 1:
        printf("Votos a favor: %d \n",afavor);
        printf("Votos  contra: %d \n",contra);
        printf("abstencias: %d \n",abstencia);

        if( (afavor >= (somaVotos/2)+1) && (afavor != 0) ){
            printf("Projeto aprovado !\n");
        }
        else{
            printf("Projeto negado !\n");
        }
        break;

    case 2:
        printf("Votos a favor: %d \n",afavor);
        printf("Votos  contra: %d \n",contra);
        printf("abstencias: %d \n",abstencia);

        if( (afavor >= somaVotos*(2/3)) && (afavor != 0) ){
            printf("Projeto aprovado !\n");
        }
        else{
            printf("Projeto negado !  \n");
        }
        break;
    }
}

void ContabilizacaoDeVotoPorPreferencia( TCongressista  deputado[513], int decisao){

    int bancada,i, afavor = 0, contra = 0, abstencia = 0, ausencia = 0, numero, distancia, tamanhoString, comparadorString;
    char state[2], tabelaAsc, vinculo[2];
    switch(decisao){

        case 1:
            printf("Escolha o estado pela sigla:\n");
            scanf("%s", vinculo);

            tamanhoString = strlen(vinculo);
            for( i = 0; i < tamanhoString; i++){
                tabelaAsc = vinculo[i];
                if( (96 < tabelaAsc) && (tabelaAsc < 123)){
                    numero= (int) tabelaAsc;
                    distancia = numero - 97;
                    tabelaAsc = 65 + distancia;
                }
                vinculo[i] = tabelaAsc;
            }

            comparadorString = strcmp(vinculo, deputado[i].partido.sigla);

            for( i = 0; i < 513; i++){
                if( comparadorString == 0){
                    if( deputado[i].voto == -1){
                        ausencia++;
                    }
                    if( deputado[i].voto == 0){
                        afavor++;
                    }
                    if( deputado[i].voto == 1){
                        contra++;
                    }
                    if( deputado[i].voto == 2){
                        abstencia++;
                    }
                }
            }
            printf("Votos a favor: %d \n",afavor);
            printf("Votos  contra: %d \n",contra);
            printf("abstencias: %d \n",abstencia);
            printf("ausencias: %d \n",ausencia);

            break;

        case 2:
            printf("Escolha o estado pela sigla:\n");
            scanf("%s", state);

            tamanhoString = strlen(state);
            for( i = 0; i < tamanhoString; i++){
                tabelaAsc = state[i];
                if( (96 < tabelaAsc) && (tabelaAsc < 123)){
                    numero= (int) tabelaAsc;
                    distancia = numero - 97;
                    tabelaAsc = 65 + distancia;
                }
                state[i] = tabelaAsc;
            }

            comparadorString = strcmp(state, deputado[i].estado.sigla);

            for( i = 0; i < 513; i++){
                if( comparadorString == 0){
                    if( deputado[i].voto == -1){
                        ausencia++;
                    }
                    if( deputado[i].voto == 0){
                        afavor++;
                    }
                    if( deputado[i].voto == 1){
                        contra++;
                    }
                    if( deputado[i].voto == 2){
                        abstencia++;
                    }
                }
            }
            printf("Votos a favor: %d \n",afavor);
            printf("Votos  contra: %d \n",contra);
            printf("abstencias: %d \n",abstencia);
            printf("ausencias: %d \n",ausencia);
            break;

        case 3:
            printf("Escolha a bancada:\n");
            scanf("%d", &bancada);
            for( i = 0; i < 513; i++){
                if( bancada == deputado[i].bancada){
                    if( deputado[i].voto == -1){
                        ausencia++;
                    }
                    if( deputado[i].voto == 0){
                        afavor++;
                    }
                    if( deputado[i].voto == 1){
                        contra++;
                    }
                    if( deputado[i].voto == 2){
                        abstencia++;
                    }
                }
            }
            printf("Votos a favor: %d \n",afavor);
            printf("Votos  contra: %d \n",contra);
            printf("abstencias: %d \n",abstencia);
            printf("ausencias: %d \n",ausencia);
            break;
    }
}



int main(){

        int decisao = -1, verifica, contadorPartido = 0, contadorDeputado = 0, escolherMatricula, verificaMatricula, i, recebedor=-1, distancia, numero, tamanhoString;
        int votos[513], verificaEstado = -1, verificaPartido = -1;
        char tabelaAsc;

        TCongressista deputado[513];
        TPartido partido[10];
        TEstado estados[27] = {"AC","Acre", "AL", "Alagoas", "AP", "Amapa", "AM", "Amazonas", "BA", "Bahia", "CE", "Ceara",
                            "DF", "Distrito Federal", "ES", "Espirito Santo", "GO", "Goias", "MA", "Maranhao", "MT", "Mato Grosso",
                            "MS", "Mato Grosso do Sul", "MG", "Minas Gerais", "PA", "Para", "PB", "Paraiba", "PR", "Parana",
                            "PE", "Pernambuco", "PI", "Piaui", "RJ", "Rio de Janeiro", "RN", "Rio Grande do Norte",
                            "RS", "Rio Grande do Sul", "RO", "Rondonia", "RR", "Roraima", "SC", "Santa Catarina", "SP", "Sao Paulo",
                            "SE", "Sergipe", "TO", "Tocantins"};

        for( i = 0 ; i < 513; i++){
            deputado[i].voto = -1;
        }

        while( ( decisao < 0 ) || ( decisao > 7 ) ){
            printf("### Votacao do impedimento ###\n");
            printf("Digite a opcao desejada:\n");
            printf("0 - Sair do programa.\n");
            printf("1 - Incluir partido.\n");
            printf("2 - Incluir congressista.\n");
            printf("3 - Realizar o voto de um deputado.\n");
            printf("4 - Contabilizar votacao.\n");
            printf("5 - Contabilizar voto por partido.\n");
            printf("6 - Contabilizar voto por estado.\n");
            printf("7 - Contabilizar voto por bancada.\n");
            sefbuf(stdin , NULL);
            scanf("%d", &decisao);

            if( ( decisao < 0 )  || ( decisao > 7 ) ){
                printf("Erro !.Digite sua escolha novamente.\n");
                printf("\n");
            }


            switch(decisao){

                case 0:
                        printf("Encerrando votacao !");
                        return 0;

                case 1:

                    if( contadorPartido < 10){
                        printf("Sigla do partido: \n");
                        sefbuf(stdin , NULL);
                        scanf( "%s", partido[contadorPartido].sigla);

                        tamanhoString = strlen( partido[contadorPartido].sigla );
                        for( i = 0; i < tamanhoString; i++){
                            tabelaAsc =  partido[contadorPartido].sigla[i];
                            if( (96 < tabelaAsc) && (tabelaAsc < 123)){
                                numero= (int) tabelaAsc;
                                distancia = numero - 97;
                                tabelaAsc = 65 + distancia;
                            }
                            partido[contadorPartido].sigla[i]= tabelaAsc;
                        }

                        printf("Nome do partido: \n");
                        gets(partido[contadorPartido].nome);

                        printf("Sigla do partido:%s \n", partido[contadorPartido].sigla);
                        printf("Nome do partido:%s \n", partido[contadorPartido].nome);
                        contadorPartido++;
                    }
                    else{
                        printf("Ja temos 10 partidos ! \n");
                    }

                    break;

                case 2:
                    if( contadorDeputado > 513){
                        printf("Digite o nome do congressista: \n");
                        gets(deputado[contadorDeputado].nome);

                        printf("Digite a matricula do congressista:\n");
                        sefbuf(stdin , NULL);
                        scanf("%d", &deputado[contadorDeputado].matricula);

                        while( verificaPartido == -1){
                            printf("Digite o partido do candidato: (Somente a sigla)\n");
                            sefbuf(stdin , NULL);
                            scanf("%s", deputado[contadorDeputado].partido.sigla);

                            tamanhoString = strlen(deputado[contadorDeputado].partido.sigla);
                            for( i = 0; i < tamanhoString; i++){
                                tabelaAsc =  deputado[contadorDeputado].partido.sigla[i];
                                if( (96 < tabelaAsc) && (tabelaAsc < 123)){
                                    numero= (int) tabelaAsc;
                                    distancia = numero - 97;
                                    tabelaAsc = 65 + distancia;
                                }
                                deputado[contadorDeputado].partido.sigla[i]= tabelaAsc;
                            }
                            for( i = 0; i < 10; i++){
                                verificaPartido = stricmp(deputado[contadorDeputado].partido.sigla, partido[i].sigla);
                            }
                        }
                        while( verificaEstado == -1){
                            printf("Digite o estado do canditado: (Somente a sigla)\n");
                            sefbuf(stdin , NULL);
                            scanf("%s", deputado[contadorDeputado].estado.sigla);

                            tamanhoString = strlen(deputado[contadorDeputado].estado.sigla);
                            for( i = 0; i < tamanhoString; i++){
                                tabelaAsc = deputado[contadorDeputado].estado.sigla[i];
                                if( (96 < tabelaAsc) && (tabelaAsc < 123)){
                                    numero= (int) tabelaAsc;
                                    distancia = numero - 97;
                                    tabelaAsc = 65 + distancia;
                                }
                                deputado[contadorDeputado].estado.sigla[i]= tabelaAsc;
                            }

                            for( i = 0; i < 27; i++){
                                verificaEstado = stricmp(deputado[contadorDeputado].estado.sigla, estados[i].sigla);
                            }
                        }

                        while( ( deputado[contadorDeputado].bancada < 1 )  || ( deputado[contadorDeputado].bancada > 5 ) ){
                            printf("Digite a bandaca do deputado:\n");
                            sefbuf(stdin , NULL);
                            scanf("%d", &deputado[contadorDeputado].bancada);
                        }

                        printf("Deputado cadastrado:\n");
                        printf("Nome do deputado:%s \n",deputado[contadorDeputado].nome);
                        printf("Matricula do deputado:%d \n",deputado[contadorDeputado].matricula);
                        printf("Voto do deputado:%d \n",deputado[contadorDeputado].voto);
                        printf("Partido do deputado:%s \n", deputado[contadorDeputado].partido.sigla);
                        printf("Estado do deputado:%s \n", deputado[contadorDeputado].estado.sigla);
                        contadorDeputado++;
                    }
                    else{
                        printf("Sistema foi totalmente preenchido!\n");
                    }
                    break;

                case 3:
                    printf("Digite a matricula do deputado: \n");
                    sefbuf(stdin , NULL);
                    scanf("%d", &escolherMatricula);
                    for( i = 0; i < 513; i++){
                        if( escolherMatricula == deputado[i].matricula){
                            verificaMatricula = i;
                            if ( deputado[verificaMatricula].voto == -1){
                                while( ( deputado[verificaMatricula].voto < 0 )  || ( deputado[verificaMatricula].voto > 2 ) ){
                                    printf("Digite o voto do congressista: (0 - A favor / 1 - Contra / 2 - Abstenção) \n");
                                    scanf("%d",&deputado[verificaMatricula].voto);
                                }

                            }
                            else{
                                printf("Sem maracutaia...este voto ja foi computado");
                            }
                        }
                        else{
                            printf("Matricula nao encontrada\n");
                        }
                    }

                    break;

                case 4:
                    for( i = 0; i < 513; i++){
                     votos[i] = deputado[i].voto;
                    }
                    imprimirContabilizacaoDeVoto(votos);

                    break;

                case 5:
                    ContabilizacaoDeVotoPorPreferencia( deputado, 1);
                    break;

                case 6:
                    ContabilizacaoDeVotoPorPreferencia( deputado, 2);
                    break;

                case 7:
                    ContabilizacaoDeVotoPorPreferencia( deputado, 3);
                    break;
            }

        printf("Deseja voltar ao menu: -1 - Sim / Qualquer outro valor - Nao\n");
        sefbuf(stdin , NULL);
        scanf("%d",&decisao);



    }

    return 0;
}
