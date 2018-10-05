#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Declaração de todas as estruturas usadas neste código relativos ao Partido, Estado e Congressista.*/
typedef struct TPartido_{
    char sigla[5];
    char nome[30];
}TPartido;

typedef struct TEstado_{
    char sigla[3];
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

/*Imprime os votos dos deputados, caso não tenha votado todas as variaveis ficam zero*/
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
    setbuf(stdin , NULL);
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

/*Imprime a contabilizacao através da opcao do menu*/
void ContabilizacaoDeVotoPorPreferencia( TCongressista  deputado[513], TPartido partido[10], TEstado estado[27], int decisao){

    int bancada,i ,j , afavor = 0, contra = 0, abstencia = 0, ausencia = 0, numero, distancia, tamanhoString, comparadorString;
    char state[2], tabelaAsc, vinculo[2];
    switch(decisao){

        case 1:
            printf("Escolha o partido pela sigla:\n");
            setbuf(stdin , NULL);
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

            for( j = 0; j < 10; j++){
                if(strcmp(vinculo, partido[j].sigla) == 0){


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
                            printf("%s\n", deputado[i].nome);
                            printf("%d\n", deputado[i].matricula);
                            printf("%s\n", deputado[i].partido.sigla);
                            printf("%s\n", deputado[i].partido.nome);
                            printf("%s\n", deputado[i].estado.sigla);
                            printf("%s\n", deputado[i].estado.nome);
                            printf("%d\n", deputado[i].bancada);
                            printf("%d\n", deputado[i].voto);
                        }
                    }
                    printf("Votos a favor: %d \n",afavor);
                    printf("Votos  contra: %d \n",contra);
                    printf("abstencias: %d \n",abstencia);
                    printf("ausencias: %d \n",ausencia);
                }
                else{
                    printf("Partido inexistente...\n");
                    break;
                }
            }
            break;

        case 2:
            printf("Escolha o estado pela sigla:\n");
            setbuf(stdin , NULL);
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

             for( j = 0; j < 10; j++){
                if(strcmp(vinculo, estado[j].sigla) == 0){
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
                            printf("%s\n", deputado[i].nome);
                            printf("%d\n", deputado[i].matricula);
                            printf("%s\n", deputado[i].partido.sigla);
                            printf("%s\n", deputado[i].partido.nome);
                            printf("%s\n", deputado[i].estado.sigla);
                            printf("%s\n", deputado[i].estado.nome);
                            printf("%d\n", deputado[i].bancada);
                            printf("%d\n", deputado[i].voto);
                        }
                    }
                    printf("Votos a favor: %d \n",afavor);
                    printf("Votos  contra: %d \n",contra);
                    printf("abstencias: %d \n",abstencia);
                    printf("ausencias: %d \n",ausencia);
                }
                else{
                    printf("Estado inexistente...\n");
                    break;
                }
             }
            break;

        case 3:
            printf("Escolha a bancada:\n");
            scanf("%d", &bancada);

             for( j = 0; j < 10; j++){
                if( bancada == deputado[j].bancada ){

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
                            printf("%s\n", deputado[i].nome);
                            printf("%d\n", deputado[i].matricula);
                            printf("%s\n", deputado[i].partido.sigla);
                            printf("%s\n", deputado[i].partido.nome);
                            printf("%s\n", deputado[i].estado.sigla);
                            printf("%s\n", deputado[i].estado.nome);
                            printf("%d\n", deputado[i].bancada);
                            printf("%d\n", deputado[i].voto);
                        }
                    }
                    printf("Votos a favor: %d \n",afavor);
                    printf("Votos  contra: %d \n",contra);
                    printf("abstencias: %d \n",abstencia);
                    printf("ausencias: %d \n",ausencia);
                }
                else{
                    printf("Bancada inexistente...\n");
                    break;
                }
            }
            break;

        }
}


int main(){

        int decisao = -1, verifica, contadorPartido = 0, contadorDeputado = 0, escolherMatricula, verificaMatricula, i, recebedor=-1, distancia, numero, tamanhoString;
        int votos[513], verificaEstado = -1, verificaPartido = -1, procurarPartidoNome = 0, procurarEstadoNome = 0, entradaPartido = -1;
        char tabelaAsc, partidoTeste[2];

        TCongressista deputado[513];
        TPartido partido[10];
        TEstado estado[27];/*= {"AC","Acre", "AL", "Alagoas", "AP", "Amapa", "AM", "Amazonas", "BA", "Bahia", "CE", "Ceara",
                            "DF", "Distrito Federal", "ES", "Espirito Santo", "GO", "Goias", "MA", "Maranhao", "MT", "Mato Grosso",
                            "MS", "Mato Grosso do Sul", "MG", "Minas Gerais", "PA", "Para", "PB", "Paraiba", "PR", "Parana",
                            "PE", "Pernambuco", "PI", "Piaui", "RJ", "Rio de Janeiro", "RN", "Rio Grande do Norte",
                            "RS", "Rio Grande do Sul", "RO", "Rondonia", "RR", "Roraima", "SC", "Santa Catarina", "SP", "Sao Paulo",
                            "SE", "Sergipe", "TO", "Tocantins"};*/



        //Estados siglas
        strcpy(estado[0].sigla,"AC\0");
        strcpy(estado[1].sigla,"AL\0");
        strcpy(estado[2].sigla,"AM\0");
        strcpy(estado[3].sigla,"AP\0");
        strcpy(estado[4].sigla,"BA\0");
        strcpy(estado[5].sigla,"CE\0");
        strcpy(estado[6].sigla,"DF\0");
        strcpy(estado[7].sigla,"ES\0");
        strcpy(estado[8].sigla,"GO\0");
        strcpy(estado[9].sigla,"MA\0");
        strcpy(estado[10].sigla,"MG\0");
        strcpy(estado[11].sigla,"MS\0");
        strcpy(estado[12].sigla,"MT\0");
        strcpy(estado[13].sigla,"PA\0");
        strcpy(estado[14].sigla,"PB\0");
        strcpy(estado[15].sigla,"PE\0");
        strcpy(estado[16].sigla,"PI\0");
        strcpy(estado[17].sigla,"PR\0");
        strcpy(estado[18].sigla,"RJ\0");
        strcpy(estado[19].sigla,"RN\0");
        strcpy(estado[20].sigla,"RO\0");
        strcpy(estado[21].sigla,"RR\0");
        strcpy(estado[22].sigla,"RS\0");
        strcpy(estado[23].sigla,"SC\0");
        strcpy(estado[24].sigla,"SE\0");
        strcpy(estado[25].sigla,"SP\0");
        strcpy(estado[26].sigla,"TO\0");

        //Estados nome
        strcpy(estado[0].nome,"Acre\0");
        strcpy(estado[1].nome,"Alagoas\0");
        strcpy(estado[2].nome,"Amazonas\0");
        strcpy(estado[3].nome,"Amapa\0");
        strcpy(estado[4].nome,"Bahia\0");
        strcpy(estado[5].nome,"Ceara\0");
        strcpy(estado[6].nome,"Distrito Federal\0");
        strcpy(estado[7].nome,"Espirito Santo\0");
        strcpy(estado[8].nome,"Goiais\0");
        strcpy(estado[9].nome,"Maranhao\0");
        strcpy(estado[10].nome,"Minas Gerais\0");
        strcpy(estado[11].nome,"Mato Grosso do sul\0");
        strcpy(estado[12].nome,"Mato Grosso\0");
        strcpy(estado[13].nome,"Para\0");
        strcpy(estado[14].nome,"Parnaiba\0");
        strcpy(estado[15].nome,"Parana\0");
        strcpy(estado[16].nome,"Pernanbuco\0");
        strcpy(estado[17].nome,"Piaui\0");
        strcpy(estado[18].nome,"Rio de Janeiro\0");
        strcpy(estado[19].nome,"Rio Grande do Norte\0");
        strcpy(estado[20].nome,"Rio Grande do Sul\0");
        strcpy(estado[21].nome,"Rondonia\0");
        strcpy(estado[22].nome,"Roraima\0");
        strcpy(estado[23].nome,"Santa Catarina\0");
        strcpy(estado[24].nome,"Sergipe\0");
        strcpy(estado[25].nome,"Sao Paulo\0");
        strcpy(estado[26].nome,"Tocatins\0");

        //inicializa os campos do deputado
        for( i = 0 ; i < 513; i++){
            deputado[i].voto = -1;
            deputado[i].matricula = 0;
            deputado[i].bancada = -1;
        }

        //Menu
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
            setbuf(stdin , NULL);
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
                        setbuf(stdin , NULL);
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
                        setbuf(stdin , NULL);
                        scanf(" %[^\n]s", partido[contadorPartido].nome);
                        printf("-------------------------------------------------\n");
                        printf("Sigla do partido:%s \n", partido[contadorPartido].sigla);
                        printf("Nome do partido:%s \n", partido[contadorPartido].nome);
                        printf("-------------------------------------------------\n");
                        contadorPartido++;
                    }
                    else{
                        printf("Ja temos 10 partidos ! \n");
                    }

                    break;


                    break;


                case 2:
                    if( contadorDeputado < 513){
                        printf("Digite o nome do congressista: \n");
                        setbuf(stdin , NULL);
                        scanf(" %[^\n]s",deputado[contadorDeputado].nome);

                        printf("Digite a matricula do congressista:\n");
                        setbuf(stdin , NULL);
                        scanf("%d", &deputado[contadorDeputado].matricula);

                        printf("---Partidos---\n");
                        for( i = 0; i < contadorPartido; i++){
                            printf("%s \n", partido[i].sigla);
                        }
                        while( verificaPartido == -1){
                            printf("Digite o partido do candidato: (Somente a sigla)\n");
                            setbuf(stdin , NULL);
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
                            for( i = 0; i < contadorPartido; i++){

                                if(strcmp(deputado[contadorDeputado].partido.sigla, partido[i].sigla) == 0){
                                    verificaEstado = 0;
                                    break;
                                }
                            }
                        }

                        //A partir da sigla inserida, o campo nome é preenchido
                        for( i = 0 ; i < 10; i++){
                            if(strcmp(deputado[contadorDeputado].partido.sigla,partido[i].sigla) == 0 ){
                                break;
                            }
                            else{
                                procurarPartidoNome++;
                            }
                        }
                        strcpy(deputado[contadorDeputado].partido.nome,partido[procurarPartidoNome].nome);

                        printf("---Estados---\n");
                        for( i = 0; i < 27; i++){
                            printf("%s \n", estado[i].sigla);
                        }
                        while( verificaEstado == -1){
                            printf("Digite o estado do canditado: (Somente a sigla)\n");
                            setbuf(stdin , NULL);
                            scanf(" %s", deputado[contadorDeputado].estado.sigla);
                            printf("%s\n", deputado[contadorDeputado].estado.sigla);

                            tamanhoString = strlen(deputado[contadorDeputado].estado.sigla);
                            printf("%d\n",tamanhoString);
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

                                if(strcmp(deputado[contadorDeputado].estado.sigla, estado[i].sigla) == 0){
                                    verificaEstado = 0;
                                    break;
                                }
                            }
                        }
                        //A partir da sigla inserida, o campo nome é preenchido
                        for( i = 0 ; i < 10; i++){
                            if(strcmp(deputado[contadorDeputado].estado.sigla,estado[i].sigla) == 0 ){
                                break;
                            }
                            else{
                                procurarEstadoNome++;
                            }
                        }

                        strcpy(deputado[contadorDeputado].estado.nome, estado[procurarEstadoNome].nome);

                        printf("----Bacadas----\n");
                        printf("1 - Ruralistas \n");
                        printf("2 - Religiosos\n");
                        printf("3 - Armamentistas\n");
                        printf("4 - Sindicalistas\n");
                        printf("5 - 'Maria vai com as outras' \n");
                        while( ( deputado[contadorDeputado].bancada < 1 )  || ( deputado[contadorDeputado].bancada > 5 ) ){
                            printf("Digite a bandaca do deputado:\n");
                            setbuf(stdin , NULL);
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
                    setbuf(stdin , NULL);
                    scanf("%d", &escolherMatricula);
                    for( i = 0; i < 513; i++){
                        if( escolherMatricula == deputado[i].matricula){
                            verificaMatricula = i;
                            if ( deputado[verificaMatricula].voto == -1){
                                while( ( deputado[verificaMatricula].voto < 0 )  || ( deputado[verificaMatricula].voto > 2 ) ){
                                    printf("Digite o voto do congressista: (0 - A favor / 1 - Contra / 2 - Abstenção) \n");
                                    setbuf(stdin , NULL);
                                    scanf("%d",&deputado[verificaMatricula].voto);
                                }

                            }
                            else{
                                printf("Sem maracutaia...este voto ja foi computado");
                                break;
                            }
                        }
                        else{
                            printf("Matricula nao encontrada\n");
                            break;
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
                    ContabilizacaoDeVotoPorPreferencia( deputado, partido, estado, 1);
                    break;

                case 6:
                    ContabilizacaoDeVotoPorPreferencia( deputado, partido, estado, 2);
                    break;

                case 7:
                    ContabilizacaoDeVotoPorPreferencia( deputado, partido, estado, 3);
                    break;
            }

        printf("Deseja voltar ao menu: 0 - Sim / Qualquer outro valor - Nao\n");
        setbuf(stdin , NULL);
        scanf("%d",&verifica);
        if( verifica == 0){
            decisao = -1;
            verificaEstado  = -1;
            verificaPartido = -1;
        }



    }

    return 0;
}
